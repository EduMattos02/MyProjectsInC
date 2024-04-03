#include <stdio.h>

int main() {

    char nome[50];
    printf("Digite seu nome: ");
    scanf("%s", nome);

    int numero;
    printf("Digite um numero para somar com o proximo: ");
    scanf("%d", &numero);

    int novoNumero;
    printf("Digite um novo numero para somar com o anterior: ");
    scanf("%d", &novoNumero);

    int resultado = numero + novoNumero;

    printf("Ola, %s!\n", nome, numero);
    printf("A soma de %d e %d e: %d\n", numero, novoNumero, resultado);

    return 0;
}
