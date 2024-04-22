#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o raio " +
            to_string(num_vertices) + " eh invalido!"));
    }

    listas_adj_.resize(num_vertices);
    
    num_vertices_ = num_vertices;
    num_arestas_ = 0;
}


void Grafo::busca_prof(int v, int marcado[]) {
    printf("%d\n", v);
    marcado[v] = 1;
    for (int u = 0; u < num_vertices_; u++)
        if (matriz_adj_[v][u] != 0)
            if (marcado[u] == 0)
                busca_prof(u, marcado);
}
