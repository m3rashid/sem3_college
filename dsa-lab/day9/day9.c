#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PQueue{
    char n[4];
    int pr;
    struct PQueue  *next;
};
struct PQueue *front = NULL, *rear = NULL;

void enqueue();
void dequeue();
void frontAndRear();
void isEmpty();
void totalElements();
void display();
void printMenu();

int main(){
    printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033\n");
    printMenu();
    int choice;
    while(1){
        printf("\nChoice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: frontAndRear(); break;
            case 4: isEmpty(); break;
            case 5: totalElements(); break;
            case 6: display(); break;
            case 7: printMenu(); break;
            case 8: exit(0); break;
            default: printf("\nInvalid choice\n"); break;
        }
    }    
    return 0;
}


void enqueue(){
    struct PQueue *temp;
    temp = (struct PQueue*)malloc(sizeof(struct PQueue));
    printf("Enter name: ");
    scanf("%s", temp->n);
    printf("Enter priority: ");
    scanf("%d", &temp->pr);
    temp->next = NULL;

    if(front == NULL){
        front = temp;
        rear = temp;
    }
    else{
        if(temp->pr < front->pr){
            temp->next = front;
            front = temp;
        }
        else{
            struct PQueue *p = front;
            while(p->next != NULL && p->next->pr < temp->pr) p = p->next;
            temp->next = p->next;
            p->next = temp;
            if(temp->next == NULL) rear = temp;
        }
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue empty\n");
        return;
    }
    if(front == rear){
        free(front);
        front = rear = NULL;
    }
    else{
        struct PQueue *p = front;
        while(p->next != rear) p = p->next;
        free(rear);
        rear = p;
        rear->next = NULL;
    }
    printf("Last element dequeued\n");
}

void frontAndRear(){
    if(front == NULL){
        printf("Queue empty\n");
        return;
    }
    printf("front: %s(%d) \t", front->n, front->pr);
    printf("and rear: %s(%d)\n", rear->n, rear->pr);
}

void isEmpty(){
    if(front == NULL){
        printf("Queue empty\n");
        return;
    }
    printf("Queue not empty\n");
}

void totalElements(){
    if(front == NULL){
        printf("Queue empty\n");
        return;
    }
    int count = 0;
    struct PQueue *temp;
    temp = front;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("Total elements: %d\n", count);
}

void display(){
    if(front == NULL){
        printf("Queue empty\n");
        return;
    }
    struct PQueue *temp;
    temp = front;
    while(temp != NULL){
        printf("%s(%d)  >>  ", temp->n, temp->pr);
        temp = temp->next;
    }
    printf("\n");
}

void printMenu(){
    printf("===============MENU===============\n");
    printf("Enter 1. to enqueue\n");
    printf("Enter 2. to dequeue\n");
    printf("Enter 3. to display front and rear elements\n");
    printf("Enter 4. to check if it is empty\n");
    printf("Enter 5. to check the total number of elements\n");
    printf("Enter 6. to display the list\n");
    printf("Enter 7. to display this help menu\n");
    printf("Enter 8. to exit\n");
}
