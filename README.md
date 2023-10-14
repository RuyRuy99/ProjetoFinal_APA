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

