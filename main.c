#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void preencherMatriz(int qtdLinhas,int qtdColunas, int matriz[qtdLinhas][qtdColunas],int probabilidadeBomba, int valorbomba){
        for(int i = 0; i < qtdLinhas; i++){
            for (int j = 0; j < qtdColunas; j++){
                matriz[i][j] = (rand()%100) < probabilidadeBomba ? valorbomba : 0;
            }
        }
}
void enumerarMatriz(int qtdLinhas, int qtdColunas,int matriz[qtdLinhas][qtdColunas],int valorbomba){
    for(int i = 0; i < qtdLinhas; i++){
        for (int j = 0; j < qtdColunas; j++){
            if(matriz[i][j] == valorbomba){
                continue;
            }
            int contador = 0;
            for (int ii = i-1; ii <= i+1; ii++) {
                for (int jj = j-1; jj <= j+1; jj++) {
                    if ( ii < qtdLinhas  && jj < qtdColunas) { 
                        if (matriz[ii][jj] == valorbomba) {
                            contador++;
                        }
                    }
                }
            }
            matriz[i][j] = contador;
        }
    }
}
int main(){
    int valorbomba = -1;
    int qtdLinhas = 10;
    int qtdColunas = 10;
    int probabilidadeBomba = 15;
    char headerHorizontal[qtdColunas+2];
    int headerVertical[qtdLinhas+2];
    srand(time(0));
    int matriz[qtdLinhas][qtdColunas]; 
    int matrizVisualizacao[qtdLinhas][qtdColunas];
    char colunaLetra;
    char colunaNumero;
    int linha;
    int erro = 0;

    for(int i = 0; i <= qtdLinhas + 1; i++){
        headerVertical[i] = i;
    }
    for(int i = 0; i <= qtdLinhas + 1; i++){
        for(int j = 0; j <= qtdColunas + 1; j++){
            matrizVisualizacao[i][j] = 0;
        }
    }
    preencherMatriz(qtdLinhas,qtdColunas,matriz,probabilidadeBomba,valorbomba);
    enumerarMatriz(qtdLinhas,qtdColunas,matriz, valorbomba);

    while (1){
        system("clear");
        headerHorizontal[0] = ' ';
        printf(" %2c ",headerHorizontal[0]);
        for(int i = 1; i < qtdColunas + 1; i++){
            headerHorizontal[i] = (char) (64+i);
            printf(" %2c ",headerHorizontal[i]);
        }
        printf("\n--------------------------------------------\n");

        for(int i = 0; i < qtdLinhas ; i++){
            printf("%2d |",headerVertical[i]);
            for (int j = 0; j < qtdColunas; j++){
                if(matrizVisualizacao[i][j] == 1){
                    if(matriz[i][j] == -1){
                    printf(" %2s ", "💣");
                    }else{
                        printf(" %2d ", matriz[i][j]);
                    }
                } else{
                    printf(" [] ");
                }
            }
            printf("\n");
        }
        if (erro){
            printf("\n\n !! Comando invalido !!");
        }
        

        printf("\n\nDigite uma posição (exemplo: A 9): \n");
        
        scanf("%c", &colunaLetra);
        scanf("%d", &linha);
        colunaNumero = colunaLetra - 65;
        if(colunaNumero > qtdColunas || colunaNumero < 0 || linha < 0 || linha > qtdLinhas){
            erro = 1;
            continue;
        } else {
            erro = 0;
            matrizVisualizacao[linha][colunaNumero] = 1;
        }
    }
    
    

    return 0;
}