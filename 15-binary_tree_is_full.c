#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 *
 * Description:
 * A binary tree is full if every node has either 0 or 2 children.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	if (tree == NULL)
		return (0);

	/* If leaf node, it's full */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If both children exist, check recursively */
	if (tree->left != NULL && tree->right != NULL)
	{
		left_full = binary_tree_is_full(tree->left);
		right_full = binary_tree_is_full(tree->right);
		return (left_full && right_full);
	}

	/* If only one child exists, it's not full */
	return (0);
}

