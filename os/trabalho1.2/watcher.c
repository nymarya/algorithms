#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, char *argv[] )
{

  FILE *fp;
  char path[1035];

  int i = 1;

  /* Open the command for reading. */
  fp = popen("ps -e -o pid,%mem --sort=-pmem | head -2", "r");
  if (fp == NULL) {
    printf("Failed to run command\n" );
    exit(1);
  }

  /* Consome a primeira linha da saída do comando */
  if (fgets(path, sizeof(path)-1, fp) != NULL ) {
      
  }

  if (fgets(path, sizeof(path)-1, fp) != NULL ) {
    //printf("%s", path);
    int pid =  atoi(strtok (path," ,.-") );
    double cpu = atof(strtok (NULL," ") );
  }
  
   if(cpu <= 25 ){
       // acende verde
       system("echo 1 > /sys/class/gpio/50/value");
   } else if( cpu <= 50 ){
        //acende amarelo
        system("echo 1 > /sys/class/gpio/51/value");
   } else if( cpu <= 75 ){
       //acende vermelho
       system("echo 1 > /sys/class/gpio/60/value");
   } else {
       //acende todos

       // checa botao do panico
   }

  /* close */
  pclose(fp);

  return 0;
}