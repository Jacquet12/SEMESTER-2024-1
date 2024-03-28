#ifndef GRAFO_H

#define GRAFO_H

#include <vector>
#include "Aresta.h"
#include <list>

class Grafo {
public:
    Grafo(int num_vertices);
    
    int num_vertices();
    int num_arestas();

    bool tem_aresta(Aresta e);
    void insert_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
private:
    std::vector<std::list<int>> listas_adj_;
    int num_vertices_;
    int num_arestas_;
};

#endif /* GRAFO_H */
