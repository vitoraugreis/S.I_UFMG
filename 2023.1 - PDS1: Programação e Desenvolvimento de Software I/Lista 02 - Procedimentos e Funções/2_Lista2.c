// Lista 2 - Procedimentos e Funções

#include <stdio.h>
#include <math.h>
#define PI 3.14159

float med(float a, float b, float c){ 
    return (a+b+c)/3;
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
    scanf("%f %f %f", &a, &b, &c);
    printf("1-a) Media: %.2f\n", med(a, b, c));
    printf("1-b) Media Ponderada: %.2f\n", med_pnd(a, b, c));
    printf("1-c) Perimetro do Circulo: %.2f\n", per_circ(a));
    printf("1-d) Area do Circulo: %.2f\n", area_circ(a));
    printf("1-e) Area do Triangulo: %.2f\n", area_tri(b, c));
    printf("1-f) Area da Caixa: %.2f\n", area_caixa(a, b, c));
    printf("1-g) Volume da Caixa: %.2f\n", vol_caixa(a, b, c));
    printf("1-h) Area do Cilindo: %.2f\n", area_cld(a, b));
    printf("1-i) Volume do Cilindro: %.2f\n", vol_cld(a, b));
    printf("1-j) Hipotenusa: %.2f\n", hipotenusa(b, c));
    printf("1-k) Raiz Positiva: %.2f\n", raiz_pos(a, b, c));
    return 0;
}