#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define MAX 20

int main()
{
  int parentFileDes[2];
  int childFileDes[2];
  pid_t pid;

  if (pipe(parentFileDes) == -1 || pipe(childFileDes) == -1)
  {
    printf("Error creating pipe \n");
    exit(1);
  }

  pid = fork();

  if (pid > 0)
  { // Parent process
    // Closing read for parent and write for child
    close(parentFileDes[0]);
    close(childFileDes[1]);
    char parentInput[MAX];
    printf("Parent: Enter some text: \n");
    fgets(parentInput, MAX, stdin);
    if (write(parentFileDes[1], parentInput, MAX) == -1)
    {
      printf("Error writing to Child \n");
      exit(1);
    }
    char buf[MAX];
    if (read(childFileDes[0], buf, MAX) == -1)
    {
      printf("Error reading from Child \n");
      exit(1);
    }
    printf("Parent: I received %s\n from Child \n", buf);
    wait(NULL);
  }
  else if (pid == 0)
  { // Child process
    // Closing write for parent and read for child
    close(parentFileDes[1]);
    close(childFileDes[0]);
    char userInput[MAX];
    printf("Child: Enter some text :");
    fgets(userInput, MAX, stdin);
    if (write(childFileDes[1], userInput, MAX) == -1)
    {
      printf("Error writing to Parent \n");
      exit(1);
    }
    char buf[MAX];
    if (read(parentFileDes[0], buf, MAX) == -1)
    {
      printf("Error reading from Parent \n");
      exit(1);
    }
    printf("Child: I received %s from Parent\n", buf);
    exit(0);
  }
  else
  {
    printf("Error in forking \n");
    exit(1);
  }
  return 0;
}
