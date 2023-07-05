// Lista 8 - Matrizes
// 01/06/2023

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float media_matriz(int n, float A[][100]){
	float media = 0;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			media += A[i][j];
		}
	}
	media /= n*n;
	return media;
}

void identidade(int n, float A[][100]){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			if (i == j){
				A[i][j] = 1;
			} else {
				A[i][j] = 0;
			}
		}
	}
}

void transposta(int n, float A[][100], float T[][100]){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			T[i][j] = A[j][i];
		}
	}
}

bool simetrica(int n, float A[][100]){
	for (int i = 0; i<n; i++){
		for (int j = i+1; j<n; j++){
			if (A[i][j] != A[j][i]){
				return 0;
			}
		}
	}
	return 1;
}

void soma_matriz(int n, float A[][100], float B[][100], float S[][100]){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			S[i][j] = A[i][j] + B[i][j];
		}
	}
}

void mult_matriz(int n, float A[][100], float B[][100], float P[][100]){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			P[i][j] = 0;
			for (int k = 0; k<n; k++){
				P[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

//--------------------------------------------------------------------------------

void Q1(int n, int m, float mat[][100]){
    printf("Questao 1: Matriz do Arquivo\n\n");
    for (int i = 0; i<n; i++){
		for (int j = 0; j<m; j++){
			printf ("%.1f ", mat[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

void Q3(int n, float mat[][100]){
    printf("Questao 3: Identidade da Matriz\n\n");
	identidade(n, mat);
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			printf ("%.0f ", mat[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

void Q4(int n, float mat[][100]){
    printf("Questao 4: Transposta da Matriz\n\n");
	float m_transposta[100][100];
	transposta(n, mat, m_transposta);
	for (int i = 0; i<n; i++){
			for (int j = 0; j<n; j++){
				printf ("%.1f ", m_transposta[i][j]);
			}
		printf("\n");
	}
    printf("\n");
}

void Q5(int n, float mat[][100]){
    printf("Questao 5: A matriz eh simetrica?\n\n");
	if (simetrica(n, mat)){ 
		printf("Sim, a matriz eh simetrica\n\n");
	} else{
		printf("Nao, a matriz nao eh simetrica\n\n");
	}
}

void Q6(int n, float mat[][100]){
	printf("Questao 6: Soma de Matrizes\n\n");
	float matriz_soma[100][100], matriz_b[100][100];
	printf("Digite a matriz para ser somada:\n");
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			scanf ("%f", &matriz_b[i][j]);
		}
	}
	soma_matriz(n, mat, matriz_b, matriz_soma);
	printf("\nMatriz do Arquivo + Matriz digitada:\n\n");
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			printf ("%.1f ", matriz_soma[i][j]);
		}
		printf("\n");
	}   
    printf("\n");
}

void Q7(int n, float mat[][100]){
    printf("Questao 7: Multiplicacao de Matrizes\n\n");
	float matriz_mult[100][100], matriz_b[100][100];
    printf("Digite a matriz para ser multiplicada:\n");
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			scanf ("%f", &matriz_b[i][j]);
		}
	}
	mult_matriz(n, mat, matriz_b, matriz_mult);
	printf("\nMatriz do Arquivo * Matriz digitada:\n\n");
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++){
			printf ("%.1f ", matriz_mult[i][j]);
		}
		printf("\n");
	}
    printf("\n");
}

//--------------------------------------------------------------------------------

int main(){
    FILE *arquivo;
    int opc, lin, col;
	float matriz[100][100];

    do{
        arquivo = fopen("matriz.txt", "r+t");
        if (arquivo == NULL){
		printf ("O arquivo nao existe\n");
        return 0;
        } else{
            fscanf(arquivo, "%i %i" , &lin, &col);
		    for (int i = 0; i<lin; i++){
			    for (int j = 0; j<col; j++){
				    fscanf(arquivo, "%f", &matriz[i][j]);
			    }
		    }
            printf("---------------------\n");
            printf("        Menu\n");
            printf("(1) Questao 1\n");
            printf("(2) Questao 2\n");
            printf("(3) Questao 3\n");
            printf("(4) Questao 4\n");
            printf("(5) Questao 5\n");
            printf("(6) Questao 6\n");
            printf("(7) Questao 7\n");
            printf("(0) Sair\n");
            printf("---------------------\n");
            printf("Insira a opcao desejada: ");
            scanf("%i",&opc); 
            system("cls");
            switch(opc){
                case 1:
                    Q1(lin, col, matriz);
                    break;
                case 2:
		            printf("Questao 2: Media da Matriz = %.2f\n\n", media_matriz(lin, matriz));
                    break;
                case 3:
                    Q3(lin, matriz);
                    break;
                case 4:
                    Q4(lin, matriz);
                    break;
                case 5:
                    Q5(lin, matriz);
                    break;
                case 6:
                    Q6(lin, matriz);
                    break;
                case 7:
                    Q7(lin, matriz);
                    break;
                case 0:
                    printf("Saindo...\n");
            }
        }
    }while(opc != 0);
    return 0;
}