#pragma once


typedef struct Ht
{
	int key;
	int value;
	int h;
	struct Ht* right;
	struct Ht* left;
}Htree;



int get_height(Htree* root);


int Hinsert(Htree** root, int key, int value);

void free_Htree(Htree* root);