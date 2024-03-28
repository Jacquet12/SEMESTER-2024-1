#include "Grafo.h"
#include "Aresta.h"
#include <iostream>

using namespace std;

int main() {
    try {
        Grafo g(4);
        g.imprime();
        Aresta e (0, 1);
        g.insert_aresta(e);
        g.insert_aresta(Aresta (0, 2));
        g.insert_aresta(Aresta (0, 2));
        g.remove_aresta(Aresta (0, 1));

        cout << "\n";
        g.imprime();

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
