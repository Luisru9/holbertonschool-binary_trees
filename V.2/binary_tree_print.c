#include "binary_trees.h"

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: The Pointer to the node to print
 * @offset: The Offset to print
 * @depth: The Depth of the node
 * @s: The Buffer
 *
 * Return: The length of printed tree, after process
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[10];
	int width, left, right, is_left, x;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);
	for (x = 0; x < width; x++)
		s[depth][offset + left + x] = b[x];
	if (depth && is_left)
	{
		for (x = 0; x < width + right; x++)
			s[depth - 1][offset + left + width / 2 + x] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (x = 0; x < left + width; x++)
			s[depth - 1][offset - width / 2 + x] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t heightleft;
	size_t heightright;

	heightleft = tree->left ? 1 + _height(tree->left) : 0;
	heightright = tree->right ? 1 + _height(tree->right) : 0;
	return (heightleft > heightright ? heightleft : heightright);
}

/**
 * binary_tree_print - Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, x, y;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (x = 0; x < height + 1; x++)
	{
		s[x] = malloc(sizeof(**s) * 255);
		if (!s[x])
			return;
		memset(s[x], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (x = 0; x < height + 1; x++)
	{
		for (y = 254; y > 1; --y)
		{
			if (s[x][y] != ' ')
				break;
			s[x][y] = '\0';
		}
		printf("%s\n", s[x]);
		free(s[x]);
	}
	free(s);
}
