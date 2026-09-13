/**
 *  Topic: Doubly Linked List
 *  Author: Monu C.
 *  CreatedAt: 13 Sept 2026
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
  struct Node *prev;
} Node;

/**
 *  @description: Create a new node with the given value
 * */
Node *create_node(int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->val = val;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

/**
 *  @description: Insert new node at the beginning of the list
 * */
void insert_at_beginning(Node **head, int val) {
  Node *new_node = create_node(val);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  new_node->next = *head;
  (*head)->prev = new_node;

  *head = new_node;
}

/**
 *  @description: Insert new element at the end of the list
 * */
void insert_at_end(Node **head, int val) {
  Node *new_node = create_node(val);

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  Node *end = *head;

  while (end->next != NULL) {
    end = end->next;
  }

  end->next = new_node;
  new_node->prev = end;
}

/**
 *  @description: Insert at any position in the list
 * */
void insert_at_position(Node **head, int val, int pos) {
  if (pos <= 0)
    return;

  if (pos == 1) {
    // 1 means we are inserting at the beginning of the list
    insert_at_beginning(head, val);
    return;
  }

  Node *new_node = create_node(val);
  Node *current = *head;

  for (int i = 1; i < pos - 1 && current != NULL; i++) {
    current = current->next;
  }

  if (current == NULL)
    return;

  new_node->next = current->next;
  new_node->prev = current;

  if (current->next != NULL) {
    current->next->prev = new_node;
  }
  current->next = new_node;
}

/**
 *  @description: Print List Forward
 * */
void print_list_forward(Node *head) {
  Node *current = head;

  printf("Forward List: \n");
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("\n");
}

/**
 *  @description: Print List Backward
 * */
void print_list_backward(Node *head) {
  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  printf("Backward List: \n");
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->prev;
  }
  printf("\n");
}

/**
 *  @description: Print list with type
 * */
typedef enum { FORWARD, BACKWARD } Type;

void print_list(Node *head, Type type) {
  if (type == FORWARD) {
    print_list_forward(head);
  } else if (type == BACKWARD) {
    print_list_backward(head);
  }
}

/**
 *  @description: Delete node at the beginning of the list;
 * */
void delete_at_beginning(Node **head) {
  if (*head == NULL)
    return;

  Node *current = *head;
  *head = (*head)->next;

  if (*head != NULL)
    (*head)->prev = NULL;

  free(current);
}

/**
 *  @description: Delete node at the end of the list;
 * */
void delete_at_end(Node **head) {
  if (*head == NULL)
    return;

  Node *end = *head;

  if (end->next == NULL) {
    free(end);
    *head = NULL;
    return;
  }

  while (end->next != NULL) {
    end = end->next;
  }
  // we can also do like going to second last
  // and then delete the next of the second last
  // that we did in the signly linked list where we use
  // while(end->next->next != NULL) and then free(end->next)
  // but in doubly we have one advantage that we can ge
  // backward; so we are doing end->prev->next that is the end itself;
  end->prev->next = NULL;
  free(end);
}

/**
 *  @description: Delete node at any position in the list;
 * */
void delete_at_position(Node **head, int pos) {
  if (pos <= 0 || *head == NULL)
    return;

  if (pos == 1) {
    delete_at_beginning(head);
    return;
  }

  Node *current = *head;

  for (int i = 1; i < pos && current != NULL; i++) {
    current = current->next;
  }

  if (current == NULL)
    return;

  if (current->prev != NULL) {
    current->prev->next = current->next;
  }

  if (current->next != NULL) {
    current->next->prev = current->prev;
  }

  free(current);
}

int main() {
  Node *head = NULL;

  insert_at_end(&head, 1);
  insert_at_end(&head, 2);
  insert_at_beginning(&head, 0);
  insert_at_position(&head, 3, 4);

  print_list(head, FORWARD);
  print_list(head, BACKWARD);

  delete_at_position(&head, 2);
  delete_at_end(&head);
  delete_at_beginning(&head);

  print_list(head, FORWARD);
  print_list(head, BACKWARD);
  return 0;
}
