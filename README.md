Projeto Final - Análise de Projetos e Algoritmos
Alunos: Ruy de Morais e Silva
        Julyanna Azevedo

PROBLEMA DE ROTEAMENTO DE VEÍCULOS COM TERCEIRIZAÇÃO

> ALGORITMO GULOSO

A ideia principal do algoritmo é sempre escolher o vizinho mais próximo do vértice atual, ou seja, a aresta de menor valor, até que todos os vértices sejam visitados ou as condições preestabelecidas sejam atingidas.

> CONSTRUTOR DA SOLUÇÃO

Após identificar o vizinho mais próximo, o próximo passo é construir a solução, determinando as rotas que os carros irão seguir.
O algoritmo é baseado em uma abordagem gulosa, que pode não garantir a solução ótima em todos os casos. No entanto, é uma estratégia eficaz para obter soluções aproximadas rapidamente.

> BUSCA EXAUSTIVA

> ESTRUTURAS DE VIZINHANÇA

> VND

- To Do:
1. Implementar o ILS (opcional)
2. Arquivo de saída
3. Criar a tabela
4. Criar uma pasta com os arquivos de saída gerados durante os testes com cada instância


> ILS

Função ILS(maxIteracoes):
    MelhorSolucao <- GereUmaSolucaoInicial()  # Gere uma solução inicial aleatória
    MelhorCusto <- CalculeCusto(MelhorSolucao)  # Calcule o custo da melhor solução inicial

    Para iteracao de 1 até maxIteracoes:
        SolucaoVizinhanca <- RealizeBuscaLocal(MelhorSolucao)  # Aplique busca local para melhorar a solução
        PerturbeSolucao(SolucaoVizinhanca)  # Introduza perturbações na solução

        CustoVizinhanca <- CalculeCusto(SolucaoVizinhanca)

        Se CustoVizinhanca < MelhorCusto:
            MelhorSolucao <- SolucaoVizinhanca
            MelhorCusto <- CustoVizinhanca

    Retorne MelhorSolucao e MelhorCusto

maxIteracoes é o número máximo de iterações a serem executadas.
GereUmaSolucaoInicial() é uma função que gera uma solução inicial aleatória.
CalculeCusto(Solucao) é uma função que calcula o custo da solução.
RealizeBuscaLocal(Solucao) é uma função que aplica busca local para melhorar a solução.
PerturbeSolucao(Solucao) é uma função que introduz perturbações na solução, por exemplo, realizando trocas aleatórias.