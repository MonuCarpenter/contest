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

/**
 * @description: It adds an element at the end of the given linked list
 * */
void add_element_at_end(Link *head, int value) {
  Link *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = (Link *)malloc(sizeof(Link));
  current->next->val = value;
  current->next->next = NULL;
}

/**
 * @description: It prints the given linkedlist
 * */
void print_list(Link *head) {
  Link *current = head;
  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("NULL\n");
}

/***
 * @description: It adds an element at the beginning of the linkedlist;
 */
void add_element_at_beginning(Link **head, int value) {
  Link *new_node = (Link *)malloc(sizeof(Link));
  new_node->val = value;
  new_node->next = *head;
  *head = new_node;
}

/**
 * @description: It removes the element from the beginning
 * */
void remove_element_from_beginning(Link **head) {
  Link *new_node = (*head)->next;
  free(*head);
  *head = new_node;
}

/**
 * @description: remove the last element from the linkedlist;
 * */
void remove_last_element(Link *head) {
  Link *cur = head;

  while (cur->next->next != NULL) {
    cur = cur->next;
  }

  free(cur->next);
  cur->next = NULL;
}

int main() {
  printf("Implementing LinkedList (Singly)\n");

  Link *head = (Link *)malloc(sizeof(Link));
  head->val = 1;
  head->next = NULL;

  print_list(head);

  printf("add_element_at_end(2): \n");
  add_element_at_end(head, 2);

  print_list(head);

  printf("add_element_at_beginning(3) \n");
  add_element_at_beginning(&head, 3);

  print_list(head);

  printf("remove_element_from_beginning: \n");
  remove_element_from_beginning(&head);

  print_list(head);

  printf("add_element_at_end(3) \n");
  add_element_at_end(head, 3);

  print_list(head);

  printf("remove_last_element \n");
  remove_last_element(head);

  print_list(head);
  return 0;
}
