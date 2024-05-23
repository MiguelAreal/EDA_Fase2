/**
 * @file lib.c
 * @author Miguel Areal (a29559@alunos.ipca.pt)
 * @brief Código-Fonte da biblioteca com implementações
 * @date 04-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "lib.h"
#include "lib_aux.h"


int add_aresta(Vertice *v1, Vertice *v2, int peso) {
    Aresta *nova_aresta = (Aresta*)malloc(sizeof(Aresta));
     if (nova_aresta == NULL) {
        // Se a alocação de memória falhar, retorna 1 (falha)
        return -1;
    }
    nova_aresta->destino = v2;
    nova_aresta->peso = peso;
    nova_aresta->proxima = v1->arestas; // Aponta para a primeira aresta da lista atual

    // A nova aresta fica a primeira da lista
    v1->arestas = nova_aresta;
    v1->num_arestas++;
    return 0;
}


int rem_aresta(GR *grafo, int index_origem, int index_destino) {

    if (grafo == NULL || index_origem < 0 || index_origem >= grafo->num_vertices ||
        index_destino < 0 || index_destino >= grafo->num_vertices) {
        return -11;
    }

    Vertice *origem = &(grafo->vertices[index_origem]);
    Vertice *destino = &(grafo->vertices[index_destino]);

    // Procurar a aresta no vértice de origem
    Aresta *anterior = NULL;
    Aresta *atual = origem->arestas;
    while (atual != NULL) {
        if (atual->destino == destino) {
            // A aresta foi encontrada, removê-la
            // Se a aresta a ser removida é a primeira da lista
            if (anterior == NULL) {
                
                origem->arestas = atual->proxima;
            } else {
                // Se a aresta a ser removida não é a primeira da lista
                anterior->proxima = atual->proxima;
            }
            free(atual); 
            return 0;
        }
        anterior = atual;
        atual = atual->proxima;
    }

    // Se não encontrar a aresta
    return -12;
}


GR* criar_grafo(int num_vertices) {
    GR *grafo = (GR*)malloc(sizeof(GR));
    grafo->vertices = (Vertice*)malloc(num_vertices * sizeof(Vertice));
    grafo->num_vertices = num_vertices;

    // Inicialização de cada vértice
    for (int i = 0; i < num_vertices; i++) {
        grafo->vertices[i] = *criar_vertice(i);
    }

    return grafo;
}


GR* carrega_fich(const char *nomefich) {
    FILE *file = fopen(nomefich, "r");
    if (file == NULL) {
        return NULL;
    }

    int max_linhas = 0;
    int max_colunas = 0;
    char linha[256];

    // Conta o número de linhas e o número máximo de colunas
    while (fgets(linha, sizeof(linha), file)) {
        char *token = strtok(linha, ";");
        int col = 0; // índice da coluna
        while (token != NULL) {
            if (strcmp(token, " ") != 0) { // Ignora os valores vazios ou nulos
                col++; //Incrementa colunas
            }
            token = strtok(NULL, ";");
        }
        max_linhas++; // Incrementa linhas 
        if (col > max_colunas) {
            max_colunas = col;
        }
    }

    rewind(file); // Volta ao início

    // Determina o tamanho do grafo com base no maior número de linhas ou colunas
    int tamanho_grafo = (max_linhas > max_colunas) ? max_linhas : max_colunas;

    // Cria o grafo com o tamanho determinado
    GR *grafo = criar_grafo(tamanho_grafo);
    int lin = 0;

    while (fgets(linha, sizeof(linha), file)) {
        char *token = strtok(linha, ";");
        int col = 0; // índice da coluna
        while (token != NULL) {
            if (strcmp(token, " ") != 0) { // Ignora os valores vazios ou nulos
                int valor = atoi(token);
                if(valor != 0){
                    add_aresta(&(grafo->vertices[lin]), &(grafo->vertices[col]), valor);
                }
                col++; // Incrementa o índice da coluna
            }
            token = strtok(NULL, ";");
        }
        // Se o número de colunas for menor que o máximo, não é necessário adicionar arestas vazias
        // para os vértices restantes, pois as arestas já estão inicializadas como NULL
        lin++;
    }
    fclose(file);
    return grafo;
}


int alterar_peso(GR *grafo, int index_origem, int index_destino, int novo_peso) {

    if (index_origem < 0 || index_origem >= grafo->num_vertices || index_destino < 0 || index_destino >= grafo->num_vertices) {
        return -31;
    }

    Vertice *v_origem = &(grafo->vertices[index_origem]);
    Vertice *v_destino = &(grafo->vertices[index_destino]);

    for (Aresta *a = v_origem->arestas; a != NULL; a = a->proxima) {
        // Se a aresta se conectar ao vértice de destino, atualiza o peso
        if (a->destino == v_destino) {
            a->peso = novo_peso;
            return 0;

        }
    }
    // Se não encontrar a aresta
    return -32;
}


int soma_pesos_caminho(GR *grafo, int *caminho ,int tamanho_caminho) {
    int soma_pesos = 0;

    // Verifica se o caminho é válido
    if (caminho == NULL || tamanho_caminho <= 0) {
        return -41;
    }

    // Itera sobre os vértices no caminho
    for (int i = 0; i < tamanho_caminho - 1; i++) {
        
        // Verifica se o índice do vértice está dentro dos limites do grafo
        if (caminho[i] < 0 || caminho[i] >= grafo->num_vertices || caminho[i + 1] < 0 || caminho[i + 1] >= grafo->num_vertices) {
            return -42;
        }

        // Procura a aresta entre os vértices
        Vertice *v_atual= &(grafo->vertices[caminho[i]]);
        Vertice *v_prox = &(grafo->vertices[caminho[i + 1]]);
        Aresta *aresta = v_atual->arestas;

        // Procura a aresta que conecta os vértices
        while (aresta != NULL) {
            if (aresta->destino == v_prox) {
                // Adiciona o peso da aresta ao sumatório dos pesos
                soma_pesos += aresta->peso;
                break; //Encontrou a aresta
            }
            //Passa para a próxima aresta
            aresta = aresta->proxima;
        }

        // Se não encontrar a aresta que conecta os vértices
        if (aresta == NULL) {
            return -43;
        }
    }

    return soma_pesos;
}


int encontrar_maior_soma_caminho(GR *grafo) {
    // Variáveis para armazenar a maior soma e a lista de melhores caminhos
    int maior_soma = INT_MIN; // Inicializa com o menor valor possível de um inteiro
    Caminho *melhores_caminhos = NULL;

    // Itera sobre todos os vértices
    for (int i = 0; i < grafo->num_vertices; i++) {
        // Array para marcar os vértices visitados durante a pesquisa
        int *visitados = (int *)malloc(grafo->num_vertices * sizeof(int));
        memset(visitados, 0, grafo->num_vertices * sizeof(int));

        // Array para armazenar o caminho atual durante a pesquisa
        int *caminho_atual = (int *)malloc(grafo->num_vertices * sizeof(int));

        // Realiza a busca em profundidade (DFS) a partir do vértice atual
        dfs(&(grafo->vertices[i]), -1, visitados, caminho_atual, 0, &maior_soma, &melhores_caminhos, grafo);

        // Liberta a memória alocada para os vetores
        free(visitados);
        free(caminho_atual);
    }

    // Mostra a maior soma encontrada e os caminhos correspondentes
    printf("Caminhos:\n");
    Caminho *caminho = melhores_caminhos;
    while (caminho != NULL) {
        for (int i = 0; i < caminho->tamanho; i++) {
            printf("V%d", caminho->vertices[i] + 1); // Vértices numerados de 1 a n
            if (i < caminho->tamanho - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
        caminho = caminho->proximo;
    }

    if (melhores_caminhos == NULL) {
        return -44;
    }

    // Libera a memória alocada para os caminhos
    limpar_caminhos(melhores_caminhos);
    return maior_soma;
}


void dfs(Vertice *v, int destino, int *visitados, int *caminho, int nivel, int *maior_soma, Caminho **melhores_caminhos, GR *grafo) {
    visitados[v->valor] = 1;
    caminho[nivel] = v->valor;

    if (nivel > 0) {
        int soma_caminho = soma_pesos_caminho(grafo, caminho, nivel + 1);
        if (soma_caminho > *maior_soma) {
            // Atualiza a maior soma e limpa a lista de melhores caminhos
            *maior_soma = soma_caminho;
            limpar_caminhos(*melhores_caminhos);
            *melhores_caminhos = NULL;
            adicionar_caminho(melhores_caminhos, caminho, nivel + 1);
        } else if (soma_caminho == *maior_soma) {
            // Adiciona o novo caminho à lista de melhores caminhos
            adicionar_caminho(melhores_caminhos, caminho, nivel + 1);
        }
    }

    Aresta *aresta = v->arestas;
    while (aresta != NULL) {
        if (!visitados[aresta->destino->valor]) {
            dfs(aresta->destino, destino, visitados, caminho, nivel + 1, maior_soma, melhores_caminhos, grafo);
        }
        aresta = aresta->proxima;
    }

    // Reseta o vértice atual após a visita
    visitados[v->valor] = 0;
}

