Ideia do Algoritmo Guloso
Alunos: Ruy de Morais e Silva
        Julyanna Azevedo

função (matriz de custo, demanda, peso, L, n){

    Iniciar uma lista de rotas vazia
    Iniciar uma lista de clientes não atendidos
    
    while(houver veículo disponível e capacidade):
        Encontre o vizinho mais próximo
        if(a demanda não ultrapassar a capacidade):
            Adiciona o cliente a rota
            Atualiza a capacidade do veículo
            Remove o cliente da lista de não atendidos

    if(lista de clientes não estiver vazia):
        Adiione o custo de terceirização de cada cliente restante à solução
}