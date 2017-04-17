#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkstate.h"

void hello(int grafo[V][V], Packet* pacotes){
  int i,j;
  int aux;

  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      if(grafo[i][j] != 0){
        if(grafo[i][j] == grafo[j][i]){
          //printf("Enlace entre %d e %d está correto!\n", i,j);
          pacotes[i].no = i;
          pacotes[i].topologia[i][j] = grafo[i][j];
        }
        else{
          //printf("Enlace entre %d e %d está incorreto!\n", i,j);  
        }          
      }else{
        pacotes[i].topologia[i][j] = INF;
      }
    }
  }
}

/*void recursive(Packet* pacotes, int i, int inicial){
  int j, k;
  int flag = 0;
  for(j = 0; j < V; j++){
    for(k = 0; k < V; k++){
      if(pacotes[inicial].topologia[j][k] == -1){
        flag = -1;
        break;
      }
    }
  }
  if(flag == 0)
    return;
  for(j = 0; j < V; j+=){
    if(pacotes[i].topologia[i][j] > 0){
      for(k = 0; k < V; k++){
        if(pacotes[j].topologia[j][k] != -1)
          pacotes[inicial].topologia[j][k] = pacotes[j].topologia[j][k];
        else
          pacotes[inicial].topologia[j][k] = INF;
      }
    }
  }
  for(j = 0; j < V; j+=){
    recursive(pacotes, j, inicial);
  }
}*/


void lsa(Packet* pacotes){
  int i,j, k;
  for(i=0;i<V;i++){
    for(j=0;j<V;j++){
      if(pacotes[i].topologia[i][j] > 0){
        for(k = 0; k < V; k++){
          if(pacotes[j].topologia[j][k] != -1)
            pacotes[i].topologia[j][k] = pacotes[j].topologia[j][k];
        }
      }
    }
  }
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