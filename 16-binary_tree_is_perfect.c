#include "binary_trees.h"

/**
 * height_for_perfect - helper to compute height for perfect-check
 * @tree: pointer to the root of the subtree
 *
 * Return: height (in nodes) of the subtree, 0 if tree is NULL
 *
 * Description:
 * We return height in nodes (leaf = 1). Using nodes vs edges
 * doesn't matter for equality; we only compare left/right heights.
 */
static size_t height_for_perfect(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (tree == NULL)
		return (0);

	lh = height_for_perfect(tree->left);
	rh = height_for_perfect(tree->right);

	return ((lh >= rh ? lh : rh) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 *
 * Description:
 * A perfect binary tree has all internal nodes with two children
 * AND all leaves at the same depth.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (tree == NULL)
		return (0);

	/* Leaf is perfect */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* If exactly one child is missing, not perfect */
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	/* Heights of both subtrees must match */
	lh = height_for_perfect(tree->left);
	rh = height_for_perfect(tree->right);
	if (lh != rh)
		return (0);

	/* Both subtrees must themselves be perfect */
	return (binary_tree_is_perfect(tree->left) &&
		binary_tree_is_perfect(tree->right));
}

