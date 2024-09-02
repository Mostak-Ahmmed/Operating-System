#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void* philosopher(void* num) {
    int id = *(int*)num;
    while (1) {
        // Thinking
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 3 + 1);

        // Hungry
        printf("Philosopher %d is hungry.\n", id);

        // Pick up left fork
        pthread_mutex_lock(&forks[id]);
        printf("Philosopher %d picked up left fork.\n", id);

        // Pick up right fork
        pthread_mutex_lock(&forks[(id + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d picked up right fork.\n", id);

        // Eating
        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 3 + 1);

        // Put down right fork
        pthread_mutex_unlock(&forks[(id + 1) % NUM_PHILOSOPHERS]);
        printf("Philosopher %d put down right fork.\n", id);

        // Put down left fork
        pthread_mutex_unlock(&forks[id]);
        printf("Philosopher %d put down left fork.\n", id);
    }
    return NULL;
}

int main() {
    int ids[NUM_PHILOSOPHERS];

    // Initialize mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
/*Initialization:

We define the number of philosophers and forks.
We create an array of pthread_mutex_t to represent forks.
We create an array of pthread_t to represent philosopher threads.
Philosopher Function:

Each philosopher will continuously think, get hungry, and try to eat.
When hungry, a philosopher will attempt to pick up their left and right forks (mutexes) to eat.
After eating, they put down the right fork first, then the left fork.
Main Function:

We initialize the mutexes for each fork.
We create a thread for each philosopher, passing their ID as an argument.
We join each thread to wait for their completion.
We destroy the mutexes at the end*/