#ifndef LINKSTATE_H
#define LINKSTATE_H

// Numero de vértices do gráfico
#define V 14

typedef struct packet{
	int no;
	int topologia[V][V];
	int sequencia;
	int idade;
}Packet;

void hello(int grafo[V][V], Packet* pacotes);

void lsa(int grafo[V][V], Packet* pacotes);

void imprime(int grafo[V][V]);

void initPacotes(Packet* pacotes);
#endif