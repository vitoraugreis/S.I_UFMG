// 04/05/2023
// Lista 5 - Repetição

#include <stdio.h>

int fat(int n){
    int Fat = 1;
    for (int i = 1; i<=n; i++){
        Fat *= i;
    }
    return Fat;
}

int mdc(int a, int b){
    int resto;
    do{
        resto = a%b;
        a = b;
        b = resto;
    }while(resto != 0);
    return a;
}

int mdc3 (int a, int b, int c){
    int resto;
    while(1){
        while (resto != 0){
            resto = a%b;
            a = b;
            b = resto;
        }
        b = a%c;
        a = c;
        c = b;
        if (b == 0){
            break;
        }
    }
    return a;
}

int fib (int n){
    int n1, n2, num;
    n1 = 0;
    n2 = 1;
    num = 0;
    for (int i = 1; i<=n; i++){
        n1 = n2;
        n2 = num;
        num = n1+n2;
    }
    return num;
}

int primo(int n){
    for (int i = 1; i<=n; i++){
        if (i == n){
            printf("%i eh primo!\n", n);
        } else if (n%i == 0 && i != 1){
            printf("%i nao eh primo!\n", n);
        }
    }
    return 0;
}

int decrescente(int x){
    for (int i = x-1; i>0; i--){
        printf("%i ", i);
    }
    printf("\n");
    return 0;
}

int res(int a, int b){
    while(a > b){
        a -= b;
    }
    return a;
}

int form (int n){
    int som = 0;
    for (int i = 1; i<=n; i++){
        som += i*i;
    }
    return som;
}

int mmc(int a, int b){
    int div = 1;
    for (int i = 1; ; i++){
        div = a*i;
        if (div%b == 0){
            break;
        }
    }
    return div;
}

int div(int a, int b){
    int res = 0;
    while (a > b){
        a -= b;
        res++;
    }
    return res;
}

float raiz(float n){
    float chute = n/2;
    while(1){
        if (chute * chute + 0.001 >= n && chute * chute - 0.001 <= n){
            break;
        } else if (chute * chute > n){
            chute /= 2;
        } else{
            chute *= 1.5;
        }
    }
    return chute;
}

int dig(int x){
    int soma = 0;
    while (x>9){
        soma += x%10;
        x /= 10;
    }
    soma += x;
    return soma;
}

int expo (int k, int n){
    int res = 1;
    for (int i = 1; i<=n; i++){
        res *= k;
    }
    return res;
}

int crescente(int x){
    for (int i = 1; i<=x; i++){
        printf("%i ", i);
    }
    printf("\n");
    return 0;
}

int main(){
    int a, b, c;
    float n;
    printf("Insira tres valores inteiros: ");
    scanf("%i %i %i", &a, &b, &c);
    printf("Insira um valor qualquer: ");
    scanf("%f", &n);
    printf("1-a) Fatorial de %i: %i\n", a, fat(a));
    printf("1-b) MDC de %i e %i: %i\n", a, b, mdc(a, b));
    printf("1-c) MDC de %i, %i e %i: %i\n", a, b, c, mdc3(a, b, c));
    printf("1-d) Numero que ocupa a posicao %i na Sequencia de Fibonacci: %i\n", a, fib(a));
    printf("1-e) "); primo(a);
    printf("1-f) "); decrescente(a);
    printf("1-g) Resto da divisao de %i por %i: %i\n", a, b, res(a, b));
    printf("1-h) Valor do somatorio: %i\n", form(a));
    printf("1-i) MMC de %i e %i: %i\n", a, b, mmc(a, b));
    printf("1-j) Resultado da divisao inteira de %i por %i: %i\n", a, b, div(a, b));
    printf("1-l) Raiz de %f: %f\n", n, raiz(n));
    printf("1-m) Soma dos digitos de %i: %i\n", a, dig(a));
    printf("1-n) %i elevado a %i: %i\n", a, b, expo(a, b));
    printf("1-o) "); crescente(a);
    return 0;
}