#include "estatistica.h"
#include <fstream>

int main(){

    ifstream f=ifstream("conjuntoamostral.txt");
    int n;
    f>>n;
    vector<pair<double,double>>amostra(n);
    for(int i=0;i<n;i++){
        f>>amostra[i].first;
        f>>amostra[i].second;
    }
    estatistica E(amostra);
    E.imprimirAmostraPair();
    cout<<"media de X: "<<E.mdX()<<endl;
    cout<<"media de Y: "<<E.mdY()<<endl;
    cout<<"desvio padrao de x"<<E.Ox()<<endl;
    cout<<"desvio padrao de y"<<E.Oy()<<endl;
    cout<<"somatorio de X²: "<<E.sumXQ()<<endl;
    cout<<"media de x²"<<pow(E.mdX(),2)<<endl;
    cout<<"regressao linear: "<<E.regressaoLinear()<<endl;
    cout<<"correlacao entre x e y: "<<E.correlacao()<<endl;
    //printf("%lf",E.correlacao());


    
    return 0;
}