//A student has for five subjects. Write a C program to read the marks of all five subjectds and calculate the total marks,average marks,
and percentage.Display all three results clearly.

  #include<stdio.h>
int main()
{
int sub1,sub2,sub3,sub4,sub5;
float total,average,percentage;
printf("enter the marks for 5 subjects:");
scanf("%d %d %d %d %d",&sub1,&sub2,&sub3,&sub4,&sub5);
total=sub1+sub2+sub3+sub4+sub5;
average=total/5;
percentage=(total/500)*100;
printf("total marks=%f\n",total);
printf("average marks=%f\n",average);
printf("percentage=%f\n",percentage);
return 0;
}

