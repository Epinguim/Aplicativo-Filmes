#include <stdio.h>
#include <string.h>
#include "filmes.h"
#include "usuarios.h"

void adicionarFilme(Filme filmes[], int *numFilmes) {
    if (*numFilmes >= MAX_FILMES) {
        printf("Limite de filmes atingido!\n");
        return;
    }

    printf("Digite o titulo do filme: ");
    getchar();
    fgets(filmes[*numFilmes].titulo, 100, stdin);
    filmes[*numFilmes].titulo[strcspn(filmes[*numFilmes].titulo, "\n")] = '\0';

    printf("Digite o ano do filme: ");
    scanf("%d", &filmes[*numFilmes].ano);

    printf("Digite o genero do filme: ");
    getchar();
    fgets(filmes[*numFilmes].genero, 50, stdin);
    filmes[*numFilmes].genero[strcspn(filmes[*numFilmes].genero, "\n")] = '\0';

    filmes[*numFilmes].numReviews = 0;
    (*numFilmes)++;
    printf("Filme adicionado com sucesso!\n");
}

void adicionarReview(Filme filmes[], int numFilmes, Usuario usuarios[], int usuarioLogado) {
    if (usuarioLogado == -1) {
        printf("Voce precisa estar logado para adicionar uma review.\n");
        return;
    }

    int indice;
    printf("Digite o indice do filme para avaliar (0 a %d): ", numFilmes - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= numFilmes) {
        printf("Indice invalido!\n");
        return;
    }

    Filme *filme = &filmes[indice];
    if (filme->numReviews >= MAX_REVIEWS) {
        printf("Este filme ja atingiu o numero maximo de reviews!\n");
        return;
    }

    Review *review = &filme->reviews[filme->numReviews];
    printf("Digite sua nota (1-5): ");
    scanf("%d", &review->nota);

    if (review->nota < 1 || review->nota > 5) {
        printf("Nota invalida!\n");
        return;
    }

    getchar();
    printf("Digite sua review: ");
    fgets(review->comentario, TAMANHO_REVIEW, stdin);
    review->comentario[strcspn(review->comentario, "\n")] = '\0';

    strcpy(review->autor, usuarios[usuarioLogado].nomeUsuario);
    filme->numReviews++;
    printf("Review adicionada com sucesso!\n");
}

void listarFilmes(Filme filmes[], int numFilmes) {
    for (int i = 0; i < numFilmes; i++) {
        printf("Filme %d: %s\n", i, filmes[i].titulo);
        printf("Ano: %d\n", filmes[i].ano);
        printf("Genero: %s\n", filmes[i].genero);
        printf("Numero de Reviews: %d\n", filmes[i].numReviews);
        printf("-------------------\n");
    }
}

void exibirReviews(Filme filmes[], int numFilmes) {
    int indice;
    printf("Digite o indice do filme para ver as reviews (0 a %d): ", numFilmes - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= numFilmes) {
        printf("Indice invalido!\n");
        return;
    }

    Filme *filme = &filmes[indice];
    if (filme->numReviews == 0) {
        printf("Este filme nao possui reviews ainda.\n");
        return;
    }

    for (int i = 0; i < filme->numReviews; i++) {
        printf("Review %d - Autor: %s\n", i + 1, filme->reviews[i].autor);
        printf("Nota: %d\n", filme->reviews[i].nota);
        printf("Comentario: %s\n", filme->reviews[i].comentario);
        printf("-------------------\n");
    }
}
