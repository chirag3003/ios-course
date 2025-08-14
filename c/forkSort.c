/**
* Author: Chirag Bhalotia
* Date: Aug 5, 2025
* PRN: 1032232301
* ROLL: 63
*/


#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void ascendingSort(int arr[], int n);
void descendingSort(int arr[], int n);
void printArray(int arr[], int n);

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    printf("Enter the element %d: ", i + 1);
    scanf("%d", &arr[i]);
  }
  printArray(arr, n);

  pid_t pid = fork();
  if (pid == 0) {
    printf("This is the child process, PID: %d\n", getpid());
    descendingSort(arr, n);
    printArray(arr, n);
  }else if( pid > 0 ){
    printf("This is the parent process, PID: %d\n", getpid());
    ascendingSort(arr,n);
    printArray(arr, n);
    wait(NULL);
  }

  return 0;
}

void ascendingSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void descendingSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printArray(int arr[], int n) {
  printf("%d", arr[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", arr[i]);
  }
  printf("\n");
}
