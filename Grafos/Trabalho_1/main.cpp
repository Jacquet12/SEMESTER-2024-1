/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2024/1
 *
 * Nome:      XXXX
 * Matricula: XXXX
 */

#include <iostream>
#include <vector>
#include "Grafo.h"

int main() {
    int V, O;
    std::cin >> V >> O;

    Grafo grafo(V);

    for (int i = 0; i < O; i++) {
        char comando;
        std::cin >> comando;

        if (comando == 'I') {
            int X, Y;
            std::cin >> X >> Y;
            Aresta aresta(X, Y);
            grafo.insere_aresta(aresta);
        } else if (comando == 'R') {
            int X, Y;
            std::cin >> X >> Y;
            Aresta aresta(X, Y);
            grafo.remove_aresta(aresta);
        } else if (comando == 'E') {
            std::cout << grafo.num_arestas() << "\n";
        } else if (comando == 'Q') {
            int N;
            std::cin >> N;
            std::vector<int> vertices(N);
            for (int j = 0; j < N; j++) {
                std::cin >> vertices[j];
            }
            if (grafo.eh_clique(vertices)) {
                std::cout << "SIM\n";
            } else {
                std::cout << "NAO\n";
            }
        } else if (comando == 'C') {
            int X, Y, W, Z;
            std::cin >> X >> Y >> W >> Z;
            Aresta aresta_proibida(W, Z);
            if (grafo.existe_caminho_restrito(X, Y, aresta_proibida)) {
                std::cout << "SIM\n";
            } else {
                std::cout << "NAO\n";
            }
        } else if (comando == 'G') {
            grafo.imprime_graus();
        }
    }

    return 0;
}
