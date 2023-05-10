// WAP to convert infix expression to prifix expression using stack.
#include<stdio.h>
#include<string.h>
int top=-1;
char st[30];

void push(char c){
    st[++top]=c;
}
void pop(){
    top--;
}

int input_precedence(char c){
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 7;
    else if(c==')')
        return 9;
    else if(c=='(')
        return 0;
}
int stack_precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 8;
    else if(c==')')
        return 0;
}

int rank(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return -1;
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 1;
    return 0;
}

void reverseString(char s[]){
    for(int i=0;i<strlen(s);i++)
        push(s[i]);
    for(int i=0;i<strlen(s);i++){
        s[i]=st[top];
        pop();
    }
}

int main(){
    char polish[30]="";
    char str[30];
    printf("Enter the Infix Expression : ");
    scanf("%s",str);
    char infix[30]="(";
    strcat(infix,str);
    int j=0,r=0;
    push(')');
    for(int i=strlen(infix)-1;i>=0;i--){
        while(input_precedence(infix[i])<stack_precedence(st[top])){
            polish[j]=st[top];
            pop();
            r+=rank(polish[j++]);
        }
        if(input_precedence(infix[i])!=stack_precedence(st[top]))
            push(infix[i]);
        else
            pop();
    }
    if(top!=-1 || r!=1){
        printf("Ivnalid Expression!!\n");
        return 0;
    }
    reverseString(polish);
    printf("Postfix Expression : %s\n",polish);
    return 0;
}