#include<stdio.h>
void rotate(int a[],int n,int k)
{

int i,j,temp;
k=k%n;

if(k<0)k+=n;
for(j=0;j<k;j++)
{

temp=a[n-1];
for(i=n-1;i>0;i--)
a[i]=a[i-1];
a[0]=temp;
}
}

int main()
{
int a[12],n,i,k,r,d;
int sum=0,min,max,second=0,found=0;
int peaks=0,run=1,longest=1,count=0;
float avg;

do
{
printf("Enter N (5 to 12): ");
scanf("%d",&n);
if(n<5 || n>12)
printf("invalid input. try again.\n");
}while(n<5 || n>12);


for(i=0;i<n;i++)
{
do
{
printf("Enter reading (0 to 1000): ");
scanf("%d",&a[i]);
if(a[i]<0 || a[i]>1000)
printf("Invalid reading. Try again.\n");
}while(a[i]<0 || a[i]>1000);
}


printf("Original readings: ");
min=max=a[0];
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
sum+=a[i];
if(a[i]<min)min=a[i];
if(a[i]>max)max=a[i];
}
avg=(float)sum/n;
printf("\nSum=%d",sum);
printf("\nAverage=%f",avg);
printf("\nMinimum=%d",min);
printf("\nMaximum=%d",max);

for(i=0;i<n;i++)
{
if(a[i]<max&&(found==0||a[i]>second))
{
second=a[i];
found=1;
}
}

if(found)printf("\nSecond largest=%d",second);
else printf("\nNo second-largest distinct value");

for(i=1;i<n-1;i++)
if(a[i]>a[i-1]&&a[i]>a[i+1])peaks++;
for(i=1;i<n;i++)
{
if(a[i]>a[i-1])run++;
else run=1;
if(run>longest)longest=run;
}
printf("\nLocal peaks=%d",peaks);
printf("\nLongest increasing run=%d",longest);
while(1)
{
printf("\nEnter K: ");
if(scanf("%d",&k)==1)break;
printf("Invalid input. Try again.\n");
while(getchar()!='\n');
}

rotate(a,n,k);
printf("Rotated readings: ");
for(i=0;i<n;i++)printf("%d ",a[i]);
while(1)
{
printf("\nEnter R (0 to 99): ");
if(scanf("%d",&r)==1&&r>=0&&r<=99)break;
printf("Invalid input. Try again.\n");
while(getchar()!='\n');
}

d=(r%9)+1;
for(i=0;i<n;i++)
if(a[i]%d==0)count++;
printf("\nD=%d",d);

printf("\nDivisible count=%d\n",count);
 
return 0;
}

 
