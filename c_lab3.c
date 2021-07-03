#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    char *data;
    int size; //present size of stack
    int top;
};
int isFull(struct Stack *stack)
{
    if (stack->top == stack->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(struct Stack *stack, char value)
{
    if (isFull(stack))
    {
        printf("Stack Overflow!!\n");
    }
    stack->top++;
    stack->data[++stack->top] = value;
}
int isEmpty(struct Stack *stack) // function to check if the stack is empty or not
{
    if (stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(struct Stack *stack)
{
    char valueRemoved;
    if (isEmpty(stack))
    {
        printf("stack is empty");
        return '\0';
    }
    else
    {
        valueRemoved = stack->data[stack->top];
        (stack->top)--;
      return valueRemoved;
    }
}
int main()
{
    struct Stack stackA;
    stackA.size = 0; //intial size is 0
    stackA.top = -1;
    char exp[50]; //store the value of expression
    int i;
    printf("enter the expression\n");
    scanf("%s", exp);
    int maxSize = strlen(exp);
    stackA.size = maxSize;
    stackA.data = (char *)malloc(stackA.size * sizeof(char));
    for (i = 0; i < maxSize; i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            push(&stackA, exp[i]);
            continue;
        }
        if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {
            if ((stackA.data[stackA.top] == '{' && exp[i] == '}') || (stackA.data[stackA.top] == '[' && exp[i] == ']') || (stackA.data[stackA.top] == '(' && exp[i] == ')'))
            {
                pop(&stackA);
            }
            else
            {
                printf("UNBALANCED!!! \n");
                return 0;
            }
        }
    }
    if (stackA.top == -1)
    {
        printf("BALANCED\n");
    }
    else
    {
        printf("UNBALANCED\n");
    }
    return 0;
}
