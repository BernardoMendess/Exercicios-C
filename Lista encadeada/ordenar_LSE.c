//O objetivo desse exercício é desenvolver uma função para ordenar uma lista simplesmente encadeada


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

//Função que ordena uma lista simplesmente encadeada 
No* ordenar(No *l){
    if(!l){
        return NULL;
    }
    else{
        No *aux = l;
        int cont = 0, cont_mud = 1, temp;
        while (aux){
            cont += 1;
            aux = aux->proximo;
        }
        while(cont_mud != 0){
            cont_mud = 0;
            aux = l;
            for(int i = 0; i < cont; i++){
                if(aux == l){
                    if(aux->proximo && aux->valor > aux->proximo->valor){
                        temp = aux->valor;
                        aux->valor = aux->proximo->valor;
                        aux->proximo->valor = temp;
                        l = aux;
                        cont_mud = 1;
                    }
                }
                if(aux->proximo){
                    if(aux->valor > aux->proximo->valor){
                        temp = aux->valor;
                        aux->valor = aux->proximo->valor;
                        aux->proximo->valor = temp;
                        cont_mud = 1;
                    }
                }
                aux = aux->proximo;
            }
        }
        return l;
    }
}


int main(void){
    No *l = NULL;
    int escolha, num;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-imprimir\n4-ordernar\n5-remover\n6-sair\n");
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
            l = ordenar(l);
            break;
        case 5:
            printf("Digite um numero: ");
            scanf("%d", &num);
            l = remover(l, num);
            break;
        }
    }
}