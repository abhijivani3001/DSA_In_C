// // Write a program to create a stack and perform the following operations.
// // Push, Pop, Peep, Change and Display
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int *arr;
    int size;
}st;

int isEmpty(st *ptr){
    if(ptr->top==-1)
        return 1;
    return 0;
}
int isFull(st *ptr){
    if(ptr->top==ptr->size-1)
        return 1;
    return 0;
}
void push(int x, st *ptr){
    if(isFull(ptr)){
        printf("Stack is overflow\n");
        return;
    }
    ptr->arr[++ptr->top]=x;
}
void pop(st *ptr){
    if(isEmpty(ptr)){
        printf("Stack is underflow\n");
        return;
    }
    printf("Value %d has been popped\n",ptr->arr[ptr->top]);
    ptr->top--;
}
int peep(int i, st* ptr){
    return ptr->arr[ptr->top-i+1];
}
void change(int i, int x, st* ptr){
    ptr->arr[ptr->top-i+1]=x;
    printf("New value %d is inserted at Index %d\n",x,i);
}
void display(st* ptr){
    printf("*** Your Stack ***\n");
    for(int i=0;i<=ptr->top;i++)
        printf("%d\n",ptr->arr[ptr->top-i]);
}

int main(){
    st *s=(st*)malloc(sizeof(st));
    s->top=-1;
    printf("Enter the size of Stack : ");
    scanf("%d",&s->size);
    s->arr=(int*)malloc(sizeof(int)*(s->size));
    int ch;

    while(1){
        printf("\n**************************\n");
        printf("Enter 1 for push operation\n");
        printf("Enter 2 for pop operation\n");
        printf("Enter 3 for peep operation\n");
        printf("Enter 4 for change operation\n");
        printf("Enter 5 for display operation\n");
        printf("Enter 0 for exit\n");
        printf("**************************\n\n");
        
        printf("Enter your choice : ");
        scanf("%d",&ch);
        int a,b;
        switch(ch){
            case 0:
                return 0;
            case 1:
                printf("Enter the number : ");
                scanf("%d",&a);
                push(a,s);
                break;
            case 2:
                pop(s);
                break;
            case 3:
                printf("Enter the Index : ");
                scanf("%d",&a);
                if(a>s->top+1 || a<=0){
                    printf("Index is wrong\n");
                    break;
                }
                printf("Value at Index %d is : %d\n",a,peep(a,s));
                break;
            case 4:
                printf("Enter Index : ");
                scanf("%d",&a);
                if(a>s->top+1 || a<=0){
                    printf("Index is wrong\n");
                    break;
                }
                printf("Enter new number to change on Index %d : ",a);
                scanf("%d",&b);
                change(a,b,s);
                break;
            case 5:
                display(s);
                break;
            default:
                printf("Wrong choice!!\n");
        }
    }
    return 0;
}