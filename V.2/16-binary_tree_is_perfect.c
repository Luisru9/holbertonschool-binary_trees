#include "binary_trees.h"

size_t _height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t height_left = _height(tree->left);
|   size_t height_right = _height(tree->right);

	return (1 + (height_left > height_right ? height_left : height_right));
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t left_height = _height(tree->left);
	size_t right_height = _height(tree->right);

	if (left_height != right_height)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	else
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	}
}
