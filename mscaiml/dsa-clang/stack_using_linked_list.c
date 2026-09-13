/**
 * Topic: Stack using linkedlist
 * Author: Monu C.
 * CreatedAt: 13 Sept 2026
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

Node *create_node(int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (new_node == NULL)
    return NULL; // incase of memory allocation failure

  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

int insert_at_beginning(Node **head, int val) {
  Node *new_node = create_node(val);

  if (new_node == NULL)
    return -1; // incase of memory allocation failure

  if (*head == NULL) {
    *head = new_node;
    return 0;
  }

  new_node->next = *head;
  *head = new_node;
  return 0;
}

int delete_at_beginning(Node **head) {
  if (*head == NULL)
    return -1; // incase of empty stack

  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
  return 0;
}

int is_empty(Node *head) { return head == NULL; }

void push(Node **stack, int val) { insert_at_beginning(stack, val); }

int pop(Node **stack) {
  if (is_empty(*stack))
    return -1; // incase of empty stack

  int val = (*stack)->val;
  delete_at_beginning(stack);
  return val;
}

int peek(Node *stack) {
  if (is_empty(stack))
    return -1; // incase of empty stack

  return stack->val;
}

void print_stack(Node *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return;
  }

  Node *current = stack;
  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node *stack = NULL;

  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);

  print_stack(stack);

  printf("Top element is %d\n", peek(stack));

  printf("Popped element is %d\n", pop(&stack));
  print_stack(stack);

  return 0;
}
