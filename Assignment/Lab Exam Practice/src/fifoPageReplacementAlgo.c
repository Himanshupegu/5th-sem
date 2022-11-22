#include <stdio.h>

void printfOuterStructure(int frames)
{
  printf("Incoming ");
  for (int i = 0; i < frames; i++)
  {
    printf("\tFrame%d\t", i + 1);
  }
}

// Function to check if the page is hit or fault
int search(int key, int frameItems[], int frameOccupied)
{
  for (int i = 0; i < frameOccupied; i++)
  {
    if (frameItems[i] == key)
    {
      return 1;
    }
  }
  return 0;
}

void printCurrFrames(int item, int frameItems[], int frameOccupied, int frames)
{
  printf("\n%d \t\t", item);
  for (int i = 0; i < frames; i++)
  {
    if (i < frameOccupied)
      printf("%d \t\t", frameItems[i]);
    else
      printf("- \t\t");
  }
}

void optimalPage(int incomingStream[], int page, int frameItems[], int frames)
{
  int frameOccupied = 0;
  printfOuterStructure(frames);
  int pageFaults = 0;

  int pageHits = 0;
  for (int i = 0; i < page; i++)
  {
    int checkPage = 0;
    if (search(incomingStream[i], frameItems, frameOccupied))
    {
      pageHits++;
      checkPage++;
      pageFaults--;
      printCurrFrames(incomingStream[i], frameItems, frameOccupied, frames);
      continue;
    }
    pageFaults++;
    if (frameOccupied < frames)
    {
      frameItems[frameOccupied] = incomingStream[i];
      frameOccupied++;
      printCurrFrames(incomingStream[i], frameItems, frameOccupied, frames);
    }
    else if (checkPage == 0)
    {
      frameItems[(pageFaults - 1) % frames] = incomingStream[i];
      printCurrFrames(incomingStream[i], frameItems, frameOccupied, frames);
    }
  }
  printf("\nTotal Page Faults:\t%d\n", pageFaults);
  printf("\nPage hits: %d", pageHits);
}

int main()
{
  int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
  int frames = 3;
  int i, j, checkPage;
  int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

  int frameItems[frames];
  optimalPage(incomingStream, pages, frameItems, frames);
  return 0;
}