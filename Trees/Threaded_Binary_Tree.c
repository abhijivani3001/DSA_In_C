/*
Write a program to create inorder threaded binary tree and perform the following operations
i) Insert a node in threaded tree
ii) Inorder traversal of threaded binary tree
*/

/*
NOTE:
Steps to convert BST into TBT:
1) Keep the left most and the right most NULL pointers as "NULL"
2) Change all other NULL pointers as 
    --> Left pointer = Inorder predecessor
    --> Right pointer = Inorder successor
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
    int l_thread, r_thread;
}node;

// If l_thread=0 means have child
node *insert(node *root,int data){
    node *temp, *current, *n;
    temp = root;
    current = 0;
    while (temp != 0){
        current = temp;
        if (data < temp->data){
            if (temp->l_thread == 0) temp = temp->left;
            else break;
        }
        else{
            if (temp->r_thread == 0) temp = temp->right;
            else  break;
        }
    }
    n = (node*)malloc(sizeof(node));
    n->data = data;
    n->l_thread = 1;
    n->r_thread = 1;

    if (current == 0){
        root = n;
        n->left = 0;
        n->right = 0;
    }
    else if(data <= current->data){
        n->left = current->left;
        n->right = current;
        current->l_thread = 0;
        current->left = n;
    }
    else{
        n->left = current;
        n->right = current->right;
        current->r_thread = 0;
        current->right = n;
    }
    return root;
}

node *inordersuccessor(node *temp){
    if (temp->r_thread == 1)
        return temp->right;
    temp = temp->right;
    while (temp->l_thread == 0)
        temp = temp->left;
    return temp;
}

void inorder(node *root){
    node *temp;
    if (root == 0)
        printf("\nTree is empty...!\n");
    else{
        temp = root;
        while (temp->l_thread == 0)
            temp = temp->left;
        printf("\nInorder traversal : ");
        while (temp != 0){
            printf("%d ", temp->data);
            temp = inordersuccessor(temp);
        }
        printf("\n");
    }
}
int main(){
    int ch, a;
    node *root;
    root = 0;
    int t = 1;
    while(t){
        printf("\n*** 1.Insert \t 2.Inorder trversal \t 0.Exit ***\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                t=0;
                break;
            case 1:
                printf("\nEnter the value : ");
                scanf("%d", &a);
                root = insert(root, a);
                printf("Node inserted Successfully...\n");
                break;
            case 2:
                inorder(root);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}
