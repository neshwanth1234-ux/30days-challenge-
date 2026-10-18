#include <stdio.h>
#include <math.h>

int main()
{

int choice,n,i,a,b,c,fact;
float x,D,r1,r2;

do
{
printf("\n1.Linear Equation");
printf("\n2.Factorial");
printf("\n3.Quadratic Equation");
printf("\n4.Exit");
printf("\nEnter choice: ");
scanf("%d",&choice);
 
switch(choice)
{
case 1:
printf("Enter a and b: ");   
scanf("%d%d",&a,&b);
if(a!=0)
{
x=(float)-b/a;
printf("x=%f\n",x);
}
else if(b==0)
printf("Infinite solutions\n");
else
printf("No solution\n");
break;
 
case 2:
printf("Enter n (0 to 12): ");
scanf("%d",&n);
if(n<0 || n>12)
printf("Invalid number\n");
else
{
fact=1;
for(i=1;i<=n;i++)
fact=fact*i;
printf("Factorial=%d\n",fact);
}
break;

case 3: 
printf("Enter a, b and c: ");
scanf("%d%d%d",&a,&b,&c);
if(a==0)
printf("Not a quadratic equation\n");
else
{
D=b*b-4*a*c;
if(D>0)
{
r1=(-b+sqrt(D))/(2*a);
r2=(-b-sqrt(D))/(2*a);  
printf("Roots=%f and %f\n",r1,r2);
}
else if(D==0)
{
r1=(float)-b/(2*a);
printf("Equal root=%f\n",r1);
}
else
printf("No real roots\n");
}
break;

case 4:
printf("Program ended\n");
break;

default:
printf("Invalid choice\n");  
}
}while(choice!=4);

return 0;
}

