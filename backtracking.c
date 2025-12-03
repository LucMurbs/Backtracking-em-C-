#include <stdio.h>
#include <locale.h>
const int tamanho = 10; // Define o tamanho do labirinto para o resto do código

// 0 = Caminho
// 1 = Parede
// 2 = Fim do Labirinto
int labirinto[10][10] = {
    {0, 1, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};
/*int labirinto[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 2},
    {0, 0, 0, 1, 1},
    {1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};*/


// Função para mostrar o estado atual do labirinto
void mostrarLabirinto(int tamanho) {
    for (int x=0; x<tamanho;x++) {
        for (int y=0; y<tamanho;y++) {
            switch (labirinto[x][y]) {
                case 0: // Caso seja um caminho
                    printf("⬜"); 
                    break;
            
                case 1: // Caso seja uma parede
                    printf("⬛");
                    break;
                case 2: // Caso seja o objetivo
                    printf("🔶");
                    break;
                case 3: // Caso seja o um caminho já visitado sem saida
                    printf("⬜");
                    break;
                case 7: // Caso seja o caminho
                    printf("🔼");
                    break;
            }
        }
        printf("\n");
    }
        
}

int resolveLabirinto(int x, int y, int tamanho) {
    if (x < 0 || x >= tamanho || y < 0 || y >= tamanho) return 0; // caso sejá fora do labirinto
    if (labirinto[x][y] == 2) return 1; // caso sejá a saída
    if (labirinto[x][y] != 0) return 0; // caso não seja um caminho

    labirinto[x][y] = 3; // marca como visitado

    if (resolveLabirinto(x+1, y, tamanho) || resolveLabirinto(x-1, y, tamanho) ||
        resolveLabirinto(x, y+1, tamanho) || resolveLabirinto(x, y-1, tamanho)) {
        labirinto[x][y] = 7; // caminho da solução
        return 1;
    }

    return 0;
}



int main() {
    int solucao;

    setlocale(LC_ALL, "Portuguese");

    mostrarLabirinto(tamanho);
    solucao = resolveLabirinto(0,0,tamanho);
    printf("\n\n");
    mostrarLabirinto(tamanho);

    if (solucao==0) printf("Labirinto sem solução!");
    
    return 0;
}