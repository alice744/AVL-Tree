#include "stdafx.h"

#include <stdlib.h> 

#include <math.h> 
#include "Binary_tree.h"




int get_height(Htree* root)
{
	return (NULL == root) ? 0 : (root->h);
}

void improve_height(Htree* root)
{
	int Hright = get_height(root->right) + 1;
	int Hleft = get_height(root->left) + 1;
	root->h = (Hright > Hleft) ? Hright : Hleft;
}

int Hinsert(Htree** root, int key, int value)
{
	int result = 0;
	if (NULL == *root)
	{
		(*root) = (Htree*)malloc(sizeof(Htree));
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
		result = Hinsert(&((*root)->left), key, value);
	}
	else
	{
		result = Hinsert(&((*root)->right), key, value);
	}

	if (result)
	{
		improve_height(*root);
	}
	return result;
}

void free_Htree(Htree* root)
{
	if (NULL != root)
	{
		free_Htree(root->left);
		free_Htree(root->right);
		free(root);
	}
}
