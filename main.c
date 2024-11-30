#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
#include "filmes.h"
#include "persistencia.h"

int main() {
    Filme filmes[MAX_FILMES];
    Usuario usuarios[MAX_USUARIOS];
    int numFilmes = carregarFilmes(filmes);
    int numUsuarios = carregarUsuarios(usuarios);
    int usuarioLogado = -1;
    int opcao;

    do {
        printf("Sistema de Avaliacao de Filmes\n");
        if (usuarioLogado == -1) {
            printf("Voce precisa fazer login para acessar as opcoes do sistema.\n");
            printf("1. Registrar Usuario\n");
            printf("2. Fazer Login\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    registrarUsuario(usuarios, &numUsuarios);
                    salvarUsuarios(usuarios, numUsuarios);
                    break;
                case 2:
                    usuarioLogado = loginUsuario(usuarios, numUsuarios);
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        } else {
            printf("1. Adicionar Filme\n");
            printf("2. Adicionar Review\n");
            printf("3. Listar Filmes\n");
            printf("4. Exibir Reviews de um Filme\n");
            printf("5. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    adicionarFilme(filmes, &numFilmes);
                    salvarFilmes(filmes, numFilmes);
                    break;
                case 2:
                    adicionarReview(filmes, numFilmes, usuarios, usuarioLogado);
                    salvarFilmes(filmes, numFilmes);
                    break;
                case 3:
                    listarFilmes(filmes, numFilmes);
                    break;
                case 4:
                    exibirReviews(filmes, numFilmes);
                    break;
                case 5:
                    printf("Saindo...\n");
                    salvarUsuarios(usuarios, numUsuarios);
                    salvarFilmes(filmes, numFilmes);
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        }
    } while (opcao != 5);

    return 0;
}
