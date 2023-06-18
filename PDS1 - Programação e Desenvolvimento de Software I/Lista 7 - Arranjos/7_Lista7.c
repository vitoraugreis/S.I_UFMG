#include <stdio.h>
#include <stdlib.h>

float media(float *arr, float cont){
    float media = 0;
    for (int i = 0; i<cont; i++){
        media += arr[i];
    }
    media /= cont;
    return media;
}

float variancia(float *arr, float cont){
    float med, var;
    var = 0;
    med = media(arr, cont);
    for (int j = 0; j<cont; j++){
        var += (arr[j] - med) * (arr[j] - med);
    }
    var /= cont;
    return var;
}

float maior(float *arr, float cont){
    float maior_num = arr[0];
    for (int i = 1; i<cont; i++){
        if (arr[i] > maior_num){
            maior_num = arr[i];
        }
    }
    return maior_num;
}

float menor(float *arr, float cont){
    float menor_num = arr[0];
    for (int i = 1; i<cont; i++){
        if (arr[i] < menor_num){
            menor_num = arr[i];
        }
    }
    return menor_num;
}

float prod_esc(float *u, float *v, float cont){
    float pd_e = 0;
    for(int i = 0; i < cont; i++){
        pd_e += u[i] * v[i];
    }
    return pd_e;
}

int questao_1(){
    FILE *numeros;
    int arr[1000], cont, arq;
    cont = 0;
    numeros = fopen("q1_numeros.txt", "r + t");
    if (numeros == NULL){
        printf("Arquivo nao encontrado\nNome do arquivo necessario: q1_numeros.txt\n\n");
        return 0;
    } else{
        while (!feof(numeros)){
            fscanf(numeros, "%i", &arq);
            arr[cont] = arq;
            cont++;
        }
        printf("Numeros do arquivo: ");
        for (int i = 0; i<cont; i++){
            printf("%i ", arr[i]);
        }
        printf("\n\n");
        return 0;
    }
}

int questao_2(){
    float arr[1000];
    int cont;
    char opt;
    cont = 0;
    do{
        printf("Insira o numero: ");
        scanf("%f", &arr[cont]);
        cont++;
        printf("Deseja inserir mais um numero? (s ou n): ");
        scanf("%s", &opt);
    } while(opt != 'n');
    printf("Media dos numeros inseridos: %f\n\n", media(arr, cont));
    return 0;
}

int questao_3(){
    float arr[1000];
    int cont;
    char opt;
    cont = 0;
    do{
        printf("Insira o numero: ");
        scanf("%f", &arr[cont]);
        cont++;
        printf("Deseja inserir mais um numero? (s ou n): ");
        scanf("%s", &opt);
    } while(opt != 'n');
    printf("Variancia dos numeros inseridos: %f\n\n", variancia(arr, cont));
    return 0;
}

int questao_4(){
    float arr[1000];
    int cont;
    char opt;
    cont = 0;
    do{
        printf("Insira o numero: ");
        scanf("%f", &arr[cont]);
        cont++;
        printf("Deseja inserir mais um numero? (s ou n): ");
        scanf("%s", &opt);
    } while(opt != 'n');
    printf("Maior dos numeros inseridos: %f\n\n", maior(arr, cont));
    return 0;
}

int questao_5(){
    float arr[1000];
    int cont;
    char opt;
    cont = 0;
    do{
        printf("Insira o numero: ");
        scanf("%f", &arr[cont]);
        cont++;
        printf("Deseja inserir mais um numero? (s ou n): ");
        scanf("%s", &opt);
    } while(opt != 'n');
    printf("Menor dos numeros inseridos: %f\n\n", menor(arr, cont));
    return 0;
}

int questao_6(){
    float u[1000], v[1000];
    int cont = 0;
    char opt;
    do{
        printf("Insira um numero para o vetor u: ");
        scanf("%f", &u[cont]);
        printf("Insira um numero para o vetor v: ");
        scanf("%f", &v[cont]);
        cont++;
        printf("Deseja inserir mais um numero nos vetores? (s ou n): ");
        scanf("%s", &opt);
    } while(opt != 'n');
    printf("Produto Escalar dos vetores: %f\n\n", prod_esc(u, v, cont));
    return 0;
}

int main(){
    int Quest;
	do{
		printf("---------------------\n");
		printf("      Menu\n");
		printf("(1) Questao 1\n");
		printf("(2) Questao 2\n");
		printf("(3) Questao 3\n");
		printf("(4) Questao 4\n");
		printf("(5) Questao 5\n");
        	printf("(6) Questao 6\n");
		printf("(0) Sair\n");
		printf("---------------------\n");
		printf("Insira a opcao desejada: ");
		scanf("%i",&Quest); 
		system("cls");
		switch (Quest){
			case 1:
				questao_1();
				break;
			case 2:
				questao_2();
				break;
			case 3:
				questao_3();
				break;
			case 4:
				questao_4();
				break;
			case 5:
				questao_5();
				break;
            		case 6:
                		questao_6();
                		break;
			case 0:
				printf("Saindo...\n");
		}
	} while(Quest != 0);
    return 0;
}
