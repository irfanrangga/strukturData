#include "graph.h"

int main()
{
    graph G;
    buildGraph_103022300100(G);

    adrVertex v = firstVertex(G);
    cout << "Hasil Graf: " << endl;
    while(v != NULL){
        cout << idVertex(v) << " ->" << endl;
        v = nextVertex(v);
    }
    cout << endl;

    return 0;
}
