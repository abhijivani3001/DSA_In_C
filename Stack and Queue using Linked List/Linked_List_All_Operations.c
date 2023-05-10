/*
Write a program to create singly linear linked list, singly circular linked list, 
doubly linear linked list and doubly circular linked list and perform following 
operations. (One single program using Switch choice)
 i) Create a linked list
 ii) Insert a node at the beginning of the list
 iii) Insert a node at the end
 iv) Insert a node at a given position
 v) Delete a node from beginning
 vi) Delete a node from end
 vii) Delete a node from a given position
 viii) Copy a given list
 ix). Display the list
*/
#include<stdio.h>
#include<stdlib.h>
int count=0,size; // count=number of nodes in LL, size=maximum size of LL

// Structure for singly linked list node
typedef struct node{
    int data;
    struct node* next;
}node;

// Structure for doubly linked list node
typedef struct node2{
    int data;
    struct node2* next;
    struct node2* prev;
}node2;

// Function definition for insert the node at front of the singly LL
node* insert_front(node* head,int x){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    n->next=head;
    head=n;
    count++;
    return head;
}

// Function definition for insert the node at end of the singly LL
node* insert_end(node* head,int x){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    n->next=NULL;
    if(head==NULL){
        head=n;
        count++;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
    count++;
    return head;
}

// Function definition for insert the node at any index of the singly LL
node* insert_at_index(node* head,int x,int i){
    if(i==1){
        head=insert_front(head,x);
        return head;
    }
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    node* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    n->next=temp->next;
    temp->next=n;
    count++;
    return head;
}

// Function definition for delete the node at front of the singly LL
node* delete_front(node* head){
    node* temp=head;
    head=temp->next;
    free(temp);
    count--;
    return head;
}

// Function definition for delete the node at end of the singly LL
node* delete_end(node* head){
    node* temp=head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        count--;
        return head;
    }
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->next=NULL;
    free(temp->next);
    count--;
    return head;
}

// Function definition for delete the node at any index of the singly LL
node* delete_at_index(node* head,int i){
    if(i==1){
        head=delete_front(head);
        return head;
    }
    node* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    node* t=temp->next;
    temp->next=temp->next->next;
    free(t);
    count--;
    return head;
}

// Function definition for copy the singly LL
node* copy_singly_linear(node* head){
    if(head==NULL) return NULL;
    node* temp=head;
    node *temp2, *head2;
    node* n=(node*)malloc(sizeof(node));
    temp2=head2=n;
    n->next=NULL; n->data=temp->data;
    temp=temp->next;
    while(temp){
        node* n=(node*)malloc(sizeof(node));
        n->data=temp->data;
        n->next=NULL;
        temp2->next=n;
        temp2=n;
        temp=temp->next;
    }
    return head2;
}

// Function definition for display the singly LL
void display_singly_linear(node* head){
    node* temp=head;
    if(head==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    printf("\n*** Your Linked List ***\n");
    while(temp){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

// Function definition for singly LL
void singly_linear(){
    node* head=NULL;
    node* head2=NULL;
    int c,a,i,m; // c=choice of operaion, a=element to insert, i=index, m=number of linkes you make before any operation
    lable:
    printf("\nEnter the number of links you want to make : ");
    scanf("%d",&m);
    if(m>size){
        printf("Please enter valid length!!\n");
        goto lable;
    }
    size-=m;
    while(m--){
        printf("Enter the value : ");
        scanf("%d",&a);
        head=insert_end(head,a);
    }
    while(1){
        printf("\n1.Insert Front \t 2.Insert End \t 3.Insert at given position \t 4.Delete Front \t 5.Delete End \t 6.Delete at given position \t 7.Copy list \t 8.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_front(head,a);
                size--;
                break;
            case 2:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_end(head,a);
                size--;
                break;
            case 3:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count+1 || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_at_index(head,a,i);
                size--;
                break;
            case 4:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_front(head);
                size++;
                break;
            case 5:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_end(head);
                size++;
                break;
            case 6:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                head=delete_at_index(head,i);
                size++;
                break;
            case 7:
                head2=copy_singly_linear(head);
                printf("\n*** Your copied Linked List ***\n");
                display_singly_linear(head2);
                break;
            case 8:
                display_singly_linear(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}

// Function definition for insert the node at front of the singly circluar LL
node* insert_front_circular(node* head,int x){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    if(head==NULL){
        n->next=n;
        head=n;
        count++;
        return head;
    }
    n->next=head;
    node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=n;
    head=n;
    count++;
    return head;
}

// Function definition for insert the node at end of the singly circluar LL
node* insert_end_circular(node* head,int x){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    if(head==NULL){
        n->next=n;
        head=n;
        count++;
        return head;
    }
    node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    n->next=head;
    temp->next=n;
    count++;
    return head;
}

// Function definition for insert the node at any endex of the singly circluar LL
node* insert_at_index_circular(node* head,int x,int i){
    if(i==1){
        head=insert_front_circular(head,x);
        return head;
    }
    if(i==count+1){
        head=insert_end_circular(head,x);
        return head;
    }
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    node* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    n->next=temp->next;
    temp->next=n;
    count++;
    return head;
}

// Function definition for delete the node at front of the singly circluar LL
node* delete_front_circular(node* head){
    node* temp=head;
    node* t=head;
    while(temp->next!=head)
        temp=temp->next;
    head=temp->next->next;
    temp->next=head;
    free(t);
    count--;
    return head;
}

// Function definition for delete the node at  of the singly circluar LL
node* delete_end_circular(node* head){
    node* temp=head;
    if(temp->next==head){
        head=NULL;
        free(temp);
        count--;
        return head;
    }
    while(temp->next->next!=head)
        temp=temp->next;
    node* t=temp->next;
    temp->next=head;
    free(t);
    count--;
    return head;
}

// Function definition for delete the node at any index of the singly circluar LL
node* delete_at_index_circular(node* head,int i){
    if(i==1){
        head=delete_front_circular(head);
        return head;
    }
    if(i==count){
        head=delete_end_circular(head);
        return head;
    }
    node* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    node* t=temp->next;
    temp->next=t->next;
    free(t);
    count--;
    return head;
}

// Function definition for copy the singly circluar LL
node* copy_singly_circular(node* head){
    if(head==NULL) return NULL;
    node* temp=head;
    node *temp2, *head2;
    node* n=(node*)malloc(sizeof(node));
    temp2=head2=n;
    n->next=head2; n->data=temp->data;
    temp=temp->next;
    while(temp!=head){
        node* n=(node*)malloc(sizeof(node));
        n->data=temp->data;
        n->next=head2;
        temp2->next=n;
        temp2=n;
        temp=temp->next;
    }
    return head2;
}

// Function definition for display the singly circluar LL
void display_singly_circular(node* head){
    node* temp=head;
    if(head==NULL || count==0){
        printf("Linked List is Empty\n");
        return;
    }
    printf("\n*** Your Linked List ***\n");
    while(temp->next!=head){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d -> ",temp->data);
    printf("...\n");
}

void singly_circular(){
    node* head=NULL;
    node* head2=NULL;
    int c,a,i,m; // c=choice of operaion, a=element to insert, i=index, m=number of linkes you want make before any operation
    lable:
    printf("\nEnter the number of links you want to make : ");
    scanf("%d",&m);
    if(m>size){
        printf("Please enter valid length!!\n");
        goto lable;
    }
    size-=m;
    while(m--){
        printf("Enter the value : ");
        scanf("%d",&a);
        head=insert_end_circular(head,a);
    }
    while(1){
        printf("\n1.Insert Front \t 2.Insert End \t 3.Insert at given position \t 4.Delete Front \t 5.Delete End \t 6.Delete at given position \t 7.Copy list \t 8.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_front_circular(head,a);
                size--;
                break;
            case 2:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_end_circular(head,a);
                size--;
                break;
            case 3:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count+1 || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_at_index_circular(head,a,i);
                size--;
                break;
            case 4:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_front_circular(head);
                size++;
                break;
            case 5:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_end_circular(head);
                size++;
                break;
            case 6:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                head=delete_at_index_circular(head,i);
                size++;
                break;
            case 7:
                head2=copy_singly_circular(head);
                printf("\n*** Your copied Linked List ***\n");
                display_singly_circular(head2);
                break;
            case 8:
                display_singly_circular(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}

// Function definition for insert the node at front of the doubly LL
node2* insert_front_doubly(node2* head,int x){
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    n->next=n->prev=NULL;
    if(head==NULL){
        head=n;
        count++;
        return head;
    }
    n->next=head;
    head->prev=n;
    head=n;
    count++;
    return head;
}

// Function definition for insert the node at end of the doubly LL
node2* insert_end_doubly(node2* head,int x){
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    n->next=n->prev=NULL;
    if(head==NULL){
        head=n;
        count++;
        return head;
    }
    node2* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=n;
    n->prev=temp;
    count++;
    return head;
}

// Function definition for insert the node at any index of the doubly LL
node2* insert_at_index_doubly(node2* head,int x,int i){
    if(i==1){
        head=insert_front_doubly(head,x);
        return head;
    }
    if(i==count+1){
        head=insert_end_doubly(head,x);
        return head;
    }
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    node2* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    n->next->prev=n;
    count++;
    return head;
}

// Function definition for delete the node at front of the doubly LL
node2* delete_front_doubly(node2* head){
    node2* temp=head;
    head=head->next;
    if(head!=NULL)
        head->prev=NULL;
    free(temp);
    count--;
    return head;
}

// Function definition for delete the node at end of the doubly LL
node2* delete_end_doubly(node2* head){
    if(head->next==NULL){
        head=delete_front_doubly(head);
        return head;
    }
    node2* temp=head;
    while(temp->next->next!=NULL)
        temp=temp->next;
    temp->next=NULL;
    free(temp->next);
    count--;
    return head;
}

// Function definition for delete the node at any index of the doubly LL
node2* delete_at_index_doubly(node2* head,int i){
    if(i==1){
        head=delete_front_doubly(head);
        return head;
    }
    if(i==count){
        head=delete_end_doubly(head);
        return head;
    }
    node2* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    node2* t=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    free(t);
    count--;
    return head;
}

// Function definition for copy the doubly LL
node2* copy_doubly_linear(node2* head){
    if(head==NULL) return NULL;
    node2* temp=head;
    node2 *temp2, *head2;
    node2* n=(node2*)malloc(sizeof(node2));
    temp2=head2=n;
    n->next=NULL; n->prev=NULL; n->data=temp->data;
    temp=temp->next;
    while(temp){
        node2* n=(node2*)malloc(sizeof(node2));
        n->data=temp->data;
        n->next=NULL;
        n->prev=temp2;
        temp2->next=n;
        temp2=n;
        temp=temp->next;
    }
    return head2;
}

// Function definition for display the doubly LL
void display_doubly_linear(node2* head){
    node2* temp=head;
    if(head==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    printf("\n*** Your Linked List ***\n");
    printf("NULL <-> ");
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void doubly_linear(){
    node2* head=NULL;
    node2* head2=NULL;
    int c,a,i,m; // c=choice of operaion, a=element to insert, i=index, m=number of linkes you make before any operation
    lable:
    printf("\nEnter the number of links you want to make : ");
    scanf("%d",&m);
    if(m>size){
        printf("Please enter valid length!!\n");
        goto lable;
    }
    size-=m;
    while(m--){
        printf("Enter the value : ");
        scanf("%d",&a);
        head=insert_end_doubly(head,a);
    }
    while(1){
        printf("\n1.Insert Front \t 2.Insert End \t 3.Insert at given position \t 4.Delete Front \t 5.Delete End \t 6.Delete at given position \t 7.Copy list \t 8.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_front_doubly(head,a);
                size--;
                break;
            case 2:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_end_doubly(head,a);
                size--;
                break;
            case 3:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count+1 || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_at_index_doubly(head,a,i);
                size--;
                break;
            case 4:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_front_doubly(head);
                size++;
                break;
            case 5:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_end_doubly(head);
                size++;
                break;
            case 6:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                head=delete_at_index_doubly(head,i);
                size++;
                break;
            case 7:
                head2=copy_doubly_linear(head);
                printf("\n*** Your copied Linked List ***\n");
                display_doubly_linear(head2);
                break;
            case 8:
                display_doubly_linear(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}

// Function definition for insert the node at front of the doubly circluar LL
node2* insert_front_doubly_circular(node2* head,int x){
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        count++;
        return head;
    }
    n->next=head;
    head->prev=n;
    node2* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=n;
    n->prev=temp;
    head=n;
    count++;
    return head;
}

// Function definition for insert the node at end of the doubly circluar LL
node2* insert_end_doubly_circular(node2* head,int x){
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    if(head==NULL){
        n->next=n;
        n->prev=n;
        head=n;
        count++;
        return head;
    }
    node2* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=n;
    n->prev=temp;
    n->next=head;
    head->prev=n;
    count++;
    return head;
}

// Function definition for insert the node at any index of the doubly circluar LL
node2* insert_at_index_doubly_circular(node2* head,int x,int i){
    if(i==1){
        head=insert_front_doubly_circular(head,x);
        return head;
    }
    if(i==count+1){
        head=insert_end_doubly_circular(head,x);
        return head;
    }
    node2* n=(node2*)malloc(sizeof(node2));
    n->data=x;
    node2* temp=head;
    i--;
    while(--i)
        temp=temp->next;
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
    count++;
    return head;
}

// Function definition for delete the node at front of the doubly circluar LL
node2* delete_front_doubly_circular(node2* head){
    node2* temp=head;
    if(temp->next==temp){
        head=NULL;
        free(temp);
        count--;
        return head;
    }
    head=temp->next;
    head->prev=temp->prev;
    temp->prev->next=head;
    free(temp);
    count--;
    return head;
}

// Function definition for delete the node at end of the doubly circluar LL
node2* delete_end_doubly_circular(node2* head){
    node2* temp=head;
    if(temp->next==temp){
        head=NULL;
        free(temp);
        count--;
        return head;
    }
    while(temp->next!=head)
        temp=temp->next;
    temp->prev->next=head;
    head->prev=temp->prev;
    free(temp);
    count--;
    return head;
}

// Function definition for delete the node at any index of the doubly circluar LL
node2* delete_at_index_doubly_circular(node2* head,int i){
    if(i==1){
        head=delete_front_doubly_circular(head);
        return head;
    }
    if(i==count+1){
        head=delete_end_doubly_circular(head);
        return head;
    }
    node2* temp=head;
    while(--i)
        temp=temp->next;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
    count--;
    return head;
}

// Function definition for copy the doubly circluar LL
node2* copy_doubly_circular(node2* head){
    if(head==NULL) return NULL;
    node2* temp=head;
    node2 *temp2, *head2;
    node2* n=(node2*)malloc(sizeof(node2));
    temp2=head2=n;
    n->next=head2; n->prev=head2; n->data=temp->data;
    temp=temp->next;
    while(temp!=head){
        node2* n=(node2*)malloc(sizeof(node2));
        n->data=temp->data;
        n->next=head2;
        n->prev=temp2;
        temp2->next=n;
        temp2=n;
        temp=temp->next;
    }
    return head2;
}

// Function definition for display the doubly circluar LL
void display_doubly_circular(node2* head){
    node2* temp=head;
    if(head==NULL){
        printf("Linked List is Empty\n");
        return;
    }
    printf("\n*** Your Linked List ***\n");
    printf("... <-> ");
    while(temp->next!=head){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("%d <-> ...\n",temp->data);
}

void doubly_circular(){
    node2* head=NULL;
    node2* head2=NULL;
    int c,a,i,m; // c=choice of operaion, a=element to insert, i=index, m=number of linkes you make before any operation
    lable:
    printf("\nEnter the number of links you want to make : ");
    scanf("%d",&m);
    if(m>size){
        printf("Please enter valid length!!\n");
        goto lable;
    }
    size-=m;
    while(m--){
        printf("Enter the value : ");
        scanf("%d",&a);
        head=insert_end_doubly_circular(head,a);
    }
    while(1){
        printf("\n1.Insert Front \t 2.Insert End \t 3.Insert at given position \t 4.Delete Front \t 5.Delete End \t 6.Delete at given position \t 7.Copy list \t 8.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_front_doubly_circular(head,a);
                size--;
                break;
            case 2:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_end_doubly_circular(head,a);
                size--;
                break;
            case 3:
                if(size<=0){
                    printf("No more Available Nodes!!\n");
                    break;;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count+1 || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=insert_at_index_doubly_circular(head,a,i);
                size--;
                break;
            case 4:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_front_doubly_circular(head);
                size++;
                break;
            case 5:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                head=delete_end_doubly_circular(head);
                size++;
                break;
            case 6:
                if(count==0){
                    printf("Linked List is Empty\n");
                    break;
                }
                printf("Enter the Index : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter Valid Index!!\n");
                    break;
                }
                head=delete_at_index_doubly_circular(head,i);
                size++;
                break;
            case 7:
                head2=copy_doubly_circular(head);
                printf("\n*** Your copied Linked List ***\n");
                display_doubly_circular(head2);
                break;
            case 8:
                display_doubly_circular(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}


int main(){
    int ch; // ch=choice of type of Linked List
    printf("\nEnter the maximum size of Linked List : ");
    scanf("%d",&size);
    while(1){
        printf("\n1.Singly Linear Linked List \t 2.Singly Circular Linked List \t 3.Doubly Linear Linked List \t 4.Doubly Circular Linked List \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                return 0;
            case 1:
                singly_linear();
                break;
            case 2:
                singly_circular();
                break;
            case 3:
                doubly_linear();
                break;
            case 4:
                doubly_circular();
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
    return 0;
}