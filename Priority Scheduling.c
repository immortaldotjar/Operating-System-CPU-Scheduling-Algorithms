#include <stdio.h>

struct pscheduling 
{
    char p;
    int BT;
    int WT;
    int TAT;
    int priority;
};

int main() 
{
    int n,position,total = 0,ASCII= 65;
    float avg_WT, avg_TAT;
    struct pscheduling temp_process;

    printf("Enter the total number of Processes: ");
    scanf("%d", &n);

    struct pscheduling p[n];

    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        p[i].p = (char)ASCII;
        printf("\nEnter the details of the process %c\n", p[i].p);
        printf("Enter the Burst Time: ");
        scanf("%d", &p[i].BT);
        printf("Enter the Priority: ");
        scanf("%d", &p[i].priority);
        ASCII++;
    }

    // Sorting processes based on priority (higher number = higher priority)
    for (int i = 0; i < n; i++) 
    {
        position = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (p[j].priority > p[position].priority)
            {
                position = j;
            }
        }
        temp_process = p[i];
        p[i] = p[position];
        p[position] = temp_process;
    }

    // Calculating waiting time
    p[0].WT = 0;
    for (int i = 1; i < n; i++) 
    {
        p[i].WT = 0;
        for (int j = 0; j < i; j++) 
        {
            p[i].WT += p[j].BT;
        }
        total += p[i].WT;
    }

    avg_WT = (float)total / (float)n;
    total = 0;

    printf("\n\nProcess Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-------------------------------------------------------------\n");

    // Calculating and displaying TAT
    for (int i = 0; i < n; i++) 
    {
        p[i].TAT = p[i].BT + p[i].WT;
        total += p[i].TAT;
        printf("\t%c\t\t%d\t\t%d\t\t%d\n",p[i].p,p[i].BT,p[i].WT,p[i].TAT);
    }

    avg_TAT = (float)total / (float)n;

    printf("\nAverage Waiting Time: %.2f", avg_WT);
    printf("\nAverage Turnaround Time: %.2f\n", avg_TAT);

    return 0;
}