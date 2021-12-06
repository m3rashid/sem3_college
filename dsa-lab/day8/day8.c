#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct node {
    int data;
    struct node *next;
} node;

struct node *front = NULL, *rear = NULL;
int size = 0;

// function prototypes
void enqueue(int a);
void dequeue();
void display();
void frontAndRear();
void count();
int isFull();
int isEmpty();

int main(){
    printf("\nThis program was submitted by MD Rashid Hussain\nRoll No: 20BCS033");
    printf("\n\n==========MENU==========\n");
    printf("Enter 1. to ENQUEUE the queue\n");
    printf("Enter 2. to DEQUEUE the queue\n");
    printf("Enter 3. to Display FRONT and REAR element\n");
    printf("Enter 4. to Check if the queue is EMPTY \n");
    printf("Enter 5. to Check if the queue is FULL\n");
    printf("Enter 6. to Total number of elements in the queue\n");
    printf("Enter 7. to Display the elements of queue\n");
    printf("Enter 8. to Exit the program\n");

    int choice;
    while (1){   
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1: printf("Enter the element to be enqueued: ");
                int a; scanf("%d", &a); enqueue(a); break;
            case 2: dequeue(); break;
            case 3: frontAndRear(); break;
            case 4: 
                if(isEmpty()) printf("\nThe queue is empty");
                else printf("\nThe queue is not empty"); 
                break;
            case 5: 
                if(isFull()) printf("\nThe queue is FULL");
                else printf("\nThe queue is NOT FULL");
                break;
            case 6: count(); break;
            case 7: display(); break;
            case 8: exit(0); break;
            default:printf("Invalid choice \n"); break;
        }
    }
    return 0;
}

void enqueue(int a){
    if(size >= MAX){
        printf("\nQueue is FULL");
        return;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = a;
    newNode->next = NULL;

    if(front == NULL && rear == NULL) front = rear = newNode;
    else{
        rear->next = newNode;
        rear = newNode;
    }
    size++;
    display();
}

void dequeue(){
    struct node *temp;
    if(front == NULL) printf("\nQueue underflow");
    else{
        temp = front;
        front = front->next;
        if(front == NULL) rear = NULL;
        free(temp);
    }
    display();
}

void display(){
    if(size == 0){
        printf("\nQueue is empty");
        return;
    }
    struct node *temp = front;
    while(temp){
        printf("%d => ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void count(){
    struct node *temp = front;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    printf("\nNo of elements in queue: %d", count);
}

int isEmpty(){
    if(front == NULL) return 1;
    else return 0;
}

int isFull(){
    if (size == MAX) return 1;
    else return 0;
}

void frontAndRear(){
    if(front == NULL) printf("\nQueue is empty");
    else{
        printf("\nFront element: %d", front->data);
        if(rear == NULL) printf("\nQueue is empty");
        else printf("\nRear element: %d", rear->data);
    }
}