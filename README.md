Ideia do Algoritmo Guloso
Alunos: Ruy de Morais e Silva
        Julyanna Azevedo

função VRP com Terceirização(matriz de custo, demanda, peso, L, n){

    Iniciar uma lista de rotas vazia
    Iniciar uma lista de clientes não atendidos
    
    for(houver veículos disponiveis): 
        while(houver capacidade do veiculo):
            Encontre o vizinho mais próximo
            if(a demanda não ultrapassar a capacidade):
                Adiciona o cliente a rota
                Atualiza a capacidade do veículo
                Remove o cliente da lista de não atendidos
            else(a demanda ultrapassar a capacidade):
                break
                Adiciona o depósito a solução

        if(lista de clientes não estiver vazia):
            Adiione o custo de terceirização de cada cliente restante à solução
}

Outra alternativa:

solução vazia
lista com clientes não atendidos(0,0,0,1)
int atendidos
result = 0
vertice_atual = 0(deposito)
while(carros tiverem disponíveis):
	vertice_atual = 0
	while(lista de clientes não atendidos diferente de vazia):
		calcula o vizinho mais proximo do vertice atual
		SE(a demanda não ultrapassar a capacidade do carro):
			adiciona o cliente na rota
			atualiza capacidade do veículo
			atualiza o vertice_atual
			atualiza o result com o custo da aresta(vertice_atual,vizinho mais proximo)
			remove o cliente da lista de cliente não atendidos
		SENÃO(a deanda ultrapassar a capaciade atual do carro):
			adiciona 0 na solução (voltar para o deposito)
			break(para não ficar em loop)	
	remove um carro
	adiciona o custo do uso do carro(só se o carro foi usado)