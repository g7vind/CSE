#include <stdio.h>
void main()
{
   int i, j, flag = 0, pf = 0, ref[50], frame[50], cur_page_index[50] = {0}, nof, nop, min;
   printf("Enter number of frames: ");
   scanf("%d", &nof);
   for (i = 0; i < nof; i++)
      frame[i] = -1;
   printf("Enter number of pages: ");
   scanf("%d", &nop);
   printf("Enter page numbers: ");
   for (i = 0; i < nop; i++)
      scanf("%d", &ref[i]);
   for (i = 0; i < nop; i++)
   {
      printf("\n");
      flag = 0;
      for (j = 0; j < nof; j++)
      {
         if (frame[j] == ref[i])
         {
            flag = 1;
            cur_page_index[j] = i;
            break;
         }
      }
      if (flag == 0)
      {
         if (i < nof)
         {
            frame[i] = ref[i];
            cur_page_index[i] = i;
         }
         else
         {
            min = 0;
            for (j = 1; j < nof; j++)
            {
               if (cur_page_index[min] > cur_page_index[j])
                  min = j;
            }
            frame[min] = ref[i];
            cur_page_index[min] = i;
         }
         pf++;
      }
      printf("Page no -> ");
      for (j = 0; j < nof; j++)
      {
         if (frame[j] != -1)
         {
            printf("%d   ", frame[j]);
         }
      }
   }
   printf("\n\nPage Fault: %d\n", pf);
}