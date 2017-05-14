#include "stdafx.h"

#include <stdlib.h> 

#include <math.h> 

#include "AVL_tree.h"


int AVL_get_height(AVLtree* root)
{
	return (NULL == root) ? 0 : (root->h);
}

void AVL_improve_height(AVLtree* root)
{
	int Hright = AVL_get_height(root->right);
	int Hleft = AVL_get_height(root->left);
	root->h = (Hright > Hleft) ? (Hright + 1) : (Hleft + 1);
}

int AVL_delta_height(AVLtree* root)
{
	return AVL_get_height(root->left) - AVL_get_height(root->right);
}

void little_left_rotation(AVLtree** root)
{
	AVLtree* t = (*root);
	(*root) = (*root)->right;
	t->right = (*root)->left;
	(*root)->left = t;
	AVL_improve_height((*root)->left);
	AVL_improve_height(*root);
}

void little_right_rotation(AVLtree** root)
{
	AVLtree* t = (*root);
	(*root) = (*root)->left;
	t->left = (*root)->right;
	(*root)->right = t;
	AVL_improve_height((*root)->right);
	AVL_improve_height(*root);
}

void big_left_rotation(AVLtree** root)
{
	little_right_rotation(&((*root)->right));
	little_left_rotation(root);
}

void big_right_rotation(AVLtree** root)
{
	little_left_rotation(&((*root)->left));
	little_right_rotation(root);
}

void AVL_improve_balance(AVLtree** root)
{
	int delta;
	delta = AVL_delta_height(*root);
	if (abs(delta) <= 1)
	{
		return;
	}
	if (2 == delta)
	{
		if (AVL_delta_height((*root)->left) < 0)
		{
			big_right_rotation(root);
		}
		else
		{
			little_right_rotation(root);
		}
	}
	else
	{
		if (AVL_delta_height((*root)->right) > 0)
		{
			big_left_rotation(root);
		}
		else
		{
			little_left_rotation(root);
		}
	}
}


int AVLinsert(AVLtree** root, int key, int value)
{
	int result = 0;
	if (NULL == *root)
	{
		(*root) = (AVLtree*)malloc(sizeof(AVLtree));
		if (NULL == *root)
		{
			return 0;
		}
		(*root)->key = key;
		(*root)->value = value;
		(*root)->h = 1;
		(*root)->right = NULL;
		(*root)->left = NULL;
		return 1;
	}
	if ((*root)->key == key)
	{
		return 0;
	}
	if ((*root)->key > key)
	{
		result = AVLinsert(&((*root)->left), key, value);
	}
	else
	{
		result = AVLinsert(&((*root)->right), key, value);
	}
	if (result)
	{
		AVL_improve_height(*root);
		AVL_improve_balance(root);
	}
	return result;
}

void free_AVLtree(AVLtree* root)
{
	if (NULL != root)
	{
		free_AVLtree(root->left);
		free_AVLtree(root->right);
		free(root);
	}
}