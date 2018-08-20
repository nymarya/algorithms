#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h> 


int main(int argc, char ** argv ){
    
    if(argc>1){
        long tgid = atol(argv[2]);

        char buffer[30];
        snprintf(buffer, sizeof(buffer), "pstree -p %li > %li.txt", tgid, tgid);
        system(buffer);

    }

}
