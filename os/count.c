#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h> 


int main(int argc, char ** argv ){
    

    	int i = 0;
    	while( i++ < 10){
    	    // imprime número de processos
			system("ps aux | wc -l");

			// imprime processos por usuário
			system("ps -eo user=|sort|uniq -c");
    	    sleep(1);
    	}


}
