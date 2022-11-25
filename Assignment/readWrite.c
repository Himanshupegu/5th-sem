#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
  int fd;
  char wbuf[128] = "Siuuuu!";
  char rbuf[128];
  fd = open("Ronaldo.txt", O_RDWR);
  write(1, wbuf, strlen(wbuf));
  read(0, rbuf, 100);
  printf("%s\n", rbuf);
  close(fd);
  return 0;
}