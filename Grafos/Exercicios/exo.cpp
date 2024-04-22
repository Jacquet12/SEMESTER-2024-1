// Exercicios;

// Como determinar se um grafo é conexo ?

bool EH_conexo() {
    vetor<int> marcado (num_vertices);

    for (int i = 0; i < num_vertices_; i++) {
        for (int j = 0; j < num_vertices_; j++) {
            if (!caminho(i,j, marcado))
            return false;
        }
    }
    return true;
}