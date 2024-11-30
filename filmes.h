#ifndef FILMES_H
#define FILMES_H

#include "usuarios.h"  // Inclua o arquivo de cabeçalho de usuarios para reconhecer o tipo Usuario

#define MAX_FILMES 100
#define MAX_REVIEWS 10
#define TAMANHO_REVIEW 256

typedef struct {
    char comentario[TAMANHO_REVIEW];
    int nota;
    char autor[50];
} Review;

typedef struct {
    char titulo[100];
    int ano;
    char genero[50];
    Review reviews[MAX_REVIEWS];
    int numReviews;
} Filme;

void adicionarFilme(Filme filmes[], int *numFilmes);
void adicionarReview(Filme filmes[], int numFilmes, Usuario usuarios[], int usuarioLogado);
void listarFilmes(Filme filmes[], int numFilmes);
void exibirReviews(Filme filmes[], int numFilmes);

#endif
