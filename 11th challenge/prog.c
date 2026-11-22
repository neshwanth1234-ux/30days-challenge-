
#include <stdio.h>
#define ZONES 5
#define DAYS 7

void inputWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES])
{
int i,j;
for(i=0;i<ZONES;i++)
{
printf("\nZone %d\n",i+1);
do
{
printf("Enter daily target: ");
scanf("%d",&dailyTarget[i]);
}while(dailyTarget[i]<100||dailyTarget[i]>50000);

printf("Enter 7 days consumption: ");
for(j=0;j<DAYS;j++)
{
scanf("%d",&usage[i][j]);
while(usage[i][j]<0||usage[i][j]>50000)
{
printf("Invalid! Enter Day %d again: ",j+1);
scanf("%d",&usage[i][j]);
}
}
}
}

void displayWaterData(int usage[ZONES][DAYS],int dailyTarget[ZONES])
{
int i,j;
char *zones[]={"Academic Block","Hostel","Library","Cafeteria","Sports Complex"};
printf("\nZONE\t\t\t");
for(j=0;j<DAYS;j++)
printf("D%d\t",j+1);
printf("Target\n");
for(i=0;i<ZONES;i++)
{
printf("%-24s",zones[i]);
for(j=0;j<DAYS;j++)
printf("%d\t",usage[i][j]);
printf("%d\n",dailyTarget[i]);
}
}

void calculateZoneStats(int *zoneUsage,int *total,float *average,int *peakUsage,int *peakDay)
{
int i;
*total=0;
*peakUsage=*zoneUsage;
*peakDay=1;
for(i=0;i<DAYS;i++)
{
*total+=*(zoneUsage+i);
if(*(zoneUsage+i)>*peakUsage)
{
*peakUsage=*(zoneUsage+i);
*peakDay=i+1;
}
}
*average=(float)*total/DAYS;
}

void detectWaterAlerts(int *zoneUsage,int dailyTarget,int *overLimitDays,int *totalExcess,int *spikeDays,int *alertDays)
{
int i,over,spike;
*overLimitDays=0;
*totalExcess=0;
*spikeDays=0;
*alertDays=0;
for(i=0;i<DAYS;i++)
{
over=0;
spike=0;
if(*(zoneUsage+i)>dailyTarget)
{
over=1;
(*overLimitDays)++;
*totalExcess+=*(zoneUsage+i)-dailyTarget;
}
if(i>0&&(long long)*(zoneUsage+i)*100>(long long)*(zoneUsage+i-1)*140)
{
spike=1;
(*spikeDays)++;
}
if(over||spike)
(*alertDays)++;
}
}

void generateAuditReport(int usage[ZONES][DAYS],int dailyTarget[ZONES],int excessByZone[ZONES],int overLimitByZone[ZONES],int spikeByZone[ZONES],int alertByZone[ZONES])
{
int i,total,peak,peakDay;
int maxExcess=0;
float average;
printf("\n========== WATER AUDIT REPORT ==========\n");
for(i=0;i<ZONES;i++)
{
calculateZoneStats(&usage[i][0],&total,&average,&peak,&peakDay);
detectWaterAlerts(&usage[i][0],dailyTarget[i],&overLimitByZone[i],&excessByZone[i],&spikeByZone[i],&alertByZone[i]);
printf("\nZone %d\n",i+1);
printf("Weekly Total: %d litres\n",total);
printf("Daily Average: %.2f litres\n",average);
printf("Highest Usage: %d litres\n",peak);
printf("Highest Usage Day: Day %d\n",peakDay);
printf("Over-limit Days: %d\n",overLimitByZone[i]);
printf("Total Excess: %d litres\n",excessByZone[i]);
printf("Spike Days: %d\n",spikeByZone[i]);
printf("Unique Alert Days: %d\n",alertByZone[i]);
if(excessByZone[i]>maxExcess)
maxExcess=excessByZone[i];
}
printf("\nGreatest Excess: %d litres\n",maxExcess);
for(i=0;i<ZONES;i++)
{
if(excessByZone[i]==maxExcess)
printf("Zone %d has the greatest excess.\n",i+1);
}
}

void rankZones(int excessByZone[ZONES])
{
int index[ZONES],i,j,temp;
int rank,previousRank=1;
for(i=0;i<ZONES;i++)
index[i]=i;
for(i=0;i<ZONES-1;i++)
{
for(j=i+1;j<ZONES;j++)
{
if(excessByZone[index[j]]>excessByZone[index[i]])
{
temp=index[i];
index[i]=index[j];
index[j]=temp;
}
}
}
printf("\n========== ZONE RANKING ==========\n");
for(i=0;i<ZONES;i++)
{
rank=i+1;
if(i>0&&excessByZone[index[i]]==excessByZone[index[i-1]])
rank=previousRank;
printf("Rank %d: Zone %d - %d litres\n",rank,index[i]+1,excessByZone[index[i]]);
previousRank=rank;
}
}

void displayConservationActions(int overLimitByZone[ZONES],int spikeByZone[ZONES],int excessByZone[ZONES])
{
int i;
printf("\n========== CONSERVATION ACTIONS ==========\n");
for(i=0;i<ZONES;i++)
{
printf("\nZone %d:\n",i+1);
if(spikeByZone[i]>0)
printf("- Check for leaks or unexpected water use.\n");
if(overLimitByZone[i]>=3)
printf("- Conduct a water audit and reduction plan.\n");
else if(overLimitByZone[i]>0)
printf("- Monitor usage and inspect taps or valves.\n");
if(overLimitByZone[i]==0&&spikeByZone[i]==0)
printf("- Maintain current good practices.\n");
}
}

int main()
{
int usage[ZONES][DAYS],dailyTarget[ZONES];
int excessByZone[ZONES]={0};
int overLimitByZone[ZONES]={0};
int spikeByZone[ZONES]={0};
int alertByZone[ZONES]={0};
int choice,auditReady=0;

printf("===== WATERWISE SYSTEM =====\n");
inputWaterData(usage,dailyTarget);

do
{
printf("\n========== MAIN MENU ==========\n");
printf("1. Display Water Data\n");
printf("2. Generate Audit Report\n");
printf("3. Rank Zones by Excess\n");
printf("4. Conservation Actions\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
displayWaterData(usage,dailyTarget);
break;

case 2:
generateAuditReport(usage,dailyTarget,excessByZone,overLimitByZone,spikeByZone,alertByZone);
auditReady=1;
break;

case 3:
if(auditReady)
rankZones(excessByZone);
else
printf("Generate audit report first!\n");
break;

case 4:
if(auditReady)
displayConservationActions(overLimitByZone,spikeByZone,excessByZone);
else
printf("Generate audit report first!\n");
break;

case 5:
printf("Thank you for using WATERWISE!\n");
break;

default:
printf("Invalid menu choice! Try again.\n");
}
}while(choice!=5);

return 0;
}

