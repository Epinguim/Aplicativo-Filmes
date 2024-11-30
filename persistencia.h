#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

void salvarUsuarios(Usuario usuarios[], int numUsuarios);
int carregarUsuarios(Usuario usuarios[]);
void salvarFilmes(Filme filmes[], int numFilmes);
int carregarFilmes(Filme filmes[]);

#endif
