#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    // Vai ser arvore n-aria
};
 
/* newNode() allocates a new node with the given data and NULL left and 
   right pointers. */
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void buildProcessTree(long tgid){
   //Recupera processo pai
   
   //Procura processo pai na arvore
   
   // Adiciona à lista de filhos
}

void print_status(long tgid) {
    char path[40], line[100], *p;
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
        if(strncmp(line, "State:", 6) != 0)
            continue;
        // Ignore "State:" (pula os 7 caracteres) and whitespace (pula os espaços em branco)
        p = line + 7;
        while(isspace(*p)) ++p;

        printf("%6d %s", tgid, p);
        break;
    }

    fclose(statusf);
}

int main(){

	DIR* proc = opendir("/proc");
	struct dirent* ent;
	long tgid;

	if(proc == NULL) {
	    perror("opendir(/proc)");
	    return 1;
	}

	struct node *root = newNode(0);

	while(ent = readdir(proc)) {
	    if(!isdigit(*ent->d_name))
		continue;

	    tgid = strtol(ent->d_name, NULL, 10);

	    print_status(tgid);
	}

	closedir(proc);

}
