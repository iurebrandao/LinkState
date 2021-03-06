#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkstate.h"

/*
TRABALHO IMPLEMENTAÇÃO DO LINK STATE PROTOCOL 

integrantes:

Felipe Lira Fernandes dos Santos - 14/0019821

Iure Vieira Brandao - 14/0083197

Yuri Castro do Amaral - 14/0033718

*/


// No 1 : Seattle,WA
// No 2 : Palo alto, CA
// No 3 : San Diego, CA
// No 4 : Salt Lk City, UT
// No 5 : Boulder, CO
// No 6 : Houston, TX
// No 7 : Lincoln, NE
// No 8 : Champaign, IL
// No 9 : Pittsbturgh, PA
// No 10 : Atlanta, GA
// No 11 : Anyny arbour, MI
// No 12 : Ithaca, MY
// No 13 : Princeton, NJ
// No 14 : College PK, MD


int main(){
    Packet pacotes[V];
    
    initPacotes(pacotes);

    int i,j,k,  anterior[V], distancia[V];
    
    int grafo[V][V] = {/*No 1 |2 3 8*/ {0, 1050, 1500, 0, 0, 0, 0, 2400, 0,  0 , 0 , 0 , 0, 0},
                      /* No 2 | 1 3 4*/ {1050,0,600,750,0,0,0,0,0,0,0,0,0,0},
                      /* No 3 | 1 2 6*/ {1500, 600, 0, 0, 0, 1800, 0, 0, 0,0,0,0,0},
                      /* No 4 | 2 5 11*/ {0, 750, 0, 0, 600, 0, 0, 0, 0,0,1950,0,0,0},
                      /* No 5 | 4 6 7*/ {0,0,0,600,0,1200,600,0,0,0,0,0,0,0},
                       /*No 6| 3 5 10 14*/ {0, 0, 1800, 0, 1200, 0, 0, 0, 0,1050, 0,0,0,1800},
                      /* No 7| 5 8 10*/ {0, 0, 0, 0, 600, 0, 0, 750, 0,1350,0,0,0,0},
                      /* No 8 | 1 7 9*/ {2400, 0, 0, 0, 0, 0, 750, 0, 750,0,0,0,0,0},
                      /* No 9 | 8 10 12 13*/ {0, 0, 0, 0, 0, 0, 0, 750, 0,750,0,300,300,0},
                      /* No 10| 6 7 9*/ {0, 0, 0, 0, 0, 1050, 1350, 0, 750,0,0,0,0,0},
                      /* No 11| 4 12 13*/ {0, 0, 0, 1950, 0, 0, 0, 0, 0,0,0,600,750,0},
                      /* No 12| 9 11 14*/ {0, 0, 0, 0, 0, 0, 0, 0, 300,0,600,0,0,300},
                        /*No 13| 9 11 14*/ {0, 0, 0, 0, 0, 0, 0, 0, 300,0,750,0,0,150},
                        /*No 14|  6 12 13*/ {0, 0, 0, 0, 0, 1800, 0, 0, 0,0,0,300,150,0},
    };

    hello(grafo, pacotes);
    for(i = 0; i < V; i++){
      printf("\n********** Imprimindo Pacote/Tabela %d antes do flooding **********\n", i + 1);
      imprime(pacotes[i].topologia);
      
    }
    lsa(pacotes);
    for(i = 0; i < V; i++){
      printf("\n********** Imprimindo Pacote/Tabela %d após o flooding **********\n", i + 1);
      imprime(pacotes[i].topologia);
      printf("Vetor distancia do nó %d:\n",i+1 );
      for ( j = 0; j < V; j++){
      	dijkstra(pacotes[i].topologia , i, j, anterior, distancia);
      	printf("Para o nó %d: ",j+1);
      	printf("%d\n",distancia[j]);
      }
    }

    return 0;
}
