#include<stdio.h>
#include<stdlib.h>
typedef struct Employee
{
  int id;
  char *name;
  char *dept;
  double salary;
}employee;
void getdata(employee *,int);
void search(employee *,int,int);
employee* addmore(employee *, int *, int);
int main()
{
  employee *emp;
  int num1=0;
  int newcount=0;
  int id=0;
  int option=0;
  printf("Enter Number of Employees to store the data:");
  scanf("%d",&num1);
  emp=(employee *)malloc(num1*sizeof(employee));
  if(emp==NULL)
  {
    printf("Memory Allocation Failed");
  }
  for(int i=0;i<num1;i++)
  {
    emp[i].name=(char *)malloc(50*sizeof(char));
    emp[i].dept=(char *)malloc(50*sizeof(char));
    printf("Enter Employee id:");
    scanf("%d",&emp[i].id);
    printf("Enter Employee name:");
    scanf("%49s",emp[i].name);
    printf("Enter Employee dept:");
    scanf("%49s",emp[i].dept);    
    printf("Enter Employee Salary:");
    scanf("%lf",&emp[i].salary);
  }
  while(1)
  {
    printf("MENU 1.Addmore Employees 2.Display All Employees 3.Search by ID 4.exit:");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      printf("Enter the no of new employees to add:");
      scanf("%d",&newcount);
      emp = addmore(emp, &num1, newcount);
      break;
      case 2:
      getdata(emp,num1);
      break;
      case 3:
      printf("Enter ID to Search:");
      scanf("%d",&id);
      search(emp,id,num1);
      break;
      case 4:
      for (int i = 0; i < num1; i++) 
      {
        free(emp[i].name);
        free(emp[i].dept);
      }
      free(emp);
      return 0;
      break;
      default:
      printf("Invalid Option !!!");
      return 0;
  }
  }
}
employee* addmore(employee *emp, int *num1,int newcount)
{
  emp = realloc(emp, (*num1 + newcount) * sizeof(employee));
  for(int i=*num1;i<*num1+newcount;i++)
  {
    emp[i].name=(char *)malloc(50*sizeof(char));
    emp[i].dept=(char *)malloc(50*sizeof(char));
    printf("Enter Employee id:");
    scanf("%d",&emp[i].id);
    printf("Enter Employee name:");
    scanf("%49s",emp[i].name);
    printf("Enter Employee dept:");
    scanf("%49s",emp[i].dept);    
    printf("Enter Employee Salary:");
    scanf("%lf",&emp[i].salary);
  }
  *num1 += newcount;
  return emp;
}
void search(employee *emp,int id,int num1)
{
  int found=0;
  for(int i=0;i<num1;i++)
  {
    if(id==emp[i].id)
    {
      found=1;
      printf("************Match Found**************\n");
      printf("Employee id: %d\n",emp[i].id);
      printf("Employee name: %s\n",emp[i].name);
      printf("Employee dept: %s\n",emp[i].dept);
      printf("Employee Salary: %lf\n",emp[i].salary);
      break;
    }
  }
  if(!found)
    {
      printf("\n!!!!!!!!!!!!No Match Found!!!!!!!!!!!!!\n");
    }
}
void getdata(employee *emp,int num1)
{
  for(int i=0;i<num1;i++)
  {
    printf("\n=================================================================================\n");
    printf("Employee id: %d\n",emp[i].id);
    printf("Employee name: %s\n",emp[i].name);
    printf("Employee dept: %s\n",emp[i].dept);
    printf("Employee Salary: %lf\n",emp[i].salary);
  }
}
