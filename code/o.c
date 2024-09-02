void priority_scheduling(int processes[], int n, int burst_time[], int priority[]) {
    // Arrange processes in decreasing order of priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] < priority[j + 1]) {
                // Swap processes, burst times, and priorities
                // ...
            }
        }
    }

    // Calculate waiting and turnaround times (similar to FCFS)
    // ...
}
