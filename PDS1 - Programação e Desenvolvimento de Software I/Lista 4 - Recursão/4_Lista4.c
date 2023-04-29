// Lista 4 - Recursão
// 29/04/2023

#include <stdio.h>

int fat(int n){
    if (n == 0){
        return 1;
    } else {
        return n*fat(n-1);
    }
}

int mdc(int a, int b){
    if (b == 0){
        return a;
    } else{
        return mdc(b, a%b);
    }
}

int mdc3(int a, int b, int c){
    if (b != 0){
        return mdc3(b, a%b, c);
    } else if (c != 0){
        return mdc3(c, b, a%c);
    } else{
        return a;
    }
}

int fib(int n){
    if (n == 1){
        return 1;
    } else if(n == 2){
        return 1;
    } else{
        return fib(n-1) + fib(n-2);
    }
}

int primo(int x, int n){
    if (n == 1){
        printf("%i eh primo!\n", x);
        return 1;
    } else if(x%n == 0){
        printf("%i nao eh primo!\n", x);
        return 0;
    } else{
        return primo(x, n-1);
    }
}

int decrescente(int x){
    if (x == 0){
        printf("\n");
        return 0;
    } else{
        printf("%i ", x);
        return decrescente(x-1);
    }
}

int res(int a, int b){
    if(a%b == a){
        return a;
    } else{
        return res(a-b, b);
    }
}

int form(int n){
    if (n == 0){
        return 0;
    } else{
        return n*n + form(n-1);
    }
}

int mmc(int a, int b, int n){
    if ((a*n)%b == 0){
        return a*n;
    } else{
        return mmc(a, b, n+1);
    }
}

int div(int a, int b){
    if (b > a){
        return 0;
    } else{
        return 1 + div(a-b, b);
    }
}

float raiz(float n, float c){
    if (c*c + 0.001 >= n && c*c - 0.001 <= n){
        return c;
    } else if (c*c > n){
        return raiz(n, c/2);
    } else{
        return raiz(n, c*1.5);
    }
}

int dig(int n){
    if (n <= 9){
        return n;
    } else{
        return n%10 + dig(n/10);
    }
}

int expo (int k, int n){
    if (n == 0){
        return 1;
    } else{
        return k * expo(k, n-1);
    }
}

int crescente (int x, int n){
    if (n > x){
        printf("\n");
        return 0;
    } else{
        printf("%i ", n);
        return crescente(x, n+1);
    }
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
    printf("1-e) "); primo(a, a-1);
    printf("1-f) "); decrescente(a-1);
    printf("1-g) Resto da divisao de %i por %i: %i\n", a, b, res(a, b));
    printf("1-h) Valor do somatorio: %i\n", form(a));
    printf("1-i) MMC de %i e %i: %i\n", a, b, mmc(a, b, 1));
    printf("1-j) Resultado da divisao inteira de %i por %i: %i\n", a, b, div(a, b));
    printf("1-l) Raiz de %f: %f\n", n, raiz(n, n/2));
    printf("1-m) Soma dos digitos de %i: %i\n", a, dig(a));
    printf("1-n) %i elevado a %i: %i\n", a, b, expo(a, b));
    printf("1-o) "); crescente(a, 1);
    return 0;
}