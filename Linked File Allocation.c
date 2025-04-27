#include <stdio.h>
#include <stdlib.h>

void recursivePart(int pages[]) 
{
    int st, len, k, j;
    char c;
    printf("Enter the : \n");
    printf("Starting block of the file : ");
    scanf("%d",&st);
    printf("Length of the file : ");
    scanf("%d",&len);

    k = len;
    if (pages[st] == 0) 
    {
        for (j = st; j < (st + k); j++) 
        {
            if (pages[j] == 0) 
            {
                pages[j] = 1;
                printf("%d -> %d\n", j, pages[j]);
            }
            else 
            {
                printf("The block %d is already allocated\n", j);
                k++;
            }
        }
    } 
    else 
    {
        printf("The block %d is already allocated\n", st);
    }

    printf("Do you want to enter more files?\n");
    printf("Enter your choice [Y/n] : ");
    scanf(" %c", &c);
    if (c == 'Y' || c == 'y')
    {
        recursivePart(pages);
    }
    else
    {
        exit(0);
    }
    return;
}

int main() 
{
    int pages[50], p, a;
    for (int i = 0; i < 50; i++)
        pages[i] = 0;

    printf("Enter the number of blocks already allocated: ");
    scanf("%d", &p);

    printf("Enter the blocks already allocated: ");
    for (int i = 0; i < p; i++) 
    {
        scanf("%d", &a);
        pages[a] = 1;
    }

    recursivePart(pages);
    return 0;
}
