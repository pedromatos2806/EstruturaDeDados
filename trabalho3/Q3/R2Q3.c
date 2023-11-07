// Alunos:	IGOR PAIM e PEDRO MATOS
#include "R2Q3.h"

int main(){
  FILE *fp_in = fopen("L2Q3.in", "r"); 
	FILE *fp_out = fopen("L2Q3.out", "w");
  char linha[257];
  int cont = 0, flag = 0;
  // *flag = 0;
  
  if(fp_in == NULL)
    perror("error ao abrir o arquivo L2Q1.in\n");
  if(fp_out == NULL)
    perror("error ao abrir o arquivo L2Q1.out\n");
	
	while (	fgets(linha, 257, fp_in)	!= NULL ){
    if(cont != 0)
      fprintf(fp_out, "\n");
    cont++;
		int tamlinha	=	strlen(linha);
		char *token	=	strtok(linha," ");
		Tree *t = createTree(); // cria e inicia a árvore
		
		while(token	!=	NULL){
			if(	strcmp	(token	,	"a"	)	==	0	)	{
				token	=	strtok(NULL," ");
				// inserir na árvore
				int num	=	atoi(token);
				Node *z = createNode(num);
				if(t->root	==	NULL)	{ // se a árvore tiver vazia
					t->root	=	z;
				}else	{
					treeInsert(t,z);
				}
			}else if (	strcmp	(token,"r")	==	0	)	{
				token = strtok(NULL, " ");
				int num =	atoi(token);
				Node *achou =	iterativeTreeSearch(	t->root	, num); //tem que passar a raiz da árvore!
				//remover na árvore
				if(achou	!= NULL	){
					treeDelete(t, achou);
				}else {
					// o "r" vira "a"
					int num	=	atoi(token);
					Node *z = createNode(num);
					if(t->root	==	NULL)	{ // se a árvore tiver vazia
						t->root	=	z;
					}else	{
						treeInsert(t,z);
					}
				}
			}
			token = strtok(NULL," ");
		}
    Node *no = t->root;
    
    percorre(no, fp_out, 0, &flag);
    flag = 0;
    // fprintf(fp_out, "\n");
	}
	
	fclose(fp_in);
  fclose(fp_out);
}