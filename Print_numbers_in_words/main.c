#include<stdio.h>/*include the header file stdio.h*/
int main() /*main function*/
{
  int num;
  int div = 1;
  int rem;
  printf("Enter any Number:\n");
  scanf("%d", &num);/*get number from user*/
  int temp = num;/*make a copy of num to temp*/
  while (temp > 0) /*to find highest power of 10 that is less than or equal to Num.*/
  {
    temp /= 10;
    div *= 10;
  }
  div /= 10;
  while (div > 0)/*extracting and processing each digit*/ 
  {
    rem = num / div;
    num = num % div;
    div /= 10;
    switch (rem) /*switch the remainder to print the corresponding word of the number*/
    {
      case 0:
        printf("Zero\t");
        break;
      case 1:
        printf("One\t");
        break;
      case 2:
        printf("Two\t");
        break;
      case 3:
        printf("Three\t");
        break;
      case 4:
        printf("Four\t");
        break;
      case 5:
        printf("Five\t");
        break;
      case 6:
        printf("Six\t");
        break;
      case 7:
        printf("Seven\t");
        break;
      case 8:
        printf("Eight\t");
        break;
      case 9:
        printf("Nine\t");
        break;
    }
  }
  return 0;/*end of main function*/
}
