#include<iostream>
#include<fstream>
#include<cstdlib>
#include"graph.h"
using namespace std;

int main()
{
	bool running = true;
	int n; //number of vertices
	int m; //number of edges
	int u, v, w;
	Graph mainGraph = Graph(NULL,NULL); //initializing the graph

	ifstream myFile;
	while (running)
	{
		cout << "Please enter your command \n";
		char input;
		cin >> input;
		switch (input) {
		case 'S':
			running = false;
			break;
		case 'R':
			myFile.open("GRAPHinput.txt");
			myFile >> n;
			myFile >> m;
			mainGraph.constrHelper(n, m);
			int i;
			for (i = 1; i <= m; i++) //this for loop assigns u, v, and w to the adjcacency list node
			{
				myFile >> u;
				myFile >> v;
				myFile >> w;
				mainGraph.buildAdjList(u, v, w);
			}
			break;
		case 'W':
			mainGraph.printGraph();
		default:
			"Error. Invalid Input.\n";
		}
	}
}