#include <stdio.h>
#include <stdlib.h>
void display(int arr[]);
void insert(int arr[], int* size, int pos, int num);
void delete(int arr[], int*size, int pos);

int main(){
    printf("This program is submitted by MD RASHID HUSSAIN (20BCS033), FET, JMI (CSE)\n");
    printf("===============Steps to run this===============\n");
    printf("Enter 1 to insert element at the beginnning\n");
    printf("Enter 2 to insert element at the end\n");
    printf("Enter 3 to insert element at some defined position (1 based numbering)\n\n");

    printf("Enter 4 to delete element at the beginnning\n");
    printf("Enter 5 to delete element at the end\n");
    printf("Enter 6 to delete element at some defined position\n");
    printf("===============Go on, Enjoy===============\n");
    

    int choice;
    int arr[20]={0};
    
    int size=0;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int num=0;
        int pos=0;

        switch(choice){
            case 1:
                // insert at the beginning
                printf("Enter the number: ");
                scanf("%d", &num);
                insert(arr, &size, 1, num);
                break;

            case 2:
                // insert at the end
                printf("Enter the number: ");
                scanf("%d", &num);
                insert(arr, &size, size-1, num);
                break;

            case 3:
                // insert at position
                printf("Enter the number: ");
                scanf("%d", &num);

                printf("\nEnter the position of insertion: ");
                scanf("%d", &pos);
                insert(arr, &size, pos, num);
                break;

            case 4:
                // delete at the beginning
                delete(arr, &size, 0);
                break;
            
            case 5:
                // delete at the end
                delete(arr, &size, size-1);
                break;
            
            case 6:
                // delete at position
                printf("\nEnter the position of deletion: ");
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            
            case 7:
                // exit the program
                exit(0);
            default: 
                // if user enters some other value
                printf("\nInvalid Input");
        }
    }
    return 0;
}


void display(int arr[]){
    for(int i=0; i<20; i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

void insert(int arr[], int* size, int pos, int num){
    if(*size <= 20){
        *size++;
        // shift elements 
        for(int i=*size-1; i>=pos; i--){
                *(arr+i) = *(arr+i-1);
        }
        // insert the number at pos
        arr[pos-1] = num;
        display(arr);
    }
    else{
        printf("Insertion is not possible, array is full\n");
    }
}

void delete(int arr[], int*size, int pos){
    if(pos>*size || pos<0){
        printf("Deletion is not possible\n");
    }
    for(int i=pos; i<*size; i++){
        *(arr+pos) = *(arr+pos+1);
    }
    size--;
    display(arr);
}
