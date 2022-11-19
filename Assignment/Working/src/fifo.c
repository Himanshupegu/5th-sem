// C program for FIFO page replacement algorithm
#include <stdio.h>
int main()
{
  // int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
  int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
  int pageFaults = 0;
  int frames = 3;
  int i, j, s, pages;

  pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

  printf("Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3");
  int temp[frames];
  for (i = 0; i < frames; i++)
  {
    temp[i] = -1;
  }
  for (i = 0; i < pages; i++)
  {
    s = 0;
    for (j = 0; j < frames; j++)
    {
      if (incomingStream[i] == temp[j])
      {
        s++;
        pageFaults--;
      }
    }
    pageFaults++;
    if ((pageFaults <= frames) && (s == 0))
    {
      temp[i] = incomingStream[i];
    }
    else if (s == 0)
    {
      temp[(pageFaults - 1) % frames] = incomingStream[i];
    }
    printf("\n%d\t\t\t", incomingStream[i]);
    for (j = 0; j < frames; j++)
    {
      if (temp[j] != -1)
        printf(" %d\t\t\t", temp[j]);
      else
        printf(" - \t\t\t");
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  return 0;
}