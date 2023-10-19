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

Testar todas as possibilidades das estruturas de vizinhança e verificar qual é a melhor

> ESTRUTURAS DE VIZINHANÇA

- A primeira deve realizar movimentos envolvendo uma única rota

Swap(Troca de clientes): Consiste em trocar clientes de posição na mesma rota e recalcular o custo

- A segunda deve realizar movimenos envolvedo múltiplas rotas

Swap(Troca de clientes entre rotas)

- A terceira deve ser capaz de lidar com entregas terceirizadas

> VND

- Dúvidas:

1. É dentro do VND que eu vou colocar a busca exaustiva ?
2. Se eu pegar a solução do algoritmo guloso e jogar na busca exaustiva e ela fizer 3 swap dentro da mesma rota(trocou 3 vertices de posição no vetor), ela é considerada uma solução vizinha à inicial(do guloso) ?
3. Quando a estrutura de vizinhança mudar(não houver melhora), vamos pegar a solução que saiu do guloso, ou a que foi melhorada pela estrutura de vizinhança ?
4. A Struct de solução está correta ?
5. Busca exaustiva específica para cada estrutura de vizinhança ou uma genérica pra cada um ?

- To Do:
1. codar busca exaustiva pra cada estrutura de vizinhança...
2. Tentar implementar o VND

-Pseudocode:
def vnd(initial_solution):
    k = 1
    k_max = 3  # Suponha que temos 3 estruturas de vizinhança.
    current_solution = initial_solution

    while k <= k_max:
        neighbor = best_neighbor(current_solution, k)

        # Se a solução vizinha é melhor, atualizamos a solução atual.
        if is_better(neighbor, current_solution):
            current_solution = neighbor
            k = 1  # Resetamos o contador de vizinhança.
        else:
            k += 1  # Passamos para a próxima estrutura de vizinhança.

    return current_solution


def best_neighbor(solution, k):
    """ Retorna a melhor solução vizinha para uma dada estrutura de vizinhança k. """
    # Supondo que temos funções para gerar a melhor solução vizinha para cada estrutura de vizinhança.
    # Aqui, vamos usar um switch case (com if-elif) para selecionar a estrutura de vizinhança.

    if k == 1:
        return best_neighbor_structure1(solution)
    elif k == 2:
        return best_neighbor_structure2(solution)
    elif k == 3:
        return best_neighbor_structure3(solution)


def is_better(solution1, solution2):
    """ Retorna verdadeiro se solution1 é melhor que solution2. """
    # Implemente a lógica de comparação aqui. Por exemplo, para problemas de minimização:
    return cost(solution1) < cost(solution2)


def best_neighbor_structure1(solution):
    # Implemente a busca pela melhor solução vizinha usando a estrutura de vizinhança 1.
    pass


def best_neighbor_structure2(solution):
    # Implemente a busca pela melhor solução vizinha usando a estrutura de vizinhança 2.
    pass


def best_neighbor_structure3(solution):
    # Implemente a busca pela melhor solução vizinha usando a estrutura de vizinhança 3.
    pass


def cost(solution):
    """ Calcule o custo (ou valor) de uma solução. """
    # Implemente a função de custo (ou avaliação) para o seu problema.
    pass

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