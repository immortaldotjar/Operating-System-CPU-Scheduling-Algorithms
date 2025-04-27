#include <stdio.h>
#include <stdlib.h>

void recurse(int files[])
{
    int flag = 0,startBlock, len, j, k;
    char ch;

    printf("Enter the : \n");
    printf("Starting block of the file : ");
    scanf("%d",&startBlock);
    printf("Length of the file : ");
    scanf("%d",&len);
    
    flag = 0;
    for (j = startBlock; j < (startBlock + len); j++) 
    {
        if (files[j] != 0)
        {
            flag++;
        }
    }

    if (flag == 0) 
    {
        for (k = startBlock; k < (startBlock + len); k++) 
        {
            files[k] = 1;
            printf("%d\t%d\n", k, files[k]);
        }
        printf("The file is allocated to the disk successfully.\n");
    } 
    else 
    {
        printf("The file is not allocated. Some blocks are already occupied.\n");
    }

    printf("Do you want to enter more files?[Y/n] ");
    scanf(" %c", &ch);

    if (ch == 'Y' || ch == 'y')
        recurse(files);
    else
        exit(0);
}

int main() 
{
    int files[50];
    for (int i = 0; i < 50; i++)
    {
        files[i] = 0;
    }
    printf("Files Allocation Table (Block Number : Allocation Status)\n");
    recurse(files);

    return 0;
}
