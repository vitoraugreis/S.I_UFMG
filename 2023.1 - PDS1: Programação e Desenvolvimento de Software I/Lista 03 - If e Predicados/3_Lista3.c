// Lista 3 - If e Predicados

#include <stdio.h>

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
    // Questão 1
    int a, b, c;
    scanf("%i %i %i", &a, &b, &c);
    printf("1-a) Max: %i\n", max(a, b, c));
    printf("1-b) Min: %i\n", min(a, b, c));

    // Questão 2
    int x, y, z;
    scanf("%i %i %i", &x, &y, &z);
    if (!(x%2)){
        printf("2-a) Par!\n");
    } else{
        printf("2-a) Impar!\n");
    }
    if(x >= y && x <= z){
        printf("2-b)c) %i esta dentro do intervalo [%i %i]\n", x, y, z);
    } else{
        printf("2-b)c) %i esta fora do intervalo [%i %i]\n", x, y, z);
    }

    // Questão 3
    int ano;
    scanf("%i", &ano);
    if (!(ano%400) || (!(ano%4) && ano%100)){
        printf("3- Bissexto\n");
    } else{
        printf("3- Nao Bissexto\n");
    }
    return 0;
}