#include <stdio.h>

int encontra_primo(int a) {

    int res = 1;

    //Um valor é primo se dividido somento por si mesmo e pelo numero 1
    //Deve-se entao verificar o oposto, ou seja, se ele e divisivel por outro numero
    //Como o menor denominador inteiro possivel é o numero 2, esse sera o limite de 'i', ou seja a metade do numero selecionado
    //A variavel i comeca no numero 2, ja que a divisao por '0' e '1' nao sao importantes
    for (int i = 2; i <= a / 2; i++) {

        //Caso algum numero consiga dividir(sem resto) o numero selecionado, o For Loop é quebrado imediatamente e o numero nao e primo
        //Caso contrario, ou seja, o For Loop completa todo seu curso sem nenhum numero que consiga divir, entao o numero é primo
        if (a % i == 0) {
            res = 0;
            break;
        }   
    }

    //Retorno do resultado da funcao
    if (res == 1) {         //'1' é numero primo
        return 1;
    }
    else if (res == 0) {    // '0' NAO é numero primo
        return 0;
    }

}

int main() {

    //O Loop While vai fazer o scan ate 'EOF' (End of file), permitindo uma quantidade arbitraria de numeros a serem avaliados
    int x;
    while (scanf("%d", &x) != EOF) {
        
        //Chamada da funcao
        int res = encontra_primo(x);

        //Avaliacao do valo retornado da funcao, se o valor for 1 ele e um primo e portanto ocorre o seu print
        //O valor 1 nao e avaliado
        if (res == 1 && x != 1) {
            printf("%d ", x);
        }

    }

    return 0;
}