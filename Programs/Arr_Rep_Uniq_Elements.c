#include<stdio.h>
int main()
{
  int arr[10]={10,20,50,20,30,60,10,40,20,80};
  int uni[10];
  int uniCount=0;
  int repCount=0;
  printf("\n--------------ARRAY ELEMENTS---------------------\n");
  for(int i=0;i<10;i++)
  {
    printf("\t%d",arr[i]);
  }
  for(int i=0;i<10;i++)
  {
    int isuniq=1;
    for(int j=0;j<uniCount;j++)
    {
      if(arr[i]==uni[j])
      {
        isuniq=0;
        break;
      }
    }
    if(isuniq)
    {
      uni[uniCount]=arr[i];
      uniCount++;
    }
    else
    {
      repCount++;
    }
  }
  printf("\n--------------UNIQUE ELEMENTS---------------------\n");
  for(int i=0;i<uniCount;i++)
  {
    printf("\t%d",uni[i]);
  }
  printf("\nRedudant Elements Count:%d",repCount);
  printf("\nUnique Elements Count:%d",uniCount);
  return 0;
}
