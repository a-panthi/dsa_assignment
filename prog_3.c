/*Write and Implement the reverse traversal algorithm in the linked list. Write main() to
demonstrate the use of the function.*/


#include<stdio.h>
#include<stdlib.h>

//linked list
typedef struct Node
{
    int data; 
    struct Node* next; //link to next node
}Node;

//stack
typedef struct Stack
{
    int *arr;  //dynamic array to store stack elements
    int top; 
    int maxSize;
}Struct;

//Node creation
Node* createNode(int value){
    Node* newNode = (Node*) malloc(sizeof(Node));

    if(newNode==NULL){
        printf("Failed heap allocation! ");
        exit(1);
    }

    newNode->data = value;
    newNode->next =NULL;
    
    return newNode;
}

//insertion at the end 
void insertAtEnd(Node* *head, int value){
    
    Node* newNode = createNode(value);
    if(*head==NULL){
        *head = newNode; //set the list's head to point to newly created node
        return; 
    }
    Node* temp = *head; //temp points to head which points to first node

    //node traversal
    while(temp->next!=NULL){
        temp=temp->next; 
    }

    temp->next = newNode;
    //now, the last node's next changes from NULL to newNode
}

//forward traversal
void forwTrav(Node* head){
    //here, function should only read head
    Node* temp = head;

    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp= temp->next;
    }

    printf("NULL LIST\n");
}

/*STACK FUNCTIONS*/

Struct* createStack(int max){
    Struct* stack = (Struct*) malloc(sizeof(Struct));

    if(stack == NULL){
        printf("Stack Allocation Failed! ");
        exit(1);
    }

    stack->maxSize = max;
    stack->top = -1; //initialize stack
    stack->arr = (int*) malloc(max * sizeof(int));

    if(stack->arr==NULL){
        printf("Stack array allocation failed! ");
        exit(1);
    }
    
    return stack;

}

void push(Struct* stack, int value){
    stack->arr[++stack->top] =value; 
    //storing the new value at the updated top index
}

int pop(Struct* stack){
    int value= stack->arr[stack->top--];
    //first pop the value, then decrement the top index by 1
    return value;
    
}
//Reverse Traversal
void revTrav(Node* head, int count) {
    if (head == NULL) 
    return;

   
    Struct* stack = createStack(count);
    Node* temp = head;

    while (temp != NULL) {
        push(stack, temp->data);
        temp = temp->next;
    }
   
    printf("Reverse: ");
    while (stack->top != -1) {
        printf("%d -> ", pop(stack));
    }
    printf("NULL\n");

    // Cleaning up stack ko memory
    free(stack->arr);
    free(stack);
}


int main() {
    Node* list = NULL;
    int n = 6;

    for(int i = 1; i <= n; i++) {
        insertAtEnd(&list, i * 5);
    }

    forwTrav(list);
    revTrav(list, n);

    return 0;
}



