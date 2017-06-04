#include<iostream>

using namespace std;

typedef string Chave;

class Comando
{
public:
    Chave comando;
    Comando(){}
    Comando(Chave comando)
    {
        this->comando = comando;
    }
    void print();
};

void Comando:: print()
{
    cout << comando;
}

//Nó genérico
template<typename Tipo>
class No
{
public:
    Tipo x;
    No* prox;

    No()
    {
        prox = NULL;
    }

    No(Tipo x) {
        this->x = x;
        prox = NULL;
    }
};

template<typename Tipo>
class Lista
{
public:
    No<Tipo> *prim, *ult;

    Lista ()
    {
        prim = new No<Tipo>();
        prim->prox = NULL;
        ult = prim;
    }
    void insere(Tipo linha);
    No<Tipo>* pred(No<Tipo> *r);
    No<Tipo>* busca(Tipo linha);
    void print();
};

template<typename Tipo>
void Lista<Tipo>::insere(Tipo linha)
{
    ult->prox = new No<Tipo>();
    ult = ult->prox;
    ult->prox = NULL;
    ult->x = linha;
};

template<typename Tipo>
No<Tipo>* Lista<Tipo>::pred(No<Tipo> *r)
{
    No<Tipo>* p = prim->prox;
    while (p->prox != r)
    {
        p = p->prox;
    }
    return p;
};

template<typename Tipo>
No<Tipo>* Lista<Tipo>::busca(Tipo linha)
{
    No<Tipo>* p = prim->prox;
    while (p != NULL && p->linha.comando != linha.comando)
    {
        p = p->prox;
    }
    return p;
};

template<typename Tipo>
void Lista<Tipo>::print()
{
    No<Tipo>* p = prim->prox;
    while (p != NULL)
    {
        p->x.print();
        p = p->prox;
        cout << endl;
    }
};

int main()
{
    string entrada;
    bool valida = true;
    Comando txt;
    Lista<Comando> bancoDados = Lista<Comando>();
    cout<< "Informe uma string: " << endl;
    while(valida)
    {
        //recebe uma entrada e enquanto o valida for true, continua o looping
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
    //cout << "---------------------" << endl;
    //bancoDados.print();
}
