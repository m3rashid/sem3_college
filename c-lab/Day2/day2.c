#include <stdio.h>
#include <stdlib.h>

void decimalToHex(int n){
    char hex[100];
    int i = 0;
    while(n != 0){
        int temp = 0;
        temp = n % 16; 
        if(temp < 10) hex[i] = temp + 48; 
        // 0 = 48 (ASCII), so temp + 48
        
        else hex[i] = temp + 55; 
        // A = 65 (ASCII), temp is at least 10, so temp + 55 
        
        i++;
        n = n / 16;
    }
    for(int j = i-1; j>=0; j--) printf("%c", hex[j]);
    printf("\n");
}

void hexToDecimal(char hex[], int len){
    int base = 1;
    int decimal = 0;
    
    for(int i = len-1; i>=0; i--){
        if(hex[i] > '0' && hex[i] <= '9'){
            decimal += (((int)hex[i] - 48) * base);
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F'){
            decimal += (((int)hex[i] - 55) * base);
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f'){
            decimal += (((int)hex[i] - 87) * base);
        }
        base = base * 16;
    }
    printf("\n%d\n", decimal);
}

int main(){
    printf("\nThis program is submitted by MD Rashid Hussain (20BCS033), FET JMI (CSE)\n\n");

    printf("===============Steps to play===============\n");
    printf("Enter 1 for decimal to hexadecimal conversion\n");
    printf("Enter 2 for hexadecimal to decimal conversion\n");
    printf("Enter 3 to exit the program\n");
    printf("===============Go on, Enjoy===============\n");

    int choice;
    int decimalNum = 0, size = 0;
    char hexNum[100];
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter the decimal number: ");
                scanf("%d", &decimalNum);
                decimalToHex(decimalNum);
                break;
            
            case 2:
                printf("Enter number of digits of hexadecimal Number: ");
                scanf("%d", &size);
                printf("\nEnter the hexadecimal number: ");
                scanf("%s", hexNum);
                hexToDecimal(hexNum, size);
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid Input, try again\n");
        }
    }
    return 0;
}