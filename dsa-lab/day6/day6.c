#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// function prototypes
void insert();
void delete ();
void display();
void front_and_rear();
void isFull();
void isEmpty();
int my_queue[MAX];
int rear = -1;
int front = -1;
int i = -1;

int main()
{
    printf("This program was submitted by MD Rashid Hussain (20BCS033)\n");
    printf("\n=============MENU=============\n");
    printf("Press 1 to ENQUEUE the queue\n");
    printf("Press 2 to DEQUEUE the queue\n");
    printf("Press 3 to Display FRONT and REAR element\n");
    printf("Press 4 to Check if the queue is EMPTY \n");
    printf("Press 5 to Check if the queue is FULL\n");
    printf("Press 6 to Total number of elements in the queue\n");
    printf("Press 7 to Display the elents of queue\n");
    printf("Press 8 to Exit the program\n");

    int choice;
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            i++;
            break;
        case 2:
            delete ();
            i--;
            break;
        case 3:
            front_and_rear();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            printf("\nTotal number of elements in queue: %d\n", i);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Exiting the program");
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
        }
    }
    return 0;
}

void insert()
{
    int add_item;
    if (rear == MAX - 1)
        printf("Queue Overflow \n");
    else
    {
        if (front == -1)
            front = 0;
        printf("Inset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        my_queue[rear] = add_item;
        printf("\nQueue after adding element\n");
        display();
    }
}

void delete ()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    else
    {
        printf("Element deleted from queue: %d\n", my_queue[front]);
        front = front + 1;
        printf("\nQueue after deleting element\n");
        display();
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is EMPTY \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", my_queue[i]);
        printf("\n");
    }
}

void isEmpty()
{
    if (front == -1 || rear == -1)
        printf("\nQueue is EMPTY\n");
    else
        printf("\nQueue is NOT EMPTY\n");
}

void isFull()
{
    if (rear == MAX - 1)
        printf("\nQueue is FULL\n");
    else
        printf("\nQueue is NOT FULL\n");
}

void front_and_rear()
{
    if (front == -1 || rear == -1)
        printf("\nQueue is EMPTY\n");
    else
    {
        printf("\nFRONT element is %d\n", my_queue[front]);
        printf("\nREAR element is: %d\n", my_queue[rear]);
    }
}
