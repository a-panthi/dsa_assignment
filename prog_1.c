/*Write a program to check if any given mathematical expression has a balanced number of
parentheses or not?*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100 

typedef struct Stack {
    int top;
    char data[MAX];
}Stack;
// push a character onta a stack
void push(Stack* s, char c){
    if(s->top == MAX-1) {
        return; 
    }
    s->data[++(s->top)] = c; 
}

//pop a char from the stack
char pop(Stack* s){
    if (s->top == -1){
        printf("Stack Underflow.\n");
        return '\0'; 
    }
    return s->data[(s->top)--];
}

int isMatch(char c1, char c2){
    if ( c1 == '(' && c2 == ')') return 1;
    if ( c1 == '[' && c2 == ']') return 1;
    if ( c1 == '{' && c2 == '}') return 1;
    return 0;
}


int isBalanced(char* exp){
    Stack s;
    s.top=-1;
    int n = strlen(exp);

    for(int i=0; i<n;i++){
        
        if(exp[i] == '(' || exp[i]=='[' || exp[i]=='{'){
            push(&s, exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']' ){
            if (s.top == -1) return 0; 

            if(!isMatch(pop(&s),exp[i])){ 

                return 0; 
            }
        }
    }
    return (s.top == -1); 
} 

int main(){
    char* expression[] = {
        "a+(b-c)*(d", "m+[a-b*(c+d*{m)]", "a+(b-c)"
    }; 

    printf("Parantheses Balance Checker\n\n");
    for(int i=0;i<3;i++){
        printf("Expression: %s\n",expression[i]);
        if(isBalanced(expression[i])){
            printf("Result: Balanced\n\n");
        }
        else{
            printf("Result: Unbalanced\n\n");
        }
    }

    return 0;
}