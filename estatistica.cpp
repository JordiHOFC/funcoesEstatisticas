#include "estatistica.h"

estatistica::estatistica(vector<double> &amostraa){
    amostra=amostraa;
    qtdItens=amostraa.size();
    desvio=vector<double>(qtdItens);
    calcVetorDesvio();
}
estatistica::estatistica(vector<pair<double,double>>& amostra){
    amostraBiDimensional=amostra;
    qtdItens=amostraBiDimensional.size();
    desvioBiDimensional=vector<pair<double,double>>(qtdItens);
    calcVetorBiDesvio();
}


estatistica::~estatistica(){

}
//funcoes unidimensional

double estatistica::media1(vector<double>& amostra){
    double media=0;
    for(int i=0;i<qtdItens;i++){
        media+=amostra[i];
    }
    media=media/qtdItens;
    return media;
}
double estatistica::media(){
    double media=media1(amostra);
    
    return media;
}
void estatistica::calcVetorDesvio(){
   double Media=media1(amostra);
    for(int i=0;i<qtdItens;i++){
        desvio[i]=pow((amostra[i]-Media),2);
    }
}

double estatistica::variancia(){
    double Variancia=media1(desvio);
    return Variancia;

}

double estatistica::desviopadrao(){
    double desviopadrao,Variancia=variancia();
    desviopadrao=sqrt(Variancia);
    return desviopadrao;

}
void estatistica::imprimirAmostra(){
     cout<<"[";
    for(int i=0;i<qtdItens;i++){
        cout<<amostra[i]<<" ";

    }
    cout<<"]"<<endl;
}
double estatistica::somatorio(){
    double somatorio=0;
    for(int i=0;i<qtdItens;i++){
        somatorio+=amostra[i];
    }
    return somatorio;
}
double estatistica::somatorioQuadrado(){
    double somatorio=0;
    for(int i=0;i<qtdItens;i++){
        somatorio+=pow(amostra[i],2);
    }
    return somatorio;
}
/*funcoes bidimensional */

double estatistica::mediaPair(int op, vector<pair<double,double>> &amostraa){
    double media=0;
    if(op==0){
        for(int i=0;i<qtdItens;i++){
            media+=amostraa[i].first;
        }
        return media/qtdItens;
    }if(op==1){
        for(int i=0;i<qtdItens;i++){
            media+=amostraa[i].second;
        }
        return media/qtdItens;
    }
}
double estatistica::SomatorioPair(int op){
    double sum=0;
    if(op==0){
        for(int i=0;i<qtdItens;i++){
            sum+=amostraBiDimensional[i].first;
        }
        return sum;
    }
    if(op==1){
        for(int i=0;i<qtdItens;i++){
            sum+=amostraBiDimensional[i].second;
        }
        return sum;
    }
}
double estatistica::SomatorioPairQ(int op){
    double sum=0;
    if(op==0){
        for(int i=0;i<qtdItens;i++){
            sum+=pow(amostraBiDimensional[i].first,2);
        }
        return sum;
    }
    if(op==1){
        for(int i=0;i<qtdItens;i++){
            sum+=pow(amostraBiDimensional[i].second,2);
        }
        return sum;
    }
}
void estatistica::calcVetorBiDesvio(){
    double mdx=mediaPair(0,amostraBiDimensional),mdy=mediaPair(1,amostraBiDimensional);
    for(int i=0;i<qtdItens;i++){
        desvioBiDimensional[i].first=pow((amostraBiDimensional[i].first-mdx),2);
        desvioBiDimensional[i].second=pow((amostraBiDimensional[i].second-mdy),2);
    }
}
double estatistica::mdX(){
    double media=mediaPair(0,amostraBiDimensional);
    return media;
}
double estatistica::mdY(){
    double media=mediaPair(1,amostraBiDimensional);
    return media;
}
double estatistica::Sx(){
    double varianca=mediaPair(0,desvioBiDimensional);
    return varianca;
}
double estatistica::Sy(){
    double varianca=mediaPair(1,desvioBiDimensional);
    return varianca;
}
double estatistica::sumX(){
    double sum=SomatorioPair(0);
    return sum;
}
double estatistica::sumY(){
    double sum=SomatorioPair(1);
    return sum;
}
double estatistica::sumXQ(){
    double sum=SomatorioPairQ(0);
    return sum;
}
double estatistica::sumYQ(){
    double sum=SomatorioPairQ(1);
    return sum;
}
double estatistica::Ox(){
    double desvio=Sx();
    desvio=sqrt(desvio);
    return desvio;
}
double estatistica::Oy(){
    double desvio=Sy();
    desvio=sqrt(desvio);
    return desvio;
}
double estatistica::regressaoLinear(){
    double a, y, b,medX=mdX(),medY=mdY(),N=qtdItens;
    double sumXY,sumxQ=sumXQ();
    //calculando somatorio de xy
    for(int i=0;i<qtdItens;i++){
        sumXY+=amostraBiDimensional[i].first*amostraBiDimensional[i].second;
    }
    //temos b calculado
    b=(sumXY-(N*medY*medX))/(sumxQ-(N*(pow(medX,2))));
    //calcularea a
    a=medY-(b*medX);
    //agora teremos o coef
    y=a+b;
    return y;

}
long double estatistica::correlacao(){
    double r=0,c=0,SumXY=0,sumx=sumX(),sumy=sumY(),SBQX,SBQY=0,medX=mdX(),medY=mdY(),n=qtdItens;
    //primeiro passo é calcular o desvio duplo das variaveis
    for(int i=0;i<qtdItens;i++){
        SumXY+=(amostraBiDimensional[i].first)*(amostraBiDimensional[i].second);
    }
    SumXY=SumXY*n;
    c=SumXY-(sumx*sumy);
    SBQX=(sumXQ()*n)-(pow(sumx,2));
    SBQY=(n*sumYQ())-(pow(sumy,2));
    r=c/sqrt(SBQX*SBQY);
    return r;

}
void estatistica::imprimirAmostraPair(){
    cout<<"X [";
    for(int i=0;i<qtdItens;i++){
        cout<<" "<<amostraBiDimensional[i].first;
    }
    cout<<" ]"<<endl;
     cout<<"Y [";
    for(int i=0;i<qtdItens;i++){
        cout<<" "<<amostraBiDimensional[i].second;
    }
    cout<<" ]"<<endl;
}
