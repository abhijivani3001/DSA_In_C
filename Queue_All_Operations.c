/*
Write a program to create a Queue, Circular Queue, Double Ended Queue and 
perform the following operations (One single program with switch choice).
Insert, Delete and Display
*/
#include<stdio.h>
#include<stdlib.h>
int front=-1,back=-1,back2,key=1; // Declaration and Initialization of Queue pointers
int n; // Size of Queue
int *q; // Declaring Queue

// Enqueue operation on Normal Queue
void enqueue_normal(int x){
    if(front==-1)
        front++;
    q[++back]=x;
    printf("Number %d has been Enqueued\n",x);
}
// Dequeue operation on Normal Queue
void dequeue_normal(){
    printf("Number %d has been Dequeued\n",q[front++]);
}
// Display function of Normal Queue
void display_normal(){
    printf("\n*** Your Queue ***\n");
    for(int i=front;i<=back;i++) printf("%d ",q[i]);
    printf("\n");
}

// Enqueue operation on Circular Queue
void enqueue_circular(int x){
    if(front==-1)
        front++;
    if(back==n-1 && front>0){
        back=-1;
        key=0;
    }
    q[++back]=x;
    printf("Number %d has been Enqueued\n",x);
}
// Dequeue operation on Circular Queue
void dequeue_circular(){
    printf("Number %d has been Dequeued\n",q[front]);
    if(front==n-1 && back<front){
        front=-1;
        key=1;
    }
    front++;
    if((front==-1 && back==-1) || (front>back && key)){
        front=-1;
        back=-1;
        return;
    }
}
// Display funcrion of Circular Queue
void display_circular(){
    printf("\n*** Your Queue ***\n");
    if(front>back){
        for(int i=front;i<n;i++) printf("%d ",q[i]);
        for(int i=0;i<=back;i++) printf("%d ",q[i]);
    }
    else{
        for(int i=front;i<=back;i++) printf("%d ",q[i]);
    }
    printf("\n");
}

// Front Enqueue operation on Double Ended Queue
void enqueue_front(int x){
    if(back2==0 && front<n-1 && front>back2)
        back2=n;
    q[--back2]=x;
    printf("Number %d has been Enqueued\n",x);
}
// Back Enqueue operation on Double Ended Queue
void enqueue_back(int x){
    if(front==n-1 && back2<front && back2>0)
        front=-1;
    q[++front]=x;
    printf("Number %d has been Enqueued\n",x);
}
// Front Dequeue operation on Double Ended Queue
void dequeue_front(){
    if(back2==n){
        back2=0;
        key=0;
    }
    printf("Number %d has been Dequeued\n",q[back2++]);
    if((front==-1 && back2==n) || (front<back2 && key==0)){
        front=-1;
        back2=n;
        key=1;
        return;
    }
}
// Back Dequeue operation on Double Ended Queue
void dequeue_back(){
    if(front==-1){
        front=n-1;
        key=0;
    }
    printf("Number %d has been Dequeued\n",q[front--]);
    if((front==-1 && back2==n) || (front<back2 && key==0)){
        front=-1;
        back2=n;
        key=1;
        return;
    }
}
// Display function of Double Ended Queue
void display_doubly(){
    printf("\n*** Your Queue ***\n");
    if(front<back2){
        for(int i=back2;i<n;i++) printf("%d ",q[i]);
        for(int i=0;i<=front;i++) printf("%d ",q[i]);
    }
    else{
        for(int i=back2;i<=front;i++) printf("%d ",q[i]);
    }
    printf("\n");
}

// Queue function (Declaration and Definition)
void queue(){
    int c,a;
    while(1){
        printf("\n********************************************************\n");
        printf("1.Insert \t 2.Delete \t 3.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(back==n-1){
                    printf("Queue Overflow!!\n");
                    break;
                }
                printf("Enter the number : ");
                scanf("%d",&a);
                enqueue_normal(a);
                break;
            case 2:
                if((front==-1 && back==-1) || front>back){
                    printf("Queue is Empty\n");
                    break;
                }
                dequeue_normal();
                break;
            case 3:
                if((front==-1 && back==-1) || front>back){
                    printf("Queue is Empty\n");
                    break;
                }
                display_normal();
                break;
            default:
                printf("Wrong choice entered!!\n");
        }
    }
}

// Circular Queue function (Declaration and Definition)
void circular_queue(){
    int c,a;
    while(1){
        printf("\n********************************************************\n");
        printf("1.Insert \t 2.Delete \t 3.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if((back==n-1 && front==0) || (back==front-1 && key==0)){
                    printf("Queue Overflow!!\n");
                    break;
                }
                printf("Enter the number : ");
                scanf("%d",&a);
                enqueue_circular(a);
                break;
            case 2:
                if((front==-1 && back==-1) || (front>back && key)){
                    printf("Queue is Empty\n");
                    break;
                }
                dequeue_circular();
                break;
            case 3:
                if((front==-1 && back==-1) || (front>back && key)){
                    printf("Queue is Empty\n");
                    front=-1;
                    back=-1;
                    break;
                }
                display_circular();
                break;
            default:
                printf("Wrong choice entered!!\n");
        }
    }
}

// Double Ended Queue function (Declaration and Definition)
void doubly_queue(){
    int c,a,b;
    while(1){
        printf("\n********************************************************\n");
        printf("1.Insert \t 2.Delete \t 3.Display \t 0.Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);
        switch(c){
            case 0:
                return;
            case 1:
                if(back2==front+1){
                    printf("Queue Overflow!!\n");
                    break;
                }
                printf("\nEnter \"1\" if you want to Insert a number before the First number\n");
                printf("Enter \"2\" if you want to Insert a number after the Last number\n");
                printf("Enter your choice : ");
                scanf("%d",&b);
                if(b!=1 && b!=2){
                    printf("Please enter right choice!!\n");
                    break;
                }
                printf("Enter the number : ");
                scanf("%d",&a);
                if(b==1) enqueue_front(a);
                else if(b==2) enqueue_back(a);
                break;
            case 2:
                if((front==-1 && back2==n) || (front<back2 && key==0)){
                    printf("Queue is Empty\n");
                    break;
                }
                printf("\nEnter \"1\" if you want to Delete a First number\n");
                printf("Enter \"2\" if you want to Delete a Last number\n");
                printf("Enter your choice : ");
                scanf("%d",&b);
                if(b==1) dequeue_front();
                else if(b==2) dequeue_back();
                else printf("Please enter right choice!!\n");
                break;
            case 3:
                if((front==-1 && back2==n) || (front<back2 && key==0)){
                    printf("Queue is Empty\n");
                    front=-1;
                    back2=n;
                    key=1;
                    break;
                }
                display_doubly();
                break;
            default:
                printf("Wrong choice entered!!\n");
        }
    }
}

int main(){
    int ch;
    printf("Enter the size of Queue : ");
    scanf("%d",&n);
    q=(int*)malloc(sizeof(int)*n); // Creates arry of Queue dynamically
    back2=n;
    while(1){
        printf("\n************************************************************************\n");
        printf("1.Queue \t 2.Circular Queue \t 3.Double Ended Queue \t 0.Exit\n");
        printf("************************************************************************\n\n");
        printf("Enter the choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                return 0;
            case 1:
                queue();
                break;
            case 2:
                circular_queue();
                break;
            case 3:
                doubly_queue();
                break;
            default:
                printf("Wrong choice entered!!\n");
        }
    }
    return 0;
}