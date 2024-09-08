#include<stdio.h>/*include the header file stdio*/
#define READ(VAL,POS) (VAL&POS)/*macros to read,set,reset bits*/
#define SET(VAL,POS) (VAL|=POS)
#define RESET(VAL,POS) (VAL&=~(POS))
int main()/*main function*/
{
  unsigned char myVar;
  printf("Enter any Number from 0-255:");
  scanf("%hhd",&myVar);
  if(READ(myVar,1))/*check if ignition on*/
  {
    SET(myVar,64);/*ignition status on*/
    printf("IGNITION ON\n");
  }
  else/*ignition status off*/
  {
    printf("IGNITION OFF\n");
    RESET(myVar,64);
  }
  if(READ(myVar,2))/*check right indicator is on*/
  {
    printf("RIGHT INDICATOR ON\n");
    SET(myVar,32);/*right indicator switch on*/
  }
  else/*right indicator switch off*/
  {
    RESET(myVar,32);/*right indicator status off*/
    printf("RIGHT INDICATOR OFF\n");
  }
  if(READ(myVar,4))/*check left indicator is on*/
  {
    printf("LEFT INDICATOR ON\n");
    SET(myVar,128);/*left indicator switch on*/
  }
  else/*left indicator switch off*/
  {
    RESET(myVar,128);/*left indicator status off*/
    printf("LEFT INDICATOR OFF\n");
  }
  if(READ(myVar,2)>0&&READ(myVar,4)>0)/*check is both indicators are on*/
  {
    printf("PARKING STATUS ON\n");/*means parking status*/
  }
  if(READ(myVar,1)==0)/*check ignition is off*/
  {
    RESET(myVar,32);/*if ignition is off*/
    RESET(myVar,128);/*then both indicator status are off*/
  }
  printf("Number after Modification:%d\n",myVar);
  return 0;
}
