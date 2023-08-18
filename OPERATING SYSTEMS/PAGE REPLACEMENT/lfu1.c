#include <stdio.h>
#include <stdlib.h>
struct frame
{
    int page;
    int freq;
    int used_time;
} frames[50];
int main()
{
    int pages[50], nof, nop;
    int pageFault = 0;
    printf("\nEnter the number of frames : ");
    scanf("%d", &nof);
    printf("Enter the number of pages : ");
    scanf("%d", &nop);
    printf("Enter the page reference string : ");
    for (int i = 0; i < nop; i++)
        scanf("%d", &pages[i]);
    for (int i = 0; i < nof; i++)
    {
        frames[i].page = -1;
        frames[i].freq = 0;
        frames[i].used_time = -1;
    }
    for (int i = 0; i < nop; i++)
    {
        int found = 0;
        for (int j = 0; j < nof; j++)
        {
            if (frames[j].page == pages[i])
            {
                frames[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            int min_freq = frames[0].freq;
            int min_time = frames[0].used_time;
            int replace_idx = 0;
            for (int j = 1; j < nof; j++)
            {
                if (frames[j].freq < min_freq || (frames[j].freq == min_freq && frames[j].used_time < min_time))
                {
                    min_freq = frames[j].freq;
                    min_time = frames[j].used_time;
                    replace_idx = j;
                }
            }
            frames[replace_idx].page = pages[i];
            frames[replace_idx].freq = 1;
            frames[replace_idx].used_time = i;
            pageFault++;
        }
        printf("\npages in frame : ", i);
        for (int j = 0; j < nof; j++)
        {
            if (frames[j].page != -1)
                printf("%d ", frames[j].page);
        }
    }
    printf("\n\nTotal Page Fault :  %d\n", pageFault);
    return 0;
}
