//O objetivo desse exercício é fazer uma função que troque a segunda metade de uma pilha com a primeira metade de lugar. Suponha que o número de elementos seja par.

#include <stdlib.h>
#include <stdio.h>


typedef struct pilha{
    int topo;
    int vet[10];
}Pilha;

#define tam 10


void push_pilha(Pilha *p, int x){
    if(p->topo == tam){
        return;
    }
    else{
        p->vet[p->topo] = x;
        p->topo++;
    }
}


int pilha_pop(Pilha *p){
    if(p->topo >= 0){
        int x;
        p->topo--;
        p->vet[p->topo] = x;
    }
}


void libera_pilha(Pilha *p){
    int x;
    for(int i = 0; i < p->topo; i++){
        p->vet[i] = x;
    }
    p->topo = 0;
}

Pilha* trocar(Pilha *p){
    Pilha *p1 = (Pilha*)malloc(sizeof(Pilha));
    Pilha *p2 = (Pilha*)malloc(sizeof(Pilha));
    p1->topo = p->topo/2;
    p2->topo = p->topo/2;
    for(int i = 0; i < p->topo/2; i++){
        p2->vet[i] = p->vet[i];
    }
    for(int i = (p1->topo); i < p->topo; i++){
        p1->vet[i] = p->vet[i];
    }
    for(int i = (p1->topo); i < p->topo; i++){
        p->vet[i-p1->topo] = p1->vet[i];
    }
    for(int i = p2->topo; i < p->topo; i++){
      p->vet[i] = p2->vet[i-p2->topo];
      }
    return p;
}


void imprimir(Pilha *p){
    printf("\n");
    for(int i = p->topo-1; i >= 0; i--){
        printf("|%d|\n", p->vet[i]);
    }
}


int main(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = 0;
    push_pilha(p, 0);
    push_pilha(p, 1);
    push_pilha(p, 2);
    push_pilha(p, 3);
    push_pilha(p, 4);
    push_pilha(p, 5);
    push_pilha(p, 6);
    push_pilha(p, 7);
    push_pilha(p, 8);
    push_pilha(p, 9);
    printf("Antes da troca: ");
    imprimir(p);
    p = trocar(p);
    printf("Depois da troca: ");
    imprimir(p);
}
