#ifndef _Graph_H_
#define _Graph_H_

class Graph
{
public:
	struct listVertex
	{
		int vertex;
		int dist;
		listVertex *next;
	};

	listVertex *array;
	int V; // number of vertices
	int E; // number of edges

	Graph(int numV, int numE);
	Graph constrHelper(int numV, int numE);
	void buildAdjList(int u, int v, int w);
	void printGraph();
};















#endif