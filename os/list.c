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
    //ppid is the 4th parameter of /proc/pid/stat

    statusf = fopen(path, "r");
    if(!statusf)
        return;

    // Abre o arquivos
    // Formato das linhas: State:    S (sleeping)
    while(fgets(line, 100, statusf)) {
        printf("%s", line);
        if(strncmp(line, "State:", 6) == 0){
            // Ignore "State:" (pula os 7 caracteres) and whitespace (pula os espaços em branco)
            p = line + 8;
            while(isspace(*p)) ++p;
    
            printf("%s", p);
            break;
        } else if ((strncmp(line, "Name:", 5) == 0)){
            // Ignore "State:" (pula os 7 caracteres) and whitespace (pula os espaços em branco)
            n = line + 6;
            while(isspace(*n)) ++n;
    
            printf("%6d (%s): ", tgid, n);
            break;
        
        } else if ((strncmp(line, "PPid:", 5) == 0)){
            // Ignore "State:" (pula os 7 caracteres) and whitespace (pula os espaços em branco)
            pp = line + 5;
            while(isspace(*p)) ++pp;
    
            printf("ppid %s: ", pp);
            break;
        
        } else {
            continue;
        }

    }

    fclose(statusf);
}

int main(int argc, char ** argv ){
    
    if(argc>1){
        long tgid = atol(argv[2]);

    	DIR* proc = opendir("/proc");
    	struct dirent* ent;
    	//long tgid;
    
    	if(proc == NULL) {
    	    perror("opendir(/proc)");
    	    return 1;
    	}
    
    	while(ent = readdir(proc)) {
    	    if(!isdigit(*ent->d_name))
    		continue;
    
    	    //tgid = strtol(ent->d_name, NULL, 10);
    
            int i = 0;
            //while( )
    	    //print_status(tgid);
    	}
    	int i = 0;
    	while( i++ < 10){
    	    print_status(tgid);
    	    sleep(1);
    	}
    
    	closedir(proc);
    }

}
