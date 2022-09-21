#include <stdio.h>

//Declaracao de uma funcao extra de organizacao
int sort(int array[], int size);

int duplicate(int array[], int arraycopy[], int size) {

    
    for (int i = 0; i<size; i++) {

        int equal = 0;
        for (int j = 0; j<size; j++) {

            //O valor na posicao 'j' de 'array' é comparada com o valor na posicao 'i' de 'arraycopy'
            //O valor de 'arraycopy' é "fixado" ate todos os numeros de 'array' serem comparados
            //Caso uma copia seja encontrada, o contador 'equal' é adicionado o valor de +1
            //Como um vetor é copia do outro, sempre tera pelo menos uma copia do valor, entao só é feito mudancas caso haja duas copias

            if (arraycopy[i] == array[j]) {
                equal++;
                if(equal > 1) { //Se houver pelo menos duas copias, é feito um For Loop para apagar aquela posicao, e "puxar" todas as posicoes posteriores do vetor para "tras"
                    for(int k=j; k<size; k++) {
                        array[k] = array[k+1];
                    }

                    //Conforme as posicoes sao apagadas e os valores reposicionados, o vetor deve diminuir, para apagar os "tracos" do vetor antigo
                    size--;

                    //Como o valor avaliado com o valor na posicao 'j' é igual e foi apagado e as posicoes diminuidas em um, a variavel 'j' deve voltar um para tras
                    j--;
                }
            }
        }
    }

    //Funcao extra para organizar os numeros em ordem ascendente
    sort(array, size);

    //Print dos numeros nao duplicados
    for(int i = 0; i<size; i++) {
        printf("%d ", array[i]);
    }

}

int sort(int array[], int size) {

    for (int i = 0; i<size; i++) {
        for (int j = i + 1; j<size; j++) {
            if (array[i] > array[j]) {
                int hold =  array[i];
                array[i] = array[j];
                array[j] = hold;
            }
        }
    }
}

int main () {

    //Scan do tamanho da lista
    printf("Digite a quantidade de numeros na lista:\n");
    int size;
    scanf("%d", &size);
    int array[size];
    
    //Scan dos valores da lista
    for(int i = 0; i<size; i++) {
        scanf("%d", &array[i]);
    }

    //Duplicacao da lista, para sua futura comparacao e verificacao de duplicados
    int arraycopy[size];
    for (int i = 0; i<size; i++) {
        arraycopy[i] = array[i];
    }

    //Chamada da funcao
    duplicate(array, arraycopy, size);

    return 0;
}