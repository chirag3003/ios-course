
#include <sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
  pid_t pid;
  if((pid=fork())<0){
    printf("Fork Error\n");
  } else if (pid == 0) {
    printf("This is the child process\n");
    printf("PID: %d \n", getpid());
  } else {
    sleep(10);
    printf("This is the parent process\n");
    printf("PID: %d \n", getpid());
    system("ps -axj | tail");
  }
}
