#include <stdio.h>
#include <limits.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
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
        processes[i].remaining_time = processes[i].burst_time;
        total_time += processes[i].burst_time;
    }
    printf("\n");

    sortOnArrivalTime(n, processes);

    int time = 0;
    int completed = 0;
    int completion_time[n];
    int gantt_chart[total_time];
    int current_process = -1;
    while (completed < n) {
        int shortest = -1;
        int min_remaining_time = INT_MAX;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0 &&
                    processes[i].remaining_time < min_remaining_time) {
                shortest = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }

        if (shortest == -1) {
            // No process is ready, so we idle
            gantt_chart[time] = -1;
            time++;
            continue;
        }

        // Execute the selected process for one unit of time
        gantt_chart[time] = processes[shortest].pid;
        processes[shortest].remaining_time--;
        if (processes[shortest].remaining_time == 0) {
            completion_time[shortest] = time + 1;
            completed++;
        }
        time++;
    }

    // Print the Gantt chart
    printf("Gantt Chart:\n|");
    for (int i = 0; i < total_time; i++) {
        if (i > 0 && gantt_chart[i] != gantt_chart[i - 1]) {
            printf("| ");
        }
        if (gantt_chart[i] == -1) {
            printf(" IDLE ");
        } else {
            printf(" P%d ", gantt_chart[i]);
        }
    }
    printf("|\n");

    printf("0");
    for (int i = 1; i <= total_time; i++) {
        if (i > 0 && gantt_chart[i] != gantt_chart[i - 1]) {
            printf(" %d ", i);
        }
        if (gantt_chart[i] == -1) {
            printf("      ");
        } else {
            printf("    ");
        }
    }
    printf("\n");

    // Print process details
    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        int turnaround_time = completion_time[i] - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].pid,
                     processes[i].arrival_time, processes[i].burst_time,
                     completion_time[i], turnaround_time, waiting_time);
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
