#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>

int main(int argc, char **argv){
    if(argc>1){
        int limit = atoi(argv[2]);

	

	    struct rlimit rlim;
        getrlimit(RLIMIT_NPROC, &rlim);
        int cur = rlim.rlim_cur;
     	int max = rlim.rlim_max;
	    printf("RLIMIT :rlim_cur => %i, :rlim_max => %i", cur, max);

        // Change the limit 
        rlim.rlim_cur = limit; 
        rlim.rlim_max = limit; 

        // Now call setrlimit() to set the  
        // changed value. 
        setrlimit (RLIMIT_NPROC, &rlim);

        // Check
        getrlimit(RLIMIT_NPROC, &rlim);
        cur = rlim.rlim_cur;
        max = rlim.rlim_max;
        printf("\nRLIMIT :rlim_cur => %i, :rlim_max => %i", cur, max); 

    }
   
   // ulimit -u $limit

}
