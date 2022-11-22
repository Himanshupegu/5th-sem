#include <stdio.h>

int main()
{
  int i, j, time, remain, flag = 0, time_quantum;
  int n;
  printf("Enter Total Process: ");
  scanf("%d", &n);
  int totalwt = 0, totaltat = 0, at[n], bt[n], rt[n];
  remain = n;
  for (i = 0; i < n; i++)
  {
    printf("Enter Arrival Time and Burst Time for Process Number %d :", i + 1);
    scanf("%d", &at[i]);
    scanf("%d", &bt[i]);
    rt[i] = bt[i];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d", &time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for (time = 0, i = 0; remain != 0;)
  {
    if (rt[i] <= time_quantum && rt[i] > 0)
    {
      time += rt[i];
      rt[i] = 0;
      flag = 1;
    }
    else if (rt[i] > 0)
    {
      rt[i] -= time_quantum;
      time += time_quantum;
    }
    if (rt[i] == 0 && flag == 1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, time - at[i], time - at[i] - bt[i]);
      totalwt += time - at[i] - bt[i];
      totaltat += time - at[i];
      flag = 0;
    }
    if (i == n - 1)
      i = 0;
    else if (at[i + 1] <= time)
      i++;
    else
      i = 0;
  }
  printf("\nAverage Waiting Time= %f\n", totalwt * 1.0 / n);
  printf("Avg Turnaround Time = %f", totaltat * 1.0 / n);

  return 0;
}