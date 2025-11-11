#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

/*
 * Simple Readers-Writers example for beginners.
 * - Any number of readers may read simultaneously.
 * - Only one writer may write at a time.
 * - While a writer has the resource, no readers may read.
 *
 * This example uses two mutexes:
 * - rc_mutex protects the readers_count variable.
 * - resource_mutex protects the shared resource (and is locked by writers,
 *   and by the first reader entering / last reader leaving).
 *
 * This is the classic readers-preference algorithm (may starve writers in
 * some schedules), but it's easy to understand for beginners.
 */

int readers_count = 0;
pthread_mutex_t rc_mutex = PTHREAD_MUTEX_INITIALIZER;    // protects readers_count
pthread_mutex_t resource_mutex = PTHREAD_MUTEX_INITIALIZER; // protects the shared resource

void do_read(int id) {
    // simulate read
    printf("Reader %d: reading...\n", id);
    fflush(stdout);
    sleep(1); // simulate time spent reading
    printf("Reader %d: done reading\n", id);
}

void do_write(int id) {
    // simulate write
    printf("Writer %d: writing...\n", id);
    fflush(stdout);
    sleep(2); // simulate time spent writing (longer so other threads interact)
    printf("Writer %d: done writing\n", id);
}

void *reader(void *arg) {
    int id = *(int*)arg;
    free(arg);

    // Each reader will try to read a few times
    for (int i = 0; i < 3; ++i) {
        // Entry section for readers
        pthread_mutex_lock(&rc_mutex);
        readers_count++;
        if (readers_count == 1) {
            // first reader locks the resource so writers cannot enter
            pthread_mutex_lock(&resource_mutex);
        }
        pthread_mutex_unlock(&rc_mutex);

        // Critical section: reading
        do_read(id);

        // Exit section for readers
        pthread_mutex_lock(&rc_mutex);
        readers_count--;
        if (readers_count == 0) {
            // last reader unlocks the resource
            pthread_mutex_unlock(&resource_mutex);
        }
        pthread_mutex_unlock(&rc_mutex);

        // Pause a bit before next attempt (let writers get a chance)
        sleep(rand() % 3);
    }

    return NULL;
}

void *writer(void *arg) {
    int id = *(int*)arg;
    free(arg);

    // Each writer will try to write a few times
    for (int i = 0; i < 2; ++i) {
        // Writers must lock the resource exclusively
        pthread_mutex_lock(&resource_mutex);

        // Critical section: writing
        do_write(id);

        pthread_mutex_unlock(&resource_mutex);

        // Pause before next write
        sleep(1 + rand() % 3);
    }

    return NULL;
}

int main(void) {
    srand((unsigned)time(NULL));

    const int NUM_READERS = 5;
    const int NUM_WRITERS = 2;

    pthread_t rthreads[NUM_READERS];
    pthread_t wthreads[NUM_WRITERS];

    // create reader threads
    for (int i = 0; i < NUM_READERS; ++i) {
        int *id = malloc(sizeof(int));
        if (!id) { perror("malloc"); exit(1); }
        *id = i + 1;
        if (pthread_create(&rthreads[i], NULL, reader, id) != 0) {
            perror("pthread_create reader"); exit(1);
        }
    }

    // create writer threads
    for (int i = 0; i < NUM_WRITERS; ++i) {
        int *id = malloc(sizeof(int));
        if (!id) { perror("malloc"); exit(1); }
        *id = i + 1;
        if (pthread_create(&wthreads[i], NULL, writer, id) != 0) {
            perror("pthread_create writer"); exit(1);
        }
    }

    // join writers
    for (int i = 0; i < NUM_WRITERS; ++i) {
        pthread_join(wthreads[i], NULL);
    }

    // join readers
    for (int i = 0; i < NUM_READERS; ++i) {
        pthread_join(rthreads[i], NULL);
    }

    printf("All readers and writers finished.\n");

    return 0;
}
