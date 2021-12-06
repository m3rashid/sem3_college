#include <stdio.h>

int main(){
    printf("\nThis program was submitted by MD Rashid Hussain (20BCS033)\n");
    int rowEnd, colEnd;
    printf("\nEnter the number of rows: ");
    scanf("%d", &rowEnd);
    printf("\nEnter the number of columns: ");
    scanf("%d", &colEnd);

    // taking matrix input from the user
    int matrix[rowEnd][colEnd];
    for(int i=0; i<rowEnd; i++){
        printf("\nEnter elements of %d th row: ", i+1);
        for(int j=0; j<colEnd; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    // Printing the initail matrix
    printf("\nThe elements of the matrix are\n");
    for(int i=0; i<rowEnd; i++){
        for(int j=0; j<colEnd; j++){
            printf("%d   ", matrix[i][j]);
        }
        printf("\n");
    }

    int rowStart=0, colStart=0;
    printf("\nSpiral array is: ");
    while (rowStart < rowEnd && colStart < colEnd){
        for (int i=colStart; i<colEnd; ++i){ printf("%d   ", matrix[rowStart][i]); } // first row
        rowStart++;

        for (int i=rowStart; i<rowEnd; ++i){ printf("%d   ", matrix[i][colEnd-1]); } // last column
        colEnd--;

        if (rowStart < rowEnd){
            for (int i=colEnd-1; i>= colStart; --i){ printf("%d   ", matrix[rowEnd-1][i]); } // last row
            rowEnd--;
        }

        if (colStart < colEnd){
            for (int i=rowEnd-1; i>=rowStart; --i){ printf("%d   ", matrix[i][colStart]); } // first column
            colStart++;
        }
    }

    return 0;
}
