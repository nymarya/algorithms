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
    //struct node* children[10];
    // Vai ser arvore n-aria
    struct node *child;   // point to children of this node
    struct node *next; 
    size_t size;
    size_t max;
    char ** name;
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

  node->size = 0;
  node->max = 10;
  //node->children = (struct node **) malloc(10 * sizeof(struct node));
  node->child =  NULL;
  node->next = NULL;
  return(node);
}

void add_child(struct node * node, struct node * nNode){
    /**size_t size = node->size;
    
    if( node->size == node->max){
        //resize
        node->children = ( struct node**) realloc(node->children, (size + 10) * sizeof(struct node *));
        node->max += 10;
    }
    node->children[size] = nNode;
    node->size++;**/
    struct node* current = node->child;
    if(current != NULL){
        while( current->next != NULL){
            current = current->next;
        }
        current->next = nNode;
    } else{
        node->child = nNode;
    }
    
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     /* first print data of node */
     printf("%d ", node->data);  

     
     printPreorder(node->child);
     printPreorder(node->next);
     
} 
struct node *find_node(struct node *root, int key){
  // stop case
  if (root==NULL) return NULL;
  if (root->data==key){
    return root;
  } 
  // first we'll recurse on the siblings
  struct node *found = find_node(root->next,key) ;
  if(found!= NULL){
      return found;
  }
  return find_node(root->child,key);
}
void buildProcessTree(long tgid, struct node* root){
   //Recupera processo pai
    char path[40], line[100], *p, str[5], name[50];
    FILE* statusf;
    int id;

    // Acessa a pasta /proc/pid/stat
    snprintf(path, 40, "/proc/%ld/stat", tgid);
    statusf = fopen(path, "r");
    if(!statusf)
        return;

    // Abre o arquivos
    while(fgets(line, 100, statusf)) {
        
        // Ignore "State:" (pula os 7 caracteres) and whitespace (pula os espaços em branco)
        p = line;
        // Pula 4 vezes os intervalos de espaços
        for (int i =0; i < 2; i++ ){
            while(!isspace(*p)) ++p;
            while(isspace(*p)) ++p;
        }
        // recupera name
        int i = 0;
        while(!isspace(*p)){
            name[i++] = *p;
            p++;
        }

        while(isspace(*p)) ++p;
        //recupera parent id
        i = 0;
        while(!isspace(*p)){
            str[i++] = *p;
            p++;
        }
        id = atoi(str);

        printf("%6d %d\n", tgid, id);
        break;
    }

    fclose(statusf);

   
   //Procura processo pai na arvore
   struct node * found = find_node(root, tgid);
   if( node == NULL){
       node = newNode(tgid);
   } else {
       //verifica se esta sem nome
       strcpy(node->name, name);
   }

   
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

	struct node *root = newNode(1);

	while(ent = readdir(proc)) {
	    if(!isdigit(*ent->d_name))
		continue;

	    tgid = strtol(ent->d_name, NULL, 10);

	    // print_status(tgid);
        buildProcessTree(232, root);
        break;
	}

	closedir(proc);
/**
    struct node *root  = newNode(1);
    struct node *n2  = newNode(2);
    struct node *n3  = newNode(3);
    struct node *n4  = newNode(4);
    struct node *n5  = newNode(5);
    struct node *n6  = newNode(6);
    struct node *n7  = newNode(7);

    add_child(root, n2);
    add_child(root, n3);
    add_child(root, n4);
    add_child(root->child, n5);
    add_child(root->child, n6);
    add_child(root->child->next, n7);


    printPreorder(root);
**/

}
