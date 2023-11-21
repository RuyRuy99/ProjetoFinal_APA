#include <iostream>
#include <vector>
#include "datatype.h"

using namespace std;

void doubleCheck(const InstanceData* data, const Solution* solution) {
    if (!data || !solution) {
        cout << "Dados ou solução nulos." << endl;
        return;
    }

    int custoTotal = 0; // Inicializa com custo total igual a 0

    cout << "Rotas:" << endl;
    for (const auto& rota : solution->routes) {
        cout << "Rota: ";
        int rotaSize = rota.size();
        for (int i = 0; i < rotaSize - 1; i++) {
            int clienteAtual = rota[i];
            int proximoCliente = rota[i + 1];
            custoTotal += data->c[clienteAtual][proximoCliente];
            cout << clienteAtual << " ";
        }
        cout << rota.back(); // Último cliente na rota
        cout << endl;
    }

    cout << "Clientes Terceirizados: ";
    for (int cliente : solution->terceirizados) {
        cout << cliente << " ";
        // Aqui você pode somar o custo do cliente terceirizado a partir do vetor p
        custoTotal += data->p[cliente-1];
    }
    cout << endl;

    // Calcula o custo dos carros
    int custoCarros = solution->routes.size() * data->r;
    custoTotal += custoCarros;

    cout << "Custo Total da Solucao: " << custoTotal << endl;
}
