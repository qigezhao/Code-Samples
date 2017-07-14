/*
 * binary-tree.c
 *
 *  Created on: Jun 22, 2017
 *      Author: Qige <qigezhao@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

struct binary_tree
{
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
};

typedef struct binary_tree btnode;

void btree_insert(btnode **tree, int val)
{
	btnode *new_btnode;
	if (!(*tree))
	{
		new_btnode = NULL;
		new_btnode = (btnode *) malloc(sizeof(btnode));
		new_btnode->left = new_btnode->right = NULL;
		new_btnode->data = val;
		*tree = new_btnode;
		return;
	}

	if ((*tree)->data > val)
	{
		btree_insert(&(*tree)->left, val);
	} else {
		btree_insert(&(*tree)->right, val);
	}
}

void btree_del(btnode *tree)
{
	if (tree)
	{
		btree_del(tree->left);
		btree_del(tree->right);
		free(tree);
	}
}

void print_preorder(btnode *tree)
{
	if (tree)
	{
		printf("%d\n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}
void print_inorder(btnode *tree)
{
	if (tree)
	{
		print_inorder(tree->left);
		printf("%d\n", tree->data);
		print_inorder(tree->right);
	}
}

int main(void)
{
	btnode *root;
	root = NULL;

	btree_insert(&root, 4);
	btree_insert(&root, 2);
	btree_insert(&root, 3);
	btree_insert(&root, 1);
	btree_insert(&root, 7);

	btree_insert(&root, 6);
	btree_insert(&root, 8);
	btree_insert(&root, 9);

	printf("Pre order\n");
	print_preorder(root);

	printf("In order\n");
	print_inorder(root);

	btree_del(root);

	return 0;
}

