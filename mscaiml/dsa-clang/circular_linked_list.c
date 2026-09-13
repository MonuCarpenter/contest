#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

/**
 * @description: Create a new node with the given value
 * */

Node *create_node(int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

/**
 *  @description: Insert new node at the beginning of the list
 * */

void insert_at_beginning(Node **head, int val) {
  Node *new_node = create_node(val);

  if (*head == NULL) {
    *head = new_node;
    new_node->next = *head; // since we are creating a circular linked list, the
                            // next of the new node should point to itself
  } else {
    Node *current = *head;

    while (current->next != *head) {
      current = current->next;
    }

    current->next = new_node;
    new_node->next = *head;
    *head = new_node;
  }
}

/**
 *  @description: Insert new element at the end of the list
 *
 *  It will be same as adding element at the beginning,
 *  but we will not change the head pointer,
 *  we will just add the new node at the end of the list
 *  and make it point to the head.
 * */

void insert_at_end(Node **head, int val) {
  Node *new_node = create_node(val);

  if (*head == NULL) {
    *head = new_node;
    new_node->next = *head; // since we are creating a circular linked list, the
                            // next of the new node should point to itself
  } else {
    Node *current = *head;

    while (current->next != *head) {
      current = current->next;
    }

    current->next = new_node;
    new_node->next = *head;
  }
}

/**
 *  @description: Insert at any position in the list
 * */

void insert_at_position(Node **head, int val, int pos) {
  Node *new_node = create_node(val);

  if (*head == NULL && pos == 0) {
    *head = new_node;
    new_node->next = *head; // since we are creating a circular linked list, the
                            // next of the new node should point to itself
  } else if (pos == 0) {
    insert_at_beginning(head, val);
  } else {
    Node *current = *head;
    int count = 0;

    while (count < pos - 1 && current->next != *head) {
      current = current->next;
      count++;
    }

    new_node->next = current->next;
    current->next = new_node;
  }
}

/**
 * @description: Print the circular linked list
 * */

void print_list(Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  Node *current = head;

  do {
    printf("%d -> ", current->val);
    current = current->next;
  } while (current != head);

  printf("(back to head)\n");
}

/**
 *  @description: Search for an element in the list
 * */

int search(Node *head, int key) {
  if (head == NULL) {
    return -1;
  }

  Node *current = head;
  do {
    if (current->val == key) {
      return 1;
    }
    current = current->next;
  } while (current != head);

  return 0;
}

/**
 *  @description: Delete from beginning
 * */
void delete_at_beginning(Node **head) {
  if (*head == NULL) {
    return;
  }

  Node *current = *head;

  if (current->next == *head) {
    free(current);
    *head = NULL;
    return;
  }

  while (current->next != *head) {
    current = current->next;
  }

  Node *temp = *head;
  current->next = temp->next;
  *head = temp->next;
  free(temp);
}

/**
 *  @description: Delete from end
 * */

void delete_at_end(Node **head) {
  if (*head == NULL) {
    return;
  }

  Node *current = *head;

  if (current->next == *head) {
    free(current);
    *head = NULL;
    return;
  }

  while (current->next->next != *head) {
    current = current->next;
  }

  Node *temp = current->next;
  current->next = *head;
  free(temp);
}

/**
 *  @description: Delete from any position
 * */

void delete_at_position(Node **head, int pos) {
  if (*head == NULL || pos < 0) {
    return;
  }

  Node *current = *head;

  if (pos == 0) {
    delete_at_beginning(head);
    return;
  }

  int count = 0;
  while (count < pos - 1 && current->next != *head) {
    current = current->next;
    count++;
  }

  if (current->next == *head) {
    return; // position is out of bounds
  }

  Node *temp = current->next;
  current->next = temp->next; // or current->next = current->next->next;
  free(temp);
}

int main() {
  Node *head = NULL;

  insert_at_end(&head, 1);
  insert_at_end(&head, 2);
  insert_at_beginning(&head, 0);
  insert_at_position(&head, 3, 2);

  print_list(head);

  int key = search(head, 2);
  printf("Searching for %d: %s\n", 2, key == 1 ? "Found" : "Not Found");

  delete_at_beginning(&head);
  print_list(head);

  delete_at_end(&head);
  print_list(head);

  delete_at_position(&head, 1);
  print_list(head);

  return 0;
}
