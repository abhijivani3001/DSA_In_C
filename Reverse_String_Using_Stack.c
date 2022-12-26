// Write a program to reverse a string using stack.
#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    char *arr;
    int size;
}st;

void push(st* str, char c){
    str->arr[++str->top]=c;
}
void display(st* str){
    for(int i=0;i<=str->top;i++)
        printf("%c",str->arr[str->top-i]);
}

int main(){
    st* s=(st*)malloc(sizeof(st));
    s->top=-1;
    printf("Enter the size of string : ");
    scanf("%d",&s->size);
    s->arr=(char*)malloc(sizeof(char)*s->size);
    printf("Enter the string : ");
    scanf("%s",s->arr);
    printf("\n*** Reversed String ***\n");
    for(int i=0;s->arr[i] !='\0';i++)
        push(s, s->arr[i]);
    display(s);
    return 0;
}