//O objetivo desse exercício é fazer uma lista circular duplamente encadeada

#include <stdlib.h>
#include <stdio.h>


typedef struct no{
  int valor;
  struct no *proximo, *anterior;
  }No;


No* insere_inicio(No *l, int num){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = num;
    if(l == NULL){
        l = novo;
        novo->proximo = l;
        novo->anterior = l;
    }
    else{
        novo->proximo = l;
        novo->anterior = l->anterior;
        l->anterior->proximo = novo;
        l->anterior = novo;
        l = novo;
    }
    return l;
}


No* insere_fim(No *l, int num){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = num;
    if(l == NULL){
        l = novo;
        novo->proximo = l;
        novo->anterior = l;
    }
    else{
        No *aux = l;
        while(1){
            if(aux->proximo == l){
                novo->anterior = aux;
                aux->proximo = novo;
                novo->proximo = l;
                l->anterior = novo;
                break;
            }
            else{
                aux = aux->proximo;
            }
        }
    }
    return l;
}


No* insere_ordenado(No *l, int num){  
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = num;
    if(l == NULL){
        l = novo;
        novo->proximo = l;
        novo->anterior = l;
    }
    else if(l->valor >= novo->valor){
        novo->proximo = l;
        novo->anterior = l->anterior;
        l->anterior->proximo = novo;
        l->anterior = novo;
        l = novo;
    }  
    else{
        No *aux = l;
        while(1){
            if(aux->proximo != l){
                if(aux->valor <= novo->valor && aux->proximo->valor >= novo->valor){
                    aux->proximo->anterior = novo;
                    novo->proximo = aux->proximo;
                    novo->anterior = aux;
                    aux->proximo = novo;
                    break;
                }
                else{
                    aux = aux->proximo;
                }
            }
            else{
                novo->anterior = aux;
                aux->proximo = novo;
                novo->proximo = l;
                l->anterior = novo;
                break;
            }
        }
    }
    return l;
}


No* remove_elemento(No *l, int num){
    if(!l){
        return NULL;
    }
    else{
        No *aux = l;
        if(l->valor == num){;
            l->proximo->anterior = l->anterior;
            l->anterior->proximo = l->proximo;
            aux = l;
            l = l->proximo;
        }
        else{
            while (1){
                if(aux->valor == num){
                    aux->anterior->proximo = aux->proximo;
                    aux->proximo->anterior = aux->anterior;
                    break;
                }
                else{
                    if(aux->proximo != l){
                        aux = aux->proximo;
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return l;
    }   
}


void imprime_lista(No *l){
    if(!l){
        return;
    }
    else{
        No *aux = l;
        while (1){
            if(aux->proximo != l){
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


void imprime_reverso(No* l){
    if(!l){
        return;
    }
    else{
        No *aux = l->anterior;
        while (1){
            if(aux != l){
                printf("%d, ", aux->valor);
                aux = aux->anterior;
            }
            else{
                printf("%d\n", aux->valor);
                break;
            }
        }
    }
}


No* limpar(No *l){
    No* aux = l->proximo;
    while (aux != l){
        No *rem = aux;
        aux = aux->proximo;
        free(rem);
        
    }
    free(l);
    return NULL;
}


int main() {
    No *l = NULL;
    int escolha, num;
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-inserir ordenado\n4-remover\n5-imprimir\n6-imprimir reverso\n7-limpar\n8-sair\n");
        scanf("%d", &escolha);
        if(escolha == 8){
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
                printf("Digite um numero: ");
                scanf("%d", &num);
                l = insere_ordenado(l, num);
                break;
            case 4:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l = remove_elemento(l, num);
                break;
            case 5:
                imprime_lista(l);
                break;
            case 6:
                imprime_reverso(l);
                break;
            case 7:
                l = limpar(l);
                break;
        }
    }
    return 0;
}