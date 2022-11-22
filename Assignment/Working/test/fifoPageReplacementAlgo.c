#include <stdio.h>
int main()
{

  // temp[(pageFaults - 1) % frames] = incomingStream[i];
  int pageFaults = 5;
  int frame = 3;

  int ans = (pageFaults - 1) % frame;
  printf("%d", ans);

  return 0;
}