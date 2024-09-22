#include<stdio.h>
void even(int arr[],int);
void dsc(int arr[],int);
void asc(int arr[],int);
void rr(int arr[],int);
int main()
{
  int len=15;
  int arr[15]={1,2,3,4,5,6,7,8,9,10,2,4,6,8,10};
  even(arr,len);
  dsc(arr,len);
  asc(arr,len);
  rr(arr,len);
  return 0;
}
void even(int arr[],int len)
{
  printf("\nInside Even fn\n");
  int i=0;
  int evenCount=0;
  for(i;i<len;i++)
  {
    if(arr[i]%2==0)
    {
      evenCount++;
    }
  }
  printf("EVEN COUNT:%d",evenCount);
}
void asc(int arr[],int len)
{
  printf("\nInside ASC fn\n");
  int i=0,j=0,temp=0;
  for(i=0;i<len;i++)
  {
    for(j=i+1;j<len;j++)
    {
      if(arr[i]>arr[j])
      {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  printf("\nASCENDING ORDER\n");
  for(i=0;i<len;i++)
  {
    printf("%d\t",arr[i]);
  }
}
void dsc(int arr[],int len)
{
  printf("\nInside DSC fn\n");
  int i=0,j=0,temp=0;
  for(i=0;i<len;i++)
  {
    for(j=i+1;j<len;j++)
    {
      if(arr[i]<arr[j])
      {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  printf("\nDESCENDING ORDER\n");
  for(i=0;i<len;i++)
  {
    printf("%d\t",arr[i]);
  }
}
void rr(int arr[],int len)
{
  printf("\nInside RR fn\n");
  int i,j,k;
  for(i=0;i<len;i++)
  {
    for(j=i+1;j<len;j++)
    {
      if(arr[i]==arr[j])
      {
      for(k=j;k<len-1;k++)
      {
        arr[k]=arr[k+1];
      }
      len--;
      j--;
      }
    }
  }
  printf("\nREMOVE REPETATION\n");
  for(i=0;i<len;i++)
  {
    printf("%d\t",arr[i]);
  }
}
