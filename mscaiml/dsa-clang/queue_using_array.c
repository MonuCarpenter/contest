/**
 * Topic: 208-Unit 5: Array implementation of queue
 * Author: Monu C.
 * CreatedAt: 14 Sept 2026
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
  int queue[MAX_SIZE];
  int front;
  int back;
} Queue;

void initialize_queue(Queue *q) {
  q->front = -1;
  q->back = -1;
}

int is_empty(Queue *q) { return q->front == -1; }

int is_full(Queue *q) { return q->back == MAX_SIZE - 1; }

void enqueue(Queue *q, int val) {
  if (is_full(q)) {
    printf("Queue is full\n");
    return;
  }

  if (is_empty(q)) {
    q->front = 0;
  }

  q->back++;
  q->queue[q->back] = val;
}

void dequeue(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  printf("Dequeued: %d\n", q->queue[q->front]);

  if (q->front == q->back) {
    q->front = -1;
    q->back = -1;
  } else {
    q->front++;
  }
}

void display(Queue *q) {
  if (is_empty(q)) {
    printf("Queue is empty\n");
    return;
  }

  for (int i = q->front; i <= q->back; i++) {
    printf("%d ", q->queue[i]);
  }
  printf("\n");
}

int main() {
  Queue q;
  initialize_queue(&q);

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  printf("Elements in the queue after enqueue operation: ");
  display(&q);

  dequeue(&q);
  printf("Elements in the queue after dequeue operation: ");
  display(&q);

  return 0;
}
