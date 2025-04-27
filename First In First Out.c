#include <stdio.h>
#include <stdlib.h>

#define FRAMES 3

typedef struct page 
{
    int number;
    int present;
} page;

typedef struct Queue 
{
    page pages[FRAMES];
    int head;
    int tail;
} Queue;

void init_fifo_queue(Queue *q) 
{
    q -> head = 0;
    q -> tail = 0;

    for (int i = 0; i < FRAMES; i++) 
    {
        q -> pages[i].number = -1; // Initialized as empty
        q -> pages[i].present = 0;
    }
}

void addInQueue(Queue *q, page p) 
{
    q -> pages[q -> tail] = p;
    q -> tail = (q -> tail + 1) % FRAMES;
}

page removeFromQueue(Queue *q) 
{
    page p = q -> pages[q -> head];
    q -> head = (q -> head + 1) % FRAMES;
    return p;
}

int is_in_fifo_queue(Queue *q,int page_number)
{
    for (int i = 0; i < FRAMES; i++) 
    {
        if (q -> pages[i].number == page_number) 
        {
            return 1;
        }
    }
    return 0;
}

int fifo_page_replacement(int page_numbers[], int num_pages) 
{
    Queue q;
    init_fifo_queue(&q);
    int faults = 0;

    for (int i = 0; i < num_pages; i++) 
    {
        if (!is_in_fifo_queue(&q, page_numbers[i])) 
        {
            faults++;

            // If frames are not full yet, just add without removing
            int frames_used = (q.tail - q.head + FRAMES) % FRAMES;
            if (frames_used < FRAMES) 
            {
                //Adding elements in queue
                page new_page;
                new_page.number = page_numbers[i];
                new_page.present = 1;
                addInQueue(&q, new_page);
            } 
            else 
            {
                //removing the old or previous elements
                removeFromQueue(&q);
                page new_page;
                new_page.number = page_numbers[i];
                new_page.present = 1;
                addInQueue(&q, new_page);
            }
        }
    }
    return faults;
}

int main() 
{
    int n,i,faults;
    printf("Enter the number of pages : ");
    scanf("%d", &n);

    int page_numbers[n];
    printf("Enter the page numbers : \n");
    for (i = 0; i < n; i++) 
    {
        printf("Page %d : ",i + 1);
        scanf("%d", &page_numbers[i]);
    }

    faults = fifo_page_replacement(page_numbers,n);
    printf("The number of page fault : %d\n",faults);

    return 0;
}
