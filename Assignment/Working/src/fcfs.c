// FCFS scheduling algo
#include <stdio.h>

void findWaitingTime(int pid[], int n, int bt[], int wt[], int at[])
{
  int serviceTime[n];
  serviceTime[0] = at[0];
  wt[0] = 0;
  for (int i = 1; i < n; i++)
  {
    serviceTime[i] = serviceTime[i - 1] + bt[i - 1];
    wt[i] = serviceTime[i] - at[i];
    if (wt[i] < 0)
    {
      wt[i] = 0;
    }
  }
}

void findTurnAroundTime(int pid[], int n, int bt[], int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = bt[i] + wt[i];
  }
}

void findAvgTime(int pid[], int n, int bt[], int at[])
{
  int wt[n], tat[n];
  findWaitingTime(pid, n, bt, wt, at);
  findTurnAroundTime(pid, n, bt, wt, tat);

  printf("\n\nProcess\t| Arrival Time\t| Burst Time\t| Compl Time\t|  TAT Time\t| Waiting Time\t|");
  int totalWT = 0, totalTAT = 0;
  for (int i = 0; i < n; i++)
  {
    totalWT = totalWT + wt[i];
    totalTAT = totalTAT + tat[i];
    int complTime = tat[i] + at[i];
    printf("\n P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", i + 1, at[i], bt[i], complTime, tat[i], wt[i]);
  }
  printf("\n\nAVERAGE WAITING TIME : %f", (float)totalWT / (float)n);
  printf("\nAVERAGE TURN AROUND TIME : %f", (float)totalTAT / (float)n);
}

int main()
{
  int n;
  printf("\nEnter the No. of processes :");
  scanf("%d", &n);
  int pid[n], bt[n], at[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter the Process id: ");
    scanf("%d", &pid[i]);
    printf("\tEnter the Arrival and Brush Time for process P[%d]:", pid[i]);
    scanf(" %d", &at[i]);
    scanf(" %d", &bt[i]);
  }
  findAvgTime(pid, n, bt, at);
  return 0;
}