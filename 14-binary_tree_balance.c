#include "binary_trees.h"

/**
 * binary_tree_height_balance - helper function to measure height of a tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height_balance(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height_balance(tree->left);
	right_h = binary_tree_height_balance(tree->right);

	if (left_h >= right_h)
		return (left_h + 1);
	else
		return (right_h + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *
 * Return: balance factor (left height - right height), or 0 if tree is NULL
 *
 * Description:
 * The balance factor of a binary tree is the difference between the heights
 * of the left and right subtrees.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = (int)binary_tree_height_balance(tree->left);
	right_h = (int)binary_tree_height_balance(tree->right);

	return (left_h - right_h);
}

