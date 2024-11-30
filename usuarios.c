#include <stdio.h>
#include <string.h>
#include "usuarios.h"

int registrarUsuario(Usuario usuarios[], int *numUsuarios) {
    if (*numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido!\n");
        return -1;
    }

    printf("Digite um nome de usuario: ");
    scanf("%s", usuarios[*numUsuarios].nomeUsuario);

    printf("Digite uma senha: ");
    scanf("%s", usuarios[*numUsuarios].senha);

    (*numUsuarios)++;
    printf("Usuario registrado com sucesso!\n");
    return *numUsuarios - 1;
}

int loginUsuario(Usuario usuarios[], int numUsuarios) {
    char nomeUsuario[50];
    char senha[50];

    printf("Digite o nome de usuario: ");
    scanf("%s", nomeUsuario);

    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].nomeUsuario, nomeUsuario) == 0 &&
            strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login bem-sucedido! Bem-vindo, %s.\n", usuarios[i].nomeUsuario);
            return i;
            }
    }

    printf("Nome de usuario ou senha incorretos.\n");
    return -1;
}
