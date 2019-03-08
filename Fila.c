#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct no *inicio = NULL;
struct no *fim_fila = NULL;

int tamanho=0;

struct no{
  int dado;
  struct no *prox;
};
typedef struct no Fila;

void insere(int valor) {
	Fila *aux;
	aux = (Fila*) malloc (sizeof(struct no));
	aux->dado = valor;

	if(tamanho==0) { //caso seja o primeiro elemento faz com que os ponteiros inicio e fim apontem para ele
		inicio = aux;
		fim_fila = aux;
	}

	fim_fila->prox = aux; // faz com que o ponteiro prox que fim aponta aponte para aux
	fim_fila = aux; //fim recebe aux
	aux->prox = NULL; //ponteiro prox de aux recebe null(ou seja fim da fila)

	tamanho++;//conta quantos elementos tem na fila
	printf("\n\n\nElemento inserido com sucesso");
}

void exibir_fila() {
	struct no *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}

	aux=inicio;

	while(aux!=NULL) {
		printf(" %d |", aux -> dado);
		aux = aux->prox;
	}
}

void remover() {
	struct no *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	aux = inicio;
	inicio = inicio->prox; //inicio recebe o proximo elemento da fila
	free(aux);
	tamanho--;
	printf("\n\nElemento removido com sucesso\n");
}

void mostrar_primeiro() {
	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	printf("\nO primeiro elemento da fila = %d \n", inicio->dado);
}

int menu(){
     int opc;
     printf("\n--1. Inserir na Fila\n"
            "--2. Remover Elemento \n"
            "--3. Exibir Fila \n"
            "--4. Primeiro elemento\n "
            "--5. Sair\n");
    scanf("%d",&opc);
    return opc;
}

int main(){
	int opc,valor;
	do{
		opc = menu();
	switch(opc){
		case 1:
		printf("Digite valor para a fila:");
		scanf("%d",&valor);
		insere(valor);
		system("cls");
		break;	
			case 2:
				system ("cls");
				remover();
				break;
			case 3:
				system ("cls");
				exibir_fila();
				break;
			case 4:
				system ("cls");
				mostrar_primeiro();
				break;
			case 5:
				system("pause");
			
		}
	}while(opc!=0);
	
}
