// RebuildBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#define MAXLENGHT  1023
using namespace std;

char preSort[MAXLENGHT] = "abdcef", midSort[MAXLENGHT] = "dbaecf";

typedef struct binaryTree
{
	binaryTree* left;
	binaryTree* right;
	char data;
};

void TreeView(binaryTree* bt)
{
	binaryTree* sort[MAXLENGHT];
	int i = 1, sig = 0;
	sort[0] = bt;
	while (bt != NULL)
	{
		if (bt->left != NULL)
			sort[i++] = bt->left;
		if (bt->right != NULL)
			sort[i++] = bt->right;
		if (sig < i - 1)
			bt = sort[++sig];
		else
			break;
	}
}

binaryTree* FindRoot(int start, int end, int pos)
{
	if (end <= start)
	{
		return NULL;
	}

	int mid = 0;
	binaryTree *root = (binaryTree*)malloc(sizeof(binaryTree));
	
	if (end - start == 1)
	{
		root->data = midSort[start];
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else
	{
		root->data = preSort[pos];
		for (int i = start; i < end; i++)
		{
			if (midSort[i] == preSort[pos])
			{
				mid = i;
				break;
			}
		}

		root->left = FindRoot(start, mid, pos + 1);
		root->right = FindRoot(mid + 1, end, mid + 1);
	}
	return root;
}
/*preSort: "abdcef" ;
  midSort: "dbaecf" ;*/
int main()
{
	int len = strlen(midSort);
	int start = 0, end = len, mid = 0;

	binaryTree *root = FindRoot(0, len, 0);
	
	TreeView(root);
	getchar();
    return 0;
}

