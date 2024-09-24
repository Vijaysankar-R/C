#include<stdio.h>
#include<stdlib.h>
typedef struct Employee
{
  int id;
  char *name;
}employee_t;
void getdata(employee_t *,int);
employee_t* add(employee_t **,int *);
void freemem(employee_t *,int num);
int main()
{
  int num;
  int option;
  employee_t *emp;
  printf("Enter Employees:");
  scanf("%d",&num);
  emp=(employee_t *)malloc(num*sizeof(employee_t));
  for(int i=0;i<num;i++)
  {
    emp[i].name=(char *)malloc(50*sizeof(char));
    printf("Enter Employee %d ID:",i+1);
    scanf("%d",&emp[i].id);
    printf("Enter Employee %d Name:",i+1);
    scanf(" %49[^\n]",emp[i].name);
  }
  while(1)
  {
    printf("\n1.Add More 2.Display :\n");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      emp=add(&emp,&num);
      break;
      case 2:
      getdata(emp,num);
      break;
      default:
      return 0;
      break;
    }
  }
  freemem(emp,num);
  return 0;
}
employee_t* add(employee_t **emp,int *num)
{
  int num2;
  printf("Enter no of new emp to add:");
  scanf("%d",&num2);
  *emp=realloc(emp,(*num+num2)*sizeof(employee_t));
  for(int i=*num;i<*num+num2;i++)
  {
    emp[i]->name=(char *)malloc(50*sizeof(char));
    printf("Enter Employee %d ID:",i+1);
    scanf("%d",&emp[i]->id);
    printf("Enter Employee %d Name:",i+1);
    scanf(" %49[^\n]",emp[i]->name);
  }
  *num+=num2;
}
void getdata(employee_t *emp,int num)
{
  for(int i=0;i<num;i++)
  {
    printf("\n======================================================================\n");
    printf("Employee Id:%d\n",emp[i].id);
    printf("Employee name:%s",emp[i].name);
    printf("\n======================================================================\n");
  }
}
void freemem(employee_t *emp,int num)
{
  for(int i=0;i<num;i++)
  {
    free(emp[i].name);
  }
  free(emp);
}
