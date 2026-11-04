#include <stdio.h>
#define ROWS 5
#define COLS 8

void initializeSeats(int s[ROWS][COLS]){
int i,j;

for(i=0;i<ROWS;i++)
for(j=0;j<COLS;j++)s[i][j]=0;
}

void displaySeats(int s[ROWS][COLS]){
int i,j;

printf("Seats (0=available, 1=booked):\n");
for(i=0;i<ROWS;i++){
for(j=0;j<COLS;j++)printf("%d ",s[i][j]);
printf("\n");
}
}

int bookSeat(int s[ROWS][COLS],int r,int c){
if(r<1||r>ROWS||c<1||c>COLS||s[r-1][c-1]==1)return 0;
s[r-1][c-1]=1;
return 1;
}

int cancelSeat(int s[ROWS][COLS],int r,int c){
if(r<1||r>ROWS||c<1||c>COLS||s[r-1][c-1]==0)
return 0;
s[r-1][c-1]=0;
return 1;
}

int reserveGroup(int s[ROWS][COLS],int size){
int i,j,k,free;

if(size<2||size>COLS)return 0;
for(i=0;i<ROWS;i++)
for(j=0;j<=COLS-size;j++){
free=1;

for(k=0;k<size;k++)
if(s[i][j+k]){free=0;break;}
if(free){
for(k=0;k<size;k++)s[i][j+k]=1;
printf("Group booked in row %d, seats %d-%d\n",i+1,j+1,j+size);
return 1;
}
}
return 0;
}

void displayReport(int s[ROWS][COLS]){
int i,j,booked=0,count[ROWS]={0},busiest=0;
float occupancy;

for(i=0;i<ROWS;i++){
for(j=0;j<COLS;j++)
if(s[i][j]){booked++;count[i]++;}
if(count[i]>busiest)busiest=count[i];
}

occupancy=(float)booked/(ROWS*COLS)*100;
printf("--- OCCUPANCY REPORT ---\n");
printf("Booked: %d Available: %d\n",booked,ROWS*COLS-booked);
printf("Occupancy: %.2f%%\n",occupancy);
printf("Busiest row(s): ");
if(busiest==0)printf("None");
else for(i=0;i<ROWS;i++)
if(count[i]==busiest)printf("%d ",i+1);
printf("\n");
}

int main(void){
int s[ROWS][COLS],choice,r,c,size;
initializeSeats(s);
do{
printf("\n1. Display seats\n2. Book a seat\n3. Cancel booking\n");
printf("4. Group reservation\n5. Occupancy report\n0. Exit\nChoice: ");
scanf("%d",&choice);

switch(choice){
case 1:displaySeats(s);
break;

case 2:
printf("Enter row and seat: ");scanf("%d%d",&r,&c);
printf(bookSeat(s,r,c)?"Seat booked\n":"Booking failed\n");
break;

case 3:
printf("Enter row and seat: ");scanf("%d%d",&r,&c);
printf(cancelSeat(s,r,c)?"Booking cancelled\n":"Cancellation failed\n");
break;

case 4:
printf("Group size (2-8): ");scanf("%d",&size);
if(!reserveGroup(s,size))
printf("Group booking failed\n");
break;

case 5:displayReport(s);break;
case 0:printf("Goodbye\n");
break;
   
default:printf("Invalid choice\n");
}
}while(choice!=0);  
return 0;
}

