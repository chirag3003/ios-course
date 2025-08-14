#include <stdio.h>

struct Process {
  int pid;
  int arrival_time;
  int burst_time;
};

void sortOnArrivalTime(int n, struct Process processes[n]);

int main() {
  printf("Enter the number of processes: ");
  int n;
  scanf("%d", &n);
  struct Process processes[n];
  int total_time = 0;
  for (int i = 0; i < n; i++) {
    processes[i].pid = i + 1;
    printf("Enter the arrival time of process %d: ", i + 1);
    scanf("%d", &processes[i].arrival_time);
    printf("Enter the burst time of process %d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    total_time += processes[i].burst_time;
  }
  printf("\n");

  sortOnArrivalTime(n, processes);

  for (int i = 0; i < n; i++) {
    printf("Process %d arrived at time %d and took %d bursts\n",
           processes[i].pid, processes[i].arrival_time,
           processes[i].burst_time);
  }

  printf("\n");
  int time = 0;
  int completion_time[n];

  for (int i = 0; i < n; i++) {
    time += processes[i].burst_time;
    completion_time[i] = time;
    printf("|P%d", processes[i].pid);
    // for(int j = 0 ; j < processes[i].burst_time; j++) {
    //   printf("█");

    for (int j = 0; j < processes[i].burst_time; j++) {
      printf("   ");
    }
  }
  printf("|\n");
  printf("0  ");
  time = 0;
  for (int i = 0; i < n; i++) {
    int secondsRemaining = completion_time[i] - time;
    for(int j = 0 ; j < secondsRemaining; j++) {
      if(j == secondsRemaining - 1) {
       // printf("%d", secondsRemaining);
        // printf("%d", completion_time[i]);
        printf("%03d", completion_time[i]);
      }
      printf("   ");
    }
    time = completion_time[i];
  }

  return 0;
}

void sortOnArrivalTime(int n, struct Process processes[n]) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (processes[i].arrival_time > processes[j].arrival_time) {
        struct Process temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
      }
    }
  }
}
