#include <iostream>
#include <string.h>
using namespace std;

string entrada []={"B :","    PRINT 6","    A"};
string funcoes  [10];
string print [10];
string chamadadeFuncao[10];

 
  void interpretador(){
     int tamanho,j;
     string numero = "";
     for (int i=0;i<3;i++){
        tamanho = entrada[i].size();
        if(tamanho == 3)
        {
            cout<< "tipo = Funcao "<<endl;
            cout<< entrada[i]<< endl;
        }else if(tamanho >= 11)
        {
            j = 10;
            while(j <= tamanho)
            {
                numero += entrada[i][j];
                j++;
            }
            numero += "  ";
        }else if(tamanho == 5)
        {
            cout<<"tipo = Chamada de funcao"<< endl;
            cout<<entrada[i]<<endl;
        }else if(tamanho == 0)
        {
            cout<<"linha em branco"<<endl;
        }
     }
 } 
 int main(){
 	interpretador();
	 
 }
