#include "binary_trees.h"

#define MAX_WIDTH 255
#define SPACE ' '

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
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}

	for (x = 0; x < height + 1; x++)
	{
		s[x] = malloc(sizeof(**s) * (MAX_WIDTH + 1));
		if (!s[x])
		{
			fprintf(stderr, "Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
		memset(s[x], SPACE, MAX_WIDTH);
		s[x][MAX_WIDTH] = '\0';
	}

	print_t(tree, 0, 0, s);

	for (x = 0; x < height + 1; x++)
	{
		for (y = MAX_WIDTH; y > 1; --y)
		{
			if (s[x][y] != SPACE)
				break;
			s[x][y] = '\0';
		}
		printf("%s\n", s[x]);
		free(s[x]);
}

	free(s);
}

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: Length of printed tree after process
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char buffer[10];
	int width, left, right, isLeft, x;

	if (!tree)
		return (0);

	isLeft = (tree->parent && tree->parent->left == tree);
	width = sprintf(buffer, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + left + width, depth + 1, s);

	for (x = 0; x < width; x++)
		s[depth][offset + left + x] = buffer[x];

	if (depth && isLeft)
	{
		for (x = 0; x < width + right; x++)
			s[depth - 1][offset + left + width / 2 + x] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !isLeft)
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
 * @tree: Pointer to the node to measure the height
 *
 * Return: The height of the tree starting at @node
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t heightLeft, heightRight;

	if (!tree)
		return (0);

	heightLeft = tree->left ? 1 + _height(tree->left) : 0;
	heightRight = tree->right ? 1 + _height(tree->right) : 0;

	return ((heightLeft > heightRight) ? heightLeft : heightRight);
}
