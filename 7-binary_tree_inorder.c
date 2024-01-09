#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through the binary tree using inorder tranversal
 * @tree: pointer to root to node to traverse
 * @func:pointer to func to call nodes
 * Return: void
*/

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
{
return;
}
binary_tree_inorder(tree->left, func);
func(tree->n);
binary_tree_inorder(tree->right, func);
}