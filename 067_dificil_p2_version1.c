#include <stdio.h>
#include <string.h>

int main () { //**Caso voce esteja usando VsCode ou um programa que de para minimizar, as linhas 53 e 940 podem ser minimizadas para facilitar visualizacao, ja que sao quase copias do inicio**

    //Fiz com 65 posicoes para ignorar a primeira posicao i = 0, e poder ter os numeros mais "bonitos" para quando for verificar as posicoes das pecas
    char position[65];
    int value[65];
    int loop = 0;
    int game = 1;
    int res[1000];

    while (loop == 0) {

        int win = 3; // 2 = Black wins(white check), 1 = White wins(black check)
        
        //Scan de todas posicoes da string dada
        for(int i = 1; i<64+1; i++) {
            scanf("%s",&position[i]);
            i += 7;
        }

        int blank = 0;

        //Comparacao de cada posicao da string com um '.', para verificar se o tabuleiro esta vazio
        for (int i = 1; i<64+1; i++) {
            if(position[i] == '.') {
                blank += 1;
            }
            else {
                break;
            }
        }

        //Se a contagem for de 64 '.', o While Loop quebra
        if (blank == 64) {
            loop == 1;
            break;
        }

        game++;
        int wking;
        int bking;

        //For Loop para procurar a posicao dos reis
        for(int i = 1; i<64+1; i++) {
            if(position[i] == 'K') {
                wking = i;
            }
            else if(position[i] == 'k') {
                bking = i;
            }
        }

        int i;
        int remainder = i%8;
        //White positions   **Eu fiz as explicacoes so para as pecas brancas, ja que a das pretas e praticamente uma copia com a substituicoes de algumas variaveis 'k' - > 'K e direcoes do peao'**
        //O For Loop vai passar pelo tabuleiro inteiro, identificando cada peca, e marcando seu alcance
        for (int i = 1; i<65; i++) {

            if (position[i] == '.') {
                continue;
            }

            // PAWN
            // Quando o peao branco esta atacando o lado preto, ele tem o alcance de 'i-7' e 'i-9', ou seja, 7 e nove posicoes anteriores
            if (position[i] == 'P'){

                //Caso esteja na coluna da direita
    	        if(i%8 == 0) {
    	            value[i-9] = 1;
    	        }

                //Caso esteja na coluna da esquerda
                else if(i%8 == 1) {
    	            value[i-7] = 1;
    	        }
                else{
    	            value[i-7] = 1;
    	            value[i-9] = 1;
    	        }
    	    }
            
            // ROOK

            if (position[i] == 'R') {

                // Side
                //Pode ser descobrir a coluna em que a peca esta, a partir da divisao presente no documento pdf, a partir disso, pode-se determinar quantas casas para frente deve ir e voltar
                switch (remainder) {
                    case 1: //COLUNA 1
                        for(int j = i+1; j<i+8; j++) {
                            if (position[j] == 'k') {         //Caso o rei ja esteja nessa posicao, o loop se quebra
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {    //**Perceba que o loop nao vai se quebrar e a variavel 'win' nao vai ser verdadeira se o rei estiver atras de uma outra peca que bloqueia o ataque da torre
                                break;                        //ja que no momento em que encontrar alguma peca, o loop se quebra** e o alcance de ataque se torna irrelevante
                            }
                            value[j] = 1;
                        }
                        break;
                    case 2: //COLUNA 2
                        for(int j = i+1; j<i+7; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-1; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 3: //COLUNA 3
                        for(int j = i+1; j<i+6; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-2; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 4: //COLUNA 4
                        for(int j = i+1; j<i+5; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-3; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 5: //COLUNA 5
                        for(int j = i+1; j<i+4; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-4; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 6: //COLUNA 6
                        for(int j = i+1; j<i+3; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-5; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 7: //COLUNA 7
                        for(int j = i+1; j<i+2; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-6; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 0: //COLUNA 8
                        for(int j = i+1; j<i+1; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-7; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                }
                
                //Down
                //Pula de 8 em 8 casas para baixo e para cima, no alcance do tabuleiro '0<j<65'
                for(int j = i+8; j<65; j++) {   //A peca deve comecar a partir de sua proxima posicao, ja que se comecasse pela propria posicao e identificasse a si mesmo, o else if de != '.' logo abaixo iria acontecer
                    if (position[j] == 'k') {
                        win = 1;
                        break;
                    }
                    else if (position[j] != '.') {  //Detecta algo alem de '.', nao pode detectar a propria peca, se nao ira quebrar o loop
                        break;                      //Essa ideia de comecar o 'j' em 'i+x' sera usado para a maioria das pecas a seguir
                    }
                    value[j] = 1;
                    j += 7; 
                }

                //Up
                for(int j = i-8; j>0; j--) {
                    if (position[j] == 'k') {
                        win = 1;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 1;
                    j -= 7; 
                }

            }
        
            // BISHOP
            //Pode ir em 4 direcoes diferentes quando nao esta em um canto
            //1 -> Diagonal superior esquerda -> vai de '-9' em '-9' casas
            //2 -> Diagonal superior direita -> vai de '-7' em '-7' casas
            //3 -> Diagonal inferior esquerda -> vai de '+7' em '+7' casas
            //4 -> Diagonal inferior direita -> vai de '+9' em '+9' casas
            if (position[i] == 'B') {

                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    for (int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j += 8;
                    }
                    for (int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j -= 6;
                    }
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    for (int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j += 6;
                    }
                    for (int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j -= 8;
                    }
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {     //Caso o ataque sendo registrado seja a primeira coluna, o loop quebra, pois se continuasse haveria um erro, como dito no pdf
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 0) {    //Situacao similar a de cima, porem na ultima coluna
                            break;
                        }
                        j += 8; 
                    }
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }

                else {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;

                        //Caso o valor de alcance do bispo esteja na primeira coluna, o for loop para
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        //Caso o valor de alcance do bispo esteja na ultima coluna, o for loop para
                        if (j%8 ==0) {
                            break;
                        }
                        j += 8;
                    }
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 ==0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }
            }

            // QUEEN
            // Combinacao da torre e do bispo
            if (position[i] == 'Q') {

                switch (remainder) {
                    case 1:
                        for(int j = i+1; j<i+8; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 2:
                        for(int j = i+1; j<i+7; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-1; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 3:
                        for(int j = i+1; j<i+6; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-2; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 4:
                        for(int j = i+1; j<i+5; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-3; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 5:
                        for(int j = i+1; j<i+4; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-4; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 6:
                        for(int j = i+1; j<i+3; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-5; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 7:
                        for(int j = i+1; j<i+2; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-6; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                    case 0:
                        for(int j = i+1; j<i+1; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        for(int j = i-7; j<i; j++) {
                            if (position[j] == 'k') {
                                win = 1;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 1;
                        }
                        break;
                }
                
                //Down
                //Pula de 8 em 8 casas para baixo e para cima, no alcance do tabuleiro '0<j<65'
                for(int j = i+8; j<65; j++) {
                    if (position[j] == 'k') {
                        win = 1;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 1;
                    j += 7; 
                }

                //Up
                for(int j = i-8; j>0; j--) {
                    if (position[j] == 'k') {
                        win = 1;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 1;
                    j -= 7; 
                }

                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    for (int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j += 8;
                    }
                    for (int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j -= 6;
                    }
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    for (int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j += 6;
                    }
                    for (int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        j -= 8;
                    }
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 0) {
                            break;
                        }
                        j += 8; 
                    }
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }

                else {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;

                        //Caso o valor de alcance do bispo esteja na primeira coluna, o for loop para
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        //Caso o valor de alcance do bispo esteja na ultima coluna, o for loop para
                        if (j%8 ==0) {
                            break;
                        }
                        j += 8;
                    }
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 ==0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'k') {
                            win = 1;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 1;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }
            }
        
            // KNIGHT
            //O cavalo se move em oito direcoes, '-6', '-10', '-15', '-17' de sua posicao, assim como seus valores positivos 
            if (position[i] == 'N') {
                
                //Ha casos excecoes que sao quando o cavalo nao pode se mover nas oito direcoes, como quando esta na ultima ou penultima linha para cada canto
                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    value[i-15] = 1;
                    value[i+15] = 1;
                    value[i-6] = 1;
                    value[i+6] = 1;
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    value[i-10] = 1;
                    value[i+10] = 1;
                    value[i-17] = 1;
                    value[i+17] = 1;
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    value[i+6] = 1;
                    value[i+10] = 1;
                    value[i+15] = 1;
                    value[i+17] = 1;
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    value[i-6] = 1;
                    value[i-10] = 1;
                    value[i-15] = 1;
                    value[i-17] = 1;
                }

                //Caso esteja na segunda coluna 
                if (remainder == 2 && i != 2 && i != 58) {
                    value[i-6] = 1;
                    value[i-15] = 1;
                    value[i-17] = 1;
                    value[i+10] = 1;
                    value[i+15] = 1;
                    value[i+17] = 1;
                }
                
                //Caso esteja na setima coluna
                if (remainder == 7 && i != 7 && i != 63) {
                    value[i-10] = 1;
                    value[i-15] = 1;
                    value[i-17] = 1;
                    value[i+6] = 1;
                    value[i+15] = 1;
                    value[i+17] = 1;
                }

                //Caso esteja na segunda fileira
                if (i < 10 && i > 15) {
                    value[i-6] = 1;
                    value[i-10] = 1;
                    value[i+6] = 1;
                    value[i+10] = 1;
                    value[i+15] = 1;
                    value[i+17] = 1;
                }

                //Caso esteja na setima fileira
                if (i < 50 && i > 55) {
                    value[i-6] = 1;
                    value[i-10] = 1;
                    value[i-15] = 1;
                    value[i-17] = 1;
                    value[i+6] = 1;
                    value[i+10] = 1;
                }

                else {
                    value[i-6] = 1;
                    value[i-10] = 1;
                    value[i-15] = 1;
                    value[i-17] = 1;
                    value[i+6] = 1;
                    value[i+10] = 1;
                    value[i+15] = 1;
                    value[i+17] = 1;
                }
            }
        
        }

        //Black positions
        for (int i = 1; i<65; i++) {

            if (position[i] == '.') {
                continue;
            }

            // PAWN
            if (position[i] == 'p'){

                //Caso esteja na coluna da direita
    	        if(i%8 == 0) {
    	            value[i+9] = 2;
    	        }

                //Caso esteja na coluna da esquerda
                else if(i%8 == 1) {
    	            value[i+7] = 2;
    	        }
                else{
    	            value[i+7] = 2;
    	            value[i+9] = 2;
    	        }
    	    }
            
            // ROOK
            if (position[i] == 'r') {

                // Side
                //Pode ser descobrir a coluna em que a peca esta, a partir da divisao presente no documento pdf, a partir disso, pode-se determinar quantas casas para frente deve ir e voltar
                switch (remainder) {
                    case 1:
                        for(int j = i+1; j<i+8; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 2:
                        for(int j = i+1; j<i+7; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-1; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 3:
                        for(int j = i+1; j<i+6; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-2; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 4:
                        for(int j = i+1; j<i+5; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-3; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 5:
                        for(int j = i+1; j<i+4; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-4; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 6:
                        for(int j = i+1; j<i+3; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-5; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 7:
                        for(int j = i+1; j<i+2; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-6; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 0:
                        for(int j = i+1; j<i+1; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-7; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                }
                
                //Down
                //Pula de 8 em 8 casas para baixo e para cima, no alcance do tabuleiro '0<j<65'
                for(int j = i+8; j<65; j++) {
                    if (position[j] == 'K') {
                        win = 2;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 2;
                    j += 7; 
                }

                //Up
                for(int j = i-8; j>0; j--) {
                    if (position[j] == 'K') {
                        win = 2;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 2;
                    j -= 7; 
                }

            }
        
            // BISHOP
            //Pode ir em 4 direcoes diferentes quando nao esta em um canto
            //1 -> Diagonal superior esquerda -> vai de '-9' em '-9' casas
            //2 -> Diagonal superior direita -> vai de '-7' em '-7' casas
            //3 -> Diagonal inferior esquerda -> vai de '+7' em '+7' casas
            //4 -> Diagonal inferior direita -> vai de '+9' em '+9' casas
            if (position[i] == 'b') {

                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    for (int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j += 8;
                    }
                    for (int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j -= 6;
                    }
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    for (int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j += 6;
                    }
                    for (int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j -= 8;
                    }
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 0) {
                            break;
                        }
                        j += 8; 
                    }
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }

                else {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;

                        //Caso o valor de alcance do bispo esteja na primeira coluna, o for loop para
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        //Caso o valor de alcance do bispo esteja na ultima coluna, o for loop para
                        if (j%8 ==0) {
                            break;
                        }
                        j += 8;
                    }
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 ==0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }
            }

            // QUEEN
            // Combinacao da torre e do bispo
            if (position[i] == 'q') {

                switch (remainder) {
                    case 1:
                        for(int j = i+1; j<i+8; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 2:
                        for(int j = i+1; j<i+7; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-1; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 3:
                        for(int j = i+1; j<i+6; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-2; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 4:
                        for(int j = i+1; j<i+5; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-3; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 5:
                        for(int j = i+1; j<i+4; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-4; j<i; j++) {
                            value[j] = 2;
                        }
                        break;
                    case 6:
                        for(int j = i+1; j<i+3; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-5; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 7:
                        for(int j = i+1; j<i+2; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-6; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                    case 0:
                        for(int j = i+1; j<i+1; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        for(int j = i-7; j<i; j++) {
                            if (position[j] == 'K') {
                                win = 2;
                                break;
                            }
                            else if (position[j] != '.') {
                                break;
                            }
                            value[j] = 2;
                        }
                        break;
                }
                
                //Down
                //Pula de 8 em 8 casas para baixo e para cima, no alcance do tabuleiro '0<j<65'
                for(int j = i+8; j<65; j++) {
                    if (position[j] == 'K') {
                        win = 2;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 2;
                    j += 7; 
                }

                //Up
                for(int j = i-8; j>0; j--) {
                    if (position[j] == 'K') {
                        win = 2;
                        break;
                    }
                    else if (position[j] != '.') {
                        break;
                    }
                    value[j] = 2;
                    j -= 7; 
                }

                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    for (int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j += 8;
                    }
                    for (int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j -= 6;
                    }
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    for (int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j += 6;
                    }
                    for (int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        j -= 8;
                    }
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 0) {
                            break;
                        }
                        j += 8; 
                    }
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }

                else {
                    for(int j = i+7; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;

                        //Caso o valor de alcance do bispo esteja na primeira coluna, o for loop para
                        if (j%8 == 1) {
                            break;
                        }
                        j += 6; 
                    }
                    for(int j = i+9; j<65; j++) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        //Caso o valor de alcance do bispo esteja na ultima coluna, o for loop para
                        if (j%8 ==0) {
                            break;
                        }
                        j += 8;
                    }
                    for(int j = i-7; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 ==0) {
                            break;
                        }
                        j -= 6; 
                    }
                    for(int j = i-9; j>0; j--) {
                        if (position[j] == 'K') {
                            win = 2;
                            break;
                        }
                        else if (position[j] != '.') {
                            break;
                        }
                        value[j] = 2;
                        if (j%8 == 1) {
                            break;
                        }
                        j -= 8; 
                    }
                }
            }
        
            // KNIGHT
            //O cavalo se move em oito direcoes, '-6', '-10', '-15', '-17' de sua posicao, assim como seus valores positivos 
            if (position[i] == 'n') {
                
                //Ha casos excecoes que sao quando o cavalo nao pode se mover nas oito direcoes, como quando esta na ultima ou penultima linha para cada canto
                //Caso esteja na coluna da esquerda
                if (remainder == 1) {
                    value[i-15] = 2;
                    value[i+15] = 2;
                    value[i-6] = 2;
                    value[i+6] = 2;
                }

                //Caso esteja na coluna da direita
                if (remainder == 0) {
                    value[i-10] = 2;
                    value[i+10] = 2;
                    value[i-17] = 2;
                    value[i+17] = 2;
                }

                //Caso esteja na fileira de cima
                if (i < 0 && i>9) {
                    value[i+6] = 2;
                    value[i+10] = 2;
                    value[i+15] = 2;
                    value[i+17] = 2;
                }

                //Caso esteja na fileira de baixo
                if (i < 56 && i>65) {
                    value[i-6] = 2;
                    value[i-10] = 2;
                    value[i-15] = 2;
                    value[i-17] = 2;
                }

                //Caso esteja na segunda coluna 
                if (remainder == 2 && i != 2 && i != 58) {
                    value[i-6] = 2;
                    value[i-15] = 2;
                    value[i-17] = 2;
                    value[i+10] = 2;
                    value[i+15] = 2;
                    value[i+17] = 2;
                }
                
                //Caso esteja na setima coluna
                if (remainder == 7 && i != 7 && i != 63) {
                    value[i-10] = 2;
                    value[i-15] = 2;
                    value[i-17] = 2;
                    value[i+6] = 2;
                    value[i+15] = 2;
                    value[i+17] = 2;
                }

                //Caso esteja na segunda fileira
                if (i < 10 && i > 15) {
                    value[i-6] = 2;
                    value[i-10] = 2;
                    value[i+6] = 2;
                    value[i+10] = 2;
                    value[i+15] = 2;
                    value[i+17] = 2;
                }

                //Caso esteja na setima fileira
                if (i < 50 && i > 55) {
                    value[i-6] = 2;
                    value[i-10] = 2;
                    value[i-15] = 2;
                    value[i-17] = 2;
                    value[i+6] = 2;
                    value[i+10] = 2;
                }

                else {
                    value[i-6] = 2;
                    value[i-10] = 2;
                    value[i-15] = 2;
                    value[i-17] = 2;
                    value[i+6] = 2;
                    value[i+10] = 2;
                    value[i+15] = 2;
                    value[i+17] = 2;
                }
            }
        
        }


        
        int pos;
        for(int a = 1; a<65; a++) {
            if (value[a] == 1) {
                pos = a;
                if (pos == bking) {
                    win == 1;
                }
            } 
        }
        int posa;
        for(int a = 1; a<65; a++) {
            if (value[a] == 2) {
                posa = a;
                if (posa == wking) {
                    win == 2;
                }
            } 
        }

        if (win == 2) {
            res[game] = 0;
        }
        else if (win == 1) {
            res[game] = 1;
        }
        else if (win == 3) {
            res[game] = 3;
        }
        
    }

    for (int k = 2; k<game+1; k++) {
        if (res[k] == 0 ) {
           printf("Jogo #%d: rei branco esta em cheque.\n", k-1);
        }
        else if (res[k] == 1 ) {
            printf("Jogo #%d: rei preto esta em cheque.\n", k-1);
        }
        else if (res[k] == 3 ) {
            printf("Jogo #%d: nenhum rei esta em cheque.\n", k-1);
        }
    }
}


