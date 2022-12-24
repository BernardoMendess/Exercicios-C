//O objetivo desse exercício é implentar uma pilha utilizando uma lista simplesmente encadeada

#include <stdlib.h>
#include <stdio.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct pilha{
    No* topo;
}Pilha;


void empilhar(Pilha *p, int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = x;
    novo->proximo = NULL;
    if(p->topo == NULL){
        p->topo = novo;
    }
    else{
        novo->proximo = p->topo;
        p->topo = novo; 
    }
}

void desempilhar(Pilha *p){
    No *aux = p->topo;
    p->topo = p->topo->proximo;
    free(aux);
}

void imprimir(Pilha *p){
    No *aux = p->topo;
    while(1){
        if(aux->proximo){
            printf("%d, ", aux->valor);
            aux = aux->proximo;
        }
        else{
            printf("%d\n", aux->valor);
            break;
        }
    }
}

void limpar(Pilha *p){
    No* aux = p->topo;
    while(aux){
        No *rem = aux;
        aux = aux->proximo;
        free(rem);       
    }
    free(p);
}


int main(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    int escolha, num;
    for(;;){
        printf("Escolha uma opcao:\n1-empilhar\n2-desempilhar\n3-imprimir\n4-limpar\n5-sair\n");
        scanf("%d", &escolha);
        if(escolha == 5){
            break;
        }
        switch(escolha){
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            empilhar(p, num);
            break;
        case 2:
            desempilhar(p);
            break;
        case 3:
            imprimir(p);
            break;
        case 4:
            limpar(p);
            break;
        }
    }
}
