#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159;

double detCirculo(double raio);
double detCilindro(double raio, double altura);
double detCubo(double area);
double detPiramide(area, base);
void redirecionadorDeCalculo(int op);

int main(){
    int op;
    printf("            SEJA BEM VINDO\n");
    printf("=========================================\n");
    printf("Qual forma deseja detalhar?\n");
    printf("\n");
    printf("1-Circulo 2-Cilindro 3-Cubo 4-Piramide\n");
    printf("escolha um numero: ");
    scanf("%d", &op);
    redirecionadorDeCalculo(op);
    return 0;
}

void redirecionadorDeCalculo(int op){
    double aux, raio, altura, area, base = 0; //todas as variaveis usadas no sistema
    int retur;

    switch(op){
        //1-circulo
        case 1 :
            system("cls");
            printf("===================================\n");
            printf("    informe o raio do circulo:");
            scanf("%lf", &raio);
            aux = detCirculo(raio); //busca a formula na função detCirculo
            system("cls");
            printf("============================================\n");
            printf("a area do circulo de raio %.2f eh: %.2f\n", raio, aux);
            printf("============================================\n");
            redirecionadorDeRetorno();
            break;

        //2-cilindro
        case 2 :
            system("cls");
            printf("============================================\n");
            printf("informe o raio do cilindro: ");
            scanf("%lf", &raio);
            printf("============================================\n");
            printf("informe a altura do cilindro: ");
            scanf("%lf", &altura);
            aux = detCilindro(raio, altura); //busca a formula na função detCilindro
            system("cls");
            printf("=============================================================\n");
            printf("area do cilindro de raio %.2f e altura %.2f eh: %.2f\n", raio, altura, aux);
            printf("=============================================================\n");
            redirecionadorDeRetorno();

        break;

        //3-cubo
        case 3 :
            system("cls");
            printf("============================================\n");
            printf("informe o valor de um dos lados do cubo: ");
            scanf("%lf", &area);
            aux = detCubo(area); //busca a formula na função detCubo
            system("cls");
            printf("============================================\n");
            printf("o valor da area total do cubo eh: %2.f\n", aux);
            printf("============================================\n");
             redirecionadorDeRetorno();
        break;

        //4-piramede
        case 4 :
            system("cls");
            printf("============================================\n");
            printf("informe a valor da lateral da piramide: ");
            scanf("%lf", &area);
            printf("============================================\n");
            printf("informe a valor da base da piramide: ");
            scanf("%lf", &base);
            aux = detPiramide (area, base);    //busca a formula na função detPiramide
            system("cls");
            printf("============================================\n");
            printf("o valor da area total da piramide eh: %2.f\n", aux);
            printf("============================================\n");

             redirecionadorDeRetorno();
        break;

        default:
            system("cls");
            redirecionadorDeInvalido();
    }
}

void redirecionadorDeRetorno() {
    int Retur;
    printf("\nDeseja retornar ao menu principal?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &Retur);
    if (Retur == 1) {
        system("cls");
        main();
    } else if (Retur == 2) {
        printf("\nPrograma encerrado.\n");
        exit(0);
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

void redirecionadorDeInvalido(){
    int inval;
    printf("\nSua opcao foi invalida\n");
    printf("deseja retornar para o menu principal?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &inval);
        if (inval == 1) {
        system("cls");
        main();
    } else if (inval == 2) {
        printf("\nPrograma encerrado.\n");
        exit(0);
    } else {
        system("cls");
        printf("\nOpcao invalida!\n");
        redirecionadorDeInvalido();
    }
}

double detCirculo(double raio){
    return PI*pow(raio, 2);
}

double detCilindro (double raio, double altura){
    return 2*PI*raio*(raio + altura);
}

double detCubo(double area){
    return 6*pow(area, 2);
}

double detPiramide(double area, double base){
    return area + base;
}
