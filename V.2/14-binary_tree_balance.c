#include "binary_trees.h"


/* Function to calculate the height of a binary tree */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/* Function to calculate the balance factor of a binary tree */
int binary_tree_balance(const binary_tree_t *tree) {
    if (tree == NULL)
	{
		return (0);
	}

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	return (left_height - right_height);
}

/* Function to create a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
	{
		binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
		if (new_node == NULL)
		{
			return (NULL);
		}

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent != NULL) {
		new_node->parent = parent;
	}

	return (new_node);
}

/* Function to insert a new node as the left child */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL) {
		return (NULL);
	}

	parent->left = binary_tree_node(parent, value);
	return (parent->left);
}

/* Function to insert a new node as the right child */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value) {
	if (parent == NULL) 
	{
		return (NULL);
	}

	parent->right = binary_tree_node(parent, value);
	return (parent->right);
}

/* Function to print a binary tree (in-order) */
void binary_tree_print(const binary_tree_t *tree)
	{
		if (tree == NULL) {
			return;
	}

	binary_tree_print(tree->left);
	printf("%d ", tree->n);
	binary_tree_print(tree->right);
}
