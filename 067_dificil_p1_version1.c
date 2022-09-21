#include<stdio.h>
#include<string.h>

//É necessario o uso do ponteiro ja que a string sera usada futuramente em outra funcao e nao so internamente no mesmo "corpo" de texto
int removedot(char * string) {

    //For Loop que avalia cada posicao da string e a compara com a areia '.'
    int size = strlen(string);
    for(int i = 0; i<size; i++) {
        if(string[i] == '.') {   //Caso a areia seja encontrada, ela é substituida pelo valor na posicao posterior, e assim por diante ate o final da string
            for(int j=i; j<size; j++) {
                string[j] = string[j+1];
            }

            //Como a areia foi encontrada e a string reposicionada, é necessario a diminuicao da string para apagar os "tracos" da string antiga
            size--;
            i--;
        }
    }
    return size;
}

//Funcao para contar diamantes em apenas uma analise de linha **VERSAO 1**
int counter(char * string, int size) {
    int count = 0;
    int sequence = 0;

    //O For Loop vai passar somente uma vez pela string "prevendo" possiveis combinacoes 
    //Como as areias foram apagadas, so existem dois casos para cada posicao, '<' e '>'
    //Porem há subcasos dentro deles
    for (int i = 0; i<size; i++) {
        if (string[i] == '<') {
            if(string[i+1] == '>' && sequence == 0) {  // Caso o valor em seguida seja '>' e nao ter nenhum caso de duplicatas de '<' a contagem sobe
                count++;
            }
            else if(string[i+1] == '<') {              // Caso o valor em seguida seja outro '<', há uma sequencia que deve ser lembrada, caso um diamante esteja bloqueando outro
                if (sequence != 0) { 
                    sequence += 1;                     // Caso ja haja uma sequencia, a contagem da sequencia só sobre +1, **USADO PARA QUANDO ESTÁ NO TERCEIRO '<' ou mais**
                }
                else{
                    sequence += 2;                     // Caso seja a primeira sequencia encontrada, a contagem sobe +2, pois ela é vista como um par 
                }
            }
        }                                               
                                                       // Nao é necessario um caso de somente '>' ja que o '>' só importa se houver um '<' anteiror
        else if (sequence != 0 && string[i] == '>') {  // Esse caso é para caso haja um '<'(que foi anotado na memoria de 'sequence') anterior ao '>', ou seja uma sequencia de '<' que foram bloqueadas pois havia um diamante bloqueando o outro, EXEMPLO: <<>>
            count++;
            sequence--;                                //A sequencia é diminuida pois um '<' foi usado para a formacao de outro diamante com o atual '>' e a contagem subiu
            if (string[i+1] == '<') {                  // Como esse 'if' só sera ativado para quando o valor é '>', esse 'if' serve para quando apos o '>' há um '<' que continuara a sequencia
                sequence++;                            // Exemplo: < <<>> <?????, apos os dois diamantes internos serem contados e 'consumidos' 
            }                                          // o restante seria <<?????, ou seja, uma nova sequencia formada com '<' antes e apos os diamantes
        }
    }
    
    return count;
}

int main() {

    char string[1000];
    int n;

    //Scan da quantidade de linhas
    scanf("%d", &n);

    //Vetor para armazenar todas variaveis e fazer o print no final
    int result[n];

    //For Loop para o scan de cada linha
    for(int i = 0; i<n; i++) {

        scanf("%s", &string);
        
        //Funcao para remover a areia '.'
        int size = removedot(string);

        //Funcao para contar os diamantes '<>'
        int count = counter(string, size);
        result[i] = count;

    }

    for (int i = 0; i<n; i++) {
        printf("%d\n", result[i]);
    }
} 