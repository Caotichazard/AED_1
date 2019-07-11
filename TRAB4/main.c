#include <stdlib.h>
#include <stdio.h>
#include <string.h>



void arrayCopy(int* a, int* b, int size);//arrayCopy(&a[0][0], &b[0][0], size); sendo size apenas de uma dimensao
int resolveNrainhas(int* tabuleiro, int qtdRainhas);
int insereRainhas(int* tabuleiro, int qtdRainhas, int x, int y);
int main(){
    int N;

    scanf("%d", &N);

    int tabuleiro[N][N];
    int qtdRainhas = N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            tabuleiro[i][j]=0;
        }
    }
    //printf("Preencheu tabuleiro com 0\n");

    printf("%d\n",resolveNrainhas(&tabuleiro[0][0],N));
    
}
    
    
void arrayCopy(int* a, int* b, int size){
    //printf("Copiando tabuleiro\n");
    memcpy(b, a, size*size*sizeof(int));
}

int resolveNrainhas(int* tabuleiro, int qtdRainhas){
    
    int x=0,cont = 0;
    while(x<qtdRainhas){
        cont+=insereRainhas(tabuleiro,qtdRainhas,x,0);
        x++;
    }

    return cont;

}

int insereRainhas(int* tabuleiro, int qtdRainhas, int x, int y){
    //printf("Testando linha %d coluna %d\n", y,x);
    int cont=0,k=0;
    int tabuleiroAux[qtdRainhas][qtdRainhas];
    arrayCopy(tabuleiro,&tabuleiroAux[0][0],qtdRainhas);
    if(y<qtdRainhas){
        if(tabuleiroAux[x][y]==0){
            tabuleiroAux[x][y]=qtdRainhas;
            if(y+1>=qtdRainhas){
                return 1;
            }
            for(int i=1;i<qtdRainhas;i++){//Preenche a matriz com posições invalidas para posicionar uma rainha
                if(x-i>-1){
                    tabuleiroAux[x-i][y]=-1;
                }
                if(x+i<qtdRainhas){
                    tabuleiroAux[x+i][y]=-1;
                }
                if(y-i>-1){
                    tabuleiroAux[x][y-i]=-1;
                }
                if(y+i<qtdRainhas){
                    tabuleiroAux[x][y+i]=-1;
                }
                if(x+i<qtdRainhas && y-i>-1){
                    tabuleiroAux[x+i][y-i]=-1;
                }
                if(x+i<qtdRainhas && y+i<qtdRainhas){
                    tabuleiroAux[x+i][y+i]=-1;
                }
                if(x-i>-1 && y+i<qtdRainhas){
                    tabuleiroAux[x-i][y+i]=-1;
                }
                if(x-i>-1 && y-i>-1){
                    tabuleiroAux[x-i][y-i]=-1;
                }
            }
            while(k<qtdRainhas){
                cont+=insereRainhas(&tabuleiroAux[0][0], qtdRainhas,k,y+1);
                k++;
            }
            return cont;
        }else{
            //printf("Impossivel posicionar rainha\n");
            return 0;
        }
    }else{
        //printf("Achou solução\n");
        return 1;
    }
}