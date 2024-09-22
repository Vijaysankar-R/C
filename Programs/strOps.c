#include<stdio.h>
#include<stdlib.h>
void copy(char *,const char *);
void compare(const char *,const char *);
void reverse(const char *,char *);
void rms(const char *,char *);
int main()
{
  int len=0;
  char *str="VIJAYSANKAR R";
  printf("\n***String***\n");
  puts(str);
  while(str[len]!='\0')
  {
    len++;
  }
  printf("\nLength of String: %d\n",len);
  char *cpstr=(char *)malloc(len+1);
  copy(cpstr,str);
  printf("\n***Copied String***\n");
  puts(cpstr);
  printf("\n***Comparing Strings***\n");
  compare(str,cpstr);
  char *revstr=(char *)malloc(len+1);
  printf("\n***Reversing the String***\n");
  reverse(cpstr,revstr);
  puts(revstr);
  char *strws=(char *)malloc(len+1);
  rms(str,strws);
  printf("\n***String Without Space***\n");
  puts(strws);
  free(cpstr);
  free(revstr);
  free(strws);
  return 0;
}
void copy(char *cpstr,const char *str)
{
  int i=0;
  while(str[i]!='\0')
  {
    cpstr[i]=str[i];
    i++;
  }
  cpstr[i]='\0';
}
void compare(const char *str,const char *cpstr)
{
  int i=0,isequal=1;
  while(str[i]!=0)
  {
    if(str[i]!=cpstr[i])
    {
      isequal=0;
      break;
    }
    i++;
  }
  if(isequal)
  {
    printf("Both Strings Are Equal");
  }
  else
  {
    printf("Strings are Not Equal");
  }
}
void reverse(const char *cpstr,char *revstr)
{
  int i=0,len=0;
  while(cpstr[i]!='\0')
  {
    len++;
    i++;
  }
  for(i=0;i<len;i++)
  {
    revstr[i]=cpstr[len-1-i];
  }
  revstr[i]='\0';
}
void rms(const char *str,char *strws)
{
  int i=0,k=0;
  while(str[i]!='\0')
  {
    if(str[i]!=' ')
    {
      strws[k]=str[i];
      k++;
    }
    i++;
  }  
  strws[k]='\0';
}
