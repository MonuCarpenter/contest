/**
 *  Topic: Implement queue using linkedlist
 *  Author: Monu C.
 *  CreatedAt: 14 Sept 2026
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *next;
} Node;

typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

Node *create_node(int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));

  if (!new_node) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  new_node->val = val;
  new_node->next = NULL;
  return new_node;
}

Queue *create_queue() {
  Queue *new_queue = (Queue *)malloc(sizeof(Queue));
  new_queue->front = new_queue->rear = NULL;

  return new_queue;
}

int is_empty(Queue *q) { return q->front == NULL; }

void enqueue(Queue *q, int val) {
  Node *new_node = create_node(val);

  if (is_empty(q)) {
    q->front = q->rear = new_node;
    return;
  }

  q->rear->next = new_node;
  q->rear = new_node;
}

int dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  Node *temp = q->front;
  int val = temp->val;

  q->front = q->front->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  free(temp);
  return val;
}

int peek(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return -1;
  }

  return q->front->val;
}

void print_queue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  Node *current = q->front;

  while (current != NULL) {
    printf("%d -> ", current->val);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  Queue *q = create_queue();

  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);

  print_queue(q);

  printf("Dequeued: %d\n", dequeue(q));
  print_queue(q);

  printf("Front element: %d\n", peek(q));

  return 0;
}
