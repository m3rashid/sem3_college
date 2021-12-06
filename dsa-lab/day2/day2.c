#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct employee{
    int empid;
    char name[20];
    float salary; 
};

void addEmployee(struct employee allEmployees[10]){
    if(count >= 10){ printf("Your organisation is full, cannot add more employees\n"); }
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
            if(allEmployees[i].empid == e.empid){
                printf("Two employees with same id cannot exist in this company\n");
                return;
            }
        }
        allEmployees[count] = e;
        count++;
        printf("You added one employee in the organisation\n");
    }
    fflush(stdout);
}

void displayAllEmployees(struct employee allEmployees[10]){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        for(int i=0; i<count; i++){
            printf("\n=====Details of Employee: %d=====\n", i+1);
            printf("Employee id: %d\n", allEmployees[i].empid);
            printf("Name: %s\n", allEmployees[i].name);
            printf("Salary: %.2f\n", allEmployees[i].salary);
        }
    }
    fflush(stdout);
}

void searchById(struct employee allEmployees[10], int id){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        for(int i=0; i<count; i++){
            if(allEmployees[i].empid == id){
                printf("\n=====Match found=====\n");
                printf("Employee id: %d\n", allEmployees[i].empid);
                printf("Name: %s\n", allEmployees[i].name);
                printf("Salary: %.2f\n", allEmployees[i].salary);
                return;
            }
        }
        printf("No employees found with the given employee id.\n");
    }
    fflush(stdout);
}

void searchByName(struct employee allEmployees[10], char name[20]){
    if(count == 0){ printf("There are no employees in your organization\n"); }
    else{
        for(int i=0; i<count; i++){
            if(strcmp(allEmployees[i].name, name) == 0){
                printf("\n=====Match found=====\n");
                printf("Employee id: %d\n", allEmployees[i].empid);
                printf("Name: %s\n", allEmployees[i].name);
                printf("Salary: %.2f\n", allEmployees[i].salary);
            }
            else{ printf("No employees found with the given employee id.\n"); }
        }
    }
    fflush(stdout);
}

void highestSalary(struct employee allEmployees[10]){
    int max = -1;
    for(int i=0; i<count; i++){
        if(allEmployees[i].salary > max){
            max = allEmployees[i].salary;
        }
    }
    for(int i=0; i<count; i++){
        if(allEmployees[i].salary == max){
            printf("Employee id: %d\n", allEmployees[i].empid);
            printf("Name: %s\n", allEmployees[i].name);
            printf("Salary: %.2f\n", allEmployees[i].salary);
        }
    }
    fflush(stdout);
}

int main(){
    printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033 FET JMI (CSE)\n");
    printf("\n==========Steps to play this==========\n");
    printf("Enter 1 to add an employee\n");
    printf("Enter 2 to display all employees\n");
    printf("Enter 3 to search employee by id\n");
    printf("Enter 4 to search employee by name\n");
    printf("Enter 5 to know more about employee with highest salary\n");
    printf("Enter 6 to exit the program\n");
    struct employee allEmployees[10];

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