/**
 * @file lib.h
 * @author Miguel Areal (a29559@alunos.ipca.pt)
 * @brief Ficheiro Header da biblioteca 'lib'
 * @date 04-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * @brief Estrutura que representa um vértice em um grafo.
 *
 * Cada vértice contém um valor inteiro, um ponteiro para a lista de arestas conectadas a ele e o número de arestas.
 * 
 */
typedef struct Vertice {
    int valor;
    struct Aresta *arestas;
    int num_arestas;
} Vertice;

/**
 * @brief Estrutura que representa uma aresta num grafo.
 *
 * Cada aresta contém um ponteiro para um vértice de destino, um peso associado e um ponteiro para a próxima aresta na lista ligada.
 * 
 */
typedef struct Aresta {
    struct Vertice *destino;
    int peso;
    struct Aresta *proxima;
} Aresta;

/**
 * @brief Estrutura que representa um grafo.
 *
 * Um grafo é composto por um array de vértices e o número total de vértices no grafo.
 * 
 */
typedef struct GR {
    Vertice *vertices;
    int num_vertices;
} GR;

/**
 * @brief Estrutura para armazenar caminhos com a maior soma.
 * 
 * Esta estrutura é usada para armazenar uma lista ligada de caminhos no grafo.
 * Cada caminho é representado por uma sequência de vértices e o tamanho dessa sequência.
 * A estrutura também possui um ponteiro para o próximo caminho na lista, permitindo a criação
 * de uma lista ligada de caminhos.
 */
typedef struct Caminho {
    int *vertices;           
    int tamanho;             
    struct Caminho *proximo; 
} Caminho;


// Declaração das funções

/**
 * @brief Adiciona uma aresta entre dois vértices com o peso especificado.
 *
 * Esta função cria espaço na memória para uma nova aresta entre os vértices de origem e destino fornecidos, com o peso especificado, e adiciona-a à lista de arestas do vértice de origem.
 *
 * @param v1 O vértice de origem da aresta.
 * @param v2 O vértice de destino da aresta.
 * @param peso O peso associado à aresta.
 * @return int 0: Sucesso. -1: Erro: Falha na alocação de memória.
 */
int add_aresta(Vertice *v1, Vertice *v2, int peso);

/**
 * @brief Remove a aresta entre dois vértices especificados.
 * 
 * Esta função remove a aresta entre o vértice de origem e o vértice de destino, identificados pelos seus índices.
 * Verifica se o grafo é nulo e se os índices dos vértices são válidos.
 * Através dos índices, procura a aresta específicada. Se a aresta a ser removida for a primeira da lista, a remoção é direta.
 * Caso contrário, ajusta os apontadores para manter a integridade da lista ligada de arestas.
 * 
 * @param grafo Instância do grafo.
 * @param index_origem Índice do vértice de origem.
 * @param index_destino Índice do vértice de destino.
 * @return int 0:Sucesso. -12:Erro: Vértices Inválidos. -13:Erro: Não foi encontrada uma aresta entre os vértices especificados.
 */
int rem_aresta(GR *grafo, int index_origem, int index_destino);

/**
 * @brief Cria um novo grafo com um número especificado de vértices.
 *
 * Esta função aloca espaço na memória para um novo grafo consoante o parâmetro num_vertices.
 * Aloca espaço na memória para a estrutura de Vertices.
 * Inicializa todos os seus vértices através da função auxiliar criar_vertice.
 *
 * @param num_vertices O número de vértices que o grafo deve conter.
 * @return Um ponteiro para o novo grafo criado, ou NULL se a alocação de memória falhar.
 */
GR* criar_grafo(int num_vertices);

/**
 * @brief Lê e inicializa o grafo a partir de um ficheiro, dado pelo seu caminho.
 * 
 * Lê o ficheiro de texto que contém uma matriz formatada com pontos e vírgulas e inicializa um grafo com base nessa matriz.
 * Se a matriz conter pesos nulos ou '0', estes serão ignorados, passando para o valor seguinte.
 * A leitura da matriz para um grafo dá-se por entender que cada coordenada representa uma conexão entre dois vértices.
 * Cada índice de coluna e linha representa um vértice.
 * Exemplo:
 * x;y
 * y;x
 * 
 * |||| V1 | V2 |
 * |V1| X  | Y  |
 * |V2| Y  | X  |
 * 
 * A regra utilizada para a geração do grafo é que cada vértice da linha se conectará aos vértices de cada coluna
 * incluindo, se assim possível, até ele próprio (lacete).
 * 
 * @param nomefich Caminho do ficheiro de texto que contém a matriz formatada.
 * @return GR* Um ponteiro para a estrutura do grafo inicializado e operacional. NULL : Erro: Erro ao abrir o ficheiro.
 */
GR *carrega_fich(const char *nomefich);

/**
 * @brief Altera o peso de uma aresta entre dois vértices especificados.
 * 
 * Esta função permite alterar o peso de uma aresta que conecta o vértice de origem ao vértice de destino.
 *  
 * A função percorre a lista de arestas do vértice de origem até encontrar a aresta que conecta ao vértice de destino.
 * Quando essa aresta é encontrada, o seu peso é atualizado com o valor especificado. Se a aresta não for encontrada,
 * a função imprime uma mensagem de erro indicando a falta de conexão entre os vértices, e retorna 0.
 * 
 * @param grafo Ponteiro para a instância do grafo.
 * @param index_origem Índice do vértice de origem.
 * @param index_destino Índice do vértice de destino.
 * @param novo_peso Novo valor que substituirá o peso atual da aresta.
 * 
 * @return int 0: Sucesso. -31 : Erro: Vértices inválidos. -32 : Erro: Não foi encontrada uma aresta entre os vértices especificados.
 * 
 */
int alterar_peso(GR *grafo, int index_origem, int index_destino, int novo_peso);


/**
 * @brief Função para encontrar o caminho com a maior soma possível de pesos das arestas no grafo.
 *
 * Esta função percorre todos os vértices do grafo e utiliza a função de busca em profundidade (DFS) para encontrar o caminho com a maior soma possível de pesos das arestas.
 * Se houver múltiplos caminhos com a mesma soma máxima, mostrará todos esses caminhos.
 * 
 * @param grafo Ponteiro para a estrutura do grafo.
 * @return int 0: Sucesso. -44 : Erro: Nenhum caminho encontrado.
 */
int encontrar_maior_soma_caminho(GR *grafo);

/**
 * @brief Realiza uma pesquisa em profundidade (DFS) no grafo para encontrar o caminho com a maior soma.
 * 
 * Esta função utiliza a técnica de pesquisa em profundidade (DFS) para percorrer o grafo a partir de um
 * vértice inicial, calculando as somas dos valores dos vértices ao longo dos caminhos. Ela armazena o
 * caminho com a maior soma encontrada e atualiza as estruturas de dados correspondentes.
 * 
 * @param v Apontador para o vértice atual a partir do qual a busca está a ser realizada.
 * @param destino Valor do vértice de destino. Se for -1, a busca considera todos os vértices como destinos válidos.
 * @param visitados Array de inteiros que indica quais vértices foram visitados. Cada posição representa um vértice,
 *                 onde um valor diferente de zero indica que o vértice foi visitado.
 * @param caminho Array de inteiros que armazena o caminho atual percorrido durante a busca. Cada posição representa
 *               um vértice no caminho.
 * @param nivel Nível atual na busca, representando a profundidade da recursividade. Também usado como índice para o array caminho.
 * @param maior_soma Apontador para a variável que armazena a maior soma encontrada até ao momento. A função atualiza este valor
 *                  sempre que um caminho com uma soma maior é encontrado.
 * @param melhores_caminhos Apontador duplo para a estrutura Caminho que armazena o melhor caminho encontrado até ao momento.
 *                         A função atualiza esta estrutura conforme novos caminhos com maiores somas são encontrados.
 * @param grafo Apontador para a estrutura do grafo que contém os vértices e as suas conexões.
 * 
 * A função não retorna valores, mas atualiza os ponteiros passados como argumentos para refletir os melhores caminhos e as suas somas.
 */
void dfs(Vertice *v, int destino, int *visitados, int *caminho, int nivel, int *maior_soma, Caminho **melhores_caminhos, GR *grafo);


/**
 * @brief Calcula a soma dos pesos das arestas num dado caminho no grafo.
 * 
 * Esta função percorre um caminho especificado pelos índices dos vértices no grafo e soma os pesos
 * das arestas entre os vértices consecutivos. Se o caminho ou os vértices forem inválidos, a função 
 * exibe uma mensagem de erro e retorna 1.
 *
 * @param grafo Ponteiro para a estrutura do grafo que contém os vértices e arestas.
 * @param caminho Array de inteiros representando a sequência de vértices no caminho.
 * @param tamanho_caminho O número de vértices no array do caminho.
 * @return int A soma dos pesos das arestas no caminho especificado. -41 : Erro: Caminho Inválido. -42 : Erro: Vértice inválido no caminho. -43 : Erro: Não foi encontrada uma aresta entre os vértices.
 */
int soma_pesos_caminho(GR *grafo, int *caminho, int tamanho_caminho);



#endif // LIB_H