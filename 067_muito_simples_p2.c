#include <stdio.h>

float converte_temperatura(float temp) {
    float res;

    //Equacao comum da conversao de fahrenheit para celsius
    res = (temp - 32) / 1.8; 

    return res;
}
int main() {    

    //Uso de float ja que a conversao possivelmente/provavelmente vai resultar em um numero nao inteiro 
    float temp, cels;

    //Scan da temperatura em fahrenheit
    scanf("%f", &temp);

    //Chamada da funcao
    cels = converte_temperatura(temp);
    printf("%.2f\n", cels);

    return 0;
}