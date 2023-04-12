#include <stdio.h>
#include <math.h>

int N1(){
    printf("1-a) %i\n", 3+4);
    printf("1-b) %.2f\n", 7.0/4.0);
    printf("1-c) %i\n", 3*3);
    printf("1-d) %.2f\n", 5.3*2.1);
    printf("1-e) %i\n", 2*5-2);
    printf("1-f) %i\n", 2+2*5);
    printf("1-g) %i\n", (2+5)*3);
    printf("1-h) %f\n", sin(3.141502));
    printf("1-i) %f\n", sqrt(5));
    printf("1-j) %i\n", 1+2+3);
    printf("1-k) %i\n", 1*2*3);
    printf("1-l) %.1f\n", (1+2+3)/3.0);
    printf("1-m) %i\n", (2+4)*(3-1));
    printf("1-n) %i\n", (9/3)+(3*2));
    printf("1-o) %f\n", sin(4.5)+cos(3.7));
    printf("1-p) %f\n", log(2.3)-log(3.1));
    printf("1-q) %f\n", log(7)+(log(7)*log(7)-cos(log(7))));
    printf("1-r) %f\n", (10.3+8.4)/50.3 - (10.3+8.4));
    printf("1-s) %f\n\n", (cos(0.8)+sin(0.8)) * (cos(0.8)-sin(0.8)));
    return 0;
}

int N2(){
    float a, b, c, d;
    printf("Digite os 4 valores: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    printf("2-a) %f\n", a+b);
    printf("2-b) %f\n", a/c);
    printf("2-c) %f\n", a*a);
    printf("2-d) %f\n", b*c);
    printf("2-e) %f\n", a*b-c);
    printf("2-f) %f\n", a+b*c);
    printf("2-g) %f\n", (a+b)*c);
    printf("2-h) %f\n", sin(a));
    printf("2-i) %f\n", sqrt(b));
    printf("2-j) %f\n", a+b+c);
    printf("2-k) %f\n", a*b*c);
    printf("2-l) %f\n", (a+b+c)/d);
    printf("2-m) %f\n", (a+b)*(a-d));
    printf("2-n) %f\n", (b/c)+(a*d));
    printf("2-o) %f\n", sin(b)+cos(c));
    printf("2-p) %f\n", log(a)-log(c));
    printf("2-q) %f\n", log(a)+(log(b)*log(d)-cos(log(c))));
    printf("2-r) %f\n", (b+a)/c-(d+a));
    printf("2-s) %f\n\n", (cos(d)+sin(c))*(cos(b)-sin(a)));
    return 0;
}

int N3(){
    float a, b, c, pi, delta;
    pi = 3.14159;
    printf("Digite os 3 valores: ");
    scanf("%f %f %f", &a, &b, &c);
    delta = sqrt(b*b - 4*a*c);
    printf("3-a) Média: %f\n", (a+b+c)/3);
    printf("3-b) Media ponderada: %f\n", (3*a+4*b+5*c)/12);
    printf("3-c) Perimetro: %f\n", 2*pi*a);
    printf("3-d) Area do circulo: %f\n", pi*a*a);
    printf("3-e) Area do triangulo: %f\n", b*c/2);
    printf("3-f) Hipotenusa: %f\n", sqrt(b*b+c*c));
    printf("3-g) Raizes: %f e %f\n\n", (b*(-1) + delta)/(2*a), (b*(-1)-delta)/(2*a));
    return 0;
}

int main(){
    int Quest;
    do{
        printf ("------------------\n");
        printf ("     Opcoes:\n");
        printf ("(1) - Questao 1\n");
        printf ("(2) - Questao 2\n");
        printf ("(3) - Questao 3\n");
        printf ("(0) - Sair\n");
        printf ("------------------\n");
        printf ("Insira a opcao desejada: ");
        scanf("%i", &Quest);
        printf ("\n");
        switch (Quest){
            case 1:
                N1();
                break;
            case 2:
                N2();
                break;
            case 3:
                N3();
                break;
            case 0:
                printf ("Fechando...\n");
                break;
            default:
                printf ("Opcao Invalida!\n\n");
                break;
        }
    }while(Quest);
    return 0;
}