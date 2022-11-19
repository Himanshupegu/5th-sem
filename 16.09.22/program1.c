#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t p;
  p = fork();
  if (p == 0)
  { // child
    sleep(3);
    printf("I am child having PID %d\n", getpid());
    printf("My Parent PID is %d\n", getppid());
  }
  else
  {
    wait(NULL);
    sleep(3);
    printf("I am parent having PID %d\n", getpid());
    printf("My child PID %d\n", p);
  }
}


//./a.out & ps