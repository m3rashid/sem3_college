#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_white_spaces(char *str){
    int i, check;
    for(i=check=0; str[i]; ++i)
        if(!isspace(str[i]) || (i>0 && !isspace(str[i-1])))
            str[check++] = str[i];
    str[check] = '\0';
    printf("%s",str);
}

int main(){
    char str[1000];
    printf("Enter your paragraph\n");
    fflush(stdin);
    scanf("%[^\n]", &str);

    int length = strlen(str), spaces = 0, tabs = 0, sentences = 0, vowels = 0, multipleSpaces=0;
    for(int i=0; i<length; i++){
        if(str[i]=='\t') { tabs++; }
        else if(str[i]==' ') { spaces++; }
        else if(str[i]=='.' || str[i]=='!' || str[i]=='?') { sentences++; }
        
        else if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') { vowels++; }
        else if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') { vowels++; }
    }
    if(str[length-1] != '.' || str[length-1] !='!' || str[length-1] !='?'){ sentences++; }

    printf("Length of string is:  %d\n", length);
    printf("Number of spaces is:  %d\n", spaces);
    printf("Number of tabs is:  %d\n", tabs);
    printf("Number of words in the string is: %d\n", spaces+1);
    printf("Number of sentences is:  %d\n", sentences);
    printf("Number of vowels is:  %d\n\n", vowels);
    printf("\nString after extra space deletion is\n");
    remove_white_spaces(str);
    return 0;
}
