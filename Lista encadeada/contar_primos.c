//O objetivo desse exercício é desenvolver uma função para contar quantos números primos existem em uma lista simplesmente encadeada 


#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int valor;
    struct no *proximo;
}No;


No* insere_inicio(No *l, int x){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = x;
    if(!l){
        novo->proximo = NULL;
        l = novo;
    }
    else{
        novo->proximo = l;
        l = novo;
    }
    return l;
}


No* insere_fim(No *l, int x){
    if(!l){
        l = insere_inicio(l, x);
    }
    else{
        No *novo = (No*)malloc(sizeof(No));
        novo->valor = x;
        novo->proximo = NULL;
        No *aux = l;
        while(1){
            if(aux->proximo == NULL){
                aux->proximo = novo;
                break;
            }
            else{
                aux = aux->proximo;
            }
        }
    }
    return l;
}


No *remover(No *l, int x){
    No *remover, *aux = NULL;
    aux = l;
    if(!l){
        return NULL;
    }
    else if(l->valor == x){
        remover = l;
        l = l->proximo;
        free(remover);
    }
    else{
        while(1){
            if(aux->proximo && aux->proximo->valor == x){
                remover = aux->proximo;
                aux->proximo = aux->proximo->proximo;
                free(remover);
                break;
            }
            else if(!aux->proximo && aux->valor != x){
                break;
            }
            else{
                if(aux->proximo){
                    aux = aux->proximo;
                }
            }
        }
    }
    return l;
}


void imprimir(No *l){
    if(!l){
        return;
    }
    else{
        No *aux = (No*)malloc(sizeof(No));
        aux = l;
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

//Função que conta quantos numeros primos existem em uma lista simplesmente encadeada 
int contar_primos(l){
    int primos = 0;
    if(!l){
        return primos;
    }
    else{
        No *aux = (No*)malloc(sizeof(No));
        aux = l;
        int cont;
        while(1){
            if(aux){
                cont = 0;
                for(int i = 1; i <= aux->valor; i++){
                    if(aux->valor % i == 0){
                        cont += 1;
                    }
                }
                if(cont == 2){
                    primos += 1;
                }
                aux = aux->proximo;
            }
            else{
                break;
            }
        }
        return primos;
    }
}


int main(void){
    No *l = NULL;
    int escolha, num, a;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-imprimir\n4-contar_primos\n5-remover\n6-sair\n");
        scanf("%d", &escolha);
        if(escolha == 6){
            break;
        }
        switch(escolha){
        case 1:
            printf("Digite um numero: ");
            scanf("%d", &num);
            l = insere_inicio(l, num);
            break;
        case 2:
            printf("Digite um numero: ");
            scanf("%d", &num);
            l = insere_fim(l, num);
            break;
        case 3:
            imprimir(l);
            break;
        case 4:
            a = contar_primos(l);
            printf("Existem %d primos na lista\n", a);
            break;
        case 5:
            printf("Digite um numero: ");
            scanf("%d", &num);
            l = remover(l, num);
            break;
        }
    }
}