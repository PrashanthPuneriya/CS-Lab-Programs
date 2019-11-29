// Program to convert Infix Notation to Postfix Notation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); //Integer Array
  
    if(!stack->array) // Array is not Created 
        return NULL;

    return stack; 
}

// Push to the Stack
void Push(struct Stack* stack, char ch) {
    stack->array[++stack->top] = ch;
}
// Pop from the Stack
char Pop(struct Stack* stack) {
    if(stack->top > -1) 
        return stack->array[stack->top--];
    return '#';
}

// Operand Checker
int IsOperand(char c) {
    return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'); // Returns 1(True) if it is an operand
}
// Operator Prec
int Prec(char symbol) {
	if(symbol == '^') return 3;
	else if(symbol == '*' || symbol == '/') return(2);
	else if(symbol == '+' || symbol == '-') return(1);
	else return 0;
}

// Notation Converter
void InfixToPostfix(char *exp) {
    int i, j; 
    // i and j are different. Since, jth index is modified to give the final output whereas ith index is modified according what character it is
    struct Stack* stack = CreateStack(strlen(exp));
    if(!stack) // Stack is not Created
        return;

    for (i = 0, j = -1; exp[i]; ++i) {
        // Character is an operand
        if(IsOperand(exp[i]))
            exp[++j] = exp[i];

        // Character is ( then Push it to the Stack
        else if(exp[i] == '(')
            Push(stack, exp[i]);
        // Character is ) then Pop elements between (....) from the Stack
        else if(exp[i] == ')') {
            char x = Pop(stack);
          	while( x != '(' ) {	
                exp[++j]  = x;
                x = Pop(stack);
			} 
        }
        // Character is an operand other than ( and ) then check the Prec and follow operations accordingly
        else {
            while(stack->top > -1 && Prec(exp[i]) <= Prec(stack->array[stack->top]))
                exp[++j] = Pop(stack);

            Push(stack, exp[i]);
        }
    }
    // If still any operators are present on the Stack then Pop it
    while (stack->top > -1) {
        exp[++j] = Pop(stack);
    }

    exp[++j] = '\0';
    printf("Postfix Notation is :\n%s", exp); 
}


int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("Infix Notation is :\n%s\n", exp);
    InfixToPostfix(exp);
    return 0;
}
