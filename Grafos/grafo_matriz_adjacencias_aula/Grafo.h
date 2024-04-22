#ifndef GRAFO_H

#define GRAFO_H

#include <vector>
#include "Aresta.h"
#include <list>

class Grafo {
public:
    Grafo(int num_vertices);
    void percorre(int v);
    void busca_prof(int v, int marcado[]);
private:
    std::vector<std::list<int>> listas_adj_;
    int num_vertices_;
    int num_arestas_;
};

#endif /* GRAFO_H */
