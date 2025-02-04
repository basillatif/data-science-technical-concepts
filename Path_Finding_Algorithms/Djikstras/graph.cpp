#include <iostream>
#include "graph.h"

using namespace std;

Graph Graph::constrHelper(int numV, int numE) //this creates my graph which has an array of vertices and edges
{
	struct Graph tempG(numV, numE);
	this->array = tempG.array;
	this->V = tempG.V;
	this->E = tempG.E;
	return tempG;
}

Graph::Graph(int numV, int numE) //this dynamically creates the graph
{
	V = numV;
	E = numE;
	array = new listVertex[numV * sizeof(listVertex)];

	for (int i = 1; i <= numV; i++)
	{
		array[i].vertex = i;
		array[i].dist = NULL;
		array[i].next = NULL;
	}
}

void Graph::buildAdjList(int u, int v, int w) //this builds my adjacency list 
{
	listVertex *newVertex = new listVertex;
	newVertex->vertex = v;
	newVertex->next = NULL;
	newVertex->dist = w;

	if (array[u].next == NULL)
		array[u].next = newVertex;
	else
	{
		listVertex *t = array[u].next;
		newVertex->next = t;
		array[u].next = newVertex;
	}
}

void Graph::printGraph() //this prints the graph
{
	if (V == NULL)
	{
		cout << "Empty.\n";
	}
	else
	{
		cout << V << " " << E << "\n";
		for (int i = 1; i <= V; i++)
		{
			listVertex *scanner = array + i;
			cout << i << " : ";
			bool done = false;
			if (scanner->next != NULL)
			{
				while (done != true)
				{
					if (scanner->next == NULL)
					{
						done = true;
					}
					if (scanner->dist != NULL)
					{
						cout << "(" << scanner->vertex << " " << scanner->dist << ")";
						scanner = scanner->next;
					}
					else
						scanner = scanner->next;
				}
			}
			cout << "\n";
		}
	}
}