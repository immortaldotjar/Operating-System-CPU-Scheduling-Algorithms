#include<stdio.h>
#define MAX 30 //maximum size is 30

int main()
{
    // declaring variables
    int n,BT[MAX],WT[MAX],TAT[MAX],i,j;
    float avg_WT = 0,avg_TAT = 0;

    //Taking the number of process from user
    printf("Enter the number of processes to be executed[MAX. Processes = 30] : ");
    scanf("%d",&n);

    //Taking Burst Time for the processes from user
    printf("\nEnter the Burst Time for processes :\n");
    for(i = 0;i < n;i++)
    {
        printf("Process [%d] : ",i + 1);
        scanf("%d",&BT[i]);
    }

    WT[0] = 0; //initiallized as zero

    //calculating waiting time
    for(i = 1;i < n;i++)
    {
        WT[i] = 0;
        for(j = 0;j < i;j++)
        {
            WT[i] += BT[j];
        }
    }

    //Printing the calulated Waiting Time and Turn Around Time
    printf("\nProcess\t|\tBurst Time\t|\tWaiting Time\t|\tTurn Around Time");
    for(i = 0;i < n;i++)
    {
        TAT[i] = BT[i] + WT[i];
        avg_WT += WT[i];
        avg_TAT += TAT[i];

        printf("\nP[%d]\t|\t\t%d\t|\t\t%d\t|\t%d",i + 1,BT[i],WT[i],TAT[i]);
    }

    avg_WT /= i; //Average of Wating Time
    avg_TAT /= i; //Average of Total Around Time

    printf("\n\nAverage Waiting Time : %f",avg_WT);
    printf("\nAverage Turn Around Time : %f",avg_TAT);

    return 0;
}