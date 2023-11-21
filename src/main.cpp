#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "datatype.h"
#include "data_loader.h"
#include "build_solution.h"
#include "check_solution.h"
#include "vnd.h"
#include "ils.h"
#include "n1.h"
#include "n2.h"
#include "n3.h"
#include "n4.h"
#include "n5.h"
#include "save_solution.h"


using namespace std;

int main(void){

    //Nome da instancia
    string nome_arquivo = "n199k17_A";

    //Carrega os dados da instancia
    InstanceData* dados_instancia = readAndExtractData(nome_arquivo);
    

    //Constrói a solução inicial
    Solution* solucao_inicial = buildSolution(dados_instancia);
    
    //Imprime a solução inicial
    //cout << "Solucao Inicial: \n";
    //Não é preciso desreferenciar mais pois a função agora espera um ponteiro como parâmetro...
    //doubleCheck(dados_instancia, solucao_inicial);


    //VND
    Solution* afterVND = vnd(solucao_inicial, dados_instancia);
    //cout << "Solucao depois do VND: \n";
    //doubleCheck(dados_instancia, afterVND);
    cout << "Custo da solucao depois do VND: " << afterVND->totalCost << "\n";

    

    //ILS
    Solution* afterILS = ils(afterVND, dados_instancia);
    cout << "Solucao depois do ILS: \n";
    doubleCheck(dados_instancia, afterILS);
    cout << "Custo da solucao depois do ILS: " << afterILS->totalCost << "\n";


    
    //escreve no arquivo de saída
    saveSolutionToFile(nome_arquivo, afterILS, dados_instancia);

    //Libera a memória alocada
    delete dados_instancia;
    delete afterILS;
    //delete solucao_inicial; problema de double-free
    //delete afterVND; problema de double-free
    
    
    cout << "Tudo certo!\n";

    return 0;
}