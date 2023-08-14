#include <stdio.h>
#include <stdbool.h>
int miss = -1, count = 0;
struct page
{
    int frequency;
    int arrival_index;
    int data;
} pg[50];
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
int searchpg(int current_index, int pg_fr[], int no_dup_count)
{
    for (int i = 0; i < no_dup_count; i++)
    {
        if (pg_fr[current_index] == pg[i].data)
            return i;
    }
    return -1;
}
int lfu(int frame_size, int frame[], int page[])
{
    int u = -1;
    int minarrival = pg[0].arrival_index;
    int minFrequency = pg[0].frequency;
    for (int i = 0; i < frame_size; i++)
    {
        for (int k = 0; k < count; k++)
        {
            if (frame[i] == pg[k].data)
            {
                if (pg[k].frequency < minFrequency)
                {
                    minFrequency = pg[i].frequency;
                    u = i;
                }
            }
        }
    }
    for (int k = 0; k < count; k++)
    {
        if (pg[k].frequency == minFrequency && pg[k].arrival_index < minarrival)
        {
            u = k;
        }
    }
    return u;
}

void main()
{
    int frame_no, page_no, frame[50], page[50], duplicate_count = 0, pageFaultCnt = 0, index;
    printf("\nEnter the number of frames : ");
    scanf("%d", &frame_no);
    printf("\nEnter the number of pages : ");
    scanf("%d", &page_no);
    printf("\nEnter the reference string : ");
    for (int i = 0; i < page_no; i++)
        scanf("%d", &page[i]);
    int flag;
    for (int i = 0; i < frame_no; i++)
        frame[i] = -1;
    for (int i = 0; i < page_no; i++)
    {
        flag = 0;
        for (int k = 0; k < count; k++)
        {
            if (page[i] == pg[k].data)
                flag = 1;
        }
        if (flag == 1)
            continue;
        pg[count].data = page[i];
        pg[count].frequency = 0;
        pg[count].arrival_index = i;
        count++;
    }
    for (int i = 0; i < frame_no; i++)
        frame[i] = -1;
    printf("\n");
    for (int i = 0; i < page_no; i++)
    {
        if (!search(frame_no, frame, page[i]))
        {
            pageFaultCnt++;
            miss++;
            if (miss < frame_no)
            {
                index = searchpg(i, page, count);
                pg[index].frequency++;
                frame[miss] = page[i];
            }
            else
            {
                index = searchpg(i, page, count);
                pg[index].frequency++;
                int j = lfu(frame_no, frame, page);
                frame[j] = page[i];
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
            index = searchpg(i, page, count);
            pg[index].frequency++;
            for (int j = 0; j < frame_no; j++)
            {
                if (frame[j] != -1)
                    printf("%d ", frame[j]);
            }
            printf("\n");
        }
    }
    printf("\nTotal number of page faults: %d", pageFaultCnt);
}
