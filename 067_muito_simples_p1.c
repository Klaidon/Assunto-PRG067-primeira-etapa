#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

float distancia(float x1, float y1, float x2, float y2) {

    float res; 

    //Equacao de pitagoras ao se descobrir a distancia 'x' e 'y' a partir da diferenca dos pontos
    res = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));

    return res;
}

int main() {

    //Uso de float ja que o calculo de distancia possivelmente/provavelmente vai dar um numero nao inteiro 
    float a, b, c, d, dist;

    //Scan dos dois pointos em quatro diferentes floats
    scanf("%f %f %f %f", &a, &b, &c, &d);

    //Chamada da funcao 
    dist = distancia(a, b, c, d);
    printf("%.3f\n", dist);

    return 0;
}