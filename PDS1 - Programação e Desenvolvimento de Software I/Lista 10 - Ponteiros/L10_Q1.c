#include <stdio.h>
#include <stdlib.h>

int *uniao(int *x1, int *x2, int n1, int n2, int* qtd){
	int* x3 = malloc((n1+n2) * sizeof(int));
	for (int i = 0; i<n2+n1; i++){
		x3[i] = 0;
	}
	for (int i = 0; i<n1; i++){
		x3[x1[i]]++;
	}
	for (int i = 0; i<n2; i++){
		x3[x2[i]]++;
	}
	
	for (int i = 0; i<n1+n2; i++){
		printf("%i ", x3[i]);
	}
	printf ("\n");
	
	int* x4 = malloc((n1+n2) * sizeof(int));
	int j = 0;
	for (int i = 0; i<n1+n2; i++){
		if(x3[i] > 0){
			x4[j] = i;
			j++;
		}
	}
	free(x3);
	*qtd = j;
	return x4;
}

int main(){
	int n1, n2;
	scanf("%i %i", &n1, &n2);
	int* x1 = malloc(n1 * sizeof(int));
	int* x2 = malloc(n2 * sizeof(int));
	
	for (int i = 0; i<n1; i++){
		scanf("%i", &x1[i]);
	}
	for (int i = 0; i<n2; i++){
		scanf("%i", &x2[i]);
	}
	int qtd;
	int* x3 = uniao(x1, x2, n1, n2, &qtd);
	for (int i = 0; i<qtd; i++){
		printf("%i ", x3[i]);
	}
	printf("\n");
	free(x1);
	free(x2);
	free(x3);
	return 0;
}
