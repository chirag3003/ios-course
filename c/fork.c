#include "stdio.h"
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
    int pid = fork();
    printf("Hello, World!\n");
    return 00;
}
