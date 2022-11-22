// Implementation of Round Robin scheduling
#include <stdio.h>

int main()
{
  int n, i, h;
  printf("Enter the number of process:");
  scanf("%d", &n);
  int at[n], bt[n];
  int timeQuantum = 5;
  for (i = 0; i < n; i++)
  {
    printf("Enter the arrival time for the process P%d: ", i + 1);
    scanf("%d", &at[i]);
    printf("Enter the burst time for the process P%d: ", i + 1);
    scanf("%d", &bt[i]);
  }
  for (i = 0; i < timeQuantum; i++)
  {
    if (bt[i] > 0)
    {
      bt[i] -= 1;
    }
  }