#ifndef USUARIOS_H
#define USUARIOS_H

#define MAX_USUARIOS 10

typedef struct {
    char nomeUsuario[50];
    char senha[50];
} Usuario;

int registrarUsuario(Usuario usuarios[], int *numUsuarios);
int loginUsuario(Usuario usuarios[], int numUsuarios);

#endif
