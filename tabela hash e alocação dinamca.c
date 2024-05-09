#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAM 15

//-----------------------------------------------//

typedef struct no{
	int chave;
	struct no *prox;
}No;

typedef struct{
	No *ini;
	int tam;
}Lista;

//-----------------------------------------------//

void iniciarLista(Lista *l){
	l->ini = NULL;
	l->tam = 0;
}

//-----------------------------------------------//

void inserirLista(Lista *l, int valor){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->chave = valor;
		novo->prox = l->ini;
		l->ini = novo;
		l->tam++;
	}
	else{
		printf("Erro ao alocar memória\n");
	}
}

//-----------------------------------------------//

int buscarLista(Lista *l, int valor){
	
	No *aux = l->ini;
	
	while(aux && aux->chave != valor){
		aux = aux->prox;
	}
	
	if(aux){
		return aux->chave;
	}
	
	return -1;
}

//-----------------------------------------------//

void imprimirLista(Lista *l){
	No *aux = l->ini;
	
	while(aux){
		printf("%d", aux->chave);
		aux = aux->prox;
	}
}

//-----------------------------------------------//

void iniciarTabela(Lista t[]){
	int i;
	
	for(i=0 ; i<TAM ; i++){
		iniciarLista(&t[i]);
	}
}

//-----------------------------------------------//

int funcaoHash(int valor){
	return (valor%TAM);
}

//-----------------------------------------------//

void inserir(Lista t[], int valor){
	int id = funcaoHash(valor);
	
	inserirLista(&t[id], valor);
}

//-----------------------------------------------//

int buscar(Lista t[], int valor){
	int id = funcaoHash(valor);
	
	return buscarLista(&t[id], valor);
}

//-----------------------------------------------//

void imprimir(Lista t[]){
	int i;
	
	for(i=0 ; i<TAM ; i++){
		printf("%2d = ", i);
		imprimirLista(&t[i]);
		printf("\n");
	}
}

//-----------------------------------------------//

int main(){
	
	int opc, valor, ret;
	Lista tab[TAM];
	
	iniciarTabela(tab);
	
	do{
		
		printf("1 -- Inserir\n2 -- Buscar\n3 -- Listar\n4 -- Sair\n\n");
		scanf("%d", &opc);
		fflush(stdin);
		
		switch(opc){
			case 1:
				printf("Valor: ");
				scanf("%d", &valor);
				fflush(stdin);
				
				inserir(tab, valor);
				
				system("pause");
				break;
			
			case 2:
				printf("Valor: ");
				scanf("%d", &valor);
				fflush(stdin);
				
				ret = buscar(tab, valor);
				
				if(ret != -1){
					printf("\nValor encontrado: %d\n", ret);
				}
				
				system("pause");
				break;
			
			case 3:
				imprimir(tab);
				
				system("pause");
				break;
		}		
		
		system("cls");
	
	}while(opc != 4);
	
	return 0;
}
