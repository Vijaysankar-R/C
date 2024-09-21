#include<stdio.h>
#define size 15
int main()
{
  int arr[size]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  int i,temp;
  printf("---------------------ARRAY-------------------------------------\n");
  for(i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }
  printf("\n");
  printf("---------------------REVERSE OF ARRAY--------------------------\n");
  for(i=0;i<size/2;i++)
    {
      temp=arr[i];
      arr[i]=arr[size-1-i];
      arr[size-1-i]=temp;
    }
  printf("\n");
  for(i=0;i<size;i++)
    {
      printf("%d\t",arr[i]);
    }
  return 0;
}
