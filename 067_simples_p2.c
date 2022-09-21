#include <stdio.h>

int perf(int a) {
    int sum;

    //Como o menor possivel denominador INTEIRO de um numerador com resto '0' é o numero 2 (alem do 1), a variavel 'i' so vai ate o numero dividido por 2
    //O For Loop vai testar todos os numeros ate a metade do numero selecionado, e caso seu resto seja 0. ele vai somar a variavel 'sum'
    for (int i = 1; i <= a/2; i++) {
        if (a%i == 0) {
            sum += i;   
        }
    }

    //Caso a soma dos numeros seja igual ao proprio numero seleciconado, o retorno da funcao vai ser verdadeiro, caso contrario sera falso
    if (sum == a) {
        return 1;
    }
    else if (sum != a) {
        return 0;
    }
}

int main() {

    //Scan do valor a ser avaliado
    int x;
    scanf("%d", &x);

    //Chamada da funcao
    int res = perf(x);

    //Print do resultado de acordo com o valor retornado da funcao
    if (res == 1) {         // 1 = Perfeito
        printf("O valor inserido e perfeito!\n");
    }
    else if (res == 0) {    // 0 == Nao perfeito
        printf("O valor inserido NAO e perfeito!\n");
    }

    return 0;
}