#include <stdio.h>
#include <stdbool.h>
int miss=-1;
bool search(int frame_size, int frame[], int key)
{
    int index = -1;
    for (int i = 0; i < frame_size; i++)
    {
        if (frame[i] == key)
            return true;
    }
    return false;
}
int farthest_page(int curent_index, int frame_size, int frame[], int page[])
{
    int need_index = curent_index;
    for (int i = 0; i < frame_size; i++)
    {
    
        for (int j = curent_index-1 ; j >= 0 ; j--)
        {
            if (frame[i] == page[j])
            {
                if (need_index > j)
                {
                    need_index = j;
                }
                break;
            }
        }
    }
    for (int i = 0; i < frame_size; i++)
    {
        if (frame[i] == page[need_index])
            return i;
    }
}
void main()
{
    int numFrames, numPages, pageFaultCnt = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    printf("Enter the number of pages: ");
    scanf("%d", &numPages);
    int frame[50];
    int page[50];
    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++)
        scanf("%d", &page[i]);
    for (int i = 0; i < numFrames; i++)
        frame[i] = -1;
    printf("\n");
    for (int i = 0; i < numPages; i++)
    {
        if (!search(numFrames, frame, page[i]))
        {
            pageFaultCnt++;
            miss++;
            if (miss < numFrames)
            {
                frame[miss] = page[i];
            }
            else
            {
                int j = farthest_page(i, numFrames, frame, page);
                frame[j] = page[i];
            }
            for (int j = 0; j < numFrames; j++)
            {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
            }
            printf("\n");
        }
        else
        {
            for (int j = 0; j < numFrames; j++)
            {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
            }
            printf("\n");
        }
    }
    printf("\nTotal number of page faults: %d", pageFaultCnt);
}
