/**
 * @file main.c
 * @author Miguel Areal (a29559@alunos.ipca.pt)
 * @brief 
 * @date 04-2024
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../lib/lib.h"
#include "../lib/lib_aux.h"
#include "../include/header.h"

int main() {
    int resultado;
    const char* ficheiro = "./data/matriz.txt";
    GR *grafo = carrega_fich(ficheiro);
    if (grafo == NULL){printf("Erro ao abrir o ficheiro.\n");return -21;}
    
    print_grafo(grafo);
    
    printf("Alterar peso de aresta\n");
    resultado = alterar_peso(grafo,1,0,100);
    if (resultado == -31){printf("Erro: Vértices Inválidos.\n"); return resultado;}
    else if (resultado == -32){printf("Erro: Não foi encontrada uma aresta entre os vértices especificados.\n"); return resultado;}
    print_grafo(grafo);

    printf("Remocao de aresta\n");
    resultado = rem_aresta(grafo,2,3);
    if (resultado == -11){printf("Erro: Vértices Inválidos.\n"); return resultado;}
    else if (resultado == -12){printf("Erro: Não foi encontrada uma aresta entre os vértices especificados.\n");return resultado;}
    print_grafo(grafo);
    
    printf("Adicao de aresta\n");
    resultado = add_aresta(&(grafo->vertices[0]), &(grafo->vertices[1]), 50);
    if (resultado == -1){printf("Erro: Falha na alocação de memória.\n"); return resultado;}
    print_grafo(grafo);


    int caminho[] = {1,0,2,0};    
    int tamanho_caminho = sizeof(caminho) / sizeof(caminho[0]);
    resultado = soma_pesos_caminho(grafo, caminho, tamanho_caminho);
    if(resultado == -41){printf("Erro: Caminho Inválido.\n");return resultado;}
    else if (resultado == -42){printf("Erro: Vértice inválido no caminho.\n");return resultado;}
    else if (resultado == -43){printf("Erro: Não foi encontrada uma aresta entre os vértices.\n"); return resultado;}
    else printf("Soma dos valores dos pesos no caminho: %d\n", resultado);
    

    resultado = encontrar_maior_soma_caminho(grafo);
    if (resultado == -51){printf("Erro: Nenhum caminho encontrado."); return resultado;}
    else printf("Maior soma: %d\n", resultado);

    liberta_grafo(grafo);
    return 0;
}
