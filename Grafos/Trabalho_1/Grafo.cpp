/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

/* Complete aqui */

#include "Grafo.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;

    adj_list_.resize(num_vertices);
}

void Grafo::insere_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);

    if (e.v1 == e.v2) {
        return;
    }

    if (!tem_aresta(e)) {
        adj_list_[e.v1].push_back(e.v2);
        adj_list_[e.v2].push_back(e.v1);

        num_arestas_ ++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (tem_aresta(e)) {
        adj_list_[e.v1].remove(e.v2);
        adj_list_[e.v2].remove(e.v1);

        num_arestas_ --;
    }
}

void Grafo::valida_vertice(int v) {
    if (v < 0 || v >= num_vertices_) {
        throw(invalid_argument("Erro o numero de"
            "vertices " + to_string(v) + " eh invalido!"));
    }
}

bool Grafo::tem_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);

    auto it = std::find(adj_list_[e.v1].begin(), adj_list_[e.v1].end(), e.v2);
    if (it != adj_list_[e.v1].end()) {
        return true; 
    }
    return false;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::eh_clique(const std::vector<int>& vertices) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        valida_vertice(vertices[i]);

        for (size_t j = i + 1; j < vertices.size(); ++j) {
            valida_vertice(vertices[j]);

            if (find(adj_list_[vertices[i]].begin(), adj_list_[vertices[i]].end(), vertices[j]) == adj_list_[vertices[i]].end()) {
                return false;
            }
        }
    }
    return true;
}

bool Grafo::existe_caminho_restrito(int v1, int v2, Aresta aresta_proibida) {
    valida_vertice(v1);
    valida_vertice(v2);

    vector<int> visitado(num_vertices_, 0);
    return dfs_existe_caminho(v1, v2, visitado, aresta_proibida);
}

bool Grafo::dfs_existe_caminho(int v1, int v2, vector<int>& visitado, Aresta aresta_proibida) {
    if (v1 == v2) {
        return true;
    }

    visitado[v1] = 1;
    for (int vizinho : adj_list_[v1]) {
        if ((v1 == aresta_proibida.v1 && vizinho == aresta_proibida.v2) || (v1 == aresta_proibida.v2 && vizinho == aresta_proibida.v1)) {
            continue;
        }

        if (visitado[vizinho] == 0) { 
            if (dfs_existe_caminho(vizinho, v2, visitado, aresta_proibida)) {
                return true;
            }
        }
    }

    return false;
}

void Grafo::imprime_graus() const {
    for (int i = 0; i < num_vertices_; i++) {
        std::cout << i << ": " << adj_list_[i].size() << "\n";
    }
}


