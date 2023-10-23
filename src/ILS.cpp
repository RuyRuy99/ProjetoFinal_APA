/*

Função ILS():

    MelhorSolucao  = //Solução inicial q vem do construtor
    MelhorCusto = CalculeCusto(MelhorSolucao)  # Calcule o custo da melhor solução inicial

    Para (criterio de parada): // Pode ser até 10 vezes sem achar uma melhor solução ou um tempo máximo
        SolucaoVizinhanca = VND(MelhorSolucao) // Busca local
        PerturbeSolucao(SolucaoVizinhanca)  # Fazer perturbações na solução

        CustoVizinhanca = CalculeCusto(SolucaoVizinhanca)

        Se CustoVizinhanca < MelhorCusto:
            MelhorSolucao = SolucaoVizinhanca
            MelhorCusto = CustoVizinhanca

    Retorne MelhorSolucao e MelhorCusto

*/


