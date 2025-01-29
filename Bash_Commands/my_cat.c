#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv) {
int fd, nread;
for(int i = 1; i < argc; i++){
  char buffer[516];
  fd = open(argv[i], O_RDONLY);
  while ((nread = read(fd, buffer, sizeof(buffer))) > 0){
    write(1, buffer, nread);
  }
}
  return 0;
}
