#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the number of nodes with at least one child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: Number of nodes with at least one child in the binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;
    else if (tree->left != NULL || tree->right != NULL)
        return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
    else
        return binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}
