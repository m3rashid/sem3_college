#include <stdio.h>
#include <stdlib.h>

int length = 0;
int max_size;

void count(){ printf("\nTotal number of elements in the stack is: %d\n", length); }
void display(int *p){ for(int i=0; i<length; i++) printf("%d  ", p[i]); }
void push(int *p){
    if(length>=max_size){ printf("\nStack is already full\n"); return; }
    else{
        int n;
        printf("Enter the element to be pushed: ");
        scanf("%d", &n);
    
        p[length] = n;
        length++;
        printf("\nPushed item %d to the stack\n", n);
        display(p);
    }
}
void pop(int *p){
    if(length==0){ printf("\nThere are no elements to pop from the satck\n"); return; }
    else{
        p[length-1] = -1;
        length--;
        printf("\nPopped the top element from the stack\n");
        display(p);
    }
}
void peek(int *p){ printf("\nPeeked element: %d\n", p[length-1]); }
void isEmpty(int *p){
    if(length==0){ printf("\nStack is empty\n"); }
    else { printf("\nStack is not empty\n"); }

}
void isFull(int *p){
    if(length==max_size){ printf("\nArray is full\n"); }
    else{ printf("\nArray is not full\n"); }
}

int main(){
    printf("\nThis program was submitted by MD Rashid Hussain, 20BCS033\n");
    printf("Press 1. to push an element to the stack\n");
    printf("Press 2. to pop the top element\n");
    printf("Press 3. to peek or see the top element\n");
    printf("Press 4. to check if the stack is empty\n");
    printf("Press 5. to check if the stack is full\n");
    printf("Press 6. check Total no of element\n");
    printf("Press 7. to Display all the elements of the stack\n");
    printf("Press 8. to Exit the program\n");
    
    printf("\nEnter the maximum size of the array: ");
    scanf("%d", &max_size);
    int *p;
    p = (int *)malloc(max_size * sizeof(int));
    for(int i=0; i<max_size; i++){ p[i] = -1; }

    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: push(p); break;
            case 2: pop(p); break;
            case 3: peek(p); break;
            case 4: isEmpty(p); break;
            case 5: isFull(p); break;
            case 6: count(); break;
            case 7: display(p); break;
            case 8: printf("\nExiting the program....."); exit(0); break;
            default: printf("\nInvalid Input\n"); break;
        }
    }
    return 0;
}
