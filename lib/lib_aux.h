/**
 * @file lib_aux.h
 * @author Miguel Areal (a29559@alunos.ipca.pt)
 * @brief Ficheiro Header auxiliar da biblioteca 'lib'
 * @date 04-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef LIB_AUX_H
#define LIB_AUX_H

#include "lib.h"

// Declaração das funções

/**
 * @brief Cria e inicializa um novo vértice com o valor especificado.
 *
 * Esta função aloca memória para um novo vértice, define o seu valor e inicializa as suas arestas como NULL e o número de arestas como 0.
 *
 * @param value O valor a ser atribuído ao vértice.
 * @return Um ponteiro para o novo vértice criado, ou NULL se a alocação de memória falhar.
 */
Vertice* criar_vertice(int valor);

/**
 * @brief Adiciona um novo caminho à estrutura de Caminhos.
 * 
 * Esta função cria um novo nó de caminho, copia os vértices do caminho fornecido para o novo nó,
 * e então adiciona este nó à lista ligada de caminhos. A lista de caminhos é atualizada para
 * incluir o novo caminho no início da lista.
 *
 * @param lista Ponteiro para o ponteiro da lista de caminhos. É usado para atualizar a lista com o novo caminho.
 * @param caminho Array de inteiros representando a sequência de vértices no novo caminho.
 * @param tamanho O número de vértices no array do caminho.
 * @return int 0: Sucesso.
 */

int adicionar_caminho(Caminho **lista, int *caminho, int tamanho);

/**
 * @brief Função para limpar da memória a lista de caminhos
 * 
 * @param lista Ponteiro para a estrutura dos caminhos.
 * @return int 0: Sucesso.
 */
int limpar_caminhos(Caminho *lista);

/**
 * @brief Exibe na consola uma visualização do grafo, mostrando as conexões entre vértices e o peso de cada aresta.
 *
 * Esta função percorre todos os vértices do grafo e imprime informações sobre as arestas conectadas a cada vértice.
 * Cada linha começa com o índice do vértice, seguido por uma lista de todas as arestas conectadas a ele, incluindo o destino da aresta e o peso associado.
 * Os vértices são numerados de 1 a n, onde n é o número total de vértices no grafo.
 * 
 * @param grafo Instância do grafo.
 */
void print_grafo(GR *grafo);

/**
 * @brief Liberta a memória alocada para o grafo.
 * Percorre o grafo consoante o número de arestas, libertando a memória de cada aresta.
 * Por fim liberta os vértices e o próprio grafo.
 * 
 * @param grafo Instância do grafo.
 * @return int 0: Sucesso.
 */
int liberta_grafo(GR *grafo);

#endif // LIB_AUX_H