#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;

  pid = fork();

  switch (pid)
  {
  case -1:
    perror("fork() failed\n");
    break;
  case 0: //child process
    execl("/bin/ls", "ls", "-l", (char *)0);
    perror("execl() failed\n");
    break;
  default:          // parent process
    wait((int *)0); //parent will wait until the child dies
    printf("execl() function execution\n");
    exit(0);
  }
  return (0);
}
