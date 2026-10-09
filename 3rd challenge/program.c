#include<stdio.h>
int main() {
int amount,discount,delivery,final;
int customer,distance,total;

printf("enter amount :");
scanf("%d",&amount);

printf("enter customer type:");
scanf("%d",&customer);

printf("enter distance :");
scanf("%d",&distance);

if(customer==1)
{
if (amount>=2000)
  discount = amount* 15/100;
else
discount= amount*10/100;
}

else
{
if (amount>=3000)
 discount=amount*8/100;
else
discount=0;
}

if (distance<=5)
delivery=40;
else if (distance<=15)
 delivery=70;
else
 delivery=100;

total = amount - discount + delivery;
printf("discount= %d\n", discount);
printf("delivery= %d\n", delivery);
printf("final amount= %d\n", total);

return 0;
}

