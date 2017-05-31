#include<iostream>

using namespace std;

typedef string Chave;

class Comando
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
    Comando comando;
    No* prox;
public:
    No () {
        prox = NULL;
    }

    No (Comando comando) {
        this->comando.setComando(comando);
        prox = NULL;
    }
    Comando getComando(){
        return comando;
    }
    void setComando(Comando comando) {
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

    No getUlt() const {
        return ult;
    }

    void setUlt(No *ult) {
        ult = ult;
    }
    void insere(Comando comando) {
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
    No* LSE::busca(Comando comando) {
        No* p = getPrim()->getProx();
        while (p != NULL && p->getComando().getComando() != comando.getComando()) {
            p = p->getProx();
        }
        return p;
    }
    void remove(No* r, Comando& comando){
        if (vazia() || r == NULL || r == getPrim()) {
            cout << "impossível remover\n";
        }
        else {
            comando = r->getComando();
            No* p = pred(r);
            p->setProx(r->getProx());
            if (p->getProx() == NULL) setUlt(p);
            delete r;
        }
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
