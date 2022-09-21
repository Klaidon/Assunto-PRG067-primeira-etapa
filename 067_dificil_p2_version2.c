#include <stdio.h>
#include <string.h>

int main () {   //**Caso voce esteja usando VsCode ou um programa que de para minimizar, as linhas 301, 517, 736, 958, 1179, 1408, 1626 e 1872 podem ser minimizadas para facilitar visualizacao, ja que sao quase copias do inicio**


    char a[10], b[10], c[10], d[10], e[10], f[10], g[10], h[10];
    int game = 0;    //Contagem de jogos
    int res[1000];   //Vetor para armazenar os resultados e serem feitos o printf no final
    int blank = 0;   //Variavel que conta se quantas posicoes sao '.' (proporcao de 1:8)
    int loop = 0;    //Variavel que vai quebrar o loop quando todas posicoes forem '.'
    while(loop == 0) {

        //Scan do tabuleiro
        scanf("%s", a);
        scanf("%s", b);
        scanf("%s", c);
        scanf("%s", d);
        scanf("%s", e);
        scanf("%s", f);
        scanf("%s", g);
        scanf("%s", h);

        game++;
        //Verifica coluna por coluna se todos as posicoes sao '.'
        for(int i = 0; i<8; i++) {
            if(a[i] == '.' && b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == '.') {
                blank++;
            }
        }

        //Quebra o Loop se todas posicoes forem '.' ao tornar o 'while' falso
        if(blank == 8) {
            loop = 1;
            break;
        }

        int win = 3;  

        //REI PRETO
        int found = 0;
        char blackposition;
        int blackpositionnum = 100;
        int whitepositionnum = 100;
        int noblock = 100;

        //Cada linha 'a', 'b', 'c', etc... possui a mesma ideia de codigo, porem com simples mudancas de valores de posicoes 'a' -> 'b', etc...
        //E quanto aos dois While Loop, so ha a diferenca de maiuscula para minuscula 'K' -> 'k' e inversao do sentido do peao, que so ataca para baixo ou para cima dependendo do lado
            
        //Procura pelo rei preto e a partir dai procura por ameacas na area
        while(blackpositionnum == 100) {
        
            //Procura o rei na linha 'a', caso nao encontre o rei passa para a proxima linha, caso encontre, verifica todas as possiveis posicoes que possa amecar essa posicao do rei
            for(int i = 0; i<8; i++) {
                if(a[i] == 'k') {
                    blackposition = 'a';
                    blackpositionnum = i;

                    //Todas as posicoes do peao, que ataca na diagonal, como o rei esta na linha a, o peao inimigo estaria na diagonal 'i-1' ou 'i+1', na linha inferior 'b'
                    // PAWN
                    if (b[i-1] == 'P' || b[i+1] == 'P') {
                        win = 1;
                        break;
                    }
                    
                    //Todas as posicoes para a torre, que pode atacar pelo lado, procurando o 'R' na mesma linha, e verificando se nao tem um bloqueio de outra peca
                    //Procura-se tambem na mesma coluna, e verificando se nao ha bloqueios de outras pecas
                    // ROOK
                    // *SIDE
                    for(int j = 0; j<8; j++) {
                        if(a[j] == 'R') {
                            for(int k = j+1; k<8; k++) {
                                if (a[k] == '.') {
                                    noblock = 0;
                                }
                                else if (a[k] != '.') {
                                    noblock = 1;
                                }
                            }
                            for(int k = j-1; k>0; k--) {
                                if (a[k] == '.') {
                                    noblock = 0;
                                }
                                else if (a[k] != '.') {
                                    noblock = 1;
                                }
                            }
                            if (noblock == 0) {
                                win = 1;
                            }
                        }
                    }
                    // *STRAIGHT
                    if (b[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'R') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'R') {
                        win = 1;
                        break;
                    }

                    //Todas as posicoes do bispo, que possui um padrao de ataque similar ao peao, porem em 4 diagonais, e nao e limitado a apenas uma casa
                    //Portanto na linha 'a' posicao 'i' verifica-se 'b' 'i+1' e 'i-1', 'c' 'i+2' 'i-2' e adiante 
                    // BISHOP
                    if(b[i-1] == 'B' || b[i+1] == 'B') {
                        win = 1;
                        break;
                    }
                    
                    else if(c[i-2] == 'B' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(c[i+2] == 'B' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    
                    else if(d[i-3] == 'B' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(d[i+3] == 'B' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    
                    else if(e[i+4] == 'B' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(e[i-4] == 'B' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    
                    else if(f[i+5] == 'B' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(f[i-5] == 'B' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    
                    else if(g[i+6] == 'B' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(g[i-6] == 'B' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }

                    else if(h[i+7] == 'B' && g[i+6] == '.' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(h[i-7] == 'B' && g[i-6] == '.' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }

                    //Todas as posicoes da rainha podem ser copiadas a partir do que foi feito para a torre e o bispo
                    // QUEEN
                    for(int j = 0; j<8; j++) {
                        if(a[j] == 'Q') {
                            for(int k = j+1; k<8; k++) {
                                if (a[k] == '.') {
                                    noblock = 0;
                                }
                                else if (a[k] != '.') {
                                    noblock = 1;
                                }
                            }
                            for(int k = j-1; k>0; k--) {
                                if (a[k] == '.') {
                                    noblock = 0;
                                }
                                else if (a[k] != '.') {
                                    noblock = 1;
                                }
                            }
                            if (noblock == 0) {
                                win = 1;
                            }
                        }
                    }
                    if (b[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if(b[i-1] == 'Q' || b[i+1] == 'Q') {
                        win = 1;
                        break;
                    }
                    else if(c[i-2] == 'Q' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(c[i+2] == 'Q' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(d[i-3] == 'Q' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(d[i+3] == 'Q' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    } 
                    else if(e[i+4] == 'Q' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(e[i-4] == 'Q' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(f[i+5] == 'Q' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(f[i-5] == 'Q' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(g[i+6] == 'Q' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(g[i-6] == 'Q' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(h[i+7] == 'Q' && g[i+6] == '.' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                        win = 1;
                        break;
                    }
                    else if(h[i-7] == 'Q' && g[i-6] == '.' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                        win = 1;
                        break;
                    }

                    //O cavalo pode atacar a partir de um valor de distancia de '3', ou seja, ou ele esta a uma linha e duas colunas de distancia, ou a duas linhas e uma coluna de dsitancia
                    //Portanto, para a linha 'a' posicao 'i', pode estar em 'a+1'(b) 'i+2' ou 'i-2', 'a+2'(c) 'i+1' ou 'i-1'
                    // HORSE
                    if (b[i-2] == 'N' || b[i+2] == 'N' || c[i-1] == 'N' || c[i+1] == 'N') {
                        win = 1;
                        break;
                    }

                    break;
                }
            else if(b[i] == 'k') {
                blackposition = 'b';
                blackpositionnum = i;

                if (c[i-1] == 'P' || c[i+1] == 'P') {
                    win = 1;
                }
                

                for(int j = 0; j<8; j++) {
                    if(b[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (c[i] == 'R'|| a[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'R') {
                    win = 1;
                    break;
                }

                
                if(a[i-1] == 'B' || a[i+1] == 'B' || c[i-1] == 'B' || c[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(d[i-2] == 'B' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+2] == 'B' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-3] == 'B' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+3] == 'B' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i+4] == 'B' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i-4] == 'B' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(g[i+5] == 'B' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i-5] == 'B' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(h[i+6] == 'B' && g[i+5] == '.' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i-6] == 'B' && g[i-5] == '.' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                for(int j = 0; j<8; j++) {
                    if(b[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (c[i] == 'Q'|| a[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'Q') {
                    win = 1;
                    break;
                }

                
                if(a[i-1] == 'Q' || a[i+1] == 'Q' || c[i-1] == 'Q' || c[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(d[i-2] == 'Q' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+2] == 'Q' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-3] == 'Q' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+3] == 'Q' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i+4] == 'Q' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i-4] == 'Q' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(g[i+5] == 'Q' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i-5] == 'Q' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(h[i+6] == 'Q' && g[i+5] == '.' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i-6] == 'Q' && g[i-5] == '.' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                

                if (c[i-2] == 'N' || c[i+2] == 'N' || d[i-1] == 'N' || d[i+1] == 'N' || a[i-2] == 'N' || a[i+2] == 'N') {
                    win = 1;
                    break;
                }


                break;
            }
            else if(c[i] == 'k') {
                blackposition = 'c';
                blackpositionnum = i;

                if (d[i-1] == 'P' || d[i+1] == 'P') {
                    win = 1;
                }


                for(int j = 0; j<8; j++) {
                    if(c[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }             
                if (d[i] == 'R' || b[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (b[i] == '.' && a[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'R') {
                    win = 1;
                    break;
                }


                if(b[i-1] == 'B' || b[i+1] == 'B' || d[i-1] == 'B' || d[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(a[i-2] == 'B' && b[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+2] == 'B' && b[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-2] == 'B' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+2] == 'B' && d[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i-3] == 'B' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+3] == 'B' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(g[i-4] == 'B' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+4] == 'B' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-5] == 'B' && g[i-4] == '.' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+5] == 'B' && g[i+4] == '.' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(c[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }             
                if (d[i] == 'Q' || b[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (b[i] == '.' && a[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'Q') {
                    win = 1;
                    break;
                }


                if(b[i-1] == 'Q' || b[i+1] == 'Q' || d[i-1] == 'Q' || d[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(a[i-2] == 'Q' && b[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+2] == 'Q' && b[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-2] == 'Q' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+2] == 'Q' && d[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i-3] == 'Q' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+3] == 'Q' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(g[i-4] == 'Q' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+4] == 'Q' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-5] == 'Q' && g[i-4] == '.' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+5] == 'Q' && g[i+4] == '.' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }


                if (b[i-2] == 'N' || b[i+2] == 'N' || a[i-1] == 'N' || a[i+1] == 'N') {
                    win = 1;
                    break;
                }
                if (d[i-2] == 'N' || d[i+2] == 'N' || e[i-1] == 'N' || e[i+1] == 'N') {
                    win = 1;
                    break;
                }

                break;
            }
            else if(d[i] == 'k') {
                blackposition = 'd';
                blackpositionnum = i;

                if (e[i-1] == 'P' || e[i+1] == 'P') {
                    win = 1;
                }
                

                for(int j = 0; j<8; j++) {
                    if(d[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (c[i] == 'R' || e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && b[i] == '.' && a[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && b[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'R') {
                    win = 1;
                    break;
                }


                if(c[i-1] == 'B' || c[i+1] == 'B' || e[i-1] == 'B' || e[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(b[i-2] == 'B' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+2] == 'B' && c[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-3] == 'B' && b[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+3] == 'B' && b[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i-2] == 'B' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+2] == 'B' && e[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(g[i-3] == 'B' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+3] == 'B' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-4] == 'B' && g[i-3] == '.' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+4] == 'B' && g[i+3] == '.' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }


                for(int j = 0; j<8; j++) {
                    if(d[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (c[i] == 'Q' || e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && b[i] == '.' && a[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (c[i] == '.' && b[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'Q') {
                    win = 1;
                    break;
                }


                if(c[i-1] == 'Q' || c[i+1] == 'Q' || e[i-1] == 'Q' || e[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(b[i-2] == 'Q' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+2] == 'Q' && c[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-3] == 'Q' && b[i-2] == '.' && c[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+3] == 'Q' && b[i+2] == '.' && c[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(f[i-2] == 'Q' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+2] == 'Q' && e[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(g[i-3] == 'Q' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+3] == 'Q' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-4] == 'Q' && g[i-3] == '.' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+4] == 'Q' && g[i+3] == '.' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }


                if (c[i-2] == 'N' || c[i+2] == 'N' || b[i-1] == 'N' || b[i+1] == 'N') {
                    win = 1;
                    break;
                }
                if (e[i-2] == 'N' || e[i+2] == 'N' || f[i-1] == 'N' || f[i+1] == 'N') {
                    win = 1;
                    break;
                }


                
                break;
            }
            else if(e[i] == 'k') {
                blackposition = 'e';
                blackpositionnum = i;

                if (f[i-1] == 'P' || f[i+1] == 'P') {
                    win = 1;
                }
                

                for(int j = 0; j<8; j++) {
                    if(e[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (f[i] == 'R' || d[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (a[i] == 'R' && b[i] == '.' && c[i] == '.' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (b[i] == 'R' && c[i] == '.' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (c[i] == 'R' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && g[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && g[i] == '.' && h[i] == 'R') {
                    win = 1;
                    break;
                }


                if(f[i-1] == 'B' || f[i+1] == 'B' || d[i-1] == 'B' || d[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(c[i-2] == 'B' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i+2] == 'B' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(b[i-3] == 'B' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+3] == 'B' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-4] == 'B' && b[i-3] == '.' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+4] == 'B' && b[i+3] == '.' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(g[i-2] == 'B' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+2] == 'B' && f[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-3] == 'B' && g[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+3] == 'B' && g[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(e[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (f[i] == 'Q' || d[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (a[i] == 'Q' && b[i] == '.' && c[i] == '.' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (b[i] == 'Q' && c[i] == '.' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (c[i] == 'Q' && d[i] == '.') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && g[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && g[i] == '.' && h[i] == 'Q') {
                    win = 1;
                    break;
                }


                if(f[i-1] == 'Q' || f[i+1] == 'Q' || d[i-1] == 'Q' || d[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(c[i-2] == 'Q' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i+2] == 'Q' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(b[i-3] == 'Q' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+3] == 'Q' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-4] == 'Q' && b[i-3] == '.' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+4] == 'Q' && b[i+3] == '.' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(g[i-2] == 'Q' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(g[i+2] == 'Q' && f[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(h[i-3] == 'Q' && g[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+3] == 'Q' && g[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }

                
                if (d[i-2] == 'N' || d[i+2] == 'N' || c[i-1] == 'N' || c[i+1] == 'N') {
                    win = 1;
                    break;
                }
                if (f[i-2] == 'N' || f[i+2] == 'N' || g[i-1] == 'N' || g[i+1] == 'N') {
                    win = 1;
                    break;
                }
                

                
                break;
            }
            else if(f[i] == 'k') {
                blackposition = 'f';
                blackpositionnum = i;

                if (g[i-1] == 'P' || g[i+1] == 'P') {
                    win = 1;
                }
                

                for(int j = 0; j<8; j++) {
                    if(f[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (g[i] == 'R' || e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && h[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'R') {
                    win = 1;
                    break;

                
                break;
            }


                if(g[i-1] == 'B' || g[i+1] == 'B' || e[i-1] == 'B' || e[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(h[i-2] == 'B' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+2] == 'B' && g[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(d[i-2] == 'B' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+2] == 'B' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(c[i-3] == 'B' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i+3] == 'B' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(b[i-4] == 'B' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+4] == 'B' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-5] == 'B' && b[i-4] == '.' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+5] == 'B' && b[i+4] == '.' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }


                for(int j = 0; j<8; j++) {
                    if(f[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (g[i] == 'Q' || e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && h[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'Q') {
                    win = 1;
                    break;

                
                break;
            }


                if(g[i-1] == 'Q' || g[i+1] == 'Q' || e[i-1] == 'Q' || e[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(h[i-2] == 'Q' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(h[i+2] == 'Q' && g[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(d[i-2] == 'Q' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+2] == 'Q' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(c[i-3] == 'Q' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i+3] == 'Q' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(b[i-4] == 'Q' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i+4] == 'Q' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i-5] == 'Q' && b[i-4] == '.' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i+5] == 'Q' && b[i+4] == '.' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 1;
                    break;
                }


                if (g[i-2] == 'N' || g[i+2] == 'N' || d[i-1] == 'N' || d[i+1] == 'N') {
                    win = 1;
                    break;
                }
                if (e[i-2] == 'N' || e[i+2] == 'N' || h[i-1] == 'N' || h[i+1] == 'N') {
                    win = 1;
                    break;
                }




                break;
            }
            else if(g[i] == 'k') {
                blackposition = 'g';
                blackpositionnum = i;

                if (h[i-1] == 'P' || h[i+1] == 'P') {
                    win = 1;
                }
                

                for(int j = 0; j<8; j++) {
                    if(g[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (f[i] == 'R' || h[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'R') {
                    win = 1;
                    break;
                }
                

                if(h[i-1] == 'B' || h[i+1] == 'B' || f[i-1] == 'B' || f[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(e[i-2] == 'B' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+2] == 'B' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(d[i-3] == 'B' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+3] == 'B' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(c[i+4] == 'B' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i-4] == 'B' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(b[i+5] == 'B' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i-5] == 'B' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(a[i+6] == 'B' && b[i+5] == '.' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i-6] == 'B' && b[i-5] == '.' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(g[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }
                if (f[i] == 'Q' || h[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'Q') {
                    win = 1;
                    break;
                }
                

                if(h[i-1] == 'Q' || h[i+1] == 'Q' || f[i-1] == 'Q' || f[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(e[i-2] == 'Q' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+2] == 'Q' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(d[i-3] == 'Q' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i+3] == 'Q' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(c[i+4] == 'Q' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i-4] == 'Q' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(b[i+5] == 'Q' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i-5] == 'Q' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(a[i+6] == 'Q' && b[i+5] == '.' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i-6] == 'Q' && b[i-5] == '.' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 1;
                    break;
                }
                

                if (h[i-2] == 'N' || h[i+2] == 'N' || e[i-1] == 'N' || e[i+1] == 'N' || f[i-2] == 'N' || f[i+2] == 'N') {
                    win = 1;
                    break;
                }




                break;
            }
            else if(h[i] == 'k') {
                blackposition = 'h';
                blackpositionnum = i;

                for(int j = 0; j<8; j++) {
                    if(h[j] == 'R') {
                        for(int k = j+1; k<8; k++) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }

                if (g[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'R') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'R') {
                    win = 1;
                    break;
                }


                if(g[i-1] == 'B' || g[i+1] == 'B') {
                    win = 1;
                    break;
                }
                
                else if(f[i-2] == 'B' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+2] == 'B' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-3] == 'B' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+3] == 'B' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(d[i+4] == 'B' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i-4] == 'B' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(c[i+5] == 'B' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i-5] == 'B' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(b[i+6] == 'B' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i-6] == 'B' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i+7] == 'B' && b[i+6] == '.' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i-7] == 'B' && b[i-6] == '.' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(h[j] == 'Q') {
                        for(int k = j+1; k<8; k++) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 1;
                        }
                    }
                }

                if (g[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'Q') {
                    win = 1;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'Q') {
                    win = 1;
                    break;
                }


                if(g[i-1] == 'Q' || g[i+1] == 'Q') {
                    win = 1;
                    break;
                }
                
                else if(f[i-2] == 'Q' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(f[i+2] == 'Q' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(e[i-3] == 'Q' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                else if(e[i+3] == 'Q' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(d[i+4] == 'Q' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(d[i-4] == 'Q' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(c[i+5] == 'Q' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(c[i-5] == 'Q' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }
                
                else if(b[i+6] == 'Q' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(b[i-6] == 'Q' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }

                else if(a[i+7] == 'Q' && b[i+6] == '.' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 1;
                    break;
                }
                else if(a[i-7] == 'Q' && b[i-6] == '.' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 1;
                    break;
                }

                
                if (g[i-2] == 'N' || g[i+2] == 'N' || f[i-1] == 'N' || f[i+1] == 'N') {
                    win = 1;
                    break;
                }




                break;
            }
        }
    }



        while(whitepositionnum == 100) {
        for(int i = 0; i<8; i++) {
            if(a[i] == 'K') {
                blackposition = 'a';
                whitepositionnum = i;
                

                // ROOK
                // *SIDE
                for(int j = 0; j<8; j++) {
                    if(a[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (a[k] == '.') {
                                noblock = 0;
                            }
                            else if (a[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (a[k] == '.') {
                                noblock = 0;
                            }
                            else if (a[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                // *STRAIGHT
                if (b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }


                // BISHOP
                if(b[i-1] == 'b' || b[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(c[i-2] == 'b' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+2] == 'b' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(d[i-3] == 'b' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+3] == 'b' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i+4] == 'b' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i-4] == 'b' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i+5] == 'b' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i-5] == 'b' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(g[i+6] == 'b' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i-6] == 'b' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i+7] == 'b' && g[i+6] == '.' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i-7] == 'b' && g[i-6] == '.' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }


                // QUEEN
                for(int j = 0; j<8; j++) {
                    if(a[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (a[k] == '.') {
                                noblock = 0;
                            }
                            else if (a[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (a[k] == '.') {
                                noblock = 0;
                            }
                            else if (a[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }
                else if(b[i-1] == 'q' || b[i+1] == 'q') {
                    win = 0;
                    break;
                }
                else if(c[i-2] == 'q' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+2] == 'q' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i-3] == 'q' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+3] == 'q' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                } 
                else if(e[i+4] == 'q' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i-4] == 'q' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+5] == 'q' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i-5] == 'q' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+6] == 'q' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i-6] == 'q' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+7] == 'q' && g[i+6] == '.' && f[i+5] == '.' && e[i+4] == '.' && d[i+3] == '.' && c[i+2] == '.' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i-7] == 'q' && g[i-6] == '.' && f[i-5] == '.' && e[i-4] == '.' && d[i-3] == '.' && c[i-2] == '.' && b[i-1] == '.') {
                    win = 0;
                    break;
                }


                // HORSE
                if (b[i-2] == 'n' || b[i+2] == 'n' || c[i-1] == 'n' || c[i+1] == 'n') {
                    win = 0;
                    break;
                }

                break;
            }
            else if(b[i] == 'K') {
                blackposition = 'b';
                whitepositionnum = i;

                if (a[i-1] == 'p' || a[i+1] == 'p') {
                    win = 0;
                }
                

                for(int j = 0; j<8; j++) {
                    if(b[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (c[i] == 'r'|| a[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }

                
                if(a[i-1] == 'b' || a[i+1] == 'b' || c[i-1] == 'b' || c[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(d[i-2] == 'b' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+2] == 'b' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-3] == 'b' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+3] == 'b' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i+4] == 'b' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i-4] == 'b' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(g[i+5] == 'b' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i-5] == 'b' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(h[i+6] == 'b' && g[i+5] == '.' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i-6] == 'b' && g[i-5] == '.' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                for(int j = 0; j<8; j++) {
                    if(b[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (b[k] == '.') {
                                noblock = 0;
                            }
                            else if (b[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (c[i] == 'q'|| a[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }

                
                if(a[i-1] == 'q' || a[i+1] == 'q' || c[i-1] == 'q' || c[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(d[i-2] == 'q' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+2] == 'q' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-3] == 'q' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+3] == 'q' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i+4] == 'q' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i-4] == 'q' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(g[i+5] == 'q' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i-5] == 'q' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(h[i+6] == 'q' && g[i+5] == '.' && f[i+4] == '.' && e[i+3] == '.' && d[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i-6] == 'q' && g[i-5] == '.' && f[i-4] == '.' && e[i-3] == '.' && d[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                

                if (c[i-2] == 'n' || c[i+2] == 'n' || d[i-1] == 'n' || d[i+1] == 'n' || a[i-2] == 'n' || a[i+2] == 'n') {
                    win = 0;
                    break;
                }


                break;
            }
            else if(c[i] == 'K') {
                blackposition = 'c';
                whitepositionnum = i;

                if (b[i-1] == 'p' || b[i+1] == 'p') {
                    win = 0;
                }


                for(int j = 0; j<8; j++) {
                    if(c[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }             
                if (d[i] == 'r' || b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && a[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }


                if(b[i-1] == 'b' || b[i+1] == 'b' || d[i-1] == 'b' || d[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(a[i-2] == 'b' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+2] == 'b' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-2] == 'b' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+2] == 'b' && d[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i-3] == 'b' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+3] == 'b' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(g[i-4] == 'b' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+4] == 'b' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-5] == 'b' && g[i-4] == '.' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+5] == 'b' && g[i+4] == '.' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(c[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (c[k] == '.') {
                                noblock = 0;
                            }
                            else if (c[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }             
                if (d[i] == 'q' || b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (b[i] == '.' && a[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (d[i] == '.' && e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }


                if(b[i-1] == 'q' || b[i+1] == 'q' || d[i-1] == 'q' || d[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(a[i-2] == 'q' && b[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+2] == 'q' && b[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-2] == 'q' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+2] == 'q' && d[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i-3] == 'q' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+3] == 'q' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(g[i-4] == 'q' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+4] == 'q' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-5] == 'q' && g[i-4] == '.' && f[i-3] == '.' && e[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+5] == 'q' && g[i+4] == '.' && f[i+3] == '.' && e[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }


                if (b[i-2] == 'n' || b[i+2] == 'n' || a[i-1] == 'n' || a[i+1] == 'n') {
                    win = 0;
                    break;
                }
                if (d[i-2] == 'n' || d[i+2] == 'n' || e[i-1] == 'n' || e[i+1] == 'n') {
                    win = 0;
                    break;
                }

                break;
            }
            else if(d[i] == 'K') {
                blackposition = 'd';
                whitepositionnum = i;

                if (c[i-1] == 'p' || c[i+1] == 'p') {
                    win = 0;
                }
                

                for(int j = 0; j<8; j++) {
                    if(d[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (c[i] == 'r' || e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && b[i] == '.' && a[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }


                if(c[i-1] == 'b' || c[i+1] == 'b' || e[i-1] == 'b' || e[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(b[i-2] == 'b' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+2] == 'b' && c[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-3] == 'b' && b[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+3] == 'b' && b[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i-2] == 'b' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+2] == 'b' && e[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(g[i-3] == 'b' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+3] == 'b' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-4] == 'b' && g[i-3] == '.' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+4] == 'b' && g[i+3] == '.' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }


                for(int j = 0; j<8; j++) {
                    if(d[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (d[k] == '.') {
                                noblock = 0;
                            }
                            else if (d[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (c[i] == 'q' || e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && b[i] == '.' && a[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (c[i] == '.' && b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && f[i] == '.' && g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }


                if(c[i-1] == 'q' || c[i+1] == 'q' || e[i-1] == 'q' || e[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(b[i-2] == 'q' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+2] == 'q' && c[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-3] == 'q' && b[i-2] == '.' && c[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+3] == 'q' && b[i+2] == '.' && c[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(f[i-2] == 'q' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+2] == 'q' && e[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(g[i-3] == 'q' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+3] == 'q' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-4] == 'q' && g[i-3] == '.' && f[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+4] == 'q' && g[i+3] == '.' && f[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }


                if (c[i-2] == 'n' || c[i+2] == 'n' || b[i-1] == 'n' || b[i+1] == 'n') {
                    win = 0;
                    break;
                }
                if (e[i-2] == 'n' || e[i+2] == 'n' || f[i-1] == 'n' || f[i+1] == 'n') {
                    win = 0;
                    break;
                }


                
                break;
            }
            else if(e[i] == 'K') {
                blackposition = 'e';
                whitepositionnum = i;

                if (d[i-1] == 'p' || d[i+1] == 'p') {
                    win = 0;
                }
                

                for(int j = 0; j<8; j++) {
                    if(e[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (f[i] == 'r' || d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (a[i] == 'r' && b[i] == '.' && c[i] == '.' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (b[i] == 'r' && c[i] == '.' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (c[i] == 'r' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }


                if(f[i-1] == 'b' || f[i+1] == 'b' || d[i-1] == 'b' || d[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(c[i-2] == 'b' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+2] == 'b' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(b[i-3] == 'b' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+3] == 'b' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-4] == 'b' && b[i-3] == '.' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+4] == 'b' && b[i+3] == '.' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(g[i-2] == 'b' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+2] == 'b' && f[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-3] == 'b' && g[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+3] == 'b' && g[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(e[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (e[k] == '.') {
                                noblock = 0;
                            }
                            else if (e[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (f[i] == 'q' || d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (a[i] == 'q' && b[i] == '.' && c[i] == '.' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (b[i] == 'q' && c[i] == '.' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (c[i] == 'q' && d[i] == '.') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }


                if(f[i-1] == 'q' || f[i+1] == 'q' || d[i-1] == 'q' || d[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(c[i-2] == 'q' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+2] == 'q' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(b[i-3] == 'q' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+3] == 'q' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-4] == 'q' && b[i-3] == '.' && c[i-2] == '.' && d[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+4] == 'q' && b[i+3] == '.' && c[i+2] == '.' && d[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(g[i-2] == 'q' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(g[i+2] == 'q' && f[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(h[i-3] == 'q' && g[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+3] == 'q' && g[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }

                
                if (d[i-2] == 'n' || d[i+2] == 'n' || c[i-1] == 'n' || c[i+1] == 'n') {
                    win = 0;
                    break;
                }
                if (f[i-2] == 'n' || f[i+2] == 'n' || g[i-1] == 'n' || g[i+1] == 'n') {
                    win = 0;
                    break;
                }
                

                
                break;
            }
            else if(f[i] == 'K') {
                blackposition = 'f';
                whitepositionnum = i;

                if (e[i-1] == 'p' || e[i+1] == 'p') {
                    win = 0;
                }
                

                for(int j = 0; j<8; j++) {
                    if(f[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (g[i] == 'r' || e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && h[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'r') {
                    win = 0;
                    break;

                
                break;
            }


                if(g[i-1] == 'b' || g[i+1] == 'b' || e[i-1] == 'b' || e[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(h[i-2] == 'b' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+2] == 'b' && g[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(d[i-2] == 'b' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+2] == 'b' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(c[i-3] == 'b' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+3] == 'b' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(b[i-4] == 'b' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+4] == 'b' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-5] == 'b' && b[i-4] == '.' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+5] == 'b' && b[i+4] == '.' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }


                for(int j = 0; j<8; j++) {
                    if(f[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (f[k] == '.') {
                                noblock = 0;
                            }
                            else if (f[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (g[i] == 'q' || e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && h[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'q') {
                    win = 0;
                    break;

                
                break;
            }


                if(g[i-1] == 'q' || g[i+1] == 'q' || e[i-1] == 'q' || e[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(h[i-2] == 'q' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(h[i+2] == 'q' && g[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(d[i-2] == 'q' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+2] == 'q' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(c[i-3] == 'q' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i+3] == 'q' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(b[i-4] == 'q' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i+4] == 'q' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i-5] == 'q' && b[i-4] == '.' && c[i-3] == '.' && d[i-2] == '.' && e[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i+5] == 'q' && b[i+4] == '.' && c[i+3] == '.' && d[i+2] == '.' && e[i+1] == '.') {
                    win = 0;
                    break;
                }


                if (g[i-2] == 'n' || g[i+2] == 'n' || d[i-1] == 'n' || d[i+1] == 'n') {
                    win = 0;
                    break;
                }
                if (e[i-2] == 'n' || e[i+2] == 'n' || h[i-1] == 'n' || h[i+1] == 'n') {
                    win = 0;
                    break;
                }




                break;
            }
            else if(g[i] == 'K') {
                blackposition = 'g';
                whitepositionnum = i;

                if (f[i-1] == 'p' || f[i+1] == 'p') {
                    win = 0;
                }
                

                for(int j = 0; j<8; j++) {
                    if(g[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (f[i] == 'r' || h[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'r') {
                    win = 0;
                    break;
                }
                

                if(h[i-1] == 'b' || h[i+1] == 'b' || f[i-1] == 'b' || f[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(e[i-2] == 'b' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+2] == 'b' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(d[i-3] == 'b' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+3] == 'b' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(c[i+4] == 'b' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i-4] == 'b' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(b[i+5] == 'b' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i-5] == 'b' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(a[i+6] == 'b' && b[i+5] == '.' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i-6] == 'b' && b[i-5] == '.' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(g[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (g[k] == '.') {
                                noblock = 0;
                            }
                            else if (g[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }
                if (f[i] == 'q' || h[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'q') {
                    win = 0;
                    break;
                }
                

                if(h[i-1] == 'q' || h[i+1] == 'q' || f[i-1] == 'q' || f[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(e[i-2] == 'q' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+2] == 'q' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(d[i-3] == 'q' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i+3] == 'q' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(c[i+4] == 'q' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i-4] == 'q' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(b[i+5] == 'q' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i-5] == 'q' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(a[i+6] == 'q' && b[i+5] == '.' && c[i+4] == '.' && d[i+3] == '.' && e[i+2] == '.' && f[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i-6] == 'q' && b[i-5] == '.' && c[i-4] == '.' && d[i-3] == '.' && e[i-2] == '.' && f[i-1] == '.') {
                    win = 0;
                    break;
                }
                

                if (h[i-2] == 'n' || h[i+2] == 'n' || e[i-1] == 'n' || e[i+1] == 'n' || f[i-2] == 'n' || f[i+2] == 'n') {
                    win = 0;
                    break;
                }




                break;
            }
            else if(h[i] == 'K') {
                blackposition = 'h';
                whitepositionnum = i;

                if (g[i-1] == 'p' || g[i+1] == 'p') {
                    win = 0;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(h[j] == 'r') {
                        for(int k = j+1; k<8; k++) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }

                if (g[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'r') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'r') {
                    win = 0;
                    break;
                }


                if(g[i-1] == 'b' || g[i+1] == 'b') {
                    win = 0;
                    break;
                }
                
                else if(f[i-2] == 'b' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+2] == 'b' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-3] == 'b' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+3] == 'b' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(d[i+4] == 'b' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i-4] == 'b' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(c[i+5] == 'b' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i-5] == 'b' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(b[i+6] == 'b' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i-6] == 'b' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i+7] == 'b' && b[i+6] == '.' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i-7] == 'b' && b[i-6] == '.' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }

                for(int j = 0; j<8; j++) {
                    if(h[j] == 'q') {
                        for(int k = j+1; k<8; k++) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        for(int k = j-1; k>0; k--) {
                            if (h[k] == '.') {
                                noblock = 0;
                            }
                            else if (h[k] != '.') {
                                noblock = 1;
                            }
                        }
                        if (noblock == 0) {
                            win = 0;
                        }
                    }
                }

                if (g[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == 'q') {
                    win = 0;
                    break;
                }
                else if (g[i] == '.' && f[i] == '.' && e[i] == '.' && d[i] == '.' && c[i] == '.' && b[i] == '.' && a[i] == 'q') {
                    win = 0;
                    break;
                }


                if(g[i-1] == 'q' || g[i+1] == 'q') {
                    win = 0;
                    break;
                }
                
                else if(f[i-2] == 'q' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(f[i+2] == 'q' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(e[i-3] == 'q' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                else if(e[i+3] == 'q' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(d[i+4] == 'q' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(d[i-4] == 'q' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(c[i+5] == 'q' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(c[i-5] == 'q' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }
                
                else if(b[i+6] == 'q' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(b[i-6] == 'q' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }

                else if(a[i+7] == 'q' && b[i+6] == '.' && c[i+5] == '.' && d[i+4] == '.' && e[i+3] == '.' && f[i+2] == '.' && g[i+1] == '.') {
                    win = 0;
                    break;
                }
                else if(a[i-7] == 'q' && b[i-6] == '.' && c[i-5] == '.' && d[i-4] == '.' && e[i-3] == '.' && f[i-2] == '.' && g[i-1] == '.') {
                    win = 0;
                    break;
                }

                
                if (g[i-2] == 'n' || g[i+2] == 'n' || f[i-1] == 'n' || f[i+1] == 'n') {
                    win = 0;
                    break;
                }




                break;
            }
        }
    }

        if (win == 0) {
            res[game] = 0;
        }
        else if (win == 1) {
            res[game] = 1;
        }
        else if (win == 3) {
            res[game] = 3;
        }

    }

    for(int i = 1; i<game; i++) {
      if (res[i] == 0 ) {
           printf("Jogo #%d: rei branco esta em cheque.\n", i);
        }
        else if (res[i] == 1 ) {
            printf("Jogo #%d: rei preto esta em cheque.\n", i);
        }
        else if (res[i] == 3 ) {
            printf("Jogo #%d: nenhum rei esta em cheque.\n", i);
        }
    }
  return 0;
}