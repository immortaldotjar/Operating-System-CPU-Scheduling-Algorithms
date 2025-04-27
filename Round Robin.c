#include<stdio.h>
#define MAX 10

int main()
{
    int cnt,n,t,remain,timeQuantum,flag = 0,WT = 0,TAT = 0,AT[MAX],BT[MAX],RT[MAX];
    printf("Enter total number of Processes : "); 
    scanf("%d",&n);

    remain = n;

    for(cnt = 0;cnt < n;cnt++)
    {
        printf("Enter Arrival Time and Burst Time for Process %d\n", cnt + 1);
        
        printf("AT : "); 
        scanf("%d",&AT[cnt]);
        printf("BT : "); 
        scanf("%d",&BT[cnt]);

        RT[cnt] = BT[cnt];
    }

    printf("Enter Time Quantum : ");
    scanf("%d",&timeQuantum);

    printf("\n\nProcess\t|\tTurnaround Time\t\t|\tWaiting Time\n\n"); 

    for(t = 0, cnt = 0; remain != 0;)
    {
        if(RT[cnt] <= timeQuantum && RT[cnt] > 0)
        {
            t += RT[cnt];
            RT[cnt] = 0;
            flag = 1;
        }
        else if(RT[cnt] > 0)
        {
            RT[cnt] -= timeQuantum;
            t += timeQuantum;
        }

        if(RT[cnt] == 0 && flag == 1)
        {
            remain--;

            printf("P[%d]\t|\t\t%d\t\t|\t\t%d\n",cnt + 1,t - AT[cnt],t - AT[cnt] - BT[cnt]);
            WT += t - AT[cnt] - BT[cnt];
            TAT += t - AT[cnt];
            flag = 0;
        }

        if(cnt == n-1)
        {
            cnt = 0;
        }
        else if(AT[cnt+1] <= t)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
    }

    printf("\nAverage Waiting Time = %f", WT * 1.0/n);
    printf("\nAverage Turnaround Time = %f\n", TAT * 1.0/n);

    return 0;
}
