#include <stdio.h>
#include <stdlib.h>
//took help from purnendu sir's code
struct stack
{
   int *data;
   int size; //intially size is 0.
};
int push(struct stack *stack, int value)
{
   if (stack->size == 0)
   {
      stack->data = (int *)malloc(sizeof(int));
   }
   else
   {
      stack->data = (int *)realloc(stack->data, (stack->size) + 1 * sizeof(int));
   }
   (stack->size)++;
   *(stack->data + (stack->size) - 1) = value; //inserting value in  stack;
   return stack->size;
}
int peek(struct stack *stack)
{
   if (stack->size == 0)
   {
      printf("stack is empty");
      return 0;
   }
   else
   {
      return *(stack->data + (stack->size - 1)); //returning the top of the element.
   } 
}
int isEmpty(struct stack *stack) // function to check if the stack is empty or not
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

int pop(struct stack *stack)
{
   if (isEmpty(stack)
   {
      printf("stack is empty");
      return Null
   }
   else
   {
      int top = peek(stack);
      (stack->size)--;
      return top;
   }
}
int main()
{
   struct stack stackA;
   stackA.size = 0;
   int value, choice, top;
   do
   {
      printf("operation on stack\nchoose any operation\n");
      printf("1.push\n2.pop\n3.view the top element\n4.exit\n");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         printf("enter the element to be pushed\n");
         scanf("%d", &value);
         push(&stackA, value);
         printf("element is pushed");
         break;
      case 2:
         top = pop(&stackA);
         printf("%d is popped:  ", top);
         printf("Top of the element is: %d ", peek(&stackA));
         break;
      case 3:
         printf("Top of the element is:%d ", peek(&stackA));
         break;
      case 4:
         printf("press enter to exit");

         exit(0);
         break;
      default:
         printf("Wrong choice");
         break;
      }
      printf("\nPress enter to continue\n");
   } while (1);
   return 0;
}
