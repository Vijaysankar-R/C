#include<stdio.h>
int main()
{
  int myInt;
  float myFloat;
  printf("Enter any Integer:");
  scanf("%d",&myInt);
  printf("Enter any Float:");
  scanf("%f",&myFloat);
  printf("The size of %d is %lld\n",myInt,sizeof(myInt));
  printf("The size of %f is %lld\n",myFloat,sizeof(myFloat));
}
