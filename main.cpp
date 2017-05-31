#include<iostream>

using namespace std;

typedef string Chave;

class ListaComandos
{
private:
    Chave comando;
public:
    Chave getComando(){
        return getComando();
    }
    void setComando(Chave comando)
    {
        this->comando = comando;
    }
    void print(){
        cout << comando;
    }
};

class No
{
private:
    ListaComandos comando;
    No* prox;
public:
    ListaComandos getComando()
    {
        return comando;
    }
    void setComando(ListaComandos comando)
    {
        this->comando = comando;
    }
    No *getProx()
    {
        return prox;
    }
    void setProx(No *prox)
    {
        this->prox = prox;
    }
    No ()
    {
        setProx(NULL);
    }

    No (ListaComandos comando)
    {
        setComando(comando);
        setProx(NULL);
    }

};

class LSE
{
private:
    No *prim, *ult;
public:
    LSE ()
    {
        prim = new No();
        prim->setProx(NULL);
        ult = prim;
    }
    No *getPrim()
    {
        return prim;
    }

    void setPrim(No *prim)
    {
        prim = prim;
    }

    No *getUlt()
    {
        return ult;
    }

    void setUlt(No *ult)
    {
        ult = ult;
    }
    void insere(ListaComandos comando)
    {
        getUlt()->setProx(new No());
        getUlt()->getProx();
        getUlt()->setProx(NULL);
        getUlt()->setComando(comando);
    }
    No* pred(No* r)
    {
        No* p = getPrim()->getProx();
        while (p->getProx() != r)
        {
            p = p->getProx();
        }
        return p;
    }
    No* busca(ListaComandos comando)
    {
        No* p = getPrim()->getProx();
        while (p != NULL && p->getComando().getComando() != comando.getComando())
        {
            p = p->getProx();
        }
        return p;
    }
    void print()
    {
        No* p = getPrim()->getProx();
        while (p != NULL)
        {
            p->getComando().print();
            p = p->getProx();
            cout << endl;
        }
    }
};
int main()
{
    string entrada, lista[250];
    bool valida = true;
    int i = 0;
    cout<< "Informe uma string: " << endl;
    while(valida)
    {
        getline(cin,entrada);
        if(entrada != "~")
        {
            lista[i] = entrada;
            i++;
        }else
        {
            valida = false;
        }
    }

}
