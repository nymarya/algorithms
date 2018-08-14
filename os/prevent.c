#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>

int main(int argc, char **argv){
   int limit = atoi(argv[2]);
   
   // ulimit -u
   struct rlimit rlim;
   getrlimit(RLIMIT_NPROC, &rlim);
   int64_t cur = rlim.rlim_cur;
   int64_t max = rlim.rlim_max;
   printf("RLIMIT :rlim_cur => %i, :rlim_max => %i", cur, max);
}

