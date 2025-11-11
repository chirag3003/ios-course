#include <stdio.h>
#include <limits.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
};

int main()
{
    printf("Enter the number of processes: ");
    int n;
    scanf("%d", &n);
    struct Process processes[n];

    //Enter individual processes
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    printf("\n");

    int time = 0;
    int completed = 0;

    while (completed < n)
    {
        int shortest = -1;
        int min_remaining_time = INT_MAX;

        // Find the process with the shortest remaining time that has arrived
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0 &&
                processes[i].remaining_time < min_remaining_time)
            {
                shortest = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }

        // Execute the selected process for one unit of time
        processes[shortest].remaining_time--;
        if (processes[shortest].remaining_time == 0)
        {
            processes[shortest].completion_time = time + 1;
            completed++;
        }
        printf(" t%d-P%d  ", time, processes[shortest].pid);
        time++;
    }
    printf(" t%d", time);

    // Print process details
    printf("\n");
    printf("\nProcess Details:\n");
    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        int turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        int waiting_time = turnaround_time - processes[i].burst_time;
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", processes[i].pid,
               processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, turnaround_time, waiting_time);
    }

    return 0;
}

