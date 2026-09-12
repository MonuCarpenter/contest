/**
 * Topic: 3.3 Array implementation of a list
 * Author: Monu C.
 * CreatedAt: 12 Sept 2026
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int count;
  int entries[100];
} List;

void insert(List *head, int pos, int val) {
  int curr = head->count;

  while (curr >= pos) {
    head->entries[curr + 1] = head->entries[curr];
    curr--;
  }

  head->entries[pos] = val;
  head->count++;
}

void delete_element(List *head, int pos) {
  int curr = pos;

  while (curr < head->count) {
    head->entries[curr] = head->entries[curr + 1];
    curr++;
  }

  head->count--;
}

void traverse(List *head) {
  for (int i = 0; i < head->count; i++) {
    printf("%d -> ", head->entries[i]);
  }
  printf("NULL\n");
}

int main() {
  List *head = (List *)malloc(sizeof(List));

  head->count = 0;
  head->entries[0] = 0;

  traverse(head);
  insert(head, 0, 1);
  insert(head, 1, 2);
  insert(head, 2, 3);
  delete_element(head, 1);
  insert(head, 2, 4);

  traverse(head);

  return 0;
}
