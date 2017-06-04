#include<iostream>

using namespace std;

typedef string Chave;

//Nó genérico
template<typename Tipo>
class No
{
private:
    Tipo x;
    No* prox;

public:
    No() {} 
	
    Tipo getItem() {
        return x;
    }
    
    void setItem(Tipo x) {
        this->x = x;
    }

    No* getProx() {
        return prox;
    }
    
    void setProx(No* prox) {
        this->prox = prox;
    }
};

template<typename Tipo>
class Pilha
{
private:
	No<Tipo> *top, *bot;
	
public:
	Pilha ();
	void empilha(Tipo);
	bool vazia();
	void desempilha(Tipo&);
	void mostra();
};

template<typename Tipo>
Pilha<Tipo>::Pilha(){
	bot = new No<Tipo>();
	top = bot;
}

template<typename Tipo>
void Pilha<Tipo>::empilha(Tipo x){
	No<Tipo> *aux = new No<Tipo>();
	top->setItem(x);
	aux->setProx(top);
	top = aux;
}

template<typename Tipo>
void Pilha<Tipo>::desempilha(Tipo& x){
	if (vazia()){
		cout << "\nPilha vazia!";
	}
	else{
		No<Tipo> *aux = top;
		top = top->getProx();
		x = top->getItem();
		delete aux;
	}
}

template<typename Tipo>
bool Pilha<Tipo>::vazia(){
	return top == bot;
}

template<typename Tipo>
void Pilha<Tipo>::mostra() { //FUNÇÃO AINDA BUGADA. LOOP INFINITO
    cout << "Pilha: topo-> ";
    for (No<Tipo> *nav = top->getProx(); nav != NULL; nav = nav->getProx()) {   	
        cout << "C";
		nav->getItem().mostra();
    }
    cout << "<- fundo\n";
}
