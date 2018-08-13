#include <stdio.h>

int main(int argc, char **argv){
   int limit = atoi(argv[2]);
   printf("%i", limit);
   char buffer[20];
   snprintf(buffer, sizeof(buffer), "getrlimit()");
   system(buffer);
}
