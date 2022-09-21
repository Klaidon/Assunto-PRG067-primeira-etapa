#include<stdio.h>
#include<string.h>

//Funcao para remover areia, igual a versao1
int removedot(char * string) {

    int size = strlen(string);
    for(int i = 0; i<size; i++) {
        if(string[i] == '.') {
            for(int j=i; j<size; j++) {
                string[j] = string[j+1];
            }

            size--;
            i--;
        }
    }
    return size;
}

//Funcao para contar diamantes ao analisar a linha varias vezes **VERSAO 2**
int counter(char * string, int size) {

    int count = 0;

    //O For Loop vai analisar a linha uma vez e verificar se há um possivel diamante
    //Caso seja possivel ele apagara o diamante, refomara a string sem o diamante, e continuara o Loop ate nenhum diamante ser encontrado
    for (int i = 0; i<size; i++) {
        if (string[i] == '<' && string[i+1] == '>') {
            count++;
            for(int j=i; j<size; j++) {
                string[j] = string[j+2];     //Como sao duas posicoes sendo apagadas, é necessario a posicao 'j' seja substituida por 'j+2' e nao 'j+1'
                string[j+1] = string[j+3];
                i = -1; 
            }
            size -= 2;                       //Como duas posicoes sao apagadas por vez, o tamanho da string diminui de 2 em 2
        }
        // Demonstracao do procedimento
        //printf("i = %d : %s\n", i, string);
    }
    return count;
}

//Corpo main igual a versao1
int main() {

    char string[1000];
    int n;
    scanf("%d", &n);
    int result[n];

    for(int i = 0; i<n; i++) {

        scanf("%s", &string);
        int size = removedot(string);
        int count = counter(string, size);
        result[i] = count;

    }

    for (int i = 0; i<n; i++) {
        printf("%d\n", result[i]);
    }
} 