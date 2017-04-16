#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkstate.h"

void hello(int grafo[V][V], Packet* pacotes){
  int i,j;

  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      if(grafo[i][j] != 0){
        if(grafo[i][j] == grafo[j][i]){
          printf("Enlace entre %d e %d está correto!\n", i,j);
        }
        else{
          printf("Enlace entre %d e %d está incorreto!\n", i,j);  
        }
      }
    }
  }
}

void lsa(int grafo[V][V], Packet* pacotes){
  int i,j;

  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      if(grafo[i][j] != 0){
          pacotes[i].no = i;
          pacotes[i].topologia[i][j] = grafo[i][j];
          //printf("No: %d, Vizinho: %d, Custo: %d\n", i, j, pacotes[i].topologia[i][j]);
      }
    }
  }

  imprime(pacotes[0].topologia);
}

void imprime(int grafo[V][V]){
  int i, j;
  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      printf("%d, ", grafo[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void initPacotes(Packet* pacotes){
  int i, j, k;
  for(k = 0; k < V; k++){
    for(i=0;i<V;i++){
      for(j=0;j<V;j++){
        pacotes[k].topologia[i][j] = -1;
        if(i == j)
          pacotes[k].topologia[i][j] = 0;
      }
    }
  }
}