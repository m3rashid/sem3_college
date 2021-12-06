#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[20][5];
    printf("================Submitted by: MD Rashid Hussain================\n");
    printf("================Roll: 20BCS033================\n");
    printf("Give the number of students\n");
    int n;
    scanf("%d",&n);

    printf("For students, Give the roll no, age and marks in three subject\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    float percentage[n];
    float max_percentage=0.0;
    int total=0;
    int high1=0, high2=0, high3=0, roll1=0, roll2=0, roll3=0;
    
    int high=100;
    for(int i=0; i<n; i++){
        total=arr[i][2]+arr[i][3]+arr[i][4];
        percentage[i]=(float)(100*total/(high*3));
    }
    
    printf("\n================Steps in the game================\n");
    printf("Press 1 to display percentage secured by each student along with the roll number\n");
    printf("Press 2 to print the highest marks in each subject alongwith the roll No\n");
    printf("Press 3 to print the roll no of the student(s)with the highest percentage\n");
    printf("Press 4 to exit the program\n\n");
    
    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                for(int i=0; i<n; i++){
                    printf("The percenage of student_%d: %.2f ", i+1, percentage[i]);
                    printf("and his roll number: %d\n", arr[i][0]);
                }
                break;

            case 2:
                for(int i=0; i<n; i++){
                    if(arr[i][2]>high1){
                        high1=arr[i][2];
                        roll1=arr[i][0];
                    }
                    if(arr[i][3]>high2){
                        high2=arr[i][3];
                        roll2=arr[i][0];
                    }
                    if(arr[i][4]>high3){
                        high3=arr[i][4];
                        roll3=arr[i][0];
                    }
                }
                printf("Highest Marks in------\n");
                printf("Subject_1:  %d  Roll No. %d\n", high1, roll1);
                printf("Subject_2:  %d  Roll No. %d\n", high2, roll2);
                printf("Subject_3:  %d  Roll No. %d\n", high3, roll3);
                break;

            case 3:
                for(int i=0; i<n; i++){
                    if(percentage[i]>max_percentage) max_percentage=percentage[i];
                }
                int minimum_age=1000;
                for(int i=0; i<n; i++){
                    if(max_percentage==percentage[i] && minimum_age>arr[i][1]) minimum_age=arr[i][1];
                }
                printf("roll number of student with highest percentage: ");
                for(int i=0; i<n; i++){
                    if(arr[i][1]==minimum_age && max_percentage==percentage[i]) printf("%d\n", arr[i][0]);
                }
                break;

            case 4:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}