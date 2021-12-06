#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int count;
struct Employee
{
    int empid;
    char name[20];
    int salary;
};
void add_emp(struct Employee *Emps)
{ //to add employee to the list
    if (count > n)
    {
        printf("Overloaded");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("\n-----------------------------------------");
            printf("\nName of Employee : "); //name
            scanf("%s", &(Emps + i)->name);
            printf("Employee-Id      : "); //id
            scanf("%d", &(Emps + i)->empid);
            /* if (&(Emps+num)->empid==&(Emps+num)->empid){//if id are same ,return and add again correctly.
            printf("Same id,Invalid ");return;
          }*/
            printf("Salary : "); //salary
            scanf("%d", &(Emps + i)->salary);
        }
        count++;
    }
}

void display(struct Employee *Emps) //function to display the items in the list
{
    if (n <= 0)
    { //if list is empty
        printf("Nothing found\n");
        return;
    }
    printf("\nList of All Employees:\n");
    printf("Emp-Id\tEmp-Name  Salary\n");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++)
    { //for loop to check
        printf("%d\t%s\t  %d\n", (Emps + i)->empid, (Emps + i)->name, (Emps + i)->salary);
    }
}

void emp_byempid(int ID, struct Employee *Emps, int nums)
{ //function to find the items using I'd

    int rep = 0;

    for (int i = 0; i < nums; i++)
    {
        if ((Emps + i)->empid == ID)
        {
            rep = 1;
            printf("Name of employee:%s\n", (Emps + i)->name);
            printf("ID of employee:%d\n", (Emps + i)->empid);
            printf("Salary of employee:%d\n", (Emps + i)->salary);
        }
    }
    if (rep == 0)
    {
        printf("Not found\n");
    }
}
void emp_byname(char Names[], struct Employee *Emps, int nums)
{
    int rep = 0; //function to find the items using I'd

    for (int i = 0; i < nums; i++)
    {
        if (strcmp(Names, (Emps + i)->name) == 0)
        {   
            rep = 1;
            printf("Name of employee:%s\n", (Emps + i)->name);
            printf("ID of employee:%d\n", (Emps + i)->empid);
            printf("Salary of employee:%d\n", (Emps + i)->salary);
        }
    }

    if (rep == 0)
    {
        printf("Not found\n");
    }
}

void emp_highsal(struct Employee *Emps, int nums)
{
    int ind = 0;
    int high = (Emps + 0)->salary;
    ;
    for (int i = 0; i < nums; i++)
    {
        if ((Emps + i)->salary >= high)
        {
            high = (Emps + 0)->salary;
            ind = i;
        }
    }
    printf("Highest salary is :%d", high);
    printf("Name : %s", (Emps + 0)->name);
    printf("Employee id : %d", (Emps + 0)->empid);
}
int main()
{
    int ID;
    char name[20];

    struct Employee *ptr;
    printf("Enter the Number of employees");
    scanf("%d", &n);

    ptr = malloc(n * sizeof(struct Employee));

    int ch;
    while (1)
    {
        printf("\nMenu\n");
        printf("-----------------------------------------");
        printf("\n 1:Add Employee");
        printf("\n 2:List of All Employee");
        printf("\n 3:Search Employee by Empid ");
        printf("\n 4:Search Employee by Name");
        printf("\n 5:Search Employee by Highest salary ");
        printf("\n 6:Exit");
        printf("\n----------------------------------------\n");
        printf("Enter Your Choice : ");
        scanf("\n %d", &ch);

        switch (ch)
        {
        case 1:
            add_emp(ptr);
            break;
        case 2:
            display(ptr);
            break;
        case 3:
            printf("Enter the employee ID\n");
            scanf("%d", &ID);
            emp_byempid(ID, ptr, n);
            break;
        case 4:
            printf("Enter the employee Name \n");
            scanf("%s", name);
            emp_byname(name, ptr, n);
            break;
        case 5:
            emp_highsal(ptr, n);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice ,Try again!");
            return 0;
        }
    }
    return 0;
}