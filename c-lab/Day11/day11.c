#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Complex{
  float realNum, imagNum;
};

struct Complex allNums[2];

float inputNumbers[4];

float stringToFloat(char *string);
void menu();
struct Complex inputfun(char *input);
void add(struct Complex[]);
void subtract(struct Complex[]);
void multiply(struct Complex[]);
void divide(struct Complex[]);

int main(){
  printf("This program is submitted by MD Rashid Hussain, 20BCS033\n");
  menu();

  char inputNumber[100];
  printf("\nEnter the numbers: ");
  scanf(" %[^\n]s", inputNumber);

  // split while space
  char num1[50], num2[50];
  int flag = 0;
  int iter1 = 0;
  int iter2 = 0;
  for(int i=0; inputNumber[i] != '\0'; i++){
    if(inputNumber[i] == ' '){ 
      flag = 1; 
      i++; 
    }
    if(flag){
      num2[iter2++] = inputNumber[i];
    }
    else{
      num1[iter1++] = inputNumber[i];
    }
  }
  num1[iter1] = '\0';
  num2[iter2] = '\0';

  allNums[0] = inputfun(num1);
  allNums[1] = inputfun(num2);

  int choice;
  while(1) {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1: add(allNums); break;
      case 2: subtract(allNums); break;
      case 3: multiply(allNums); break;
      case 4: divide(allNums); break;
      case 5: menu(); break;
      case 6: printf("\nExiting the program...\n"); exit(0); break;
      default: printf("\nInvalid Input");
    }
  }
  return 0;
}

void menu(){
  printf("\n===============MENU===============\n");
  printf("Press 1 to add two complex numbers.\n");
  printf("Press 2 to subtract two complex numbers.\n");
  printf("Press 3 to multiply two complex numbers.\n");
  printf("Press 4 to divide two complex numbers.\n");
  printf("Press 5 to show this menu");
  printf("Press 6 to exit.\n");
  printf("Enter your choice\n");
}

float stringToFloat(char *string){
  float result = 0.0;
  int len = strlen(string);
  int dotPosition = 0;

  for (int i = 0; i < len; i++){
    if (string[i] == '.') dotPosition = len - i - 1;
    else result = result * 10.0 + (string[i] - '0');
  }
  while (dotPosition--) result /= 10.0;
  return result;
}

struct Complex inputfun(char *input){
  int signs[2] = {1, 1};
  char real[25];
  char imag[25];
  int i=0;
  if(input[0] == '-'){
    signs[0] = -1;
    i = 1;
  }
  int iter = 0;
  while(input[i] != '\0'){
    if(input[i] == '+' || input[i] == '-') break;
    real[iter++] = input[i];
    i++;
  }
  if(input[i] == '-'){
    signs[1] = -1;
  }
  i++;
  real[iter] = '\0';
  iter = 0;
  while(input[i] != '\0'){
    if(input[i] == 'i' || input[i] == 'j') break;
    imag[iter++] = input[i];
    i++;
  }
  imag[iter] = '\0';
  
  struct Complex num;
  num.realNum = stringToFloat(real)*signs[0];
  num.imagNum = stringToFloat(imag)*signs[1];
  return num;
}

void add(struct Complex nums[]){
  printf("\nThe addition of the numbers is: %.4f + %.4fi", nums[0].realNum + nums[1].realNum, nums[0].imagNum + nums[1].imagNum);
}

void subtract(struct Complex nums[]){
  printf("\nThe subtraction of the numbers is: %.4f + %.4fi", nums[0].realNum - nums[1].realNum, nums[0].imagNum - nums[1].imagNum);
}

void multiply(struct Complex nums[]){
  struct Complex c;
  c.realNum = nums[0].realNum * nums[1].realNum - nums[0].imagNum * nums[1].imagNum;
  c.imagNum = nums[0].imagNum * nums[1].realNum + nums[0].realNum * nums[1].imagNum;  
  printf("\nThe multiplication of the numbers is: %.4f + %.4fi", c.realNum, c.imagNum);
}

void divide(struct Complex nums[]){
  if (nums[1].realNum == 0.0 && nums[1].imagNum == 0.0){
    printf("\nDivision by 0 + 0i isn't allowed.");
    return;
  }
  struct Complex conjugate;
  conjugate.realNum = nums[1].realNum;
  conjugate.imagNum = -nums[1].imagNum;

  struct Complex c;
  c.realNum = nums[0].realNum * conjugate.realNum - nums[0].imagNum * conjugate.imagNum;
  c.imagNum = nums[0].imagNum * conjugate.realNum + nums[0].realNum * conjugate.imagNum;

  float mod = (nums[1].realNum * nums[1].realNum) + (nums[1].imagNum * nums[1].imagNum);

  c.realNum /= mod;
  c.imagNum /= mod;
  printf("\nThe division of the numbers is: %.4f + %.4fi", c.realNum, c.imagNum);
}
