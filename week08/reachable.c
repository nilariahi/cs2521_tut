// Warning: this file will not compile
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

typedef int Vertex;

typedef struct {
	int nV;
	bool **edges;
} *Graph;

void doDFS(Graph g, Vertex v, Set s);

// returns a set containing all of the vertices that can be reached
// by following a path from the starting point
Set reachable(Graph g, Vertex src) {
	Set s = SetNew();
	doDFS(g, src, s);
	return s;
}

// performs DFS from Vertex v, adding reachable vertices to Set s
void doDFS(Graph g, Vertex v, Set s) {
	SetAdd(s, v);

	// find adjacent vertices and do dfs on them
	for (int w = 0; w < g->nV; w++) {
		if (g->edges[v][w] && !SetContains(s, w)) {
			doDFS(g, w, s);
		}
	}
}












