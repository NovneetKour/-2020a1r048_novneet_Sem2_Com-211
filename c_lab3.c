#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    int *data;
    int size; //intially size is 0.
};
int push(struct Stack *stack, int value)
{
    if (stack->size == 0)
    {
        stack->data = (int *)malloc(sizeof(int)); //allocate memory when size is zero
    }
    else
    {
        stack->data = (int *)realloc(stack->data, (stack->size) + 1 * sizeof(int));
    }
    (stack->size)++;
    *(stack->data + (stack->size) - 1) = value; //inserting value in  stack;
    return stack->size;                         //returning the size of stack
}
int isEmpty(struct Stack *stack) // function to check if the stack is empty or not
{
    if (stack->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack is empty");
    }
    else
    {
        (stack->size)--;
    }
}
int main()
{
    struct Stack stackA;
    stackA.size = 0; //intial size is 0
    char exp[50];    //store the value of expression
    int maxSize = strlen(exp);
    int i;
    printf("enter the expression\n");
    scanf("%s", exp);
    for (i = 0; i < maxSize; i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            push(&stackA, exp[i]);
            continue;
        }
        if (exp[i] == ']' || exp[i] == '}' || exp[i] == ')')
        {
            if (stackA.data[stackA.size - 1] == '{' && exp[i] == '}' || stackA.data[stackA.size - 1] == '[' && exp[i] == ']' || stackA.data[stackA.size - 1] == '(' && exp[i] == ')')
            {
                pop(&stackA);
            }
        }
        else
        {
            push(&stackA, exp[i]);
        }
    }
    if (stackA.size == 0)
    {
        printf("BALANCED\n");
    }
    else
    {
        printf("UNBALANCED\n");
    }
    return 0;
}