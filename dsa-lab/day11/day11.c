#include <stdio.h>
#include <stdlib.h>

struct node
{
  int num;
  struct node *next;
  struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

// function prototypes
void menu();
void insert_at_beginning();
void insert_at_end();
void insert_at_position();
void delete_from_beginning();
void delete_from_end();
void printReverse();
void search();
void display();

int main()
{
  int choice;
  printf("\nThis program is submitted by MD Rashid Hussain, 20BCS033\n");
  menu();

  while (1)
  {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
      menu();
      break;
    case 1:
      insert_at_beginning();
      break;
    case 2:
      insert_at_end();
      break;
    case 3:
      insert_at_position();
      break;
    case 4:
      delete_from_beginning();
      break;
    case 5:
      delete_from_end();
      break;
    case 6:
      printReverse();
      break;
    case 7:
      search();
      break;
    case 8:
      display();
      break;
    case 9:
      printf("\nExiting the program......\n");
      exit(0);
      break;
    default:
      printf("\nInvalid input...... \n");
      break;
    }
  }
  return 0;
}

void menu()
{
  printf("\n===============MENU===============\n");
  printf("Press 1. to Insert at the beginning \n");
  printf("Press 2. to Insert at the end \n");
  printf("Press 3. to Insert at given position \n");
  printf("Press 4. to Delete from Beginning \n");
  printf("Press 5. to Delete from the end \n");
  printf("Press 6. to Print backwards\n");
  printf("Press 7. to Search for an Item \n");
  printf("Press 8. to Display\n");
  printf("Press 9. to Exit the program \n");
  printf("Press 0. to display this help menu \n");
  printf("===================================\n");
}

void insert_at_beginning()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the number to be inserted: ");
  scanf("%d", &newNode->num);
  newNode->next = head;
  newNode->prev = NULL;
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    head->prev = newNode;
    head = newNode;
  }
  display();
}

void insert_at_end()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the number to be inserted: ");
  scanf("%d", &newNode->num);
  newNode->next = NULL;
  newNode->prev = tail;
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
  display();
}

void insert_at_position()
{
  int pos, i = 1;
  struct node *newNode, *temp;
  newNode = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter the position: ");
  scanf("%d", &pos);
  if (pos == 0)
  {
    insert_at_beginning();
    return;
  }
  temp = head;
  while (temp != NULL && i < pos)
  {
    temp = temp->next;
    i++;
  }
  if (temp == NULL)
  {
    printf("\nInvalid Position, so number be added at the end\n");
    insert_at_end();
    return;
  }
  else
  {
    printf("\nEnter the number to be inserted: ");
    scanf("%d", &newNode->num);
    newNode->next = temp;
    newNode->prev = temp->prev;
    (temp->prev)->next = newNode;
    temp->prev = newNode;
  }
  display();
}

void delete_from_beginning()
{
  struct node *temp;
  if (head == NULL)
  {
    printf("\nList is empty\n");
  }
  else
  {
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
  }
  display();
}

void delete_from_end()
{
  struct node *temp;
  if (head == NULL)
  {
    printf("\nList is empty\n");
  }
  else
  {
    temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
  }
  display();
}

void printReverse()
{
  struct node *temp;
  temp = tail;
  while (temp != NULL)
  {
    printf("%d ", temp->num);
    temp = temp->prev;
  }
}

void search()
{
  int item;
  struct node *temp;
  temp = head;
  int pos = 0;
  printf("\nEnter the item to be searched: ");
  scanf("%d", &item);
  while (temp != NULL)
  {
    if (temp->num == item)
    {
      printf("\nItem found at position: %d\n", pos + 1);
      return;
    }
    temp = temp->next;
    pos++;
  }
  printf("\nItem not found\n");
}

void display()
{
  struct node *temp;
  temp = head;
  while (temp != NULL)
  {
    printf("%d ", temp->num);
    temp = temp->next;
  }
}
