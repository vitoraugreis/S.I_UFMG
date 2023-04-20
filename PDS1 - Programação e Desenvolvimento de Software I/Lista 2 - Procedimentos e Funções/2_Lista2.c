// Lista 2 - Procedimentos e Funções
// 10/04/2023

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159

float med(float a, float b, float c){
    return (a+b+c)/3;;
}

float med_pnd(float a, float b, float c){
    return (a*3 + b*4 + c*5)/12;
}

float per_circ(float r){
    return 2*PI*r;
}

float area_circ(float r){
    return PI*r*r;
}

float area_tri(float b, float c){
    return (b*c)/2;
}

float area_caixa(float a, float b, float c){
    return 2*(a*b) + 2*(a*c) + 2*(b*c);
}

float vol_caixa(float a, float b, float c){
    return a*b*c;
}

float area_cld(float r, float h){
    return 2*(PI*r*r) + (2*PI*r*h);
}

float vol_cld(float r, float h){
    return PI*r*r*h;
}

float hipotenusa(float b, float c){
    return sqrt(b*b + c*c);
}

float raiz_pos(float a, float b, float c){
    return ((b*(-1)) + sqrt((b*b - 4*a*c))) / 2*a;
}

int main(){
    float a, b, c;
    int Quest;

    do{
        printf ("---------------------------\n");
        printf ("           Opcoes:\n");
        printf ("(1) - Media\n");
        printf ("(2) - Media Ponderada\n");
        printf ("(3) - Perimetro de Circulo\n");
        printf ("(4) - Area de Circulo\n");
        printf ("(5) - Area de Triangulo\n");
        printf ("(6) - Area de Caixa\n");
        printf ("(7) - Volume de Caixa\n");
        printf ("(8) - Area de Cilindro\n");
        printf ("(9) - Volume de Cilindro\n");
        printf ("(10) - Hipotenusa\n");
        printf ("(11) - Raiz Positiva\n");
        printf ("(0) - Sair\n");
        printf ("------------------\n");
        printf ("Insira a opcao desejada: ");
        scanf("%i", &Quest);
        system("cls");

        switch(Quest){
            case 1:
                printf ("Insira tres numeros: ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Media: %.2f\n\n", med(a, b, c));
                break;
            case 2:
                printf ("Pesos: 3, 4 e 5\n");
                printf ("Insira tres numeros: ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Media Ponderada: %.2f\n\n", med_pnd(a, b, c));
                break;
            case 3:
                printf ("Insira o raio do circulo: ");
                scanf("%f", &a);
                printf("Perimetro do Circulo: %.2f\n\n", per_circ(a));
                break;
            case 4:
                printf ("Insira o raio do circulo: ");
                scanf("%f", &a);
                printf("Area do Circulo: %.2f\n\n", area_circ(a));
                break;
            case 5:
                printf ("Insira a base e a altura do triangulo: ");
                scanf("%f %f", &b, &c);
                printf("Area do Triangulo: %.2f\n\n", area_tri(b, c));
                break;
            case 6:
                printf ("Insira as dimensoes da caixa: ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Area da Caixa: %.2f\n\n", area_caixa(a, b, c));
                break;
            case 7:
                printf ("Insira as dimensoes da caixa: ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Volume da Caixa: %.2f\n\n", vol_caixa(a, b, c));
                break;
            case 8:
                printf ("Insira a base e a altura do cilindro: ");
                scanf("%f %f", &a, &b);
                printf("Area do Cilindro: %.2f\n\n", area_cld(a, b));
                break;
            case 9:
                printf ("Insira a base e a altura do cilindro: ");
                scanf("%f %f", &a, &b);
                printf("Volume do Cilindro: %.2f\n\n", vol_cld(a, b));
                break;
            case 10:
                printf ("Insira os catetos do triangulo: ");
                scanf("%f %f", &a, &b);
                printf("Hipotenusa: %.2f\n\n", hipotenusa(a, b));
                break;
            case 11:
                printf ("Insira o valor dos coeficientes: ");
                scanf("%f %f %f", &a, &b, &c);
                printf("Raiz Positiva: %.2f\n\n", raiz_pos(a, b, c));
                break;
            case 0:
                printf ("Fechando...\n");
                break;
            default:
                printf ("Opcao Invalida!\n\n");
                break;
        }
    } while (Quest);
    return 0;
}
