// WAP to convert infix expression to postfix expression using stack.
#include<stdio.h>
#include<string.h>
int st_top=-1;

void st_push(char st[],char c){
    st[++st_top]=c;
}
void st_pop(char st[]){
    st_top--;
}

int input_precedence(char c){
    if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 3;
    else if(c=='^')
        return 6;
    else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 7;
    else if(c=='(')
        return 9;
    else if(c==')')
        return 0;
}
int stack_precedence(char c){
    if(c=='+' || c=='-')
        return 2;
    else if(c=='*' || c=='/')
        return 4;
    else if(c=='^')
        return 5;
    else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 8;
    else if(c=='(')
        return 0;
}

int rank(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        return -1;
    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
        return 1;
    return 0;
}

int main(){
    char st[30];
    char polish[30]="";
    char str[30];
    printf("Enter the Infix Expression : ");
    scanf("%s",str);
    st_push(st,'(');
    strcat(str,")");
    int j=0,r=0;
    for(int i=0;i<strlen(str);i++){
        while(input_precedence(str[i]) < stack_precedence(st[st_top])){
            polish[j] = st[st_top];
            st_pop(st);
            r+=rank(polish[j++]);
        }
        if(input_precedence(str[i]) != stack_precedence(st[st_top]))
            st_push(st, str[i]);
        else
            st_pop(st);
    }
    if(st_top!=-1 || r!=1){
        printf("Ivnalid Expression!!\n");
        return 0;
    }
    printf("Postfix Expression : %s\n",polish);
    return 0;
}