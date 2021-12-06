#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[20];
    int roll;
    int sub1;
    int sub2;
    int sub3;
    double percentage;
};

void insert();
void delete();
void update();
void display();
int rollNumberFound(int roll);
int validMarks(int marks);
int count = 0;

int main(){
    printf("\nEnter 1. to insert");        
    printf("\nEnter 2. to delete");
    printf("\nEnter 3. to update");
    printf("\nEnter 4. to display");
    printf("\nEnter 5. to exit");

    int choice;
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: update(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default: printf("\nInvalid choice"); break;
        }
    }
    return 0;
}

void insert(){
    FILE *ptr;
    ptr = fopen("data.txt", "a");
    if(ptr == NULL){
        printf("\nError opening file");
        exit(1);
    }
    struct Student s;
    printf("\nEnter name: ");
    fflush(stdin);
    scanf(" %[^\n]", s.name);
    printf("\nEnter roll: ");
    scanf("%d", &s.roll);
    printf("\nEnter marks of 3 subjects: ");
    scanf("%d %d %d", &s.sub1, &s.sub2, &s.sub3);
    s.percentage = (s.sub1 + s.sub2 + s.sub3)/3.0;
    if(!rollNumberFound(s.roll)){
        if(validMarks(s.sub1) && validMarks(s.sub2) && validMarks(s.sub3)){
            fprintf(ptr, "%d \t %s \t %d \t %d \t %d \t %.2lf\n", s.roll, s.name, s.sub1, s.sub2, s.sub3, s.percentage);
            fclose(ptr);
            count++;
        }
        else printf("\nInvalid marks entered, try again");
    }
    else printf("\nRoll number already exists, try again");
}

void delete(){
    int roll;
    printf("\nEnter the roll to be searched: ");
    scanf("%d", &roll);
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if(ptr == NULL){
        printf("\nError opening file");
        exit(1);
    }
    FILE *temp;
    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        printf("\nError opening file");
        exit(1);
    }
    struct Student s;
    while(fscanf(ptr, "%d \t %[^\t] \t %d \t %d \t %d \t %lf\n", &s.roll, s.name, &s.sub1, &s.sub2, &s.sub3, &s.percentage) != EOF){
        if(s.roll != roll){
            fprintf(temp, "%d \t %s \t %d \t %d \t %d \t %.2lf\n", s.roll, s.name, s.sub1, s.sub2, s.sub3, s.percentage);
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
    count--;
}

void update(){
    int roll;
    printf("\nEnter the roll to be searched: ");
    scanf("%d", &roll);
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if(ptr == NULL){
        printf("\nError opening file");
        exit(1);
    }
    FILE *temp;
    temp = fopen("temp.txt", "w");
    if(temp == NULL){
        printf("\nError opening file");
        exit(1);
    }
    struct Student s;
    while(fscanf(ptr, "%d \t %[^\t] \t %d \t %d \t %d \t %lf\n", &s.roll, s.name, &s.sub1, &s.sub2, &s.sub3, &s.percentage) != EOF){
        if(s.roll != roll){
            fprintf(temp, "%d \t %s \t %d \t %d \t %d \t %.2lf\n", s.roll, s.name, s.sub1, s.sub2, s.sub3, s.percentage);
        }
        else{
            printf("\nEnter new marks of 3 subjects: ");
            scanf("%d %d %d", &s.sub1, &s.sub2, &s.sub3);
            if(validMarks(s.sub1) && validMarks(s.sub2) && validMarks(s.sub3)){
                s.percentage = (s.sub1 + s.sub2 + s.sub3)/3.0;
                fprintf(temp, "%d \t %s \t %d \t %d \t %d \t %.2lf\n", s.roll, s.name, s.sub1, s.sub2, s.sub3, s.percentage);
            }
            else printf("\nInvalid marks entered, try again"); 
        }
    }
    fclose(ptr);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

int rollNumberFound(int roll){
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if(ptr == NULL){
        printf("\nError opening file"); exit(1);
    }
    struct Student s;
    while(fscanf(ptr, "%d \t %[^\t] \t %d \t %d \t %d \t %lf\n", &s.roll, s.name, &s.sub1, &s.sub2, &s.sub3, &s.percentage) != EOF){
        if(s.roll == roll) return 1;
    }
    return 0;
}

int validMarks(int marks){
    if(marks >= 0 && marks <= 100) return 1;
    else return 0;
}

void display(){
    FILE *ptr;
    ptr = fopen("data.txt", "r");
    if(ptr == NULL){
        printf("\nFile not found"); exit(0);
    }
    char ch;
    while((ch = fgetc(ptr)) != EOF) printf("%c", ch);
    fclose(ptr);
    return;
}
