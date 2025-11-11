#include <stdio.h>
int main()
{
    int n, frames, i, j;
    int page_faults = 0;
    int found;
    printf("Enter no. of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter pg ref string: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter no. of frames: ");
    scanf("%d", &frames);
    int memory[frames];
    int front = 0;
    for (i = 0; i < frames; i++)
    {
        memory[i] = -1;
    }
    printf("\nPg Ref | Memory Frames | Pg Fault?\n");
    printf("---------|---------------|----------\n");
    for (i = 0; i < n; i++)
    {
        found = 0;
        for (j = 0; j < frames; j++)
        {
            if (memory[j] == pages[i])
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            memory[front] = pages[i];
            front = (front + 1) % frames;
            page_faults++;
            printf(" %d |", pages[i]);
            for (j = 0; j < frames; j++)
            {
                if (memory[j] == -1)
                {
                    printf(" - ");
                }
                else
                {
                    printf(" %2d ", memory[j]);
                }
            }
            printf("| YES\n");
        }
        else
        {
            printf(" %d |", pages[i]);
            for (j = 0; j < frames; j++)
            {
                if (memory[j] == -1)
                {
                    printf(" - ");
                }
                else
                {
                    printf(" %2d ", memory[j]);
                }
            }
            printf("| NO\n");
        }
    }
    printf("\nTotal Pg Faults: %d\n", page_faults);
    printf("Pg Fault Rate: %.2f%%\n", (float)page_faults * 100 / n);
    return 0;
}