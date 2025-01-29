#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char** argv) {
int source, nread, destination;
char buffer[516];
char buffer2[1024];

source = open(argv[1], O_RDONLY);
destination = open(argv[2], O_CREAT|O_WRONLY);

while ((nread = read(source, buffer, 516)) > 0){
  write(destination, buffer, nread);
 printf("%d\n", source);
 printf("%s\n", buffer);
 printf("%d\n", nread);
  }
  return 0;
  }
