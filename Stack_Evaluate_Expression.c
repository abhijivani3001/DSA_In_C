// WAP to evaluate expression using stack
#include<stdio.h>
#include<string.h>
int st[30];
int top=-1;

void push(int c){
    st[++top]=c;
}
int pop(){
    return st[top--];
}

int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/')
        return 1;
    return 0;
}

int prefixEvaluation(char str[]){
    for(int i=strlen(str)-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            int ans=str[i]-'0';
            push(ans);
        }
        else{
            int op1=pop();
            int op2=pop();
            switch(str[i]){
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
            }
        }
    }
    return st[top];
}
int postfixEvaluation(char str[]){
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='0' && str[i]<='9'){
            int ans=str[i]-'0';
            push(ans);
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(str[i]){
                case '+':
                    push(op1+op2);
                    break;
                case '-':
                    push(op1-op2);
                    break;
                case '*':
                    push(op1*op2);
                    break;
                case '/':
                    push(op1/op2);
                    break;
            }
        }
    }
    return st[top];
}

int main(){
    char str[30];
    printf("Enter the Expression : ");
    scanf("%s",str);
    int ans;
    if(isOperator(str[0]))
        ans=prefixEvaluation(str);
    else
        ans=postfixEvaluation(str);
    printf("The result of given Expression is : %d\n",ans);
    return 0;
}
