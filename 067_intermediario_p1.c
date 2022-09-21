#include <stdio.h>
#include <math.h>

float angle(int x1, int x2, int x3, int y1, int y2, int y3) {

    //Com dois pontos pode ser feita uma reta, com tres pontos podem ser feitas tres retas
    //Supondo que o angulo desejado é o do ponto 'B', podem ser feitos duas retas a partir de 'B' e avaliar o angulo entre elas
    
    //Determinacao das coordenadas das duas retas
    int ab_x = x2-x1;
    int ab_y = y2-y1;

    int bc_x = x3-x2;
    int bc_y = y3-y2;

    //Com duas retas, ou dois VETORES, pode-se determinar seu angulo com a seguinte equacao
    //Produto escalar dos vetores, divididos pelo modulo de cada um
    float part1 = (ab_x*bc_x) + (ab_y*bc_y);
    float part2 = sqrt(pow(ab_x, 2) + pow(ab_y, 2));
    float part3 = sqrt(pow(bc_x, 2) + pow(bc_y, 2));


    //Arc cosseno do valor obtido da divisao
    float anglerad = acos(part1/(part2*part3));

    //Conversao para graus
    float convert = anglerad * (180/3.1415);

    return convert;

}


int main() {

    int x1, x2, x3, y1, y2, y3;

    //Scan dos tres pontos

    printf("Ponto A:\n");
    scanf("%d %d", &x1, &y1);

    printf("Ponto B:\n");
    scanf("%d %d", &x2, &y2);

    printf("Ponto C:\n");
    scanf("%d %d", &x3, &y3);

    //Chamada da funcao
    float angledegree = angle(x1, x2, x3, y1, y2 ,y3);

    //Limitando o print até dois decimais
    printf("%.2f", angledegree);

    return 0;
}