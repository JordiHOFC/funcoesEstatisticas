#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class estatistica{
    public:


    estatistica(vector<double>& amostra);
    estatistica(vector<pair<double,double>>& amostra);
    
    virtual~estatistica();
    int qtdItens;
    
    
    vector<double>amostra;
    vector<double>desvio;
    vector<pair<double,double>>amostraBiDimensional;
    vector<pair<double,double>>desvioBiDimensional;

    /*funcoes implementadas */
    double mediaPair(int op,vector<pair<double,double>> &amostraa);
    double SomatorioPair(int op);
    double SomatorioPairQ(int op);

    /*funcoes unidimensional */
    //media
    double media();
    //calculo de media intero
    double media1(vector<double>& amostra);
    //calculo do vetor com o calculo de desvio da amostra  da media
    void calcVetorDesvio();
    //variancia
    double variancia();
    //desvio padrao
    double desviopadrao();
    //imprimir amostra
    void imprimirAmostra();
    //somatorio da amostra
    double somatorio();
    //somatorio de cada item da amostra ao quadrado
    double somatorioQuadrado();

    /*funcoes bidimensional */

    //media de x
    double mdX();
    //media de y
    double mdY();
    //vetor de desvio da amostra para media
    void calcVetorBiDesvio();
    //variancia de x
    double Sx();
    //variancia de y
    double Sy();
    //desvio padrao de x
    double Ox();
    //desvio padrao de y
    double Oy();
    //somatorio de x
    double sumX();
    //somatorio de y
    double sumY();
    //somatorio de x^2
    double sumXQ();
    //somatorio de y^2
    double sumYQ();
    //regressao linear
    double regressaoLinear();
    //correlacao
    long double correlacao();
    //imprimir conjunto amostral
    void imprimirAmostraPair();
    

    
};