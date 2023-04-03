#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro.h"

Lista* cria_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio = NULL;
    return lista;
}

void captura_dados(Filme* f) {
    printf("Digite o codigo do filme: ");
    scanf("%d", &(f->codigo));

    printf("Digite o nome do filme: ");
    scanf(" %[^\n]s", f->nome);

    printf("Digite o genero do filme: ");
    scanf(" %[^\n]s", f->genero);

    printf("Digite o nome do diretor do filme: ");
    scanf(" %[^\n]s", f->diretor);

    printf("Digite o ano de lancamento do filme: ");
    scanf("%s", f->ano);

    printf("Digite a duracao do filme (em minutos): ");
    scanf("%f", &(f->duracao));
}

void destroi_lista(Lista* lista) {
    No* atual = lista->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    free(lista);
}

void imprime_lista(Lista* lista) {
    No* atual = lista->inicio;
    printf("\n---- FILMES CADASTRADOS ----\n");
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->filme.codigo);
        printf("Nome: %s\n", atual->filme.nome);
        printf("Genero: %s\n", atual->filme.genero);
        printf("Diretor: %s\n", atual->filme.diretor);
        printf("Ano: %s\n", atual->filme.ano);
        printf("Duracao: %.2f minutos\n", atual->filme.duracao);
        printf("--------------------------\n");
        atual = atual->prox;
    }
}

void insere_filme(Lista* lista, Filme filme) {
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->filme = filme;
    novo_no->prox = lista->inicio;
    lista->inicio = novo_no;
    printf("\n");
    printf("Filme cadastrado com sucesso!\n");
}

void remove_filme(Lista* lista, int codigo) {
    No* atual = lista->inicio;
    No* anterior = NULL;
    
    while (atual != NULL && atual->filme.codigo != codigo) {
        anterior = atual;
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        printf("Filme com codigo %d nao encontrado na lista.\n", codigo);
        return;
    }
    
    if (anterior == NULL) { // o filme a ser removido é o primeiro da lista
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    
    free(atual);
    printf("Filme com codigo %d removido com sucesso.\n", codigo);
}


void imprime_filme(Lista* lista, int codigo) {
    No* atual = lista->inicio;

    printf("\n");
    
    while (atual != NULL && atual->filme.codigo != codigo) {
        atual = atual->prox;
    }
    
    if (atual == NULL) {
        printf("Filme com codigo %d nao encontrado na lista.\n", codigo);
        return;
    }
    
    printf("Codigo: %d\n", atual->filme.codigo);
    printf("Nome: %s\n", atual->filme.nome);
    printf("Genero: %s\n", atual->filme.genero);
    printf("Diretor: %s\n", atual->filme.diretor);
    printf("Ano: %s\n", atual->filme.ano);
    printf("Duracao: %.2f\n", atual->filme.duracao);
}

void escreve_arquivo(Lista* lista, char* nome_arquivo) {
    FILE* arq = fopen(nome_arquivo, "w");
    if (arq == NULL) {
        printf("Erro ao abrir arquivo para escrita.\n");
        return;
    }
    
    No* atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arq, "Codigo: %d\n", atual->filme.codigo);
        fprintf(arq, "Titulo: %s\n", atual->filme.nome);
        fprintf(arq, "Genero: %s\n", atual->filme.genero);
        fprintf(arq, "Diretor: %s\n", atual->filme.diretor);
        fprintf(arq, "Ano de lancamento: %s\n", atual->filme.ano);
        fprintf(arq, "Duracao: %.2f\n", atual->filme.duracao);
        fprintf(arq, "___________________________\n");
        
        atual = atual->prox;
    }
    
    fclose(arq);
}

