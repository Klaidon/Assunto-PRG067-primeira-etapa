#include <stdio.h>
#include <string.h>

int counter(char string[100], char letter) {
    int size, count;

    //Contagem do tamanho da string
    size = strlen(string);

    //For Loop que avalia cada posicao da string, comparando se a letra a posicao da string sao iguais, caso sim é adicionado +1 a variavel 'count'
    for(int i = 0; i < size; i++) {

        if(string[i] == letter){
            count++;
        }
    }
    
    return count;
}

int main () {

    char letter;
    char string[100];

    //Como a entrada do problema nao pareceu precisar de exatidao para mim, eu decidi simplesmente dividir em dois scan diferentes com uma perguntinha para cada

    //Inicialmente é feito o scan da string
    printf("Digite uma string:\n");
    scanf("%[^\n]%*c", string);    // O uso de '%[^\n]%*c' permite o scan de uma string com espacos

    //Scan da letra a ser contada
    printf("\nDigite uma letra:\n"); 
    scanf("%c", &letter);

    //Chamada da funcao
    int count = counter(string, letter);
    printf("\n%d\n", count);

    return 0;
}