# Projeto de Avaliação - Fase 2

Estrutura de Dados Avançadas

Licenciatura em Engenharia de Sistemas Informáticos (*regime pós-laboral*) 2023-24

## Autor
Miguel Areal - Nº29559 - a29559@alunos.ipca.pt

## Organização
[src/](./src/)  Código principal da solução desenvolvida.

[lib/](./lib/)  Código da biblioteca da solução desenvolvida.

## Objetivo
Este projeto surge da necessidade de aplicar conceitos avançados de teoria dos grafos e programação em C para resolver problemas computacionais de com algum nível de complexidade.  
Está inserido na disciplina de estruturas de dados avançadas, com um foco especial na implementação de soluções eficientes para manipulação e análise de grafos.
Neste contexto, a segunda fase do projeto visa desenvolver uma aplicação capaz de gerir e manipular dados de grafos, calcular somas de pesos, criação de grafos a partir de uma matriz, e mais.  
A aplicação será construída sobre estruturas de dados dinâmicas que representam um grafo, vértices, arestas, e caminhos permitindo a modelagem e resolução de problemas através da utilização de algoritmos de procura.  
O objetivo principal desta fase é aprender a definir e manipular estruturas de dados dinâmicas, e aplicar algoritmos para encontrar soluções ótimas em problemas de somas e procura.  
Para alcançar este objetivo, foram estabelecidas várias tarefas, incluindo a definição de estruturas de dados, modelagem do problema, implementação de algoritmos de procura e manipulação de grafos, e desenvolvimento de funções para cálculo de somas e identificação de caminhos.

  
## Estrutura do Projeto
-   [data/](./data)
    -   Armazena o [ficheiro de dados](./data/matriz.txt) utilizado pela aplicação.
        -  [matriz.txt](./data/matriz.txt)
            -   Matriz utilizada pela aplicação.
-   [include/](./include)
    -   Contém os arquivos de cabeçalho (headers) do projeto.
        -   [header.h](./include/header.h)
            -   Ficheiro header principal que conecta e declara as funções do programa em linguagem C.
-   [src/](./src)
    -   Contém os ficheiros fonte do programa em linguagem C.
        -   [main.c](./src/main.c)
            -   Ficheiro principal que contém a função `main` e a lógica principal do programa, incluindo tratamento de erros.
-   [lib/](./lib)
    -   Contém os ficheiros fonte da biblioteca, em linguagem C.
        -   [lib.c](./lib/lib.c)
            -   Ficheiro principal contendo as funções utilizadas para realizar operações com os dados.
        -   [lib.h](./lib/lib.h)
            -   Ficheiro header que contém a declaração das funções e estruturas de dados utilizadas.
        -   [lib_aux.c](./lib/lib_aux.c)
            -   Ficheiro auxiliar contendo as funções utilizadas para realizar operações menores.
        -   [lib_aux.h](./lib/lib_aux.h)
            -   Ficheiro header que contém a declaração das funções auxiliares.               
-   [Makefile](Makefile)
    -   Ficheiro utilizado pelo comando `make` para compilar o projeto de forma automatizada.
-   [README.md](README.md)
    -   Ficheiro que contém informações básicas sobre o projeto, a sua descrição, uso e outras instruções.
-   [lib.dll](lib.dll)
    -   Ficheiro do tipo `Dynamic Link Library`, compilado através dos ficheiros em [lib/](./lib). Para ser utilizado, necessita de estar no mesmo diretório que [PFase2.exe](PFase2.exe).
-   [PFase2.exe](PFase2.exe)
    -   Executável do projeto, gerado após a compilação.

### Descrição da Estrutura

Este projeto está organizado de forma a separar claramente os componentes do código-fonte, dados e documentação.

Os diretórios `doc/` e `data/` mantêm a [documentação gerada em *Doxygen*](doc/html/index.html) e os ficheiros de dados usados pelo programa, respetivamente.

O diretório `include/` mantém o ficheiro principal de cabeçalho que interliga todas as funções e algoritmos do projeto.

O diretório `lib/` possui os ficheiros relativos ao código da biblioteca utilizada. 

Já o diretório `src/` contém os ficheiros-fonte da aplicação, organizados de acordo com suas funcionalidades específicas.

O ficheiro `Makefile` automatiza o processo de compilação do projeto, enquanto `README.md` fornece informações básicas sobre o projeto.

Por fim, `PFase2.exe` é o executável gerado após a compilação do projeto (também compila a biblioteca ao mesmo efeito).
  
## Compilação
Para a compilação e execução do programa, é apenas necessário utilizar o comando *make* a partir do diretório raíz do projeto.

Após a compilação do projeto, é gerado um novo executável `PFase2.exe` e `lib.dll`, na raíz do repositório.
## Execução / Utilização
Para executar esta aplicação, é possível de duas formas:
- Ambiente gráfico:
  - Duplo-clique no ficheiro `PFase2.exe`
- CLI / Consola:
  - Navegar para o diretório raíz do projeto, e executar `./PFase2.exe`

## Bibliografia
- https://www.tutorialspoint.com/c_standard_library/index.htm
- https://www.doxygen.nl/manual/docblocks.html
- https://stackoverflow.com
- https://code.visualstudio.com
- https://gnuwin32.sourceforge.net/packages/make.htm
- https://sourceforge.net/projects/mingw/files/
- https://elemarjr.com/clube-de-estudos/artigos/o-algoritmo-hungaro-e-a-solucao-de-problemas-de-atribuicao/
- https://chat.openai.com
- https://devdocs.io/c/
- https://en.wikipedia.org/wiki/Hungarian_algorithm
- https://www.geeksforgeeks.org/what-is-linked-list/
- https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdbool.h.html
- https://www.tutorialspoint.com/c_standard_library/ctype_h.htm
- https://www.tutorialspoint.com/c_standard_library/limits_h.htm
- https://www.simplilearn.com/tutorials/data-structure-tutorial/dfs-algorithm
- https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Graphs.html 

