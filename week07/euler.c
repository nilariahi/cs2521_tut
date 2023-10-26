#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int nE; // 10
	int nV;
	bool **edges; // 1 --/--> 0
} *Graph;

struct edge {
	int v;
	int w;
};

// returns true if the given edges form an eutler path in graph g
// otherwise returns false
// O(E^2)
bool isEulerPath(Graph g, struct edge e[], int nE) {
	// 1) every edge is included exactly once
	if (nE != g->nE) return false;
	for (int i = 0; i < nE; i++) { // O(E)
		for (int j = i + 1; j < nE; j++) { // ~O(E)
			if (e[i].v == e[j].v && e[i].w == e[j].w) return false;
			if (e[i].v == e[j].w && e[i].w == e[j].v) return false;
		}
	}

	// 2) every edge in e has to appear in g
	for (int i = 0; i < nE; i++) {
		struct edge edge = e[i];
		if (!g->edges[edge.v][edge.w]) return false;
	}

	// 3) do all edges in e form a valid path in g
	for (int i = 0; i < nE - 1; i++) {
		if (e[i].w != e[i + 1].v) return false;
	}

	return true;
}

// empty main function just to test compilation
int main(void) {}
