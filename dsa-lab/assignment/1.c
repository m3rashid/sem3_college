#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node *next;
} *start, *ptr, *p, *header;

// function prototypes
void insert_at_beginning();
void insert_at_end();
void insert_at_position();
void delete_from_beginning();
void delete_from_end();
void delete_from_position();
void search();
void sum();
void display();
void maximum();
void total_number();


int main(){
    int choice;
    header = (struct node*)malloc(sizeof(struct node));
    header->next = NULL;
    header->num = 0;
    start = header;
    printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033\n\n");
    printf("===============MENU===============\n");
    printf("Press 1. to Insert at the beginning \n");
    printf("Press 2. to Insert at the end \n");
    printf("Press 3. to Insert at given position \n");
    printf("Press 4. to Delete from Beginning \n");
    printf("Press 5. to Delete from the end \n");
    printf("Press 6. to Delete from the given position \n");
    printf("Press 7. to show total number of elements \n");
    printf("Press 8. to Sum elements \n");
    printf("Press 9. to Search for an Item \n");
    printf("Press 10. to find Maximum Number in linked list \n");
    printf("Press 11. to Display the linked list \n");
    printf("Press 12. to Exit the program \n");

    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert_at_beginning(); break;
            case 2: insert_at_end(); break;
            case 3: insert_at_position(); break;
            case 4: delete_from_beginning(); break;
            case 5: delete_from_end(); break;
            case 6: delete_from_position(); break;
            case 7: total_number(); break;
            case 8: sum(); break;
            case 9: search(); break;
            case 10: maximum(); break;
            case 11: display(); break;
            case 12: printf("\nExiting the program......\n"); exit(0); break;
            default: printf("\nInvalid input...... \n"); break;
        }
    }
    return 0;
}


void insert_at_beginning(){
    int val;
    printf("Enter number to be inserted: ");
    scanf("%d", &val);
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory not allocated \n");
        return;
    }
    ptr->num = val;
    ptr->next = NULL;
    if(header->num == 0){
        header->next = ptr;
        header->num = 1;
    }
    else{
        ptr->next = header->next;
        header->next = ptr;
        header->num = header->num+1;
    }
}

void insert_at_end(){
    int val;
    printf("Enter number to be inserted: ");
    scanf("%d", &val);
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory not allocated \n");
        return;
    }
    ptr->num = val;
    ptr->next = NULL;
    if(header->num == 0){
        header->next = ptr;
        header->num = 1;
    }
    else{
        p = header->next;
        while(p->next != NULL)
        p = p->next;
        p->next = ptr;
        header->num = header->num + 1;
    }
}

void insert_at_position(){
    int val, pos, i;
    printf("Enter number to be inserted: ");
    scanf("%d", &val);
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("Memory not allocated \n");
        return;
    }
    ptr->num = val;
    ptr->next = NULL;
    printf("Enter insertion position: ");
    scanf("%d", &pos);
    if(header->num == 0){
        header->next = ptr;
        header->num = 1;
        printf("This is the first element \n");
    }
    else{ 
        i = 0;
        p = header;
        while(i != (pos-1)){ 
            p = p->next;
            if(p == NULL) break;
            i++;
        }
       if(i < pos-1) printf("position out of range \n");
       else{ 
            ptr->next = p->next;
            p->next = ptr;
            header->num = header->num + 1;
        }
    }
}

void delete_from_beginning(){
    if(header->num == 0) printf("\nUnderflow....\n");
    else{
        p = header->next;
        printf("deleted element: %d\n", p->num);
        header->next = p->next;
        header->num = header->num-1;
    }
}

void delete_from_end(){
    if(header->num == 0) printf("\n Underflow....\n");
    else{  
        int i = 0;
        p = start;
        while(i != header->num - 1){ 
            p = p->next;
            i++;
        }
        ptr = p->next;
        printf("deleted element: %d \n", ptr->num);
        p->next = NULL;
        header->num = header->num-1;
    }
}

void delete_from_position(){
    if(header->num == 0) printf("\nUnderflow\n");
    else{  
        int i = 0,pos;
        p = header;
        printf("Enter deletion position: ");
        scanf("%d", &pos);
        while(i != pos - 1){ 
            p = p->next;
            if(p->next == NULL) break;
            i++;
        }
        if(i == pos - 1){
            ptr = p->next;
            printf("deleted element: %d \n", ptr->num);
            p->next = ptr->next;
            header->num = header->num-1;
        }
        else printf("Position out of range\n");
    }
}

void search(){
    if(header->num == 0) printf("\nThe Linked list is empty....\n");
    else{
        int s, i = 1, flag = 0;
        printf("Enter number to be searched: ");
        scanf("%d", &s);
        ptr = header->next;
        while(ptr != NULL){
            if(ptr->num == s){
                printf("Element found at position: %d \n", i);
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if(flag == 0) printf("\nElement not found \n");
    }
}

void sum(){   
    int sum = 0;
    if(header->num == 0) printf("\nLinked list empty\n");
    else{
        ptr = header->next;
        while(ptr != NULL){
            sum = sum+ptr->num;
            ptr = ptr->next;
        }
        printf("Sum: %d \n", sum);
    }
}

void display(){
    if(header->num == 0) printf("\nLinked list empty\n");
    else{
        printf("\nElements in the list are : \n");
        ptr = header->next;
        while(ptr != NULL){
            printf("%d => ", ptr->num);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void maximum(){
   if(header->num == 0) printf("\nLinked list empty\n");
   else{
       int no;
       ptr = header->next;
       no = ptr->num;
       while(ptr != NULL){
           if(ptr->num > no) no = ptr->num;
           ptr = ptr->next;
       }
       printf("Maximum Element: %d\n", no);
   }
}

void total_number(){
  printf("Total number of elements: %d \n", header->num);
}
