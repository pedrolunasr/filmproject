#ifndef FILMES_H_INCLUDED
#define FILMES_H_INCLUDED

#define TAM_NOME 50
#define TAM_GENERO 20
#define TAM_DIRETOR 30

typedef struct filme Filme;

struct filme {
    int codigo;
    char nome[TAM_NOME];
    char genero[TAM_GENERO];
    char diretor[TAM_DIRETOR];
    char ano[5];
    float duracao;
};

typedef struct no No;

struct no {
    Filme filme;
    No* prox;
};

typedef struct lista Lista;

struct lista {
    No* inicio;
};

Lista* cria_lista();
void destroi_lista(Lista* lista);
void captura_dados(Filme* f);
void imprime_lista(Lista* lista);
void insere_filme(Lista* lista, Filme filme);
void remove_filme(Lista* lista, int codigo);
void imprime_filme(Lista* lista, int codigo);
void escreve_arquivo(Lista* lista, char* nome_arquivo);

#endif
