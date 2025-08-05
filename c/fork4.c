#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int pid = fork();
  if (pid == 0) {
    sleep(4);
    printf("This is the child process\n");
    printf("child PID: %d \n", getpid());
    printf("parent PID: %d \n", getppid());
  } else if (pid < 0) {
    printf("Error in forking \n");
  } else {
    printf("This is the parent process. PID: %d \n", getpid());
  }
}
