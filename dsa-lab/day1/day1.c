#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n, int flag);

int main(){
    printf("\nThis program is given by MD RASHID HUSSAIN, (20BCS033), FET-JMI(CSE)");

    // taking user input
    int n;
    printf("\nEnter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the array elements: ");
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int choice=0;
    printf("\n===============Choose one of the options===============");
    printf("\nEnter 1 to sort the array using bubble sort");
    printf("\nEnter 2 to sort the array using early termination bubble sort");
    printf("\nEnter 3 to exit the program");
    
    while(1){
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                bubbleSort(arr, n, 0);
                break;
            
            case 2:
                bubbleSort(arr, n, 1);
                break;

            case 3:
                printf("\n===============Program Terminated===============");
                exit(0);
                break;
            
            default:
                printf("\nInvalid Input");
                break;
        }
    }    
    return 0;
}

void printArray(int arr[], int n){
    printf("\n");
    for(int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
}

void bubbleSort(int arr[], int n, int flag){
    int f=flag;
    printf("\nOriginal Array: ");
    printArray(arr, n);
    printf("\n");
    
    for(int i=0; i<n-1; i++){
        f=flag;
        printf("\nIteration: %d", i+1);
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                // swap them
                f=0;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                printArray(arr, n);
            }
        }
        printf("\n");
        if(f==1) break;
    }

    printf("\nSorted array: ");
    printArray(arr, n);
}
