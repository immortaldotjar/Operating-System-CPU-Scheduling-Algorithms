#include<stdio.h>

int main()
{
    int BT[20],p[20],WT[20],TAT[20],i,j,n,total = 0,pos,temp; 
    float avg_WT,avg_TAT;

    printf("Enter total number of Processes : "); 
    scanf("%d",&n);

    printf("\nEnter the Burst Time:\n");
    for(i = 0;i < n;i++)
    {
        printf("P%d : ",i+1);
        scanf("%d",&BT[i]);
        p[i] = i + 1;
    }

    for(i = 0;i < n;i++)
    {
        pos = i;
        for(j = i+1;j < n;j++)
        {
            if(BT[j] < BT[pos]) 
            {
                pos=j;
            }

            temp = BT[i]; 
            BT[i] = BT[pos]; 
            BT[pos] = temp; 
            temp=p[i];
            
            p[i]=p[pos];
            p[pos]=temp;
        }
        WT[0]=0; 
    }

    for(i = 1;i < n;i++)
    {
        WT[i] = 0; 

        for(j = 0;j < i;j++)
        { 
            WT[i] += BT[j]; 
            total += WT[i];
        }
    }
    
    avg_WT = (float)total/n;
    total = 0;

    printf("\nProcess\t|\tBurst Time\t|\tWaiting Time\t|\tTurnaround Time");
    for(i = 0;i < n;i++)
    {
        TAT[i] = BT[i] + WT[i]; 
        total += TAT[i];
        printf("\nP%d\t| \t%d\t\t| \t%d\t\t| \t%d",p[i],BT[i],WT[i],TAT[i]);
    }

    avg_TAT=(float)total/n;
    printf("\nAverage Waiting Time = %f",avg_WT);
    printf("\nAverage Turnaround Time = %f\n",avg_TAT);
    return 0;
}