#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;          // Semaphores
int shared_var = 99;       // Shared variable
int reader_count = 0;      // Number of readers
int n;                     // Number of readers and writers

// ---------------- Reader Function ----------------
void reader() {
    sem_wait(&mutex);           // Lock mutex before updating count
    reader_count++;

    if (reader_count == 1)
        sem_wait(&wrt);         // First reader blocks writers

    sem_post(&mutex);           // Unlock mutex

    printf("\nReader is reading shared_var = %d", shared_var);
    sleep(1);
    printf("\nReader finished reading");

    sem_wait(&mutex);
    reader_count--;

    if (reader_count == 0)
        sem_post(&wrt);         // Last reader allows writers

    sem_post(&mutex);
}

// ---------------- Writer Function ----------------
void writer() {
    printf("\nWriter is trying to enter");
    sem_wait(&wrt);             // Wait for exclusive access
    int val;
    printf("Enter the value to change to: ");
    scanf("%d", &val);
    shared_var = val;
    printf("\nWriter entered CS and changed shared_var to %d", shared_var);
    sleep(1);
    printf("\nWriter leaving CS");

    sem_post(&wrt);             // Release access
}

// ---------------- Main Function ----------------
int main() {
    int i;
    pthread_t rthread[100], wthread[100];

    printf("Enter number of readers and writers: ");
    scanf("%d", &n);

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < n; i++) {
        pthread_create(&rthread[i], NULL, (void*)reader, NULL);
        pthread_create(&wthread[i], NULL, (void*)writer, NULL);
    }

    for (i = 0; i < n; i++) {
        pthread_join(rthread[i], NULL);
        pthread_join(wthread[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    printf("\nAll readers and writers have finished.\n");
    return 0;
}
