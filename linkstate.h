#ifndef LINKSTATE_H
#define LINKSTATE_H

// Numero de vértices do gráfico
#define V 14
#define INF 90000000

typedef struct packet{
	int no;
	int topologia[V][V];
	int sequencia;
	int idade;
}Packet;

void hello(int grafo[V][V], Packet* pacotes);

void lsa(Packet* pacotes);

void imprime(int grafo[V][V]);

void initPacotes(Packet* pacotes);

void dijkstra(int grafo[V][V],int origem, int destino, int anterior[V], int distancia[V]);

#endif