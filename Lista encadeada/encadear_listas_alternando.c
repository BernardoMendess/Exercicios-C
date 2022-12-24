/*Implemente uma função recursiva que encadeia de forma alternada os nós de duas listas l1 e l2. O primeiro nó deve vir da lista l1, caso não seja nula. 
Se uma das listas for menor do que a outra, o restante dos nós da maior lista deve ser encadeado no final da intercalação*/


#include <stdlib.h>
#include <stdio.h>

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

  

No* insere_ordenado(No *l, int x){
    if(!l){
        l = insere_inicio(l, x);
    }
    else{
        No *aux, *novo = (No*)malloc(sizeof(No));
        novo->valor = x;
        novo->proximo = NULL;
        if(novo->valor < l->valor){
            novo->proximo = l;
            l = novo;
        }
        else{
            aux = l;
            while(1){
                if(aux->proximo){
                    if(aux->valor <= novo->valor && aux->proximo->valor >= novo->valor){
                        novo->proximo = aux->proximo;
                        aux->proximo = novo;
                        break;
                    }
                }
                else{ 
                    if(aux->valor <= novo->valor){
                        novo->proximo = NULL;
                        aux->proximo = novo;
                        break;
                    }
                }
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


void imprime(No *l){
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


No* intercalar(No *l1, No *l2){
    if(l1 && l2){
        No* aux = l1->proximo;
        l1->proximo = l2;
        l2->proximo = intercalar(aux, l2->proximo);
    }
    else if(l1 && !l2){
        return l1;
    }
    else if(!l1 && l2){
        return l2;
    }
    else{
        return NULL;
    }
    return l1;
}


int main(void){
    No* l1 = NULL;
    int num;
    int escolha;
    printf("\nlista 1:\n");
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-inserir ordenado\n4-remover\n5-imprimir\n6-sair\n");
        scanf("%d", &escolha);
        if(escolha == 6){
            break;
        }
        switch(escolha){
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l1 = insere_inicio(l1, num);
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &num);            
                l1 = insere_fim(l1, num);
                break;
            case 3:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l1 = insere_ordenado(l1, num);
                break;
            case 4:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l1 = remover(l1, num);
                break;
            case 5:
                imprime(l1);
                break;
        }
    }
    No* l2 = NULL;
    printf("\nlista 2:\n");
    for(;;){
        printf("Escolha uma opcao:\n1-inserir inicio\n2-inserir no fim\n3-inserir ordenado\n4-remover\n5-imprimir\n6-sair\n");
        scanf("%d", &escolha);
        if(escolha == 6){
            break;
        }
        switch(escolha){
            case 1:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l2 = insere_inicio(l2, num);
                break;
            case 2:
                printf("Digite um numero: ");
                scanf("%d", &num);            
                l2 = insere_fim(l2, num);
                break;
            case 3:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l2 = insere_ordenado(l2, num);
                break;
            case 4:
                printf("Digite um numero: ");
                scanf("%d", &num);
                l2 = remover(l2, num);
                break;
            case 5:
                imprime(l2);
                break;
        }
    }
    No* l = intercalar(l1, l2);
    printf("A lista intercalada e: ");
    imprime(l);
}