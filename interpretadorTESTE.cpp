#include <iostream>
#include <string.h>
using namespace std;

string entrada []={"B :","    PRINT 6","    A"};
string funcoes  [10];
string print [10];
string chamadadeFuncao[10];

 
 void interpretador(){
 	 for (int i=0;i<3;i++){
 		int tamanho = entrada[i].size();
		switch (tamanho){
	  case  3 :
 	 	 cout<< "tipo : Funcao "<<endl;
 	 	 cout<< entrada[i]<< endl;
 	 	 break;
		 
   	  case  11 : 
  	  	  cout<<"tipo: print "<<endl;
  	  	  cout<< entrada[i] <<endl;
  	  	  break;
	   case 5:
		  cout<<"tipo: Chamada de funcao"<< endl;
		  cout<<entrada[i];
	  	  break;
  	  case 0:
  	  	cout<<"linha em branco";
	 	 break;
 	 	 }
 	 }
 }
 
 int main(){
 	interpretador();
	 
 }