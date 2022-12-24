//O objetivo desse exercício é implentar uma fila utilizando uma lista simplesmente encadeada

#include <stdlib.h>
#include <stdio.h>


typedef struct No{
    int valor;
    struct No *proximo;
}No;


No *inserir(No *f, int num){
    No *novo = (No*)malloc(sizeof(No));
    novo->proximo = NULL;
    novo->valor = num;
    if(!f){
        f = novo;
    }
    else{
        No *aux = f;
        while(1){
            if(!aux->proximo){
                aux->proximo = novo;
                break;
            }
            else{
                aux = aux->proximo;
            }
        }
    }
    return f;
}


No *retirar(No *f){
    if(!f){
        return NULL;
    }
    else{
        No *aux = f;
        f = f->proximo;
        free(aux);
        return f;
    }
}


void imprimir(No *f){
    No *aux = f;
    if(!f){
        return;
    }
    else{
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
}

No *limpar(No *f){
    if(!f){
        return NULL;
    }
    else{
        while(f){
            No *aux = f;
            f = f->proximo;
            free(aux);
        }
        return NULL;
    }
}   


int main(){
    No *f = NULL;
    int escolha, num;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir\n2-retirar\n3-imprimir\n4-limpar\n5-sair\n");
        scanf("%d", &escolha);
        if(escolha == 5){
            break;
        }
        switch(escolha){
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            f = inserir(f, num);
            break;
        case 2:
            f = retirar(f);
            break;
        case 3:
            imprimir(f);
            break;
        case 4:
            f = limpar(f);
            break;
        }
    }
    return 0;
}