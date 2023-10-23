/*

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

*/