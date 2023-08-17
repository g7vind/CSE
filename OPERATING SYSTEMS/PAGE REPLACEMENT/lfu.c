#include <stdio.h>
#include <stdbool.h>
int miss = -1;
bool search(int frame_size, int frame[], int key)
{
    for (int i = 0; i < frame_size; i++)
    {
        if (frame[i] == key)
            return true;
    }
    return false;
}
int lfu(int frame_size, int frame[], int current[], int freq[])
{
    int u = -1, i;
    int minfrq = freq[0];
    for (i = 0; i < frame_size; i++)
    {
        if (freq[i] < minfrq || freq[i] == minfrq && current[i] < current[u])
        {
            u = i;
            minfrq = freq[i];
        }
    }
    return u;
}

int main()
{
    int frame_no, page_no, frame[50], page[50], freq[20], current[30], pageFaultCnt = 0;
    printf("\nEnter the number of frames: ");
    scanf("%d", &frame_no);
    printf("\nEnter the number of pages: ");
    scanf("%d", &page_no);
    printf("\nEnter the reference string: ");
    for (int i = 0; i < page_no; i++)
        scanf("%d", &page[i]);
    for (int i = 0; i < frame_no; i++)
    {
        frame[i] = -1;
        freq[i] = 0;
    }
    for (int i = 0; i < page_no; i++)
    {
        printf("Pages in frame --> ");
        if (!search(frame_no, frame, page[i]))
        {
            miss++;
            pageFaultCnt++;
            if (miss < frame_no)
            {
                freq[miss] = 1;
                frame[miss] = page[i];
                current[miss] = i;
            }
            else
            {
                int j = lfu(frame_no, frame, current, freq);
                frame[j] = page[i];
                freq[j] = 1;
                current[j] = i;
            }
            for (int j = 0; j < frame_no; j++)
            {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
            }
            printf("\n");
        }
        else
        {
            for (int j = 0; j < frame_no; j++)
            {
                if (frame[j] == page[i])
                {
                    freq[j]++;
                }
            }
            for (int j = 0; j < frame_no; j++)
            {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
            }
            printf("\n");
        }
    }
    printf("\nTotal number of page faults: %d\n", pageFaultCnt);

    return 0;
}
