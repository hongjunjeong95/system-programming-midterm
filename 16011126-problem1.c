#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid, wpid;
  int status;

  // Create the child process by using fork()
  // 만약 fork()가 오작동하면 perror를 통해 error 메시지를 생성한다.
  if ((pid = fork()) < 0)
    perror("error in fork()\n");

  /* here, the child code part */
  // pid 값이 0이면 child process다.
  else if (pid == 0)
  {
    // Get the process id by getpid() and get the parent process id by getppid()
    printf("Child PID is %d, Parent PID is %d\n", getpid(), getppid());
    exit(7);
  }

  /* here, the parent code part */
  else
  {
    // The parent process wait until the child process dies
    if ((wpid = wait(&status)) != pid)
      perror("wait error");

    // Get the parent proces id
    printf("Parent PID is %d\n", getpid());
  }

  exit(EXIT_SUCCESS);
}
