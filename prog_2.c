/*Write a program to convert an infix mathematical expression to postfix and evaluate it.*/

#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100 

//structure os stack 
typedef struct 
{
    int top;
    char data[MAX];
}Stack;


void initStack(Stack* s){
    s->top = -1;
}
int isEmpty(Stack* s){
    return s->top == -1;
}
//push operation
void push(Stack* s, char x){
    if(s->top == MAX-1) {
        printf("Stack Overflow!");
        
        return; 
    }
    s->data[++s->top] = x; 
}
//pop operation
char pop(Stack* s){
    if (isEmpty(s)){
        printf("Stack Underflow!");
        return '\0'; 
    }
    return s->data[(s->top)--]; 
}
//peek operation
char peek(Stack* s){
    if(isEmpty(s)){
        return '\0';
    }
    return s->data[s->top];
}

int precedence(char opr){
    switch(opr){
        case '+':
        case '-': return 1;

        case'*':
        case '/': return 2;

        case '^': return 3;
    }
    return 0;
}

//checking if the character is an operator or not
int isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
int isOperand(char c){
    return isalnum(c);   // checks digit or alphabet
}

//infix to postfix conversion
void infixToPostfix(char* infix, char*postfix){
    Stack s;
    initStack(&s);

    int i=0; //for infix
    int k=0; //for postfix

    while(infix[i]!='\0'){

        char current = infix[i];

        //directly add operand to postfix
        if(isOperand(current)){
            postfix[k++] = current; 
        }
        //push opening brackets to stack
        else if(current == '('){
            push(&s, current);
        }

        //closing brackets
        else if(current == ')'){
            //pop until matching '(' is found
            while(!isEmpty(&s) && peek(&s)!='('){
                postfix[k++] = pop(&s);
            }

            if(!isEmpty(&s)){
                pop(&s);
            }
        }

        //operator encountered
        else if (isOperator(current)){
            //pop operators with higher or equal precedence
            while(!isEmpty(&s) && ((precedence(peek(&s)) > precedence(current)) ||(precedence(peek(&s)) == precedence(current) && current != '^'))){

                postfix[k++] = pop(&s);
            }

            push(&s, current);
        }
        i++;
    }
    
    while(!isEmpty(&s)){
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

//postfix evaluation
int evaluatePost(char *postfix){
    int stack[MAX]; 
    int top = -1;

    for(int i=0; postfix[i]!='\0'; i++){
        char current = postfix[i];

        //push operand to stack
        if(isOperand(current)){
            stack[++top] = current - '0';
        }

        //pop two operands and apply operator

        else{
            int oprnd2= stack[top--];
            int oprnd1 = stack[top--];
            int result;

            switch(current){
                case '+': result = oprnd1 + oprnd2; break;
                case '-': result = oprnd1 - oprnd2; break;
                case '*': result = oprnd1 * oprnd2; break;
                case '/': result = oprnd1 / oprnd2; break;
                case '^': result = (int)pow(oprnd1, oprnd2); break;
            }
            stack[++top]=result;
        }
    }
    return stack[top];
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result =evaluatePost(postfix);
    printf("Evaluated postfix result: %d\n", result);

    return 0;
}