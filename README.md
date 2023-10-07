Ideia do Algoritmo Guloso
Alunos: Ruy de Morais e Silva
        Julyanna Azevedo

OBS(MAKRFILE): mingw32-make run

Algoritmo Guloso para Roteamento de Veículos com Terceirização
O algoritmo apresentado é uma abordagem gulosa para resolver o problema de roteamento de veículos com terceirização. A ideia principal do algoritmo é sempre escolher o vizinho mais próximo do vértice atual, ou seja, a aresta de menor valor, até que todos os vértices sejam visitados ou as condições preestabelecidas sejam atingidas.

Algoritmo Principal
O primeiro passo é encontrar o vizinho mais próximo do vértice de início usando a matriz de custos. O pseudocódigo a seguir ilustra este processo:

algoritmo_guloso(inicio, tamanho, matriz):
	vizinho_maisprox = primeiro do vetor

	for i in range(tamanho):
		//procura o MENOR PESO (ignora o deposito e ignora i = inicio).
		if (matriz[inicio][i] < viz_prox and i != inicio ):
			viz_prox = matriz[inicio][i]

	return viz_prox

Construção da Solução
Após identificar o vizinho mais próximo, o próximo passo é construir a solução, determinando as rotas que os carros irão seguir. O pseudocódigo abaixo ilustra a construção da solução:


buildSolution(inicio, viz_prox, matriz, demanda, k_carros):
	//Inicio é o deposito
	//Vizinho mais proximo calculado
	//Matriz de custo
	//vetor de demanda

	Solução = []
	result = 0

	for(int k=0;k_carros > 0;k--){
		rota.append(0); //rota começa no deposito

		WHILE (capacidade do carro > 0):
			//verifica a demanda do vizinho mais proximo vetor[demanda[i]]
			if (demanda[viz_prox] <= capacidade do carro):
				rota.append(viz_prox)
				capacidade do carro -= demanda[viz_prox]
				result += matriz[inicio][viz_prox]

			ELSE: //a demanda do cliente ULTRAPASSAR a capacidade do carro
				rota.append(inicio)
				Solução.append(rota)
				break 
	}

	return Solução, result

Nota: As capacidades dos carros devem ser definidas no método buildSolution.

Considerações
O algoritmo é baseado em uma abordagem gulosa, que pode não garantir a solução ótima em todos os casos. No entanto, é uma estratégia eficaz para obter soluções aproximadas rapidamente.

BUSCA EXAUSTIVA

Testar todas as possibilidades das estruturas de vizinhança e verificar qual é a melhor

ESTRUTURAS DE VIZINHANÇA

> A primeira deve realizar movimentos envolvendo uma única rota

Swap(Troca de clientes): Consiste em trocar clientes de posição na mesma rota e recalcular o custo

> A segunda deve realizar movimenos envolvedo múltiplas rotas

> A terceira deve ser capaz de lidar com entregas terceirizadas