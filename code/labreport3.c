#include <stdio.h>

void priority_scheduling(int processes[], int n, int burst_times[], int priorities[]) {
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    // Sort processes by priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priorities[j] > priorities[j + 1]) {
                // Swap priorities
                int temp_priority = priorities[j];
                priorities[j] = priorities[j + 1];
                priorities[j + 1] = temp_priority;
                
                // Swap processes
                int temp_process = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp_process;
                
                // Swap burst times
                int temp_burst_time = burst_times[j];
                burst_times[j] = burst_times[j + 1];
                burst_times[j + 1] = temp_burst_time;
            }
        }
    }
    
    waiting_time[0] = 0; // First process has 0 waiting time

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_times[i - 1] + waiting_time[i - 1];
        total_waiting_time += waiting_time[i];
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_times[i] + waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("Priority %d:\t Process %d\t Burst Time %d\t Waiting Time %d\t Turnaround Time %d\n", priorities[i], processes[i], burst_times[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_times[n], priorities[n];
    
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_times[i]);
        processes[i] = i + 1;
    }
    
    printf("Enter priorities for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priorities[i]);
    }

    printf("Priority CPU Scheduling Algorithm:\n");
    priority_scheduling(processes, n, burst_times, priorities);

    return 0;
}
