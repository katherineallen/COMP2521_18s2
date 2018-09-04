// Graph.h definitions
 
// vertices denoted by integers 0..N-1 
typedef struct graphRep * Graph;
typedef int Vertex; 
typedef struct edge Edge;
 
// edges are pairs of vertices (end-points) 
struct edge { Vertex v; Vertex w; };
typedef struct edge Edge;

///// Array of edges representation
 
struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges 
    Edge *edges;  // array of Edges
}; 
typedef struct graphRep * Graph;

Edge *edges (Graph g, int *nE) {
    *nE = g->nE;
    return g->edges;
}


///// Adjacency matrix graph representation
 
struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges 
    int **edges;  // matrix of booleans (0 or 1)
}; 
typedef struct graphRep * Graph;

Edge *edges(Graph g, int *nE) { 
    
}
 
///// Adjacency list graph representation
 
struct graphRep { 
    int nV;       // #vertices 
    int nE;       // #edges
    List *edges;  // array of Vertex lists 
};
typedef struct graphRep * Graph;

int nE;
Edge * edges = edges(g, &nE);

Edge *edges(Graph g, int *nE) { 
   int i = 0;
   Edge* edges = malloc((sizeof(Edge))*g->nE);
   int upTo = 0;
   for (i=0; i < g->nV; i++) {
       List curr;
       for (curr = edges[i]; curr != NULL; curr = curr->next) {
           if (curr->value >= i) {
                edges[upTo].v = curr->value;
                edges[upTo].w = i;
                upTo ++;
           }
       }
   }
   *nE = g->nE;
   return edges;
}