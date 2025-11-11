#include <stdio.h>

struct Process
{
  int pid;
  int arrival_time;
  int burst_time;
  int ct;

};

void sortOnArrivalTime(int n, struct Process processes[n]);

int main()
{

  // Taking user input
  printf("Enter the number of processes: ");
  int n;
  scanf("%d", &n);
  struct Process processes[n];

  // Enter each process
  for (int i = 0; i < n; i++)
  {
    processes[i].pid = i + 1;
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &processes[i].arrival_time);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
  }

  printf("\n");

  sortOnArrivalTime(n, processes);

  for (int i = 0; i < n; i++)
  {
    printf("Process %d arrived at time %d and took %d bursts\n",
           processes[i].pid, processes[i].arrival_time,
           processes[i].burst_time);
  }

  printf("\n");

  int time = 0;
  printf("0");
  for (int i = 0; i < n; i++)
  {
    time += processes[i].burst_time;
    processes[i].ct = time;
    printf(" - P%d - %d", processes[i].pid, time);
  }
  return 0;
}

void sortOnArrivalTime(int n, struct Process processes[n])
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (processes[i].arrival_time > processes[j].arrival_time)
      {
        struct Process temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
      }
    }
  }
}
