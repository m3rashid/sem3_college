#include <stdio.h>

int main(){
    printf("\nThis program is submitted my MD Rashid Hussain, 20BCS033\n");
    // taking use inputs
    int count = 0;
    printf("Enter the number of integers in the array: ");
    scanf("%d", &count);
    int arr[count];
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < count; i++) scanf("%d", &arr[i]);

    // Algorithm
    int min_sum = arr[0]; 
    int current_sum = 0;
    for (int i = 0; i < count; i++){
        current_sum += arr[i];
        if (current_sum < min_sum) min_sum = current_sum;
        if (current_sum > 0) current_sum = 0;
    }
    printf("\nThe sum of the minimum subarray is:  %d\n", min_sum);
    return 0;
}

// test cases ------
// 5 -3 1 -5 -1 7 -5  => -8
// 5 7 3 1 4  => 1
// -5 -3 13 -4 -2 -2  => -8
// -5 -3 3 -4 -2 -2  => -13