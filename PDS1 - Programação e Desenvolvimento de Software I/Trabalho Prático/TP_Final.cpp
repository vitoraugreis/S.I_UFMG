#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Casa{
    int x;
    int y;
};

struct Restaurante{
    int x;
    int y;
    char nome[20];
    char custo[6];
    float velocidade;
    int distancia;
};

struct Rua{
    int x;
    int y;
    int pavimento;
};

struct Esquina{
    int x;
    int y;
    int distancia;
};

struct Cidade{
    Casa casa;
    Rua caminhos[1000];
    Restaurante rest[100];

    void preencher_ruas(int n, int a, int b, int c);
    void preencher_restaurantes(int n, int a, int b, float v);
    void rotas(int a, int b, int max_x, int max_y, int n_rua, int n_rest);
};

void Cidade::preencher_ruas(int n, int a, int b, int c){
    this->caminhos[n].x = a;
    this->caminhos[n].y = b;
    this->caminhos[n].pavimento = c;
}

void Cidade::preencher_restaurantes(int n, int a, int b, float v){
    this->rest[n].x = a;
    this->rest[n].y = b;
    this->rest[n].velocidade = v;
}

void Cidade::rotas(int a, int b, int max_x, int max_y, int n_rua, int n_rest){
    int x = a, y = b;
    int esq = 0, dir = 0, cima = 0, baixo = 0, ver_esquina;
    int ind = 0, dist = 0;
    int ind_rua;
    Esquina esquina[50];
    while(ind >= 0){
        for(int i = 0; i<n_rest; i++){
            if(x == this->rest[i].x && y == this->rest[i].y){
                this->rest[i].distancia = dist;
            }
        }
        for(int i = 0; i<n_rua; i++){
            if (x == this->caminhos[i].x && y == this->caminhos[i].y){
                ind_rua = i;
            }
            if (x == max_x){
                dir = 0;
            } else if (x+1 == this->caminhos[i].x && y == this->caminhos[i].y){
                dir = this->caminhos[i].pavimento;
            }
            if (x == 1){
                esq = 0;
            } else if (x-1 == this->caminhos[i].x && y == this->caminhos[i].y){
                esq = this->caminhos[i].pavimento;
            }
            if (y == max_y){
                baixo = 0;
            } else if (x == this->caminhos[i].x && y+1 == this->caminhos[i].y){
                baixo = this->caminhos[i].pavimento;
            }
            if (y == 1){
                cima = 0;
            } else if (x == this->caminhos[i].x && y-1 == this->caminhos[i].y){
                cima = this->caminhos[i].pavimento;
            }
        }
        ver_esquina = dir+esq+cima+baixo;
        if(ver_esquina > 1){
            esquina[ind].x = x;
            esquina[ind].y = y;
            esquina[ind].distancia = dist;
            ind++;
        }
        if(dir){
            this->caminhos[ind_rua].pavimento = 0;
            x++;
            dist++;
        } else if(esq){
            this->caminhos[ind_rua].pavimento = 0;
            x--;
            dist++;
        } else if(cima){
            this->caminhos[ind_rua].pavimento = 0;
            y--;
            dist++;
        } else if(baixo){
            this->caminhos[ind_rua].pavimento = 0;
            y++;
            dist++;
        } else{
            this->caminhos[ind_rua].pavimento = 0;
            x = esquina[ind-1].x;
            y = esquina[ind-1].y;
            dist = esquina[ind-1].distancia;
            ind--;
        }
    }
}

void insert_sort(float *vet, int *ind, int n){
    int i, j, aux_i;
    float aux;
    for(i = 1; i<n; i++){
        aux = vet[i]; aux_i = ind[i];
        for (j = i; j > 0 && aux < vet[j-1]; j--){
            vet[j] = vet[j-1];
            ind[j] = ind[j-1];
        }
        vet[j] = aux;
        ind[j] = aux_i;
    }
}

int main(){
    Cidade bh;
    FILE *ruas, *restaurantes;
    int x, y, pav;
    float velocidade;
    int n_ruas = 0, n_rest = 0;

    // Lendo arquivos:
    ruas = fopen("ruas.txt", "r+t");
    restaurantes = fopen("restaurantes.txt", "r+t");
    if (ruas == NULL || restaurantes == NULL){
        printf("Algum arquivo nao foi encontrado.\n");
        return 0;
    }

    while(!feof(ruas)){
        fscanf(ruas, "%i %i %i", &x, &y, &pav);
        bh.preencher_ruas(n_ruas, x, y, pav);
        n_ruas++;
    }
    while(!feof(restaurantes)){
        fscanf(restaurantes, "%i %i %s %s %f", &x, &y, bh.rest[n_rest].nome, bh.rest[n_rest].custo, &velocidade);
        bh.preencher_restaurantes(n_rest, x, y, velocidade);
        n_rest++;
    }

    int maior_x = 0, maior_y = 0;
    for(int i = 0; i<n_ruas; i++){
        if (bh.caminhos[i].x > maior_x){
            maior_x = bh.caminhos[i].x;
        }
        if (bh.caminhos[i].y > maior_y){
            maior_y = bh.caminhos[i].y;
        }
    }
    for(int i = 0; i<n_rest; i++){
        if (bh.rest[i].x > maior_x){
            maior_x = bh.rest[i].x;
        }
        if (bh.rest[i].y > maior_y){
            maior_y = bh.rest[i].y;
        }
    }
    int m[maior_y+1][maior_x+1];
    for (int i = 0; i<=maior_y; i++){
        for (int j = 0; j<=maior_x; j++){
            m[i][j] = 0;
        }
    }
    for(int i = 0; i<n_ruas; i++){
        if (bh.caminhos[i].pavimento == 1){
            m[bh.caminhos[i].y][bh.caminhos[i].x] = 1;
        }
    }
    for(int i = 0; i<n_rest; i++){
        m[bh.rest[i].y][bh.rest[i].x] = 2;
    }
    // Coordenadas da casa:
    printf("Digite as coordenadas de sua casa: ");
    while(1){
        scanf("%i %i", &bh.casa.x, &bh.casa.y);
        if(m[bh.casa.y][bh.casa.x] != 1){
            printf("Coordenada da casa invalida.\n");
            printf("Voce posicionou ela emm uma rua nao pavimentada ou no lugar de um restaurante.\n");
            printf("Digite outras coordenadas: ");
        } else{
            break;
        }
    }
    system("cls");
    m[bh.casa.y][bh.casa.x] = 3;
    // Calculando Distancias:
    bh.rotas(bh.casa.x, bh.casa.y, maior_x, maior_y, n_ruas, n_rest);
    float distancias[n_rest]; 
    int indices_dist[n_rest];
    for (int i = 0; i<n_rest; i++){
        distancias[i] = (float)bh.rest[i].distancia;
        indices_dist[i] = i;
    }
    insert_sort(distancias, indices_dist, n_rest);
    // Calculando Rapidez:
    float rapidez[n_rest];
    int indices_rap[n_rest];
    for (int i = 0; i<n_rest; i++){
        rapidez[i] = bh.rest[i].distancia / bh.rest[i].velocidade;
        indices_rap[i] = i;
    }
    insert_sort(rapidez, indices_rap, n_rest);
    char preferencia[6];

    int opcao;
    do{
        printf("=================== MENU ===================\n");
        printf("(0) Mostrar Mapa\n");
        printf("(1) Distancias dos restaurantes\n");
        printf("(2) Preferencia + Rapidez\n");
        printf("(3) Preferencia + Rapidez + Tempo Maximo\n");
        printf("(4) Fechar Programa\n");
        printf("============================================\n\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &opcao);
        system("cls");
        switch(opcao){
            case 0:
                printf(" Mapa:\n\n");
                for (int i = 1; i<=maior_y; i++){
                    for (int j = 1; j<=maior_x; j++){
                        if(m[i][j] == 0){
                            printf(". ");
                        } else if (m[i][j] == 1){
                            printf("o ");
                        } else if (m[i][j] == 2){
                            printf("M ");
                        } else if (m[i][j] == 3){
                            printf("H ");   
                        }
                    }
                    printf("\n");
                }
                printf("\nLegenda:\n");
                printf("o -> Rua pavimentada\t\tM -> Restaurante\n");
                printf(". -> Rua nao pavimentada\tH -> Casa\n");
                printf("\n\n");
                break;
            
            case 1:
                printf("Distancias da casa ao restaurante:\n\n");
                for(int i = 0; i<n_rest; i++){
                    printf("%s : %.0f zambs\n", bh.rest[indices_dist[i]].nome, distancias[i]);
                }
                printf("\n\n");
                break;
            
            case 2:
                printf("Digite a preferencia de custo (Caro ou Barato): ");
                scanf("%s", preferencia);
                while(strcmp(preferencia, "Caro") && strcmp(preferencia, "Barato")){
                    printf("Preferencia inserida invalida.\n");
                    printf("Digite a preferencia de custo (Caro ou Barato): ");
                    scanf("%s", preferencia);
                }
                system("cls");
                printf("Restaurantes %ss em ordem de rapidez de entrega:\n\n", preferencia);
                for(int i = 0; i<n_rest; i++){
                if (!(strcmp(bh.rest[indices_rap[i]].custo, preferencia))){
                        printf("%s : %.1f minutos\n", bh.rest[indices_rap[i]].nome, rapidez[i]);
                    }
                }
                printf("\n\n");
                break;
            
            case 3:
                float temp_max;
                printf("Digite a preferencia de custo (Caro ou Barato): ");
                scanf("%s", preferencia);
                while(strcmp(preferencia, "Caro") && strcmp(preferencia, "Barato")){
                    printf("Preferencia inserida invalida.\n");
                    printf("Digite a preferencia de custo (Caro ou Barato): ");
                    scanf("%s", preferencia);
                }
                printf("Digite o tempo maximo de espera: ");
                scanf("%f", &temp_max);
                system("cls");
                printf("Restaurantes %ss e com tempo de entrega <= %.2f minutos:\n\n", preferencia, temp_max);
                for (int i = 0; i<n_rest; i++){
                    if(!(strcmp(preferencia, bh.rest[indices_rap[i]].custo)) && rapidez[i]<=temp_max){
                        printf("%s : %.1f minutos\n", bh.rest[indices_rap[i]].nome, rapidez[i]);
                    }
                }
                printf("\n\n");
                break;
            
            case 4:
                printf("Fechando...\n");
                break;
            
            default:
                printf("Opcao Invalida\n\n");
        }
    }while(opcao != 4);
    return 0;
}