#include<stdio.h>
int main()
{
double weight,height,BMI;

printf("enter weight and height");
scanf("%lf%lf",&weight,&height);
  BMI=(703*weight)/(height*height);
  printf("%lf",BMI);

if(BMI<18.5)
   printf("Under weight");


else if(BMI>18.5 && BMI<24.9)
   printf("Normal");

else if(BMI>25.0 && BMI<29.9)
   printf("Over weight");

else if(BMI>30.0)
   printf("Obese");
}
