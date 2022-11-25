// shortest remaining time first (SRTF) preemptive scheduling algorithm

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
typedef struct process
{
  int pid;
  int bt;
  int at;
} p;

void findWaitingTime(p proc[], int n, int wt[])
{
  int rt[n];
  for (int i = 0; i < n; i++)
  {
    rt[i] = proc[i].bt;
  }

  int complete = 0, t = 0, min = INT_MAX;
  int shortest = 0, finishTime;
  bool check = false;

  while (complete != n)
  {
    for (int j = 0; j < n; j++)
    {
      if ((proc[j].at <= t) && (rt[j] < min) && rt[j] > 0)
      {
        min = rt[j];
        shortest = j;
        check = true;
      }
    }
    if (check == false)
    {
      t++;
      continue;
    }
    rt[shortest]--;
    min = rt[shortest];
    if (min == 0)
    {
      min = INT_MAX;
    }
    if (rt[shortest] == 0)
    {
      complete++;
      check = false;
      finishTime = t + 1;

      wt[shortest] = finishTime - proc[shortest].bt - proc[shortest].at;
      if (wt[shortest] < 0)
      {
        wt[shortest] = 0;
      }
    }
    t++;
  }
}

void findTurnAroundTime(p proc[], int n, int wt[], int tat[])
{
  for (int i = 0; i < n; i++)
  {
    tat[i] = proc[i].bt + wt[i];
  }
}

void findAvgTime(p proc[], int n)
{
  int wt[n], tat[n], totalWT = 0, totalTAT = 0;

  findWaitingTime(proc, n, wt);
  findTurnAroundTime(proc, n, wt, tat);

  printf("\n\nProcess\t| Arrival Time\t| Burst Time\t|  TAT Time\t| Waiting Time\t|");

  for (int i = 0; i < n; i++)
  {
    totalWT = totalWT + wt[i];
    totalTAT = totalTAT + tat[i];
    printf("\n P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", proc[i].pid, proc[i].at, proc[i].bt, tat[i], wt[i]);
  }
  printf("\n\nAVERAGE WAITING TIME : %f", (float)totalWT / (float)n);
  printf("\nAVERAGE TURN AROUND TIME : %f", (float)totalTAT / (float)n);
}

int main()
{
  int n;
  printf("\nEnter the No. of processes :");
  scanf("%d", &n);
  p proc[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter the Process id: ");
    scanf("%d", &proc[i].pid);
    printf("Now enter the Arrival and Burst time for process P[%d]: ", proc[i].pid);
    scanf("%d %d", &proc[i].at, &proc[i].bt);
  }
  findAvgTime(proc, n);
  return 0;
}