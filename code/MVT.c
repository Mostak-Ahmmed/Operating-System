#include<stdio.h>
#include<stdbool.h>

#define MEMORY_SIZE 1000

// Process structure
struct Process {
    int pid;
    int size;
};

int main() {
    int memory[MEMORY_SIZE] = {0};
    int total_memory, total_allocated_memory = 0, external_fragmentation;
    char choice;


    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &total_memory);

    // Array to store processes
    struct Process processes[10];
    int num_processes = 0;

    // Input memory required for each process
    do {
        printf("Enter memory required for process %d (in Bytes): ", num_processes + 1);
        scanf("%d", &processes[num_processes].size);
        processes[num_processes].pid = num_processes + 1;
        total_allocated_memory += processes[num_processes].size;
        if(total_allocated_memory > total_memory) {
            printf("Memory is Full\n");
            break;
        }
        printf("Memory is allocated for Process %d\n", num_processes + 1);
        num_processes++;

        printf("Do you want to continue (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    // Calculate external fragmentation
    external_fragmentation = total_memory - total_allocated_memory;


    printf("\nTotal Memory Available -%d\n", total_memory);
    printf("PROCESS-----MEMORY-ALLOCATED\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%d\t%d\n", processes[i].pid, processes[i].size);
    }
    printf("Total Memory Allocated is %d\n", total_allocated_memory);
    printf("Total External Fragmentation is %d\n", external_fragmentation);

    return 0;
}
