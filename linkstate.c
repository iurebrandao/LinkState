#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkstate.h"

void hello(int grafo[V][V]){

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
