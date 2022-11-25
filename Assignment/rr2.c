// Without at
#include <stdio.h>

int main()
{
  int n;
  printf("Enter Total Process: ");
  scanf("%d", &n);
  int i, temp, qt, sq = 0, count = 0, bt[n], tat[n], rem_bt[n], wt[n];
  float avgwt = 0, avgtat = 0;
  for (i = 0; i < n; i++)
  {
    printf("Enter the burst time for the process P%d: ", i + 1);
    scanf("%d", &bt[i]);
    rem_bt[i] = bt[i];
  }
  printf("Enter the Quantum time: ");
  scanf("%d", &qt);

  while (1)
  {
    for (i = 0, count = 0; i < n; i++)
    {
      temp = qt;
      if (rem_bt[i] == 0)
      {
        count++;
        continue;
      }
      if (rem_bt[i] > qt)
      {
        rem_bt[i] = rem_bt[i] - qt;
      }
      else
      {
        if (rem_bt[i] >= 0)
        {
          temp = rem_bt[i];
          rem_bt[i] = 0;
        }
        sq = sq + temp;
        tat[i] = sq;
      }
    }
    if (n == count)
    {
      break;
    }
  }
  printf("Process ID\t Brust time\t Turn around time\t Waiting time\n");
  for (i = 0; i < n; i++)
  {
    wt[i] = tat[i] - bt[i];
    avgwt = avgwt + wt[i];
    avgtat = avgtat + tat[i];
    printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], tat[i], wt[i]);
  }
  avgwt = avgwt / n;
  avgtat = avgtat / n;
  printf("Average waiting time: %f\n", avgwt);
  printf("Average turn around time: %f", avgtat);
  return 0;
}