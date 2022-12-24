#include <stdio.h>
#include <stdlib.h>


typedef struct cont{
    char nome[50];
    char telefone[15];
    char email[50];
    struct cont *proximo;
}Contatos;


Contatos* criar_contato(Contatos *c){
    Contatos *novo = (Contatos*)malloc(sizeof(Contatos));
    printf("\nDigite o nome: ");
    gets(novo->nome);
    fflush(stdin);
    printf("Digite o email: ");
    gets(novo->email);
    fflush(stdin);
    printf("Digite o telefone: ");
    gets(novo->telefone);
    fflush(stdin);
    novo->proximo = NULL;
    if(!c){
        c = novo;
    }
    else{
        Contatos *aux = c;
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
    return c;
}


Contatos* excluir_contato(Contatos *c){
    if(!c){
        return NULL;
    }
    else{
        char nome_excluir[50];
        printf("Digite o nome do contato que deseja excluir: ");
        gets(nome_excluir);
        int comp = 0;
        Contatos *remover, *aux = c;
        comp = strcmp(nome_excluir, c->nome);
        if(comp == 0){
            remover = c;
            c = c->proximo;
            free(remover);
        }
        else{
            while(1){
                if(aux->proximo){
                    int comp = 0;
                    comp = strcmp(nome_excluir, aux->proximo->nome);
                    if(comp == 0){
                        remover = aux->proximo;
                        aux->proximo = aux->proximo->proximo;
                        free(remover);
                    }
                }
                else if(!aux->proximo){
                    break;
                }
                else{
                    if(aux->proximo){
                        aux = aux->proximo;
                    }
                }
            }
        }
        return c;
    }
}


void imprimir_contato(Contatos *c){
    Contatos *aux = c;
    if(!c){
        return;
    }
    while(1){
        if(aux){
            printf("\n=============================================\n");
            printf("Nome: %s\n", aux->nome);
            printf("Email: %s\n", aux->email);
            printf("Telefone: %s\n", aux->telefone);
            printf("=============================================\n");
            aux = aux->proximo;
        }
        else{
            break;
        }
    }
}


int main(void){
    Contatos *c = NULL;
    int escolha;
    while(1){
        printf("\n============AGENDA============\n");
        printf("| 1 - Incluir contato        |\n");
        printf("| 2 - Excluir contato        |\n");
        printf("| 3 - Imprimir contatos      |\n");
        printf("| 4 - Sair                   |\n");
        printf("==============================\n");
        printf("Digite a opcao que voce deseja: ");
        scanf("%d", &escolha);
        if(escolha == 4){
            printf("Tenha um bom dia!!!\n");
            break;
        }
        else if(escolha == 1){
            fflush(stdin);
            c = criar_contato(c);
        }
        else if(escolha == 2){
            fflush(stdin);
            c = excluir_contato(c);
        }
        else if(escolha == 3){
            fflush(stdin);
            imprimir_contato(c);
        }
        else{printf("Digite um valor valido!\n");}
    }
}