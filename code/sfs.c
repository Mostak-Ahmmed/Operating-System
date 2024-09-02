#include <stdio.h>

void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    waiting_time[0] = 0;  // Waiting time for first process is 0
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // Calculate total waiting and turnaround times
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Display results
    printf("Process\t  Burst Time  \tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("  P%d ", i + 1);
        printf("\t  %d ", burst_time[i]);
        printf("\t\t  %d", waiting_time[i]);
        printf("\t\t\t  %d\n", turnaround_time[i]);
    }

    /* Calculate and print average waiting and turnaround times */
    // ...
}
