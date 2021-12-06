#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int size;

    
struct employee{
    int empid;
    char name[20];
    float salary; 
};


void addEmployee(struct employee *allEmployees){
    if(count >= size){ 
        printf("Your organisation is full, cannot add more employees\n"); 
    }
    else{
        struct employee e;
        printf("Enter employee id: ");
        scanf("%d", &e.empid);

        fflush(stdin);
        printf("Enter Employee name: ");
        scanf("%[^\n]", &e.name);

        printf("Enter Employee salary: ");
        scanf("%f", &e.salary);
        for(int i=0; i<=count; i++){
            if((allEmployees+i)->empid == e.empid){
                printf("Two employees with same id cannot exist in this company\n");
                return;
            }
        }
        *(allEmployees+count) = e;
        count++;
        printf("You added one employee in the organisation\n");
    }
    fflush(stdout);
}


void displayAllEmployees(struct employee *allEmployees){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        printf("Id \t|\t Name \t|\t Salary\n");
        printf("---------------------------------------\n");
        for(int i=0; i<count; i++){
            printf("%d\t|\t", (allEmployees+i)->empid);
            printf("%s\t|\t", (allEmployees+i)->name);
            printf("%.2f\t|\t", (allEmployees+i)->salary);
            printf("\n");
            printf("---------------------------------------\n");
        }
    }
    fflush(stdout);
}


void searchById(struct employee *allEmployees, int id){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        for(int i=0; i<count; i++){
            if((allEmployees+i)->empid == id){
                printf("Id \t|\t Name \t|\t Salary\n");
                printf("---------------------------------------\n");
                printf("%d\t|\t", (allEmployees+i)->empid);
                printf("%s\t|\t", (allEmployees+i)->name);
                printf("%.2f\t|\t", (allEmployees+i)->salary);
                printf("\n");
                printf("---------------------------------------\n");
                return;
            }
        }
        printf("No employees found with the given employee id.\n");
    }
    fflush(stdout);
}

void searchByName(struct employee *allEmployees, char name[20]){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        for(int i=0; i<count; i++){
            if(strcmp((allEmployees+i)->name, name) == 0){
                printf("Id \t|\t Name \t|\t Salary\n");
                printf("---------------------------------------\n");
                printf("%d\t|\t", (allEmployees+i)->empid);
                printf("%s\t|\t", (allEmployees+i)->name);
                printf("%.2f\t|\t", (allEmployees+i)->salary);
                printf("\n");
                printf("---------------------------------------\n");
            }
            else{ printf("No employees found with the given employee id.\n"); }
        }
    }
    fflush(stdout);
}

void highestSalary(struct employee *allEmployees){
    int max = -1;
    for(int i=0; i<count; i++){
        if(allEmployees[i].salary > max){
            max = (allEmployees+i)->salary;
        }
    }
    printf("Id \t|\t Name \t|\t Salary\n");
    printf("---------------------------------------\n");

    for(int i=0; i<count; i++){
        if((allEmployees+i)->salary == max){
            printf("%d\t|\t", (allEmployees+i)->empid);
            printf("%s\t|\t", (allEmployees+i)->name);
            printf("%.2f\t|\t", (allEmployees+i)->salary);
            printf("\n");
            printf("---------------------------------------\n");

        }
        printf("\n");
    }
    fflush(stdout);
}

int main(){
    printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033 FET JMI (CSE)\n");

    printf("Enter the maximum number of employees: ");
    scanf("%d", &size);

    printf("\n==========Steps to play this==========\n");
    printf("Enter 1 to add an employee\n");
    printf("Enter 2 to display all employees\n");
    printf("Enter 3 to search employee by id\n");
    printf("Enter 4 to search employee by name\n");
    printf("Enter 5 to know more about employee with highest salary\n");
    printf("Enter 6 to know the number of employees\n");
    printf("Enter 7 to exit the program\n");
    // struct employee allEmployees[10];
    struct employee *allEmployees;
    allEmployees = malloc(size * sizeof(struct employee));

    int id, choice=0;
    char name[20];

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                addEmployee(allEmployees);
                break;

            case 2:
                displayAllEmployees(allEmployees);  
                break;

            case 3:
                printf("Enter Employee ID to be searched: ");
                scanf("%d", &id);
                searchById(allEmployees, id); 
                break;

            case 4:
                fflush(stdin);
                printf("Enter the Employee name to be searched: ");
                scanf("%[^\n]", &name);  
                searchByName(allEmployees, name); 
                break;

            case 5: 
                printf("Employee with highest salary\n"); 
                highestSalary(allEmployees); 
                break;

            case 6: 
                printf("The current number of employees is: %d\n", count); 
                break;
                
            case 7:  
                printf("Exiting the program\n");
                exit(0);  
                break;

            default:    
                printf("Invalid Input received\n");
                break;
        }
    }
    return 0;
}