#include <stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct{
    char arr[MAX];
    int top;
}stack;
void init(stack*s){
    s->top=-1;
}
int isEmpty(stack*s){
    return s->top==-1;
}
int isFULL(stack*s){
    return s->top==MAX-1;
}
void push(stack*s,char c){
if (!isFULL(s)){
        s->arr[++(s->top)]=c;
    }
}
char pop(stack*s){
    if(!isEmpty(s)){
            return s->arr[(s->top)--];
    }
    return'\0';
}
char peek(stack*s){
    if(!isEmpty(s)){
            return s->arr[s->top];
    }
    return '/0';
    }
    int precedence(char op){
switch (op) {
     case'+':
     case'-':return 1;
     case'*':
     case'/':return 2;
     case'^':return 3;
    }
    return 0;
    }
int isOperator(char){
return c=='+'||c=='-'||c=='*'||c=='/'||=='^';
    }
    void infixToPostfix(char*infix,char*postfix){
        stack s;
        init(&s);
        int k=0;
        for(int i=0;infix[i]!='\0'i++){
                char c=infix[i];
        if(isalnum(c)){
                postfix[k++]=c;
        }
        else if(c=='(')){
                push(&s,c);
        }
        else if(c==')'){
                while(!isEMPTY(&S)&&peek(&S)!='('){
                        postfix[k++]=pop(&s);
                }
                pop(&s);
        }
        else if(isOperator(c)){
                while(!isEMPTY(&s)&&precedence(peek(&s)))>=precedence(c)){
                    if(c=='^'&&peek(&s)=='^'){
                            break;
                    }else{
                        postfix[k++]=pop(&s);
                    }
                }
                push(&s,c);
        }
        }
        while(!isEmpty(&s)){
                postfix[k++]=pop(&s);
        }
        postfix[k]='\0';
    }
    int main(){
        char infix[MAX];
        char postfix[MAX];
        printf("enter infix exppression:");
        fgets(infix,MAX,stdin);
        infix[srecspn(infix,"\n")]='\0';
        infixToPostfix(infix,postfix);
        printf("Postfix expression:%s\n",postfix);
        return 0;
        }
