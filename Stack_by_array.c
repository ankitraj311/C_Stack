#include<stdio.h>
#include<stdlib.h>
struct ArrayStack
{
  int top;
  int capacity;
  int *array;
};



struct ArrayStack *createStack(int cap)
{
  struct ArrayStack *stack;
  stack = malloc(sizeof(struct ArrayStack));
  stack->capacity = cap;
  stack->top = -1;
  stack->array = malloc(sizeof(int) * (stack->capacity));
  return (stack);
}

int isFull(struct ArrayStack *stack)
{
  if(stack->top == stack->capacity-1)
    return 1;
  else
    return 0;
}

int isEmpty(struct ArrayStack *stack)
{
  if(stack->top == -1)
    return 1;
  else
    return 0;
}

void push(struct ArrayStack *stack, int item)
{
  if(!isFull(stack))
  {
    stack->top++;
    stack->array[stack->top] = item;
  }
}

int pop(struct ArrayStack *stack)
{
  int item;
  if(!isEmpty(stack))
  {
    item = stack->array[stack->top];
    stack->top--;
    return item;
  }
  else
    return -1;
}


int main()
{
  int choice,item,i;
  struct ArrayStack *stack;
  stack= createStack(4);
  while(1)
  {
   // clrscr();
    printf(" 1.Push");
    printf("\n 2.Pop");
    printf("\n 3.Exit\n");
    printf("\nEnter Your Choice");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	   printf("\nEnter Item\n");
	   scanf("%d",&item);
	   push(stack,item);
	   break;
      case 2:
	   item=pop(stack);
	   if(item == -1)
	     printf("Stack is Empty\n");
	   else
	     printf("Poped Value is %d\n",item);
	     break;
      case 3:
	   exit(0);
    }
    //getch();
  }
}
