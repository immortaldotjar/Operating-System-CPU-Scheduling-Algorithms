#include <stdio.h>
#include <stdlib.h>

int files[50],indexBlock[50],indBlock,n;
void recurse1();
void recurse2();

void recurse1()
{
    printf("Enter the index block: ");
    scanf("%d", &indBlock);

    if (files[indBlock] != 1) 
    {
        printf("Enter the number of blocks needed for the index %d on the disk: ", indBlock);
        scanf("%d", &n);
        recurse2();
    }
    else 
    {
        printf("%d is already allocated\n", indBlock);
        recurse1();
    }
}

void recurse2()
{
    char ch;
    int flag = 0;

    printf("Enter the blocks for the indexed file:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &indexBlock[i]);
        if (files[indexBlock[i]] != 0)
        {
            flag++;
        }
    }

    if (flag == 0) 
    {
        for (int j = 0; j < n; j++) 
        {
            files[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k = 0; k < n; k++) 
        {
            printf("%d --> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
        }
    } 
    else 
    {
        printf("Some blocks are already allocated.\n");
        printf("Enter another indexed file.\n");
        recurse2();
    }

    printf("Do you want to enter more files?\n");
    printf("Enter your choice [Y/n] : ");
    scanf(" %c", &ch);
    if (ch == 'Y'|| ch == 'y')
    {
        recurse1();
    }
    else
    {
        exit(0);
    }
}

int main() 
{
    for (int i = 0; i < 50; i++)
    {
        files[i] = 0;
    }
    recurse1();
    return 0;
}
