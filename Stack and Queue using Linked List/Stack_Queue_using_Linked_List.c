/*
Implement all the operations of Stack and Queue using Doubly Linked List.
*/
#include<stdio.h>
#include<stdlib.h>
int count=0,size; // count=Number of elements in Stack or Queue, size=size of Stack or Queue

// Structure of Node of Linked List
typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
}node;

// Function definition of Empty Stack/Queue
int isEmpty(node* head){
    if(!head)
        return 1;
    return 0;
}

// Function definition of Full Stack/Queue
int isFull(){
    if(count>=size)
        return 1;
    return 0;
}

// Function definition for push element into Stack
node* push(node* head,int x){
    node* n=(node*)malloc(sizeof(node));
    n->data=x;
    count++;
    if(!head){
        n->next=n->prev=NULL;
        head=n;
        return head;
    }
    node* temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=n;
    n->prev=temp;
    n->next=NULL;
    return head;
}

// Function definition for pop element from Stack
node* pop(node* head){
    node* temp=head;
    count--;
    if(!temp->next){
        head=NULL;
        free(temp);
        return head;
    }
    while(temp->next)
        temp=temp->next;
    temp->prev->next=NULL;
    free(temp);
    return head;
}

// Function definition for peep(display) value from Stack for given index
void peep(node* head,int i){
    node* temp=head;
    int j=count-i;
    while(j--)
        temp=temp->next;
    printf("Value at Index %d is %d\n",i,temp->data);
}

// Function definition for return value of Top of the Stack
int peek_stack(node* head){
    node* temp=head;
    while(temp->next)
        temp=temp->next;
    return temp->data;
}

// Function definition for change the value at given index
void change(node* head,int i,int x){
    node* temp=head;
    int j=count-i;
    while(j--)
        temp=temp->next;
    temp->data=x;
}

// Function definition for display the Stack
void display_stack(node* head){
    node* temp=head;
    printf("\n*** Your Stack ***\n");
    while(temp->next)
        temp=temp->next;
    while(temp){
        printf("\t%d\n",temp->data);
        temp=temp->prev;
    }
}

// Function definition for Build Stack
void make_stack(){
    node* head=NULL;
    printf("Enter the size of Stack : ");
    scanf("%d",&size);
    int ch,a,i; // ch=choice to select an operation, a=value of element, i=index
    while(1){
        printf("\n1.Push \t 2.Pop \t 3.Peep \t 4.Peak \t 5.Change \t 6.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                free(head);
                count=0;
                return;
            case 1:
                if(isFull()){
                    printf("Stack Overflow!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                head=push(head,a);
                break;
            case 2:
                if(isEmpty(head)){
                    printf("Stack Underflow!!\n");
                    break;
                }
                head=pop(head);
                break;
            case 3:
                if(isEmpty(head)){
                    printf("Stack Underflow!!\n");
                    break;
                }
                lable:
                printf("\nEnter the Index : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter valid Index!!\n");
                    goto lable;
                }
                peep(head,i);
                break;
            case 4:
                if(isEmpty(head)){
                    printf("Stack Underflow!!\n");
                    break;
                }
                printf("Value at Top of Stack is %d\n",peek_stack(head));
                break;
            case 5:
                if(isEmpty(head)){
                    printf("Stack Underflow!!\n");
                    break;
                }
                lable2:
                printf("\nEnter the Index, on which you want to make change : ");
                scanf("%d",&i);
                if(i>count || i<=0){
                    printf("Please enter valid Index!!\n");
                    goto lable2;
                }
                printf("Enter the new value : ");
                scanf("%d",&a);
                change(head,i,a);
                break;
            case 6:
                if(isEmpty(head)){
                    printf("Stack Underflow!!\n");
                    break;
                }
                display_stack(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}

// Function definition for enqueue the element into Queue
node* enqueue(node* head,node* tail,int a){
    node* n=(node*)malloc(sizeof(node));
    n->data=a;
    count++;
    if(!tail){
        n->next=n->prev=NULL;
        head=tail=n;
        return tail;
    }
    tail->next=n;
    n->prev=tail;
    n->next=NULL;
    tail=n;
    return tail;
}

// Function definition for dequeue the element from Queue
node* dequeue(node* head){
    node* temp=head;
    count--;
    if(!temp->next){
        free(temp);
        return NULL;
    }
    head=temp->next;
    head->prev=NULL;
    free(temp);
    return head;
}

// Function definition for return the front element from Queue
int peek_queue(node* head){
    return head->data;
}

// Function definition for display the Queue
void display_queue(node* head){
    node* temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

// Function definition for build the Queue
void make_queue(){
    node* head=NULL;
    node* tail=NULL;
    printf("Enter the size of Queue : ");
    scanf("%d",&size);
    int ch,a,i; // ch=choice to select an operation, a=value of element, i=index
    while(1){
        printf("\n1.Enqueue \t 2.Dequeue \t 3.Peek \t 4.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                free(head); free(tail);
                count=0;
                return;
            case 1:
                if(isFull()){
                    printf("Queue Overflow!!\n");
                    break;
                }
                printf("Enter the value : ");
                scanf("%d",&a);
                tail=enqueue(head,tail,a);
                if(head==NULL) head=tail;
                break;
            case 2:
                if(isEmpty(head)){
                    printf("Queue Underflow!!\n");
                    break;
                }
                head=dequeue(head);
                break;
            case 3:
                if(isEmpty(head)){
                    printf("Queue Underflow!!\n");
                    break;
                }
                printf("Value at Front of Queue is %d\n",peek_queue(head));
                break;
            case 4:
                if(isEmpty(head)){
                    printf("Queue Underflow!!\n");
                    break;
                }
                display_queue(head);
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
}

int main(){
    int ch; // ch=choice to select Stack or Queue
    while(1){
        printf("\n*** 1.Stack \t 2.Queue \t 0.Exit ***\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                return 0;
            case 1:
                make_stack();
                break;
            case 2:
                make_queue();
                break;
            default:
                printf("Wrong choice entered!!\n");
                break;
        }
    }
    return 0;
}