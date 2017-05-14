#pragma once
typedef struct AVLt
{
	int key;
	int value;
	int h;
	struct AVLt* right;
	struct AVLt* left;
} AVLtree;

int AVL_get_height(AVLtree* root);

int AVLinsert(AVLtree** root, int key, int value);

void free_AVLtree(AVLtree* root);