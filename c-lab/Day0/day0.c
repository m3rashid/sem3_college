// MD Rashid Hussain (20BCS033)
// A menu driven program to find the addition subtraction of two matrix

#include <stdio.h>
#include <stdlib.h>

int checkDimension(int m1_rows, int m2_rows, int m1_columns, int m2_columns){
    if(m1_rows == m2_rows && m1_columns == m2_columns){ return 1; }
    else { return 0; }
}

int checkSquare(int m1_rows, int m2_rows, int m1_columns, int m2_columns){
    if(m1_columns == m2_rows){ return 1; }
    else { return 0; }
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

    int m1_rows, m1_columns, m2_rows, m2_columns;
    printf("\nEnter the number of rows in first matrix: ");
    scanf("%d", &m1_rows);
    printf("\nEnter the number of columns in first matrix: ");
    scanf("%d", &m1_columns);

    printf("Enter the number of rows in second matrix: ");
    scanf("%d", &m2_rows);
    printf("Enter the number of columns in second matrix: ");
    scanf("%d", &m2_columns);

    int m1[10][10];
    int m2[10][10];

    // Input for first matrix
    for(int i=0; i<m1_rows; i++){
        for(int j=0; j<m1_columns; j++){
            printf("\nEnter the [%d][%d]th element of first matrix: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    // Input for second matrix
    for(int i=0; i<m2_rows; i++){
        for(int j=0; j<m2_columns; j++){
            printf("\nEnter the [%d][%d]th element of second matrix: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    // Choice for operation
    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            if(checkDimension(m1_rows, m2_rows, m1_columns, m2_columns)){
                // Adding
                int matrix[m1_rows][m1_columns];
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m1_columns; j++){ matrix[i][j] = m1[i][j] + m2[i][j]; }
                }

                // Print the matrix finally
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m1_columns; j++){ printf("%d ", matrix[i][j]); }
                    printf("\n");
                }
            }
            else{ printf("\nThese matrices can't be added"); }
            break;
        case 2:
            if (checkDimension(m1_rows, m2_rows, m1_columns, m2_columns)){
                // Subtracting
                int matrix[m1_rows][m1_columns];
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m1_columns; j++){ matrix[i][j] = m1[i][j] - m2[i][j]; }
                }

                // Print the matrix finally
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m1_columns; j++){ printf("%d ", matrix[i][j]); }
                    printf("\n");
                }
            }
            else{ printf("\nThese matrices can't be subtracted"); }
            break;
        case 3:
            if (checkSquare(m1_rows, m2_rows, m1_columns, m2_columns)){
                // Multiplying 
                int matrix[10][10];
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m2_columns; j++){
                        int sum = 0;
                        for(int k=0; k<m2_rows; k++){
                            sum = sum + (m1[i][k] * m2[k][j]);
                        }
                        matrix[i][j] = sum;
                        sum = 0;
                    }
                }
                
                //printing
                for(int i=0; i<m1_rows; i++){
                    for(int j=0; j<m2_columns; j++){ printf("%d ", matrix[i][j]); }
                    printf("\n");
                }
            }
            else{ printf("\nThese matrices can't be multiplied"); }
            break;
        case 4:
            printf("Program exit, have a nice day");
            return;
        default:
            printf("invalid Input");
        }
    }
}