#include<iostream>

using namespace std;

typedef string Chave;

class Comando
{
public:
    Chave comando;
    Comando(){
    }
    Comando(Chave comando)
    {
        this->comando = comando;
    }
    void print()
    {
        cout << comando;
    }
};

class No
{
public:
    Comando linha;
    No* prox;

    No()
    {
        prox = NULL;
    }

    No(Comando linha) {
        this->linha = linha;
        prox = NULL;
    }
};

class Lista
{
public:
    No *prim, *ult;

    Lista ()
    {
        prim = new No();
        prim->prox = NULL;
        ult = prim;
    }
    void insere(Comando linha)
    {
        ult->prox = new No();
        ult = ult->prox;
        ult->prox = NULL;
        ult->linha = linha;
    }
    No* pred(No* r)
    {
        No* p = prim->prox;
        while (p->prox != r)
        {
            p = p->prox;
        }
        return p;
    }
    No* busca(Comando linha)
    {
        No* p = prim->prox;
        while (p != NULL && p->linha.comando != linha.comando)
        {
            p = p->prox;
        }
        return p;
    }
    void print()
    {
        No* p = prim->prox;
        while (p != NULL)
        {
            p->linha.print();
            p = p->prox;
            cout << endl;
        }
    }
};
int main()
{
    string entrada;
    bool valida = true;
    Comando txt;
    Lista bancoDados = Lista();
    cout<< "Informe uma string: " << endl;
    while(valida)
    {
        #recebe uma entrada e enquanto o valida for true, continua o looping
        getline(cin,entrada);
        if(entrada != "~")
        {
            txt = Comando(entrada);
            bancoDados.insere(txt);
        }else
        {
            valida = false;
        }
    }
    /*O codigo de baixo é so para se vocês quiserem ver a lista
    pode ser adaptado mais tarde também*/
    #cout << "---------------------" << endl;
    #bancoDados.print();
}
