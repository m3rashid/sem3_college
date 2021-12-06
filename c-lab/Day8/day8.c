#include <stdio.h>
#include <string.h>

int main(){
    printf("MD Rashid Hussain\n");
    printf("Roll: 20BCS033");
    char str[100];
    printf("\nEnter the string: ");
    scanf("%[^\n]", str);

    char sub[20];
    printf("\nEnter the string to replace: ");
    fflush(stdin);
    scanf(" %[^\n]", sub);

    char replace[20];
    printf("Enter new string: ");
    scanf(" %[^\n]", replace);

    int i = 0;
    while (str[i] != '\0'){
        if (str[i] == sub[0]){
            int j = 0;
            while (sub[j] != '\0'){
                if (str[i + j] != sub[j]) break;
                j++;
            }
            if (sub[j] == '\0'){
                int k = 0;
                while (replace[k] != '\0'){
                    str[i + k] = replace[k];
                    k++;
                }
                i = i + k - 1;
            }
            else printf("\nThe substring is not found in the main string");
        }
        i++;
    }
    printf("\nThe string after replacement is: %s", str);
    printf("\n");
    return 0;
}
