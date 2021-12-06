#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int STRLEN(char str[20]){
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

void STRREV(char str[20]){
    int length = STRLEN(str);
    for(int j=length-1; j>=0; j--)printf("%c", str[j]);
    printf("\n");
}

void STRCPY(char str1[20], char str2[20]){
    int length = STRLEN(str1);
    for(int i=0; i<length; i++){
        str2[i] = str1[i];
    }
}

void STRCMP(char str1[20], char str2[20]){
    int len1 = STRLEN(str1);
    int len2 = STRLEN(str2);
    if(len1 != len2) {
        printf("Strings are not identical\n");
        return;
    }
    else{
        for(int i=0; i<len1; i++){
            if(str1[i] != str2[i]){
                printf("Strings are not identical\n");
                return;
            }
        }
        printf("Strings are identical\n");
    }
}

void STRCONCAT(char str1[20], char str2[20], char concat[40]){
    int len1 = STRLEN(str1);
    int len2 = STRLEN(str2);
    for(int i=0; i<len1; i++){
        concat[i] = str1[i];
    }
    for(int i=0; i<len2; i++){
        concat[len1+i] = str2[i];
    }
}

void PALINDROME(char str[20]){
    int length = STRLEN(str);
    for(int i=0; i<=length/2; i++){
        if(str[i] != str[length-i-1]){
            printf("This string is not a palindrome\n");
            return;
        }
    }
    printf("This string is a palindrome\n");
}

void SUBSTRING(char str1[20], char str2[20]){
    int len1 = STRLEN(str1);
    int len2 = STRLEN(str2);

    if(len1 == len2 && str1[0] != str2[0]) printf("Second string is not a substring of first\n");
    else if(len2 > len1) printf("Second string is not a substring of firs\n");
    else{
        int flag = 0;
        for(int i=0; i<len2; i++){
            for(int j=0; j<len1; j++){
                if(str1[j]==str2[i]){
                    for(int k=0; k<len2; k++){
                        if(str1[j+k] != str2[i+k]){
                            flag = 0;
                            break;
                        }
                        else{
                            flag = 1;
                        }
                    }
                }
            }
        }
        if(flag == 1) printf("Second string is a substring of first\n");
        else printf("Second string is not a substring of first\n");
    }
}

int main(){
    printf("This program was submitted by MD Rashid Hussain, 20BCS033\n\n");
    printf("================= MENU =================\n");
    printf("Enter 1 to find the length of the string\n");
    printf("Enter 2 to reverse a string\n");
    printf("Enter 3 to copy a string\n");
    printf("Enter 4 to compare two strings\n");
    printf("Enter 5 to concatanate two strings\n");
    printf("Enter 6 to check if string is palindrome\n");
    printf("Enter 7 to search a substring in a string\n");
    printf("Enter 8 to exit the program\n\n");

    while(1){
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        char str1[20] = {'\0'}; 
        char str2[20] = {'\0'}; 
        char concat[40] = {'\0'};
        fflush(stdin);
        printf("Enter the string: ");
        scanf("%[^\n]", &str1); 

        int length;
        switch(choice){
            case 1: 
                length = STRLEN(str1);
                printf("\nLength of the string is: %d\n", length);
                break;
            case 2: 
                STRREV(str1); break;
            case 3: 
                STRCPY(str1, str2);
                printf("%s", str2);
                break;
            case 4: 
                fflush(stdin);
                printf("Enter the second string: ");
                scanf("%[^\n]", &str2); 
                STRCMP(str1, str2);
                break;
            case 5: 
                fflush(stdin);
                printf("Enter the second string: ");
                scanf("%[^\n]", &str2); 
                STRCONCAT(str1, str2, concat);
                printf("%s", concat);
                break;
            case 6: 
                PALINDROME(str1);
                break;
            case 7: 
                fflush(stdin);
                printf("Enter the substring: ");
                scanf("%[^\n]", &str2);
                SUBSTRING(str1, str2);
                break;
            case 8: 
                exit(0);
                break;
            default: 
                printf("Invalid Input\n");
                break;
        }
    }
    return 0;
}