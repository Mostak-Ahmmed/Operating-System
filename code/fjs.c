void sjf(int processes[], int n, int burst_time[]) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                // Swap processes and their burst times
                // ...
            }
        }
    }

    // Calculate waiting and turnaround times (similar to FCFS)
    // ...
}
