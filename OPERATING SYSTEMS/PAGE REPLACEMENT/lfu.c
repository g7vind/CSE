#include <stdio.h>
#include <stdbool.h>

int findLFUIndex(int frame_no, int freq[], int current[])
{
    int lfuIndex = 0;
    int minFreq = freq[0];

    for (int j = 1; j < frame_no; j++)
    {
        if (freq[j] < minFreq || (freq[j] == minFreq && current[j] < current[lfuIndex]))
        {
            minFreq = freq[j];
            lfuIndex = j;
        }
    }

    return lfuIndex;
}

int main()
{
    int frame_no, page_no, frame[50], page[50], freq[50], current[50], pageFaultCnt = 0, miss = -1;
    printf("Enter the number of frames: ");
    scanf("%d", &frame_no);
    printf("Enter the number of pages: ");
    scanf("%d", &page_no);
    printf("Enter the reference string: ");
    for (int i = 0; i < page_no; i++)
        scanf("%d", &page[i]);
    for (int i = 0; i < frame_no; i++)
    {
        frame[i] = -1;
        freq[i] = 0;
        current[i] = -1;
    }
    for (int i = 0; i < page_no; i++)
    {
        printf("Pages in frame --> ");
        bool found = false;
        int lfuIndex = 0;
        for (int j = 0; j < frame_no; j++)
        {
            if (frame[j] == page[i])
            {
                freq[j]++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            pageFaultCnt++;
            miss++;
            if (miss < frame_no)
            {
                lfuIndex = miss;
            }
            else
            {
                lfuIndex = findLFUIndex(frame_no, freq, current);
            }
            frame[lfuIndex] = page[i];
            freq[lfuIndex] = 1;
            current[lfuIndex] = i;
        }
        for (int j = 0; j < frame_no; j++)
        {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
        }
        printf("\n");
    }
    printf("\nTotal number of page faults: %d\n", pageFaultCnt);
    return 0;
}
