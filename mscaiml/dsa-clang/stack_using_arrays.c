/**
 *  Topic: Implement stack using arrays
 *  Author: Monu C.
 *  CreatedAt: 13 Sept 2026
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
  int top;
  int capacity;
  int *array;
} Stack;

Stack *create_stack(int capacity) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(sizeof(int) * capacity);
  return stack;
}

/**
 * @return bool
 * @description: Check if the stack is empty or not
 * */
int is_empty(Stack *stack) { return stack->top == -1; }

/**
 * @description: Check if the stack is full or not
 */
int is_full(Stack *stack) { return stack->top == stack->capacity - 1; }

/**
 * @description: Push an element to the stack
 * */
void push(Stack *stack, int val) {
  if (is_full(stack))
    return;

  stack->array[++stack->top] = val;
}

/**
 * @description: Pop an element from the stack
 * */
int pop(Stack *stack) {
  if (is_empty(stack))
    return -1;
  return stack->array[stack->top--];
}

/**
 * @description: Peek the top element of the stack
 * */
int peek(Stack *stack) {
  if (is_empty(stack))
    return -1;
  return stack->array[stack->top];
}

/***
 * @description: List all elements of the stack
 * */
void print_stack(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

int main() {

  struct Stack *stack = create_stack(100);

  push(stack, 1);
  push(stack, 2);
  push(stack, 3);

  printf("%d popped from stack\n", pop(stack));
  printf("Top element is %d\n", peek(stack));

  printf("Elements present in stack:\n");
  print_stack(stack);
  return 0;
}
