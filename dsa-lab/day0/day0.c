#include <stdio.h>
#include <conio.h>

void factorial(int n){
    int res=1;
    for(int i=1; i<=n; i++){ res *= i; }
    printf("The factorial of %d is: %d\n", n, res);
}
void seriesSum(int n){ printf("The sum of numbers from 1 to %d is: %d\n", n, n*(n+1)/2); }
void fibonacci(int n ){
    int fib[n];
    fib[0] = 0;
    fib[1] = 1;

    // Calculating fibonacci numbers
    for(int i=2; i<n; i++){ fib[i] = fib[i-1] + fib[i-2]; }

    // Printing
    printf("The fibonacci series is as under:\n");
    for(int i=0; i<n; i++){ printf("%d  ", fib[i]); }
    printf("\n");
}
void power(int a, int b){
    int res = 1;
    for(int i=0; i<b; i++){ res *= a; }
    printf("%d to the power of %d is: %d\n",a, b, res);
}

void main(){
    printf("This program is written by MD RASHID HUSSAIN (20BCS033), B.Tech (CSE), JMI\n\n");

    printf("===============Steps to play=================\n");
    printf("Enter 1 for factorial\n");
    printf("Enter 2 for sum of natural numbers\n");
    printf("Enter 3 for fibonacci numbers\n");
    printf("Enter 4 for power of two numbers\n");
    printf("Enter 5 for exiting the program\n");
    printf("===============================================\n");

    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        int a=0, b=0, n=0;

        switch(choice){
            case 1:
                // factorial
                printf("Number: ");
                scanf("%d", &n);
                factorial(n);
                break;

            case 2:
                // Sum of natural numbers from 1 to n
                printf("Number: ");
                scanf("%d", &n);
                seriesSum(n);
                break;

            case 3:
                // print fibonacci numbers till n
                printf("Number: ");
                scanf("%d", &n);
                fibonacci(n);
                break;

            case 4:
                // power a^b
                printf("Enter two numbers a and b separated with space if you need a^b: ");
                scanf("%d %d", &a, &b);
                power(a, b);
                break;

            case 5:
                // exit
                printf("Program exited, have a nice day\n");
                return;

            default:
                printf("Invalid input received\n");
        }
    }
}