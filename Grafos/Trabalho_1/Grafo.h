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
#include <list>

class Grafo {
    public:
        Grafo(int num_vertices);
        // ~Grafo(); // Se necessario
        int num_arestas();
        void insere_aresta(Aresta e);
        void remove_aresta(Aresta e);
        bool eh_clique(const std::vector<int>& vertices);
        bool existe_caminho_restrito(int v1, int v2, Aresta aresta_proibida);
        bool dfs_existe_caminho(int v1, int v2, std::vector<int>& visitado, Aresta aresta_proibida);
        void imprime_graus() const;
        bool tem_aresta(Aresta e);
    private:
        int num_vertices_;
        int num_arestas_;
        std::vector<std::list<int>> adj_list_;
        
        void valida_vertice(int v);
        void valida_aresta(Aresta e);
    };

#endif /* GRAFO_H */