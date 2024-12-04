#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#define firstVertex(G) G.firstVertex
#define idVertex(v) v->idVertex
#define firstEdge(v) v->firstEdge
#define nextEdge(v) v->nextEdge
#define nextVertex(v) v->nextVertex
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex
{
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge
{
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph
{
    adrVertex firstVertex;
};

void createVertex_103022300100(char newVertexID, adrVertex &v);
void initGraph_103022300100(graph &G);
void addVertex_103022300100(graph &G, char newVertexID);
void buildGraph_103022300100(graph &G);
#endif // GRAPH_H_INCLUDED
