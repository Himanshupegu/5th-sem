#include <stdio.h>

void printOuterStructure(int frames)
{
  printf("Incoming ");

  for (int i = 0; i < frames; i++)
  {
    printf("\tFrame%d\t", i + 1);
  }
}

int predict(int incomingStream[], int frameItems[], int page, int index, int frame)
{
  int result = -1, farthest = index;
  for (int i = 0; i < frame; i++)
  {
    int j;
    for (j = 0; j < page; j++)
    {
      if (frameItems[i] == incomingStream[j])
      {
        if (j > farthest)
        {
          farthest = j;
          result = i;
        }
        break;
      }
    }
    if (j == page)
    {
      return i;
    }
  }

  return (result == -1) ? 0 : result;
}

int main()
{
  int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
  int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
  int frames = 4;
  int pageFaults = 0;
  int pageHits = 0;
  int i, j, checkPage;

  printOuterStructure(frames);

  int frameItems[frames];
  for (i = 0; i < frames; i++)
  {
    frameItems[i] = -1;
  }

  for (i = 0; i < pages; i++)
  {
    checkPage = 0;

    for (j = 0; j < frames; j++)
    {
      if (incomingStream[i] == frameItems[j])
      {
        checkPage++;
        pageFaults--;
        pageHits++;
      }
    }
    pageFaults++;

    if ((pageFaults <= frames) && (checkPage == 0))
    {
      frameItems[i] = incomingStream[i];
    }
    else if (checkPage == 0)
    {
      int pos = predict(incomingStream, frameItems, pages, i + 1, frames);
      frameItems[pos] = incomingStream[i];
    }
    printf("\n%d\t\t\t", incomingStream[i]);

    for (j = 0; j < frames; j++)
    {
      if (frameItems[j] != -1)
        printf("%d\t\t", frameItems[j]);
      else
        printf(" - \t\t");
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  printf("\nPage hits: %d", pageHits);
  return 0;
}