/**
 * @file lib_aux.c
 * @author Miguel Areal (a29559@alunos.ipca.pt)
 * @brief Código-Fonte da biblioteca com implementações de funções auxiliares
 * @date 04-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#include "lib_aux.h"

// Criar e inicializar um novo vértice
Vertice* criar_vertice(int valor) {
    Vertice *v = (Vertice*)malloc(sizeof(Vertice));
    v->valor = valor;
    v->arestas = NULL;
    v->num_arestas = 0;
    return v;
}

// Adiciona um novo caminho à estrutura de Caminhos.
int adicionar_caminho(Caminho **lista, int *caminho, int tamanho) {
    Caminho *novo_caminho = (Caminho*)malloc(sizeof(Caminho));
    novo_caminho->vertices = (int*)malloc(tamanho * sizeof(int));
    memcpy(novo_caminho->vertices, caminho, tamanho * sizeof(int));
    novo_caminho->tamanho = tamanho;
    novo_caminho->proximo = *lista;
    *lista = novo_caminho;
    return 0;
}

// Limpar a lista de caminhos
int limpar_caminhos(Caminho *lista) {
    while (lista != NULL) {
        Caminho *temp = lista;
        lista = lista->proximo;
        free(temp->vertices);
        free(temp);
    }
    return 0;
}

// Função para imprimir o grafo na consola
void print_grafo(GR *grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        Vertice v = grafo->vertices[i];
        printf("V%d: ", v.valor + 1); // Vértices numerados de 1 a n (em vez de 0 a n)

        // Imprime informações sobre as arestas conectadas ao vértice
        for (Aresta *a = v.arestas; a != NULL; a = a->proxima) {
            printf("-> V%d (Peso %d) ", a->destino->valor + 1, a->peso); // Vértices numerados de 1 a n
        }
        printf("\n");
    }
}

// Função para libertar a memória alocada
int liberta_grafo(GR *grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        // Liberta a memória alocada para cada aresta
        Aresta *atual = grafo->vertices[i].arestas;
        while (atual != NULL) {
            Aresta *proximo = atual->proxima;
            free(atual);
            atual = proximo;
        }
    }
    // Libera a memória alocada para o array de vértices e, finalmente, para o próprio grafo
    free(grafo->vertices);
    free(grafo);
    return 0;
}