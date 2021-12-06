#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int queue_array[MAX];
int rear = -1;
int front = -1;

// function prototypes
void enqueue(int a);
void dequeue();
void display();
int isFull();
int isEmpty();
int total();

int main(){
    printf("\nThis program was submitted by MD Rashid Hussain\nRoll No: 20BCS033");

    int choice;
    while (1){   
        printf("\n\n==========MENU==========\n");
        printf("Enter 1. to ENQUEUE the queue\n");
        printf("Enter 2. to DEQUEUE the queue\n");
        printf("Enter 3. to Display FRONT and REAR element\n");
        printf("Enter 4. to Check if the queue is EMPTY \n");
        printf("Enter 5. to Check if the queue is FULL\n");
        printf("Enter 6. to Total number of elements in the queue\n");
        printf("Enter 7. to Display the elements of queue\n");
        printf("Enter 8. to Exit the program\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice){
            case 1: printf("\nEnter the element to be enqueued: ");
                int a; scanf("%d", &a); enqueue(a); break;
            case 2: dequeue(); break;
            case 3: printf("\nFront Element : %d", queue_array[front]);
					printf("\nRear Element : %d", queue_array[rear]);
					break;
            case 4: 
                if(isEmpty()) printf("\nThe queue is empty\n");
                else printf("\nThe queue is not empty\n"); 
                break;
            case 5: 
                if(isFull()) printf("\nThe queue is FULL\n");
                else printf("\nThe queue is NOT FULL\n");
                break;
            case 6: printf("\nNo of elements in queue: %d\n", total()); break;
            case 7: display(); break;
            case 8: exit(0); break;
            default:printf("Invalid choice \n"); break;
        }
    }
    return 0;
}

void enqueue(int element){
    if(isFull()) printf("\nQueue Overflow\n");
    else{
        if(rear == -1){ front = 0; rear = 0; }
        else if(rear == MAX - 1) rear = 0;
        else rear++;
        queue_array[rear] = element;
        display();
    }
}

void dequeue(){
    if(isEmpty()) printf("\nQueue Underflow !\n");
    else{
        if (front == rear){ front = -1; rear = -1; }
        else if (front == MAX - 1) front = 0;
        else front++;
        display();
    }
}

void display(){
    if(!isEmpty()){
        if (front <= rear){
            for(int i = front; i <= rear; ++i) printf(" %d ", queue_array[i]);
            printf("\n");
        }
        else{
            for(int i = front; i < MAX; ++i) printf(" %d ", queue_array[i]);
            for(int i = 0; i <= rear; ++i) printf(" %d ", queue_array[i]);
            printf("\n");
        }
    }
    else printf("\nQueue underflow");
}

int isEmpty(){
    if(front == -1 && rear == -1) return 1;
    else return 0;
}

int isFull(){
    if ((front == 0 && rear == MAX - 1) || rear + 1 == front) return 1;
    else return 0;
}

int total(){
	if(front == -1 && rear == -1) return 0;
	else if(front <= rear) return (rear - front + 1);
	else return (MAX - front + rear + 1);
}
