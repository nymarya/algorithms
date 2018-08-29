#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main( int argc, char *argv[] )
{

  FILE* fp, *btn;
  char path[1035], value[10];
  double cpu;
  int pid;

  int i = 1;
  
  long int j = 100000;
  while( j-- > 0 ){
    /* Open the command for reading. */
    fp = popen("ps -e -o pid,%cpu --sort=-pcpu | head -2", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    /* Consome a primeira linha da saída do comando */
    if (fgets(path, sizeof(path)-1, fp) != NULL ) {
        
    }

    if (fgets(path, sizeof(path)-1, fp) != NULL ) {
        //printf("%s", path);
        pid =  atoi(strtok (path," ,.-") );
        cpu = atof(strtok (NULL," ") );
    }
    
    if(cpu <= 25 ){
        // acende verde
        system("echo 1 > /sys/class/gpio/gpio50/value");
        system("echo 0 > /sys/class/gpio/gpio51/value");
        system("echo 0 > /sys/class/gpio/gpio60/value");
    } else if( cpu <= 50 ){
        //acende amarelo
        system("echo 0 > /sys/class/gpio/gpio50/value");
        system("echo 1 > /sys/class/gpio/gpio51/value");
        system("echo 0 > /sys/class/gpio/gpio60/value");
    } else if( cpu <= 75 ){
        //acende vermelho
        system("echo 0 > /sys/class/gpio/gpio50/value");
        system("echo 0 > /sys/class/gpio/gpio51/value");
        system("echo 1 > /sys/class/gpio/gpio60/value");
    } else {
        //acende todos
        system("echo 1 > /sys/class/gpio/gpio50/value");
        system("echo 1 > /sys/class/gpio/gpio51/value");
        system("echo 1 > /sys/class/gpio/gpio60/value");

        // checa botao do panico
        btn = popen("cat /sys/class/gpio/gpio115/value", "r");
        if (btn == NULL) {
            printf("Failed to run command\n" );
            exit(1);
        }

        /* Consome a primeira linha da saída do comando */
        if (fgets(value, sizeof(value)-1, btn) != NULL ) {
            int pressed = atoi(value);
            if( pressed == 1){
                //mata processo
                char buffer[30];
                snprintf(buffer, sizeof(buffer), "kill -9 %i", pid);
                system(buffer);

                // apaga os por x segundos
                system("echo 0 > /sys/class/gpio/gpio50/value");
                system("echo 0 > /sys/class/gpio/gpio51/value");
                system("echo 0 > /sys/class/gpio/gpio60/value");
                sleep(5);
            }
        }
    }

    sleep(1);
  }

  

  /* close */
  pclose(fp);

  return 0;
}