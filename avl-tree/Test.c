#include "stdafx.h"

#include <stdio.h> 

#define N 1000 

#include "binary_tree.h"
#include "AVL_tree.h"


void fir_test()
{
	int error;
	int count;
	int i;
	Htree* root = NULL;
	AVLtree* avl_root = NULL;
	error = 0;
	count = N;

	for (i = 1; i <= count; i++)
	{
		if ((!(AVLinsert(&avl_root, i, i))) || (!(Hinsert(&root, i, i))))
		{
			error = 1;
			break;
		}

	}

	if (!error) {
		printf("\nFirst test:\n");
		printf("AVL height: %d\n", AVL_get_height(avl_root));
		printf("Binary height: %d\n", get_height(root));
	}
	free_Htree(root);
	free_AVLtree(avl_root);
}


void second_test()
{
	int error;
	int count;
	int i;
	Htree* root = NULL;
	AVLtree* avl_root = NULL;
	error = 0;
	count = N;

	for (i = count; i >= 1; i--)
	{
		if ((!(AVLinsert(&avl_root, i, i))) || (!(Hinsert(&root, i, i))))
		{
			error = 1;
			break;
		}

	}

	if (!error) {
		printf("\nSecond test:\n");
		printf("AVL height: %d\n", AVL_get_height(avl_root));
		printf("Binary height: %d\n", get_height(root));
	}
	free_Htree(root);
	free_AVLtree(avl_root);
}




void third_test()
{
	int error;
	int count;
	int value;
	int i;
	Htree* root = NULL;
	AVLtree* avl_root = NULL;
	error = 0;
	count = N / 2;
	if (N != count * 2)
	{
		count++;
	}
	for (i = 1; i <= count; i++)
	{
		if ((!(AVLinsert(&avl_root, i, i))) || (!(Hinsert(&root, i, i)))) {
			error = 1;
			break;
		}
		value = N - i + 1;
		if (value != i)
		{
			if ((!(AVLinsert(&avl_root, value, value))) || (!(Hinsert(&root, value, value)))) {
				error = 1;
				break;
			}
		}
	}

	if (!error) {
		printf("\nThird test:\n");
		printf("AVL height: %d\n", AVL_get_height(avl_root));
		printf("Binary height: %d\n", get_height(root));
	}
	free_Htree(root);
	free_AVLtree(avl_root);
}
void tests()
{
	fir_test();
	second_test();
	third_test();
}