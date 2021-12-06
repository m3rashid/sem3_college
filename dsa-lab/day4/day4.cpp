#include <iostream>
#include <cstring>
using namespace std;

struct employee{
    int empid;
    char name[20];
    int salary;
    struct employee *next; 
};

struct employee* addemployee(struct employee *emp);
void display(struct employee *emp);
void searchempbyid(struct employee *emp);
void searchempbyname(struct employee *emp);
void highestsalemp(struct employee *emp);

int c = 0;
int main(){
    struct employee *start = NULL;
    int ch;

    cout << "This program was submitted by MD Rashid Hussain 20BCS033\n";
    cout << "Enter your choice as follows:\n1.Add employee.\n";
    cout << "2.Display all employees' data.\n3.Search employee by id.\n";
    cout << "4.Search employee by name.\n";
    cout << "5.Display employee with highest salary.\n6.Total employees.\n7.Exit.\n";

    while (ch != 7){
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch){
            case 1: start=addemployee(start); c++; break;
            case 2: display(start); break;
            case 3: searchempbyid(start); break;
            case 4: searchempbyname(start); break;
            case 5: highestsalemp(start); break;
            case 6: cout << "Total employees: " << c << endl; break;
            case 7: cout << "Program exited.\n"; break;
            default: cout << "Invalid Choice.\n"; break;
        }
    }
    return 0;
}

struct employee* addemployee(struct employee *start){
    struct employee *emp = (struct employee *)malloc(sizeof(struct employee));

    cout << "Enter the details of the employee.\n";
    cout << "Enter employee ID: ";
    cin >> (emp)->empid;
    cin.get();
    cout << "Enter employee name: ";
    cin.getline((emp)->name, 20);
    cout << "Enter employee salary: ";
    cin >> (emp)->salary;
    cout << endl;
    emp->next = start;
    start = emp;
    return start;
}

void display(struct employee *start){
    cout << "Details of all employees...\n";
    cout << "ID\tNAME\tSALARY.\n";
    while (start != NULL){
        cout << (start)->empid << "\t";
        cout << (start)->name << "\t";
        cout << (start)->salary << endl;
        start = start->next;
    }
}

void searchempbyid(struct employee *start){
    int n;
    cout << "Enter the id: ";
    cin >> n;
    while (start != NULL){
        if (start->empid == n){
            cout << "Details of the employee...\n";
            cout << "ID\tNAME\tSALARY\n";
            cout << (start)->empid << "\t";
            cout << (start)->name << "\t";
            cout << (start)->salary << endl;
            break;
        }
        start = start->next;
    }
    if(start==NULL) cout<<"Employee Not found."<<endl;
}

void searchempbyname(struct employee *start){
    int i;
    char name[20];

    cout << "Enter the name: ";
    cin.get();
    cin.getline(name, 20);
    while(start!=NULL){
        if (strcmp(name, start->name) == 0){
            cout << "Details of the employee...\n";
            cout << "ID\tNAME\tSALARY\n";
            cout << (start)->empid << "\t";
            cout << (start)->name << "\t";
            cout << (start)->salary << endl;
            break;
        }
        start=start->next;
    }
    if(start==NULL)
    cout<<"Employee Not found."<<endl;
}

void highestsalemp(struct employee *start){
    int max = 0;
    struct employee *p1=NULL;
    while(start!=NULL){
        if (start->salary >= max){
            max = start->salary;
            p1=start;
        }
        start=start->next;
    }
    if(p1==NULL)
    cout<<"Employee not found"<<endl;
    else{
        cout << "Details of the employee with highest salary.....\n";
        cout << "ID\tNAME\tSALARY\n";
        cout << (p1)->empid << "\t";
        cout << (p1)->name << "\t";
        cout << (p1)->salary << endl;
    }
}