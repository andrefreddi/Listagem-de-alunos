# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <time.h>
# include <string.h>
# include <locale.h>

int searchStudent();
int insertStudent();
void imprimeAtras();

struct node *head = NULL;
struct node *last = NULL;

typedef struct _student
{
	int		    id;
	char		name[100];
	float		gpa;
}student;

typedef struct _node
{
	student k;
	
	struct _node *next;
	struct _node *prev;
}node, *list;

void insert_list(list *L, student k)
{
	node  *novo;
	
	novo = (node *)malloc(sizeof(node));
	novo->k = k;
	novo->next = *L;
	*L = novo;
}

student *search_list(list L, int id)
{
	node *novo;
	
	for(novo = L; novo && novo->k.id != id; novo= novo->next);
	if(novo)
	return &novo->k;
}

void create_list(list *L)
{
	*L = NULL;	
}

// == == == MENU == == == 

int main(){
	
	system("color 3");
	setlocale(LC_ALL, "Portuguese");
	
	int opcao;
	
	do{
		system("@cls||clear");
		printf(" ----------------------------\n");
		printf(" | > Escolha uma opcao      |\n");
		printf(" |                          |\n");
		printf(" | > 1 < Buscar Alunos      |\n");
		printf(" | > 2 < Cadastrar Aluno    |\n");
		printf(" | > 3 < Ordenar Alunos     |\n");
		printf(" | > 4 < Ordem Decrescente  |\n");
		printf(" ----------------------------\n");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				searchStudent();
				system("@cls||clear");
				break;
				
			case 2:
				insertStudent();
				system("@cls||clear");
				break;
				
			case 3:
			//	printOrdenado();
				system("@cls||clear");
				break;
				
			case 4:
				imprimeAtras();
				system("@cls||clear");
				break;
		}
	}
	
	while(opcao!=5);
}

// == == == FIM MENU  == == == 

// == == == FUNCOES == == ==

int searchStudent()
{
		
	system("@cls||clear");
	
	list		C;
	student		s, *novo;
	int		    id;	
	struct node *p = last;
	
	FILE		*arq;
	arq = fopen ("list.txt", "r");

	if (arq == NULL)
	{	
   		printf("ERRO! O arquivo nao foi aberto!\n");
    }
	else
	{
	create_list(&C);
	
	for(;;)
	{
		fscanf (arq, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof(arq))
        break;
		insert_list (&C, s);
	}
	fclose (arq);
	}

	for (;;)
	{
		system("@cls||clear");
		printf(" > Para voltar ao menu digite > 0 <\n\n");
		printf(" > Qual o ID do aluno(a) que deseja procurar?\n > ");
		scanf("%d", &id);

	if(id == 0)
           main();

	novo = search_list (C, id);

	while(p != NULL)
		system("@cls||clear");
		printf (" > Informacoes do aluno(a):\n");
		printf(" > ID: %d \n > Nome: %s \n > Nota: %0.2f \n\n", novo->id, novo->name, novo->gpa);
		system("pause");
	}
}

int insertStudent()
{
	
	system("@cls||clear");

	int id, resp;
	char name[100];
	float gpa;
	
	FILE *arq;
	arq = fopen ("list.txt", "a");

	if (arq == NULL)
	{
    	printf("ERRO! O arquivo nao foi aberto!\n");
    }
	else
	{
		
	    printf(" > ID do estudante: \n");
	    printf(" > ");
		scanf("%d", &id);
		
		printf(" > Nome do estudante: \n");
		printf(" > ");
		scanf("%s", name);
		
		printf(" > Nota do estudante: \n");
		printf(" > ");
		scanf("%f", &gpa);
		
		fprintf(arq, "\n");
		fprintf(arq, "%d %s %2.f", id, name, gpa);
	}
	
		printf("\n > Cadastrar outro aluno?\n");
		printf(" > 1 < Sim\n > 2 < Nao\n");
		printf(" > ");
		scanf("%d", &resp);
	
	if(resp == 1)
	{
		fclose (arq);
		insertStudent();
	}
	else
	{
		fclose (arq);
		main();
	}

}

void imprimeAtras()
{
	list		C;
	student		s, *aux;
	int		    id;
	int i;
	
	FILE		*arq;

	arq = fopen ("list.txt", "r");

	if (arq == NULL){
		
  	  printf("ERRO! O arquivo nao foi aberto!\n");
  	  system("pause");
    
    }
	else
	{
    node *aux;
	aux = last;
	fclose(arq);
	
		while(aux->prev != NULL)
		{
    		printf("\n Id: %d, Nome: %s, Nota: %2.f", aux->k.id, aux->k.name, aux->k.gpa);
   			//aux = aux->prev;
  		}

  	//aux = imprimeDesc(C, id);
  	printf("\n Id: %d, Nome: %s, Nota: %2.f", aux->k.id, aux->k.name, aux->k.gpa);  

	}
}
