// http://hpca23.cse.tamu.edu/taco/utsa-www/ut/utsa/cs1723/lecture4.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>


typedef struct _student {
	int		    id;
	char		name[100];
	float		gpa;
} student;

typedef struct _node {
	student k; //pq k nao é ponteiro
	struct _node *next; // ponteiro para o proximo elemento
	struct _node *anterior;
} node, *list; //pq list e um ponteiro

struct node *ultimo = NULL;

void insert_list (list *L, student k){
	node  *novo; //*p
	novo = (node *)malloc(sizeof(node));
	novo->k = k;
	novo->next = *L;

	*L = novo;
}

student *search_list (list L, int id){
	node	*novo;

	for(novo = L; novo && novo->k.id != id; novo= novo->next);

	if(novo)
		return &novo->k;
}

void create_list (list *L){
	*L = NULL;
}

int searchStudents(){
		
	system("@cls||clear");
	
	list		C;	/* a class of students */
	student		s, *novo;
	int		    id;
	
	struct node *p = ultimo;
	
	FILE		*arq;

	arq = fopen ("list.txt", "r"); //alterado nome arquivo
	/*if (!f) {
		perror ("List");
		exit (1);
	}*/
	
	if (arq == NULL){
    printf(" > ERRO! O arquivo não foi aberto!\n");
}else{

	create_list(&C);

	for(;;){
		fscanf (arq, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (arq))
      break;
		insert_list (&C, s);
	}
	
	fclose (arq);
	
	}

	for (;;) {
		system("@cls||clear");
		printf(" > Para voltar ao menu digite > 0 <\n\n");
		printf(" > Qual o ID do aluno(a) que deseja procurar?\n > ");
		scanf("%d", &id);

		if(id == 0) //zero é mais fácil
           main();

		novo = search_list (C, id);

		if(!novo)
			printf (" > O ID do aluno(a) > %d < nao foi encontrado!\n\n", id);
			system("pause");
		while(p != NULL)
			printf (" > Informacoes do aluno(a):\n");
			printf(" > ID: %d \n > Nome: %s \n > Nota: %0.2f \n\n", novo->id, novo->name, novo->gpa);
			system("pause");
		//	p = p->anterior;
	}
	//exit (0);
}

int insertStudents() { //funcao insert
	
	system("@cls||clear");
	
	//list		C;	/* a class of students */
	//student		s, *novo;
	int id, resp;
	char name[100];
	float gpa;
	
	FILE *arq;

	arq = fopen ("list.txt", "a"); //alterado nome arquivo
	/*if (!arq) {
		perror ("List");
		exit (1);
	}*/
	
	if (arq == NULL){
    printf(" > ERRO! O arquivo não foi aberto!\n");
    
    }else{

	//create_list (&C);

	/*for (;;) {
		fscanf (arq, "%d %s %f\n", &s.id, s.name, &s.gpa);
		if (feof (arq))
      break;
		insert_list (&C, s);*/
		
	    printf(" > Insira o ID do estudante: \n > ");
		scanf("%d", &id);
		printf("\n");
		
		printf(" > Insira o nome do estudante: \n > ");
		scanf("%s", name);
		printf("\n");
		
		printf(" > Insira a nota do estudante:\n > ");
		scanf("%f", &gpa);
		printf("\n");
		
		fprintf(arq, "\n");
		fprintf(arq, "%d %s %2.f", id, name, gpa);
	}
	
	printf("\n > Cadastrar outro aluno?\n");
	printf(" > 1 < Sim\n > 2 < Não\n > ");
	scanf("%d", &resp);
	
	if(resp == 1){
		fclose (arq);
		insertStudents();
	}else{
		fclose (arq);
		main();
	}

	/*for (;;) {
		printf ("Enter student ID: \n");
		scanf("%d", &id);
		
		printf("Enter student name: \n");
		scanf("%s", nome);
		
		printf("Enter student note: \n");
		scanf("%f", &gpa);
		
		

		if (id == 0) //zero ï¿½ mais fï¿½cil
           main();

		novo = search_list (C, id);


		if (!novo)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", novo->id, novo->name, novo->gpa);
	}*/
	
	
}

int main(){ //inserido menu
	
	system("color 3");
	setlocale(LC_ALL, "Portuguese"); //inserido locale
	
	int opcao;
	
	do{
		printf(" --------------------------\n");
		printf(" | > Escolha uma opcao    |\n");
		printf(" |                        |\n");
		printf(" | > 1 < Buscar Alunos    |\n");
		printf(" | > 2 < Cadastrar Alunos |\n");
		printf(" | > 3 < Sair             |\n");
		printf(" --------------------------\n > ");
		scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
				searchStudents();
				break;
				
			case 2:
				insertStudents();
				break;
		}
	}
	
	while(opcao!=3);
}
