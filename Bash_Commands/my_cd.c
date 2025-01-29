#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char** argv) {

char buffer[1024];
char* path = realpath(argv[1], buffer);
chdir(path);

getwd(buffer);
int buffLen = strlen(buffer); // strlen = # of chars until \0
buffer[buffLen]   = '\n';
buffer[buffLen+1] = '\0';
write(1, buffer, strlen(buffer));

 }
