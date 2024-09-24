#include<stdio.h>
#include<stdlib.h>
typedef struct Student_info
{
  int reg_no;
  char *name;
}studinfo_t;
void add(studinfo_t **,int *);
void search(studinfo_t *,int *);
void getall(studinfo_t *,int *);
void freemem(studinfo_t *,int *);
void del(studinfo_t *,int *);
int main()
{
  int num=0;
  int option=0;
  studinfo_t *sinfo=NULL;
  printf("Enter number of Student to store:");
  scanf("%d",&num);
  sinfo=(studinfo_t *)malloc(num*sizeof(studinfo_t));
  if(sinfo==NULL)
  {
    printf("Memory Allocation Failed !!!\n");
  }
  else
  {
    printf("Memory Allocated for sinfo\n");
  }
  for(int i=0;i<num;i++)
  {
    sinfo[i].name=(char *)malloc(50*sizeof(char));
    printf("Enter Student %d reg_no:",i+1);
    scanf("%d",&sinfo[i].reg_no);
    printf("Enter Student %d Name:",i+1);
    scanf( " %49[^\n]",sinfo[i].name);
  }
  while(1)
  {
    printf("1.Add Students 2.Del student 3.Search by ID 4.Display All 5.Exit:");
    scanf("%d",&option);
    switch(option)
    {
      case 1:
      add(&sinfo,&num);
      break;
      case 2:
      del(sinfo,&num);
      break;
      case 3:
      search(sinfo,&num);
      break;
      case 4:
      getall(sinfo,&num);
      break;
      case 5:
      freemem(sinfo,&num);
      return 0;
      default:
      freemem(sinfo,&num);
      return 0;
    }
  }
}
void add(studinfo_t **sinfo,int *num)
{
  int num2=0;
  printf("How many Student do you want to add:");
  scanf("%d",&num2);
  *sinfo=(studinfo_t *)realloc(*sinfo,(*num+num2)*sizeof(studinfo_t));
  if(*sinfo==NULL)
  {
    printf("Reallocation for sinfo Failed !!!\n");
  }
  else
  {
    printf("Reallocation Successful\n");
  }
  for(int i=*num;i<(*num+num2);i++)
  {
    (*sinfo)[i].name=(char *)malloc(50*sizeof(char));
    printf("Enter Student %d reg_no:",i+1);
    scanf("%d",&(*sinfo)[i].reg_no);
    printf("Enter Student %d Name:",i+1);
    scanf(" %49[^\n]",(*sinfo)[i].name);
  }
  *num+=num2;
}
void search(studinfo_t *sinfo,int *num)
{
  int reg_no;
  int found=0;
  printf("Enter Student reg_no to Search:");
  scanf("%d",&reg_no);
  for(int i=0;i<*num;i++)
  {
    if(reg_no==sinfo[i].reg_no)
    {
      printf("Student Id Found\n");
      printf("Student ID:%d\n",sinfo[i].reg_no);
      printf("Student Name:%s\n",sinfo[i].name);
      found=1;
      break;
    }
  }
  if(!found)
  {
    printf("Id Not Found !!!\n");
  }
}
void getall(studinfo_t *sinfo,int *num)
{
  for(int i=0;i<*num;i++)
  {
    printf("Student ID:%d\n",sinfo[i].reg_no);
    printf("Student Name:%s",sinfo[i].name);
    printf("\n==========================================================================================\n");
  }
}
void freemem(studinfo_t *sinfo,int *num)
{
  for(int i=0;i<*num;i++)
  {
    free(sinfo[i].name);
  }
  free(sinfo);
}
void del(studinfo_t *sinfo,int *num)
{
  int id;
  int found=0;
  printf("Enter Student id to Delete:");
  scanf("%d",&id);
  for(int i=0;i<*num;i++)
  {
    if(id==sinfo[i].reg_no)
    {
      found=1;
      free(sinfo[i].name);
      for(int j=i;j<*num;j++)
      {
        sinfo[j]=sinfo[j+1];
      }
      *num-=1;
      sinfo = (studinfo_t *)realloc(sinfo, (*num) * sizeof(studinfo_t));
      if (sinfo == NULL && *num > 0)
      {
      printf("Reallocation failed after deletion!\n");
      }
      printf("Student Deleted Successfully\n");
      break;
    }
  }
  if(!found)
  {
    printf("No Such Student Id Find to Delete\n");
  }
}
