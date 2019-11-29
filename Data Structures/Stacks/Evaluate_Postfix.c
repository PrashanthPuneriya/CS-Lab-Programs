// Program to Evaluate Postfix Notation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack { 
    int top;
    int capacity; 
    int* array; 
};
// Create Stack
struct Stack* CreateStack(int capacity) { 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack) // Stack is not Created
        return NULL; 

    stack->top = -1; 
    stack->capacity = capacity; 
    stack->array = (int*)malloc(stack->capacity*sizeof(int)); //Integer Array
  
    if(!stack->array) // Array is not Created 
        return NULL;

    return stack; 
}

// Push to the Stack
void Push(struct Stack* stack, int ch) {
    stack->array[++stack->top] = ch;
}
// Pop from the Stack
int Pop(struct Stack* stack) {
    if(stack->top > -1) 
        return stack->array[stack->top--];
    else {
        printf("Stack is empty i.e. Not enough Operands or Operators");
        exit(1);
    }
}

int PostfixEvaluation(char *exp) {

    struct Stack* stack = CreateStack(strlen(exp));
    if(!stack) // Stack is not Created
        return 0;

    for(int i=0; exp[i]; ++i) {
        
        if(isdigit(exp[i])) // Encountered an operand
            Push(stack, exp[i] - '0'); // - '0' converts a char into integer

        else { // Encountered an operator
            int val1, val2;
            val2 = Pop(stack);
            val1 = Pop(stack);
            switch (exp[i])  
            {  
                case '+': Push(stack, val1 + val2); break;  
                case '-': Push(stack, val1 - val2); break;  
                case '*': Push(stack, val1 * val2); break;  
                case '/': Push(stack, val1/val2); break;  
            }   
        } 
    }
    return Pop(stack);
}

int main() {
    char exp[] = "42+351-*+";
    printf("Postfix Notation is: %s \n", exp);
    printf("Postfix Evaluation gives: %d", PostfixEvaluation(exp));
    return 0;
}