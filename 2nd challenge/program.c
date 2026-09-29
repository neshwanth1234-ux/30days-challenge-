#include <stdio.h>
int main()
{
float distance,milage,price;
float fuel,cost;

printf("enter distance: ");
scanf("%f", &distance);

printf("enter milage: ");
scanf("%f", &milage);

printf("enter price: ");
scanf("%f", &price);

fuel=distance/milage;
cost=fuel*price;

printf("fuel required=%f\n", fuel);
printf("total cost=%f", cost);

return 0;
}
