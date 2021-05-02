#include<stdio.h>

struct _retire_info
{
  int months;
  double contribution, rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement (int startAge, double initial, retire_info working, retire_info retired)
{
  double current_balance = initial;
  int age = startAge/12;
  int month = startAge - (12*age);
  printf("Age %3d month %2d you have $%.2f\n", age, month, current_balance);
  for (int i = 0; i<working.months; i++)
    {
      if (month<11)
	{month ++;}
      else if (month>=11)
	{month = 0;age++;}
      current_balance += (current_balance*working.rate_of_return)+working.contribution;
      printf("Age %3d month %2d you have $%.2f\n", age, month, current_balance);


    }


  for (int  j = 0; j <retired.months-1; j++)
    {
      if (month<11)
	{month ++;}
      else if (month>=11)
	{month = 0;age++;}
      current_balance += (current_balance*retired.rate_of_return)+retired.contribution;
      printf("Age %3d month %2d you have $%.2f\n", age, month, current_balance);

    }

}
int main()
{
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(327,21345,working,retired);
}
