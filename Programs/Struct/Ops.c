#include<stdio.h>
typedef struct Book
{
  char name[40];
  float price;
  int id;
}book_t;
void putData(book_t *);
void getdata(book_t *);
int main()
{
  book_t arr[5];
  int searchId;
  putData(arr);
  getdata(arr);
  return 0;
}
void putData(book_t *arr)
{
  int i;
  for(i=0;i<5;i++)
  {
    printf("Enter Book %d Name:",i+1);
    getchar();
    scanf("%[^\n]s",arr[i].name);
    printf("Enter Book %d ID:",i+1);
    scanf("%d",&arr[i].id);
    printf("Enter Book %d Price:",i+1);
    scanf("%f",&arr[i].price);
    printf("\n=====================================================================================\n");
  }
}
void getdata(book_t *arr)
{
  int i;
  int isfound=0;
  int searchId;
  printf("\nEnter the Book ID to search:");
  scanf("%d",&searchId);
  for(i=0;i<5;i++)
  {
    if(searchId==arr[i].id)
    {
    isfound=1;
    printf("*****Book Found******\n");
    printf("Book Name: %s\n",arr[i].name);
    printf("Book ID: %d\n",arr[i].id);
    printf("Book Price: %.2f\n",arr[i].price);
    break;
    }
  }
  if(!isfound)
  {
    printf("!!!!Sorry Book Id Not Match!!!!");
    getdata(arr);
  }
}
