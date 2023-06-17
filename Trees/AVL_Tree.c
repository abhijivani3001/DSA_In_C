/*
Perform following operations on AVL tree
i) Insert a Node
ii) Traverse the Tree
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int height;
    struct node* left;
    struct node* right;
}node;

void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void preorder(node* root){
    if(!root) return;
    printf("%d ",root->data);
    inorder(root->left);
    inorder(root->right);
}
void postorder(node* root){
    if(!root) return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ",root->data);
}

int nodeHeight(node* p){
    int hl,hr;
    hl=((p && p->left) ? p->left->height : 0);
    hr=((p && p->right) ? p->right->height : 0);
    return hl>hr ? hl+1 : hr+1;
}

int balanceFactor(node* p){
    int hl,hr;
    hl=((p && p->left) ? p->left->height : 0);
    hr=((p && p->right) ? p->right->height : 0);
    return hl-hr;
}

node* llRotation(node* root,node* p){
    node* pl=p->left;
    node* plr=pl->right;
    pl->right=p;
    p->left=plr;
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);

    if(root==p) root=pl;
    return pl;
}
node* lrRotation(node* root,node* p){
    node* pl=p->left;
    node* plr=pl->right;
    pl->right=plr->left;
    p->left=plr->right;
    plr->left=pl;
    plr->right=p;

    pl->height=nodeHeight(pl);
    p->height=nodeHeight(p);
    plr->height=nodeHeight(plr);

    if(root==p) return root=plr;
    return plr;
}
node* rrRotation(node* root,node* p){
    node* pr=p->right;
    node* prl=pr->left;
    pr->left=p;
    p->right=prl;
    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);

    if(root==p) root=pr;
    return pr;
}
node* rlRotation(node* root,node* p){
    node* pr=p->right;
    node* prl=pr->left;
    pr->left=prl->right;
    p->right=prl->left;
    prl->left=p;
    prl->right=pr;

    pr->height=nodeHeight(pr);
    p->height=nodeHeight(p);
    prl->height=nodeHeight(prl);
    if(root==p) return root=prl;
    return prl;
}

node* insert_recursive(node* root,node* p,int key){
    node* t=NULL;
    if(p==NULL){
        t=(node*)malloc(sizeof(node));
        t->data=key;
        t->height=1;
        t->left=t->right=NULL;
        return t;
    }
    if(key>p->data)
        p->right=insert_recursive(root,p->right,key);
    else if(key<p->data)
        p->left=insert_recursive(root,p->left,key);
    p->height=nodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->left)==1)
        return llRotation(root,p);
    else if(balanceFactor(p)==2 && balanceFactor(p->left)==-1)
        return lrRotation(root,p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->right)==-1)
        return rrRotation(root,p);
    else if(balanceFactor(p)==-2 && balanceFactor(p->right)==1)
        return rlRotation(root,p);
    return p;
}

int main(){
    node* root=NULL;
    int ch,a,t;
    while(1){
        printf("\n*** 1.Insert \t 2.Traverse \t 0.Exit ***\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                free(root);
                return 0;
            case 1:
                printf("Enter the value : ");
                scanf("%d",&a);
                root=insert_recursive(root,root,a);
                break;
            case 2:
                printf("\n*** 1.Preorder \t 2.Inorder \t 3.Postorder ***\n");
                printf("Enter your choice : ");
                scanf("%d",&t);
                switch(t){
                    case 1:
                        printf("Preorder Traversal : ");
                        preorder(root);
                        printf("\n");
                        break;
                    case 2:
                        printf("Inorder Traversal : ");
                        inorder(root);
                        printf("\n");
                        break;
                    case 3:
                        printf("Postorder Traversal : ");
                        postorder(root);
                        printf("\n");
                        break;
                    default:
                        printf("Wrong choice entered!!\n");
                        break;
                }
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
    return 0;
}
