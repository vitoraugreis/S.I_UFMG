#include <stdio.h>
#include <stdlib.h>

void leitura(int *v, int n){
    for (int i = 0; i<n; i++){
        scanf("%i", v+i);
    }
}

int main(){
    int n;
    scanf("%i", &n);
    int *v = malloc(n * sizeof(int));
    leitura(v, n);
    for (int i = 0; i<n; i++){
        printf("%i ", v[i]);
    }
    printf ("\n");
    return 0;
}