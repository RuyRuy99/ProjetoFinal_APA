Ideia do Algoritmo Guloso
Alunos: Ruy de Morais e Silva
        Julyanna Azevedo

Outra alternativa:

solução vazia
lista com clientes não atendidos(0,0,0,1)
int atendidos
result = 0
vertice_atual = 0(deposito)
uso_carro = 0
while(carros tiverem disponíveis):
	vertice_atual = 0
	while(lista de clientes não atendidos diferente de vazia):
		calcula o vizinho mais proximo do vertice atual
		SE(a demanda não ultrapassar a capacidade do carro):
            uso_carro = 1
			adiciona o cliente na rota
			atualiza capacidade do veículo
			atualiza o vertice_atual
			atualiza o result com o custo da aresta(vertice_atual,vizinho mais proximo)
			remove o cliente da lista de cliente não atendidos
		SENÃO(a deanda ultrapassar a capaciade atual do carro):
			adiciona 0 na solução (voltar para o deposito)
			break(para não ficar em loop)	
	decrementa um carro
    SE(carro_uso = 1)
	    adiciona o custo do uso do carro(só se o carro foi usado)