// Lista 3 - If e Predicados
// 14/04/2023

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b, int c){
    if (a > b && a > c){
        return a;
    } else if(b > a && b > c){
        return b;
    } else{
        return c;
    }
}

int min(int a, int b, int c){
    if (a < b && a < c){
        return a;
    } else if(b < a && b < c){
        return b;
    } else{
        return c;
    }
}

int main(){
    int Quest, a, b, c;
    do{
        printf("---------------------\n");
        printf("      Opcoes:\n\n");
        printf("(1) - Questao 1\n");
        printf("(2) - Questao 2\n");
        printf("(3) - Questao 3\n");
        printf("(0) - Sair\n\n");
        printf("----------------------\n");
        printf("Insira a opcao desejada: ");
        scanf("%i", &Quest);
        system("cls");
        switch (Quest){
            case 1:
                printf("Digite tres numeros: ");
                scanf("%i %i %i", &a, &b, &c);
                printf("1-a) Maior numero digitado: %i\n", max(a, b, c));
                printf("1-b) Menor numero digitado: %i\n\n", min(a, b, c));
                break;

            case 2:
                printf("Digite tres numeros: ");
                scanf("%i %i %i", &a, &b, &c);
                if (!(a%2)){
                    printf("2-a) %i eh Par!\n", a);
                } else{
                    printf("2-a) %i eh Impar!\n", a);
                }
                if(a >= b && a <= c){
                    printf("2-b)c) %i esta dentro do intervalo [%i %i]\n\n", a, b, c);
                } else{
                    printf("2-b)c) %i esta fora do intervalo [%i %i]\n\n", a, b, c);
                }
                break;

            case 3:
                printf("Digite um ano: ");
                scanf("%i", &a);
                if (!(a%400) || (!(a%4) && a%100)){
                    printf("3- %i eh um ano bissexto\n\n", a);
                } else{
                    printf("3- %i nao eh um ano bissexto\n\n", a);
                }
                break;
                
            case 0:
                printf("Saindo...");
                break;
                
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    } while (Quest);
    return 0;
}
