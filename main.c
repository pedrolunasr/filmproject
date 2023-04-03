#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

int main() {
    Lista* lista = cria_lista();
    int codigo;

    int opcao;
    do {
        printf("\n---- Menu ----\n");
        printf("1 - Inserir filme\n");
        printf("2 - Remover filme\n");
        printf("3 - Imprimir todos os filmes\n");
        printf("4 - Imprimir dados de um filme\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                Filme f;
                captura_dados(&f);
                insere_filme(lista, f);
                escreve_arquivo(lista, "Lista.txt");
                break;
            }
            case 2: {
                char titulo[TAM_NOME];
                printf("Digite o codigo do filme a ser removido: ");
                scanf("%d", &codigo);
                remove_filme(lista, codigo);
                escreve_arquivo(lista, "Lista.txt");
                break;
            }
            case 3: {
                imprime_lista(lista);
                break;
            }
            case 4: {
                char titulo[TAM_NOME];
                printf("Digite o codigo do filme a ser impresso: ");
                scanf("%d", &codigo);
                imprime_filme(lista, codigo);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    } while(opcao != 0);

    destroi_lista(lista);
    return 0;
}
