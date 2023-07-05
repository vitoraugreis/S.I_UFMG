// Lista 5  Repetição
// 05/05/2023

#include <stdio.h>

void fat(int n){
    int Fat = 1;
    for (int i = 1; i<=n; i++){
        Fat *= i;
    }
    printf("1-a) Fatorial de %i: %i\n", n, Fat);
}

void mdc(int a, int b){
    printf("1-b) MDC de %i e %i: ", a, b);
    int resto = 0;
    do{
        resto = a%b;
        a = b;
        b = resto;
    } while(b!=0);
    printf("%i\n", a);
}

void mdc3(int a, int b, int c){
    printf("1-c) MDC de %i, %i e %i: ", a, b, c);
    int resto = 0;
    while(c!=0){
        while(b!=0){
            resto = a%b;
            a = b;
            b = resto;
        }
        resto = a%c;
        a = c;
        c = resto;
    }
    printf("%i\n", a);
}

void fib(int n){
    int n1, n2, soma;
    n1 = 0; n2 = 1; soma = 0;
    for(int i = 1; i<=n; i++){
        n1 = n2;
        n2 = soma;
        soma = n1 + n2;
    }
    printf("1-d) Numero que ocupa a posicao %i na Sequencia de Fibonacci: %i\n", n, soma);
}

void primo(int x){
    for(int i=x-1; i>0; i--){
        if (i == 1){
            printf("1-e) %i eh primo!\n", x);
            break;
        } else if (x%i==0){
            printf("1-e) %i nao eh primo!\n", x);
            break;
        }
    }
}

void decrescente(int x){
    printf("1-f) ");
    for(int i = x-1; i>0; i--){
        printf("%i ", i);
    }
    printf("\n");
}

void res(int a, int b){
    printf("1-g) Resto da divisao de %i por %i: ", a, b);
    while(a>b){
        a -= b;
    }
    printf("%i\n", a);
}

void form(int n){
    int Somatorio = 0;
    for(int i = 1; i<=n; i++){
        Somatorio += i*i;
    }
    printf("1-h) Valor do somatorio: %i\n", Somatorio);
}

void mmc(int a, int b){
    printf("1-i) MMC de %i e %i: ", a, b);
    for(int i = 1; ; i++){
        if (a*i % b == 0){
            printf("%i\n", a*i);
            break;
        }
    }
}

void div(int a, int b){
    printf("1-j) Resultado da divisao inteira de %i por %i: ", a, b);
    int divisao = 0;
    while(a>=b){
        a -= b;
        divisao++;
    }
    printf("%i\n", divisao);
}

void my_sqrt(float n){
    float chute = n/2;
    while (1){
        if (chute*chute + 0.001 >= n && chute*chute - 0.001 <= n){
            break;
        } else if (chute*chute > n){
            chute /= 2;
        } else{
            chute *= 1.5;
        }
    }
    printf("1-l) Raiz de %f: %f\n", n, chute);
}

void dig(int n){
    printf("1-m) Soma dos digitos de %i: ", n);
    int soma = 0;
    while (n>9){
        soma += n%10;
        n /= 10;
    }
    soma += n;
    printf("%i\n", soma);
}

void my_exp(int k, int n){
    int expo = 1;
    for(int i = 1; i<=n; i++){
        expo *= k;
    }
    printf("1-n) %i elevado a %i: %i\n", k, n, expo);
}

void crescente(int x){
    printf("1-o) ");
    for(int i = 1; i<=x; i++){
        printf("%i ", i);
    }
    printf("\n");
}

int main(){
    int a, b, c;
    float n;
    printf("Insira tres valores inteiros: ");
    scanf("%i %i %i", &a, &b, &c);
    printf("Insira um valor qualquer: ");
    scanf("%f", &n);
    fat(a);
    mdc(a, b);
    mdc3(a, b, c);
    fib(a);
    primo(a);
    decrescente(a);
    res(a, b);
    form(a);
    mmc(a, b);
    div(a, b);
    my_sqrt(n);
    dig(a);
    my_exp(a, b);
    crescente(a);
    return 0;
}