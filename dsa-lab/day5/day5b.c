#include <stdio.h> 
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *top;
void initialize(){
    top = NULL;
}

void display(node *head){
    if (head == NULL){ printf(""); }
    else{
        printf("%d  ", head->data);
        display(head->next);
    }
}

void push(){
    int value = 0;
    printf("\nEnter the element to be pushed: ");
    scanf("%d", &value);
    node *tmp;
    tmp = malloc(sizeof(node));
    tmp->data = value;
    tmp->next = top;
    top = tmp;
    printf("\nStack after push\n");
    display(top);
}

void pop(){
    node *tmp; tmp = top; int n;
    if (tmp == NULL){ printf("\nCannot pop no element left\n"); }
    else{
        n = tmp->data;
        top = top->next;
        free(tmp);
        printf("\nPoppped element :%d\n", n);
        printf("\nStack after pop\n");
        display(top);
    }
}

void Top(){ printf("\nThe top element is : %d\n", top->data); }

void isempty(){
    if (top == NULL){ printf("\nStack is empty\n"); }
    else{ printf("\nStack is not empty\n"); }
}

int main(){
    int i = 0;
    int choice = 0;
    initialize();
    printf("\nThis program was submitted by MD Rashid Hussain, 20BCS033\n");
    printf("\nPress 1 to PUSH element");
    printf("\nPress 2 to POP element");
    printf("\nPress 3 to Check if the stack is empty or not");
    printf("\nPress 4 to See the top element");
    printf("\nPress 5 to Total number of elements in the stack");
    printf("\nPress 6 to Display the stack");
    printf("\nPress 7 to Exit the program");

    while (1){
        printf("\nEnter Your Choice : ");
        scanf("\n %d", &choice);

        switch(choice){
            case 1: push(); i++; break;
            case 2: pop(); i--; break;
            case 3: isempty(); break;
            case 4: Top(); break;
            case 5: printf("\nTotal elements of the stack are : %d\n", i); break;
            case 6: display(top); break;
            case 7: printf("\nExiting the program"); exit(0); break;
            default: printf("\n invalid choice "); break;
        }
    }
    return 0;
}