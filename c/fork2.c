#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

pid_t num_pid;

int main(void) {
  num_pid = fork();
  if (num_pid == 0) {
    printf("This is the child process\n");
  } else if (num_pid < 0) {
    printf("Error in forking \n");
  } else {
    printf("This is the parent process\n");
    printf("PID: %d \n", getpid());
    wait(NULL);
  }
  return 0;
}
