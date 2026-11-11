#include <stdio.h>
#define ZONES 5
#define DAYS 7
void inputData(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS]);
void displayData(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS]);
void calculateAverages(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS],
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES]);
void detectRiskZones(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS],
int riskDays[ZONES]);
void computeGreenIndex(
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES],
float greenIndex[ZONES]);
void displayRanking(float greenIndex[ZONES]);
void displayRecommendations(
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES],
int riskDays[ZONES]);
void inputData(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS])
{
    int z,d;
    printf("Enter readings. Label simulated readings as sample data.\n");
    for(z=0;z<ZONES;z++){
        printf("\nZone %d\n",z+1);
        for(d=0;d<DAYS;d++){
            do{
                printf("Day %d temperature (10-50 C): ",d+1);
                scanf("%f",&temp[z][d]);
            }while(temp[z][d]<10||temp[z][d]>50);
            do{
                printf("Humidity (0-100%%): ");
                scanf("%f",&humidity[z][d]);
            }while(humidity[z][d]<0||humidity[z][d]>100);
            do{
                printf("AQI (0-500): ");
                scanf("%d",&aqi[z][d]);
            }while(aqi[z][d]<0||aqi[z][d]>500);
        }
    }
}
void displayData(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS])
{
    int z,d;
    printf("\nReadings (simulated values are sample data):\n");
    for(z=0;z<ZONES;z++){
        printf("\nZone %d\nDay  Temperature  Humidity  AQI\n",z+1);
        for(d=0;d<DAYS;d++)
            printf("%d    %.1f C       %.1f%%      %d\n",
                   d+1,temp[z][d],humidity[z][d],aqi[z][d]);
    }
}
void calculateAverages(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS],
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES])
{
    int z,d;
    for(z=0;z<ZONES;z++){
        avgTemp[z]=avgHumidity[z]=avgAqi[z]=0;
        for(d=0;d<DAYS;d++){
            avgTemp[z]+=temp[z][d];
            avgHumidity[z]+=humidity[z][d];
            avgAqi[z]+=aqi[z][d];
        }
        avgTemp[z]/=DAYS;
        avgHumidity[z]/=DAYS;
        avgAqi[z]/=DAYS;
    }
}
void detectRiskZones(
float temp[ZONES][DAYS],
float humidity[ZONES][DAYS],
int aqi[ZONES][DAYS],
int riskDays[ZONES])
{
    int z,d;
    printf("\nRisk days (each day counted once):\n");
    for(z=0;z<ZONES;z++){
        riskDays[z]=0;
        printf("Zone %d: ",z+1);
        for(d=0;d<DAYS;d++){
            if(aqi[z][d]>150||temp[z][d]>35||humidity[z][d]>80){
                printf("Day %d ",d+1);
                riskDays[z]++;
            }
        }
        if(riskDays[z]==0)printf("No risk days");
        printf("(total: %d)\n",riskDays[z]);
    }
}
void computeGreenIndex(
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES],
float greenIndex[ZONES])
{
    int z;
    for(z=0;z<ZONES;z++){
        float dt=avgTemp[z]-25;
        float dh=avgHumidity[z]-50;
        float aqScore,tempScore,humidityScore;
        if(dt<0)dt=-dt;
        if(dh<0)dh=-dh;
        aqScore=100-avgAqi[z]/5;
        tempScore=100-4*dt;
        humidityScore=100-2*dh;
        if(aqScore<0)aqScore=0;
        if(tempScore<0)tempScore=0;
        if(humidityScore<0)humidityScore=0;
        greenIndex[z]=0.4f*aqScore+0.3f*tempScore+0.3f*humidityScore;
    }
}
void displayRanking(float greenIndex[ZONES])
{
    int z,other,rank;
    printf("\nGreen Index ranking (higher is better):\n");
    for(z=0;z<ZONES;z++){
        rank=1;
        for(other=0;other<ZONES;other++)
            if(greenIndex[other]>greenIndex[z])rank++;
        printf("Zone %d: %.2f, rank %d\n",z+1,greenIndex[z],rank);
    }
}
void displayRecommendations(
float avgTemp[ZONES],
float avgHumidity[ZONES],
float avgAqi[ZONES],
int riskDays[ZONES])
{
    int z;
    for(z=0;z<ZONES;z++){
        printf("Zone %d: ",z+1);
        if(avgAqi[z]>150)printf("Reduce vehicle idling or improve ventilation. ");
        if(avgTemp[z]>35)printf("Add shade or green cover. ");
        if(avgHumidity[z]>80)printf("Check ventilation or stagnant water. ");
        if(avgAqi[z]<=150&&avgTemp[z]<=35&&avgHumidity[z]<=80){
            if(riskDays[z]>0)printf("Review flagged days.");
            else printf("Continue monitoring.");
        }
        printf("\n");
    }
}
int main(void)
{
    float temp[ZONES][DAYS],humidity[ZONES][DAYS];
    float avgTemp[ZONES],avgHumidity[ZONES],avgAqi[ZONES],greenIndex[ZONES];
    int aqi[ZONES][DAYS],riskDays[ZONES];
    int choice,dataReady=0,z;
    do{
        printf("\n1 Input  2 Display  3 Averages  4 Risk days\n");
        printf("5 Green Index/Ranking  6 Recommendations  7 Exit\nChoice: ");
        if(scanf("%d",&choice)!=1){
            printf("Enter a menu number.\n");
            while(getchar()!='\n'){}
            continue;
        }
        switch(choice){
            case 1:
                inputData(temp,humidity,aqi);
                dataReady=1;
                break;
            case 2:
                if(dataReady)displayData(temp,humidity,aqi);
                else printf("Enter data first.\n");
                break;
            case 3:
                if(dataReady){
                    calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAqi);
                    for(z=0;z<ZONES;z++)
                        printf("Zone %d: %.1f C, %.1f%% humidity, AQI %.1f\n",
                               z+1,avgTemp[z],avgHumidity[z],avgAqi[z]);
                }else printf("Enter data first.\n");
                break;
            case 4:
                if(dataReady)detectRiskZones(temp,humidity,aqi,riskDays);
                else printf("Enter data first.\n");
                break;
            case 5:
                if(dataReady){
                    calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAqi);
                    computeGreenIndex(avgTemp,avgHumidity,avgAqi,greenIndex);
                    displayRanking(greenIndex);
                }else printf("Enter data first.\n");
                break;
            case 6:
                if(dataReady){
                    calculateAverages(temp,humidity,aqi,avgTemp,avgHumidity,avgAqi);
                    detectRiskZones(temp,humidity,aqi,riskDays);
                    displayRecommendations(avgTemp,avgHumidity,avgAqi,riskDays);
                }else printf("Enter data first.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Enter 1 to 7.\n");
        }
    }while(choice!=7);
  return 0;
}
