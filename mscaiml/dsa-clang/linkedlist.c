/**
 *  Author: Monu C;
 *  CreatedAt: 12 Sept 2026
 * */

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *next;
};

typedef struct Node Link;

void add_element_at_end(Link *head, int value) {
  Link *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (Link *)malloc(sizeof(Link));
  current->next->val = value;
  current->next->next = NULL;
}

void print_list(Link *head) {
  Link *current = head;
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("NULL\n");
}

void add_element_at_beginning(Link **head, int value) {
  Link *new_node = (Link *)malloc(sizeof(Link));
  new_node->val = value;
  new_node->next = *head;
  *head = new_node;
}

int main() {
  printf("Implementing LinkedList (Singly)\n");

  Link *head = (Link *)malloc(sizeof(Link));
  head->val = 1;
  head->next = NULL;

  print_list(head);

  printf("Adding elements to the linked list...\n");
  add_element_at_end(head, 2);
  printf("Added 2\n");
  print_list(head);

  add_element_at_beginning(&head, 3);
  printf("Added 3\n");
  print_list(head);
  return 0;
}
