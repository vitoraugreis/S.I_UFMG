// Lista 6 - Arquivos
// 18/05/2023
// Professor, caso esteja lendo isso, após fazer as listas, costumo fazer menus para navegação.

#include <stdio.h>
#include <stdlib.h>

int primo (int x){
    for (int d = x-1; d>0; d--){
        if (d == 1){
            return 1;
        } else if (x % d == 0){
            return 0;
        }
    }
}

void Questao1 (){
	FILE *q1_primos;
	int n, prim;
    prim = 0;
    printf("Insira a quantidade de numeros primos desejadas: ");
    scanf ("%i", &n);
    q1_primos = fopen("Q1_primos.txt", "w + t");
    if (q1_primos != NULL){
        for (int i = 1; prim < n; i++){
            if (primo(i)){
                fprintf(q1_primos, "%i\n", i);
                prim++;
            }
        }
    }
    printf("=== Arquivos Q1 atualizados ===\n\n");
    fclose(q1_primos);
}

void Questao2(){
	FILE *q2_numeros, *q2_primos;
	int n;
    q2_numeros = fopen("Q2_numeros.txt", "r + t");
    q2_primos = fopen("Q2_primos.txt", "w + t");
    if (q2_numeros != NULL && q2_primos != NULL){
        while (!feof(q2_numeros)){
            fscanf(q2_numeros, "%i", &n);
            if (primo(n)){
                fprintf(q2_primos, "Primo\n");
            } else{
                fprintf(q2_primos, "Nao primo\n");
            }
        }
    }
    printf("=== Arquivos Q2 atualizados ===\n\n");
    fclose(q2_primos);
    fclose(q2_numeros);
}

void Questao3(){
	FILE *q3_numeros, *q3_outros, *q3_primos;	
	int n;
    q3_numeros = fopen("Q3_numeros.txt", "r + t");
    q3_outros = fopen("Q3_outros.txt", "w + t");
    q3_primos = fopen("Q3_primos.txt", "w + t");
    if(q3_numeros != NULL && q3_outros != NULL && q3_primos != NULL){
        while (!feof(q3_numeros)){
            fscanf(q3_numeros, "%i", &n);
            if (primo(n)){
                fprintf(q3_primos, "%i\n", n);
            } else{
                fprintf(q3_outros, "%i\n", n);
            }
        }
    }
    fclose(q3_numeros);
    fclose(q3_primos);
    fclose(q3_outros);
    printf("=== Arquivos Q3 atualizados ===\n\n");
}

void Questao4(){
	FILE *q4_numeros, *q4_resultado;
    float n, fun;
    q4_numeros = fopen("Q4_numeros.txt", "r + t");
    q4_resultado = fopen("Q4_resultado.txt", "w + t");
    if (q4_numeros != NULL && q4_resultado != NULL){
        while (!feof(q4_numeros)){
            fscanf(q4_numeros, "%f", &n);
            fun = n*n - 5*n + 1;
            fprintf(q4_resultado, "%f\n", fun);
        }
    }
    fclose(q4_numeros);
    fclose(q4_resultado);
    printf("=== Arquivos Q4 atualizados ===\n\n");
}

void Questao5(){
	FILE *q5_numeros, *q5_funcao;
    float a, b, c, d, n, res;
    q5_numeros = fopen("Q5_numeros.txt", "r + t");
    q5_funcao = fopen("Q5_resultado.txt", "w + t");
    printf("Insira os valores dos coeficientes a, b, c, d: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    if (q5_numeros != NULL && q5_funcao != NULL){
        while (!feof(q5_numeros)){
            fscanf(q5_numeros, "%f", &n);
            res = (a*n*n*n) + (b*n*n) + (c*n) + d;
            fprintf(q5_funcao, "%f\n", res);
        }
    }
    fclose(q5_numeros);
    fclose(q5_funcao);
    printf("=== Arquivos Q5 atualizados ===\n\n");
}

int main(){
	int Quest;
	do{
		printf("---------------------\n");
		printf("        Menu\n");
		printf("(1) Questao 1\n");
		printf("(2) Questao 2\n");
		printf("(3) Questao 3\n");
		printf("(4) Questao 4\n");
		printf("(5) Questao 5\n");
		printf("(0) Sair\n");
		printf("---------------------\n");
		printf("Insira a opcao desejada: ");
		scanf("%i",&Quest); 
		system("cls");
		switch (Quest){
			case 1:
				Questao1();
				break;
			case 2:
				Questao2();
				break;
			case 3:
				Questao3();
				break;
			case 4:
				Questao4();
				break;
			case 5:
				Questao5();
				break;
			case 0:
				printf("Saindo...\n");
		}
	} while(Quest != 0);
	return 0;
}
