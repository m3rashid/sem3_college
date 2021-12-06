// MD Rashid Hussain (20BCS033)
// A menu driven program to find the addition subtraction of two matrix

#include <stdio.h>
#include <stdlib.h>

int checkDimension(int m1, int n1, int m2, int n2){ return (m1 == m2 && n1 == n2) ? 1 : 0; }
int checkSquare(int n1, int m2){ return (n1 == m2) ? 1 : 0; }

void print(int m, int n, int matrix[m][n]){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }
    return;
}

void plusMinus(int m1, int n1, int mat1[m1][n1], int m2, int n2, int mat2[m2][n2], char operand){
    if(checkDimension(m1, n1, m2, n2)){
        int matrix[m1][n1];
        if(operand == '+'){
            for(int i=0; i<m1; i++){
                for(int j=0; j<m2; j++) matrix[i][j] += mat1[i][j] + mat2[i][j];
            }
            print(m1, n1, matrix);
        }
        else if(operand == '-'){
            for(int i=0; i<m1; i++){
                for(int j=0; j<m2; j++) matrix[i][j] += mat1[i][j] + mat2[i][j];
            }
            print(m1, n1, matrix);
        }
        else { printf("Operand cant be accessed"); }
        return;    
    }
    else{
        printf("These matrices don't meet the criteria to be added");
        return;
    } 
}

void multiply(int m1, int n1, int mat1[m1][n1], int m2, int n2, int mat2[m2][n2]){
    if(checkSquare(n1, m2)){
        int matrix[10][10];
        for(int i=0; i<m1; i++){
            for(int j=0; j<n2; j++){
                int sum = 0;
                for(int k=0; k<m2; k++){ sum = sum + (mat1[i][k] * mat2[k][j]); }
                matrix[i][j] = sum;
                sum = 0;
            }
        }
        print(m1, n2, matrix);
        return;
    }
    else{
        printf("These matrices don't meet the criteria to be multiplied");
        return;
    }
}



void main(){
    printf("\n=============================Steps to play this===============================");
    printf("\nEnter the rows and columns of matrix");
    printf("\nEnter the matrix elements\n");

    printf("\n===============================Options available==============================");
    printf("\nEnter 1 for addition");
    printf("\nEnter 2 for subtraction");
    printf("\nEnter 3 for multiplication");
    printf("\nEnter 4 to exit");

    int m1, n1, m2, n2;
    printf("\nEnter the number of rows in first matrix: ");
    scanf("%d", &m1);
    printf("\nEnter the number of columns in first matrix: ");
    scanf("%d", &n1);

    printf("Enter the number of rows in second matrix: ");
    scanf("%d", &m2);
    printf("Enter the number of columns in second matrix: ");
    scanf("%d", &n2);

    int mat1[10][10];
    int mat2[10][10];

    // Input for first matrix
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            printf("\nEnter the [%d][%d]th element of first matrix: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input for second matrix
    for(int i=0; i<m2; i++){
        for(int j=0; j<n2; j++){
            printf("\nEnter the [%d][%d]th element of second matrix: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Choice for operation
    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            // Adding 
            plusMinus(m1, n1, mat1, m2, n2, mat2, '+');
            break;
        case 2:
            // Subtracting
            plusMinus(m1, n1, mat1, m2, n2, mat2, '-');
            break;
        case 3:
            // Multiplying 
            multiply(m1, n1, mat1, m2, n2, mat2);
            break;
        case 4:
            printf("Program exit, have a nice day");
            return;
        default: printf("invalid Input"); 
        }
    }
}