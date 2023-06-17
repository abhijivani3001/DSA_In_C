/*
Write a program to create a binary search tree and perform the following operations :
i) Insert a node in tree
ii) Search a node in tree
iii) Traversal of Tree (Inorder, Preorder, Postorder)
iv) Delete a node in tree
v) Calculate height of the tree
vi) Calculate total number of nodes, number of internal node and number of leaf node
*/
#include<stdio.h>
#include<stdlib.h>

// Structure of tree node
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

// Function definition of Inserting node recursively
node* insert_recursive(node* root,int key){
    node* t=NULL;
    if(root==NULL){
        t=(node*)malloc(sizeof(node));
        t->data=key;
        t->left=t->right=NULL;
        return t;
    }
    if(key>root->data) root->right=insert_recursive(root->right,key);
    else if(key<root->data) root->left=insert_recursive(root->left,key);
    return root;
}

// Function definition of Inserting node
node* insert_node(node* root,int key){
    node* curr=root;
    node* prev=NULL,*n;
    if(root==NULL){
        n=(node*)malloc(sizeof(node));
        n->data=key;
        n->left=n->right=NULL;
        root=n;
        return root;
    }
    while(curr){
        prev=curr;
        if(key<curr->data) curr=curr->left;
        else if(key>curr->data) curr=curr->right;
    }
    n=(node*)malloc(sizeof(node));
    n->data=key;
    n->left=n->right=NULL;
    if(key<prev->data) prev->left=n;
    else prev->right=n;
    return root;
}

// Function definition to search node
node* search_node(node* root,int key){
    node* t=root;
    while(t){
        if(key==t->data) return t;
        else if(key<t->data) t=t->left;
        else if(key>t->data) t=t->right;
    }
    return t;
}

// Function definition to count the height of tree
int height(node* p){
    int x,y;
    if(p==NULL) return 0;
    x=height(p->left);
    y=height(p->right);
    return (x>y) ? x+1 : y+1;
}

// Function definition to find inorder predecessor
node* inorder_predecessor(node* p){
    while(p && p->right!=NULL) p=p->right;
    return p;
}

// Function definition to find inorder successor
node* inorder_successor(node* p){
    while(p && p->left!=NULL) p=p->left;
    return p;
}

// Function definition to delete node
node* delete_node(node* p,node* root,int key){
    node* q;
    if(p==NULL) return NULL;
    if(p->left==NULL && p->right==NULL){
        if(p==root) root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data) 
        p->left=delete_node(p->left,root,key);
    else if(key>p->data) 
        p->right=delete_node(p->right,root,key);
    else{
        if(height(p->left)>height(p->right)){
            q=inorder_predecessor(p->left);
            p->data=q->data;
            p->left=delete_node(p->left,root,q->data);
        }
        else{
            q=inorder_successor(p->right);
            p->data=q->data;
            p->right=delete_node(p->right,root,q->data);
        }
    }
    return p;
}

// Function definition to count total number of nodes in tree
int count_total_nodes(node* root){
    if(!root) return 0;
    return 1+count_total_nodes(root->left)+count_total_nodes(root->right);
}
// Function definition to count total number of internal nodes in tree
int count_internal_nodes(node* root){
    if(!root || (!root->left && !root->right)) return 0;
    return 1+count_internal_nodes(root->left)+count_internal_nodes(root->right);
}
// Function definition to count total number of leaf nodes in tree
int count_leaf_nodes(node* root){
    if(!root) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return count_leaf_nodes(root->left)+count_leaf_nodes(root->right);
}

// Function definition to display tree in preorder way
void preorder(node* root){
    // D L R formate
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
// Function definition to display tree in inorder way
void inorder(node* root){
    // L D R formate
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
// Function definition to display tree in postorder way
void postorder(node* root){
    // L R D formate
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main(){
    node* root=NULL,*find;
    inorder(root);
    int ch,a,t,key;
    while(1){
        printf("\n*** 1.Insert \t 2.Search \t 3.Traverse a Tree \t 4.Delete \t 5.Calculate Height \t 6.Calculate Number of nodes \t 0.Exit ***\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                free(root);
                return 0;
            case 1:
                printf("Enter the value : ");
                scanf("%d",&a);
                // root=insert_node(root,a);
                root=insert_recursive(root,a);
                break;
            case 2:
                printf("Enter the value to search : ");
                scanf("%d",&key);
                find=search_node(root,key);
                if(find) printf("The value %d is present in the Binary Tree\n",find->data);
                else printf("The value %d is not present in the Binary Tree\n",key);
                break;
            case 3:
                printf("\n*** 1.Preorder \t 2.Inorder \t 3.Postorder ***\n");
                printf("Enter your choice : ");
                scanf("%d",&t);
                if(t==1){
                    printf("\n*** Preorder Traversal ***\n");
                    preorder(root);
                }
                else if(t==2){
                    printf("\n*** Inorder Traversal ***\n");
                    inorder(root);
                }
                else if(t==3){
                    printf("\n*** Postorder Traversal ***\n");
                    postorder(root);
                }
                else printf("Wrong choice entered!!");
                printf("\n");
                break;
            case 4:
                printf("Enter the value to delete from Tree : ");
                scanf("%d",&a);
                root=delete_node(root,root,a);
                break;
            case 5:
                printf("Heigth of the Binary Tree : %d\n",height(root));
                break;
            case 6:
                printf("\nTotal number of nodes : %d\n",count_total_nodes(root));
                printf("The number of Internal nodes : %d\n",count_internal_nodes(root));
                printf("The number of Leaf nodes : %d\n",count_leaf_nodes(root));
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
    return 0;
}