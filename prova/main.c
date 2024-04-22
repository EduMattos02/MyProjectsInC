#include <stdio.h>
#include <string.h>
#define MAX_LIVROS 100
#define MAX_USUARIOS 100
#define MAX_EMPRESTIMOS 7
#define MAX_NOME 50

int num_livros = 0;
int num_usuarios = 0;
int num_emprestimos = 0;

struct Livro {
    char titulo[MAX_NOME];
    int disponivel;
};

struct Usuario {
    char nome[MAX_NOME];
    int livros_emprestados[MAX_LIVROS];
    int num_livros_emprestados;
};

struct Emprestimo {
    int id_usuario;
    int id_livro;
    char data_emprestimo[MAX_NOME];
};

struct Livro lista_livros[MAX_LIVROS];
struct Usuario lista_usuarios[MAX_USUARIOS];
struct Emprestimo lista_emprestimos[MAX_EMPRESTIMOS];

void cadastrarLivro() {
    system("cls");
    if (num_livros < MAX_LIVROS) {
        printf("Digite o titulo do livro: ");
        scanf("%s", lista_livros[num_livros].titulo);
        lista_livros[num_livros].disponivel = 1;
        num_livros++;
        printf("Livro cadastrado com sucesso!\n");
    } else {
        printf("Limite maximo de livros alcançado!\n");
    }
}

void cadastrarUsuario() {
        system("cls");
    if (num_usuarios < MAX_USUARIOS) {
        printf("Digite o nome do usuario: ");
        scanf("%s", lista_usuarios[num_usuarios].nome);
        lista_usuarios[num_usuarios].num_livros_emprestados = 0;
        num_usuarios++;
        printf("Usuario cadastrado com sucesso! :D\n");
    } else {
        printf("Limite maximo de usuarios alcançado! :c \n");
    }
}

void emprestarLivro() {
    system("cls");
    int id_usuario, id_livro;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id_usuario);
    printf("Digite o ID do livro: ");
    scanf("%d", &id_livro);

    if (lista_usuarios[id_usuario].num_livros_emprestados < MAX_LIVROS &&
        lista_livros[id_livro].disponivel) {
        lista_usuarios[id_usuario].livros_emprestados[lista_usuarios[id_usuario].num_livros_emprestados] = id_livro;
        lista_usuarios[id_usuario].num_livros_emprestados++;
        lista_livros[id_livro].disponivel = 0;

        strcpy(lista_emprestimos[num_emprestimos].data_emprestimo, "20/04/2024"); // Data atual
        lista_emprestimos[num_emprestimos].id_usuario = id_usuario;
        lista_emprestimos[num_emprestimos].id_livro = id_livro;
        num_emprestimos++;

        printf("Livro emprestado com sucesso! :D \n");
    } else {
        printf("Usuario atingiu o limite de livros emprestados ou livro indisponivel, lamento :c\n");
    }
}

void listarLivrosDisponiveis() {
    system("cls");
    printf("Livros disponiveis para emprestimo:\n");
    for (int i = 0; i < num_livros; i++) {
        if (lista_livros[i].disponivel) {
            printf("%d - %s\n", i, lista_livros[i].titulo);
        }
    }
}

void listarLivrosUsuario() {
    system("cls");
    int id_usuario;
    printf("Digite o ID do usuario: ");
    scanf("%d", &id_usuario);

    printf("Livros emprestados pelo usuario %s:\n", lista_usuarios[id_usuario].nome);
    for (int i = 0; i < lista_usuarios[id_usuario].num_livros_emprestados; i++) {
        printf("%d - %s\n", lista_usuarios[id_usuario].livros_emprestados[i], lista_livros[lista_usuarios[id_usuario].livros_emprestados[i]].titulo);
    }
}

void redirecionadorDeInvalido(){
    int inval;
    system("cls");
    printf("============================================\n");
    printf("Sua opcao foi invalida\n");
    printf("deseja retornar para o menu principal?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha um numero:");
    scanf("%d", &inval);
        if (inval == 1) {
        system("cls");
        return main();
    } else if (inval == 2) {
        system("cls");
        printf("===============================\n");
        printf("Programa encerrado.\n");
        printf("===============================\n");
        exit(0);
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

void redirecionadorDeEncerramento() {
    int Retur;
    system("cls");
    printf("============================================\n");
    printf("Deseja encerrar o programa?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha um numero:");
    scanf("%d", &Retur);
    if (Retur == 1) {system("cls");
        printf("=============================\n");
        printf("Programa encerrado.\n");
        printf("=============================\n");
        exit(0);

    } else if (Retur == 2) {
        system("cls");
        main();
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

int main() {
    int op;

    do {
        printf("=======================================\n");
        printf("              BEM VINDO\n");
        printf("=======================================");
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Cadastrar usuario\n");
        printf("3 - Emprestar livro\n");
        printf("4 - Listar livros disponiveis\n");
        printf("5 - Listar livros de um usuario\n");
        printf("0 - Sair\n");
        printf("Resposta:");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarLivro();
                break;
            case 2:
                cadastrarUsuario();
                break;
            case 3:
                emprestarLivro();
                break;
            case 4:
                listarLivrosDisponiveis();
                break;
            case 5:
                listarLivrosUsuario();
                break;
            case 0:
                redirecionadorDeEncerramento();
                break;
            default:
                redirecionadorDeInvalido();
                break;
        }
    } while (op != 0);

    return 0;
}
