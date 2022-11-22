#include <stdio.h>

int main(){
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