#include "graph.h"

void createVertex_103022300100(char newVertexID, adrVertex &v)
{
    v = new vertex;
    idVertex(v) = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph_103022300100(graph &G)
{
    firstVertex(G) = NULL;
}

void addVertex_103022300100(graph &G, char newVertexID)
{
    adrVertex v;
    createVertex_103022300100(newVertexID, v);

    if(firstVertex(G) == NULL){
        firstVertex(G) = v;
    } else {
        adrVertex q = firstVertex(G);
        while(nextVertex(q) != NULL) {
            q = nextVertex(q);
        }
        nextVertex(q) = v;
    }
}

void buildGraph_103022300100(graph &G)
{
    char insertVertex;
    initGraph_103022300100(G);

    cin >> insertVertex;
    while(insertVertex >= 'A' && insertVertex <= 'Z'){
        addVertex_103022300100(G, insertVertex);
        cin >> insertVertex;
    }
}
