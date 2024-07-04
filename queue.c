#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

typedef struct Queue {
    int front, rear, size;
    int array[MAX];
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isFull(Queue* queue) {
    return (queue->size == MAX);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to queue\n", item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->rear];
}

void displayQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);

    displayQueue(&queue);

    printf("Dequeued item: %d\n", dequeue(&queue));
    displayQueue(&queue);

    printf("Front item: %d\n", front(&queue));
    printf("Rear item: %d\n", rear(&queue));

    return 0;
}
