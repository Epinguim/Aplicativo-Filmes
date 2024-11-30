#include <stdio.h>
#include "usuarios.h"
#include "filmes.h"

void salvarUsuarios(Usuario usuarios[], int numUsuarios) {
    FILE *file = fopen("usuarios.dat", "wb");
    if (file) {
        fwrite(usuarios, sizeof(Usuario), numUsuarios, file);
        fclose(file);
    }
}

int carregarUsuarios(Usuario usuarios[]) {
    FILE *file = fopen("usuarios.dat", "rb");
    if (file) {
        int numUsuarios = fread(usuarios, sizeof(Usuario), MAX_USUARIOS, file);
        fclose(file);
        return numUsuarios;
    }
    return 0;
}

void salvarFilmes(Filme filmes[], int numFilmes) {
    FILE *file = fopen("filmes.dat", "wb");
    if (file) {
        fwrite(filmes, sizeof(Filme), numFilmes, file);
        fclose(file);
    }
}

int carregarFilmes(Filme filmes[]) {
    FILE *file = fopen("filmes.dat", "rb");
    if (file) {
        int numFilmes = fread(filmes, sizeof(Filme), MAX_FILMES, file);
        fclose(file);
        return numFilmes;
    }
    return 0;
}
