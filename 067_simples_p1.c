#include <stdio.h>

int main() {

    int lista[10];
    
    //For loop para o scan dos 10 numeros   
    for (int i = 0; i < 10; i++) {
        scanf("%d", &lista[i]);
    }

    //Scan da posicao 'X' e 'Y'
    int x, y;
    printf("Digite X:\n");
    scanf("%d", &x);
    printf("Digite Y:\n", &y);
    scanf("%d", &y);

    //Soma dos numeros de acordo com a posicao dada pelo usuario **A primeira posicao do vetor comeca em '0'**
    int sum = lista[x] + lista[y];
    printf("Soma = %d\n", sum);

}