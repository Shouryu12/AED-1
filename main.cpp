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
    No () {
        prox = NULL;
    }

    No (ListaComandos comando) {
        this->comando.setComando(comando);
        prox = NULL;
    }
    ListaComandos getComando(){
        return comando;
    }
    void setComando(ListaComandos comando) {
        this->comando = comando;
    }
    No *getProx() {
        return prox;
    }
    void setProx(No *prox) {
        this->prox = prox;
    }
};

class LSE
{
private:
    No *prim, *ult;
public:
    LSE () {
        prim = new No();
        prim->setProx(NULL);
        ult = prim;
    }
    No *getPrim() const {
        return prim;
    }

    void setPrim(No *prim) {
        prim = prim;
    }

    No getUlt(){
        return ult;
    }

    void setUlt(No *ult) {
        ult = ult;
    }
    void insere(ListaComandos comando) {
        getUlt().setProx(new No());
        getUlt().getProx();
        getUlt().setProx(NULL);
        getUlt().setComando(comando);
    }
    No* pred(No* r) {
        No* p = getPrim()->getProx();
        while (p->getProx() != r) {
            p = p->getProx();
        }
        return p;
    }
    bool vazia() {
        return getPrim() == getUlt();
    }
    No* LSE::busca(ListaComandos comando) {
        No* p = getPrim()->getProx();
        while (p != NULL && p->getComando().getComando() != comando.getComando()) {
            p = p->getProx();
        }
        return p;
    }
    void print() {
        No* p = getPrim()->getProx();
        while (p != NULL) {
            p->getComando().print();
            p = p->getProx();
            cout << endl;
        }
    }

int main()
{
    string entrada;
    cout<< "Informe uma string: " << endl;
    while(getline(cin,entrada) && entrada != "~")
    {
        cout << entrada << endl ;
    }
    return 0;
}
