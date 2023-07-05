#include <stdio.h>
#include <stdlib.h>

int *interseccao(int *v1, int *v2, int n1, int n2, int *qtd){
    int *v3 = malloc(n1 * sizeof(int));
    int cont = 0;
    for(int i = 0; i<n1; i++){
        for (int j = 0; j<n2; j++){
            if(v1[i] == v2[j]){
                v3[cont] = v1[i];
                cont++;
                break;
            }
        }
    }
    *qtd = cont;
    return v3;
}

int main(){
    int n1, n2, qtd;
    qtd = 0;
    scanf("%i %i", &n1, &n2);
    int *x1 = malloc(n1 * sizeof(int));
    int *x2 = malloc(n2 * sizeof(int));

    for (int i = 0; i<n1; i++){
        scanf("%i", &x1[i]);
    }
    for (int i = 0; i<n2; i++){
        scanf("%i", &x2[i]);
    }

    int *x3 = interseccao(x1, x2, n1, n2, &qtd);

    for (int i = 0; i<qtd; i++){
        printf("%i ", x3[i]);
    }
    printf("\n");
    free(x1);
    free(x2);
    free(x3);
    return 0;
}