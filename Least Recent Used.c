#include <stdio.h>
#include <limits.h>

int checkHit(int incomingPage, int queue[], int occupied) 
{
    for (int i = 0; i < occupied; i++) 
    {
        if (incomingPage == queue[i])
        {
            return 1; //hit
        }
    }
    return 0; //missed
}

void printFrame(int queue[], int occupied) 
{
    for (int i = 0; i < occupied; i++)
    {
        printf("%d\t\t\t", queue[i]);
    }
    for (int i = occupied; i < 3; i++)
    { 
        printf("-\t\t\t");
    }
    printf("\n");
}

int main() 
{
    int incomingStream[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3;
    int queue[frames],distance[frames],occupied = 0,pagefault = 0;

    printf("Page\t|\tFrame1\t\t|\tFrame2\t\t|\tFrame3\n");

    for (int i = 0; i < n; i++) 
    
    {
        printf("%d:\t\t", incomingStream[i]);

        if (checkHit(incomingStream[i], queue, occupied)) 
        {
            printFrame(queue, occupied);
        } 
        else if (occupied < frames) 
        {
            queue[occupied] = incomingStream[i];
            pagefault++;
            occupied++;
            printFrame(queue, occupied);
        } 
        else 
        {
            // Find the page in frame that is least recently used
            for (int j = 0; j < frames; j++) 
            {
                distance[j] = 0;
                for (int k = i - 1; k >= 0; k--) 
                {
                    if (queue[j] != incomingStream[k])
                    {
                        distance[j]++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            int max = INT_MIN;
            int index = -1;
            for (int j = 0; j < frames; j++) 
            {
                if (distance[j] > max) 
                {
                    max = distance[j];
                    index = j;
                }
            }

            queue[index] = incomingStream[i];
            printFrame(queue, occupied);
            pagefault++;
        }
    }

    printf("\nTotal Page Faults : %d\n", pagefault);
    return 0;
}