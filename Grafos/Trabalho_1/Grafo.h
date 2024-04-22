/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <vector>

class Grafo {
    public:
        Grafo(int num_vertices);
        // ~Grafo(); // Se necessario
        int num_arestas();
        void insere_aresta(Aresta e);
        void remove_aresta(Aresta e);
        void eh_clique();
        void existe_caminho_restrito();
        void imprime_graus();
    private:
        int num_vertices_;
        int num_arestas_;
        std::vector<std::vector<int>> matriz_adj_;

        void valida_vertice(int v);
        void valida_aresta(Aresta e);
    };

#endif /* GRAFO_H */