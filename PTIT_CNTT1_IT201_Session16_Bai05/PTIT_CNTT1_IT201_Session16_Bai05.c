#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* front;
    Node* rear;
    int size;
} Queue;

void initQueue(Queue** q){
    *q = (Queue*)malloc(sizeof(Queue));
    (*q)->front = NULL;
    (*q)->rear = NULL;
    (*q)->size = 0;
}

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(Queue** q, int data){
    Node* newNode = createNode(data);
    if((*q)->size == 0){
        (*q)->front = newNode;
        (*q)->rear = newNode;
    }
    else{
        (*q)->rear->next = newNode;
        (*q)->rear = newNode;
    }
    (*q)->size++;
}

int dequeue(Queue** q){
    if((*q)->size == 0){
        printf("Queue is empty\n");
        return -1;
    }
    int value = (*q)->front->data;
    Node* temp = (*q)->front;
    (*q)->front = (*q)->front->next;
    free(temp);
    (*q)->size--;
    if((*q)->size == 0) (*q)->rear = NULL;
    return value;
}

int isEmpty(Queue* q){
    return q->size == 0;
}

int main(){
    Queue* queue;
    initQueue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    int result = dequeue(&queue);
    printf("%d", result);
    return 0;
}