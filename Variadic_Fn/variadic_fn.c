#include<stdio.h>
#include<stdarg.h>
int fun(int,...);
int main()
{
    fun(5,20,40,60,100,160);
    return 0;
}
int fun(int num,...)
{
    int sum=0;
    va_list args;
    va_start(args,num);
    for(int i=0;i<num;i++)
    {
        sum=sum+va_arg(args,int);
        // printf("%d\n",va_arg(args,int));
    }
    sum=sum/num;
    printf("\n%d",sum);
    va_end(args);
    return 0;
}
