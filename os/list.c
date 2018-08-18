#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h> 


void print_status(long tgid) {
    char path[40], line[100], *p, *n, *pp, name[100],pid[10],ppid[10];
    FILE* statusf;

    // Acessa a pasta /proc/pid/status
    snprintf(path, 40, "/proc/%ld/status", tgid);

    statusf = fopen(path, "r");
    if(!statusf)
        return;

    // Abre o arquivo
    while(fgets(line, 100, statusf)) {
        if(strncmp(line, "State:", 6) == 0){
            // Ignore "State:" and whitespace
            p = line + 9;
            while(isspace(*p)) ++p;
    
            printf("Status: %s", p);

        } else if ((strncmp(line, "Name:", 5) == 0)){
            // Ignore "Name: " and whitespace 
            n = line + 6;
            while(isspace(*n)) ++n;
            
            printf("Processo %d com nome: %s", tgid, n--);
        
        } else if ((strncmp(line, "PPid:", 5) == 0)){
            // Ignore "PPid:" and whitespace
            pp = line + 5;
            while(isspace(*pp)) ++pp;
    
            printf("ppid: %s", pp);
        
        } else {
            continue;
        }

    }

    fclose(statusf);
}

int main(int argc, char ** argv ){
    
    if(argc>1){
        long tgid = atol(argv[2]);

        print_status(tgid);
    }

}
