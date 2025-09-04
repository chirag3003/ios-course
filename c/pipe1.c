#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 20

int main() {
  int fileDes[2];
  pid_t pid;

  if (pipe(fileDes) == -1) {
    printf("Error creating pipe \n");
    exit(1);
  }

  pid = fork();
  if (pid > 0) { // Parent process
    close(fileDes[0]);
    if (write(fileDes[1], "Hello World", MAX) == -1) {
      printf("Error writing to pipe \n");
      exit(1);
    } 
    wait(NULL);
  } else if (pid == 0) { // Child process
    close(fileDes[1]);
    char buf[MAX];
    if (read(fileDes[0], buf, MAX) == -1) {
      printf("Error reading from pipe \n");
      exit(1);
    }
    printf("Child: I received %s from Parent\n", buf);
    exit(0);
  } else {
    printf("Error in forking \n");
    exit(1);
  }
  return 0;
}
