// C program for FIFO page replacement algorithm
#include <stdio.h>
int main()
{
  // int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
  int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
  int frames = 3;
  int pageFaults = 0;
  int pageHit = 0;
  int i, j, checkPage, pages;

  pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

  printf("Incoming \t\t Frame 1 \t\t Frame 2 \t\t Frame 3");
  int frameItems[frames];
  for (i = 0; i < frames; i++)
  {
    frameItems[i] = -1;
  }
  for (i = 0; i < pages; i++)
  {
    checkPage = 0; // this counter will check if the page is hit of fault, if hit checkPage = 1 and if fault checkPage = 0

    // to check if there is any existing page in the frame
    for (j = 0; j < frames; j++)
    {
      if (incomingStream[i] == frameItems[j])
      {
        checkPage++;
        pageFaults--;
        pageHit++;
      }
    }
    pageFaults++;

    // if there is no existing page then replace the frameItems[i] value into the first incoming page no.
    if ((pageFaults <= frames) && (checkPage == 0))
    {
      // this if loop is for the first 3 empty frame after that when the first 3 empty fame is filled then else if statement start to execute
      frameItems[i] = incomingStream[i];
    }
    else if (checkPage == 0)
    {
      // this formula is to calculate the first incoming page in frameItems array
      frameItems[(pageFaults - 1) % frames] = incomingStream[i];
    }
    printf("\n%d\t\t\t", incomingStream[i]);

    // to print the table
    for (j = 0; j < frames; j++)
    {
      if (frameItems[j] != -1)
        printf("%d\t\t\t", frameItems[j]);
      else
        printf(" - \t\t\t");
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  printf("\nPage hits: %d", pageHit);
  return 0;
}