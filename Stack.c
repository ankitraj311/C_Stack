#include<stdio.h>
#include<stdlib.h>

struct ArrayStack
{
  int top;
  unsigned capacity;
  int *array;
};


struct ArrayStack* create(int cap)
{
  struct ArrayStack *stack;
  stack = (struct ArrayStack *)malloc(sizeof(struct ArrayStack));
  stack->top = -1;
  stack->capacity = cap;
  stack->array = malloc(sizeof(int)*(stack->capacity));
  return (stack);
}


int isFull( struct ArrayStack *stack)
{
  if( stack->top == (stack->capacity)-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty(struct ArrayStack *stack)
{
  if( stack->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void push(struct ArrayStack *stack, int item)
{
  if(!isFull(stack))
  {
    stack->top++;
    stack->array[stack->top]=item;
  }
}

int pop(struct ArrayStack *stack)
{
  int item;
  if(!isEmpty(stack))
  {
    item = stack->array[stack->top];
    (stack->top)--;
    return (item); 
  }
  return (-1);
}
int main()
{
  
  int choice,item;
  struct ArrayStack *stack;
  stack=create(4);
  while(1)
  {
    printf("\n1. Enter for Push\n");
    printf("2. Enter for pop\n");
    printf("3. Enter for Exit\n");
    printf("Enetr the Choice to Execute");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	      printf("Enter the value of Item");
	      scanf("%d",&item);
	      push(stack,item);
	      break;
      case 2: 
	      item = pop(stack);
	      if( item==-1 )
	        printf("Stack is Empty");
	      else
	        printf("\nPoped Item is %d",item);
	      break;
      case 3:
	      exit(0);
    }
  }
}
