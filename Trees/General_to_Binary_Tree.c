// Write a program to convert a general tree to binary tree
#include <stdio.h>
#include <stdlib.h>

// Definition for a general tree node.
typedef struct TreeNode{
    int val;
    int num_children;
    struct TreeNode **children;
}TreeNode;

// Definition for a binary tree node.
typedef struct BinaryTreeNode{
    int val;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
}BinaryTreeNode;

BinaryTreeNode *convertToBinaryTree(TreeNode *root){
    if (!root)
        return NULL;
    BinaryTreeNode *binary_root = malloc(sizeof(BinaryTreeNode));
    binary_root->val = root->val;
    binary_root->left = NULL;
    binary_root->right = NULL;

    if (root->num_children > 0)
    {
        binary_root->left = convertToBinaryTree(root->children[0]);
    }
    if (root->num_children > 1)
    {
        binary_root->right = convertToBinaryTree(root->children[1]);
    }

    // Convert the rest of the children to a linked list, with the head of the
    // linked list as the right child of the current binary tree node.
    BinaryTreeNode *current = binary_root->right;
    for (int i = 2; i < root->num_children; i++)
    {
        current->right = convertToBinaryTree(root->children[i]);
        current = current->right;
    }

    return binary_root;
}

int main()
{
    // Create a general tree with 3 children for the root node.
    TreeNode *root = malloc(sizeof(TreeNode));
    root->val = 1;
    root->num_children = 3;
    root->children = malloc(sizeof(TreeNode *) * root->num_children);
    root->children[0] = malloc(sizeof(TreeNode));
    root->children[0]->val = 2;
    root->children[0]->num_children = 0;
    root->children[1] = malloc(sizeof(TreeNode));
    root->children[1]->val = 3;
    root->children[1]->num_children = 0;
    root->children[2] = malloc(sizeof(TreeNode));
    root->children[2]->val = 4;
    root->children[2]->num_children = 0;

    BinaryTreeNode *binary_root = convertToBinaryTree(root);
    printf("Your Binary Tree is : ");
    printf("%d ", binary_root->val);
    printf("%d ", binary_root->left->val);
    printf("%d ", binary_root->right->val);
    printf("%d ", binary_root->right->right->val);
    return 0;
}
/*
Your Binary Tree is : 1 2 3 4
*/