#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "ArvAVL.h"

using namespace std;

ArvAVL::ArvAVL()
{
    raiz = NULL;
}

ArvAVL::~ArvAVL()
{
   raiz = libera(raiz); 
   cout << "Arvore Liberada" << endl;
}

NoArv* ArvAVL::libera(NoArv *p)
{
    if (p != NULL)
{
p->setEsq(libera(p->getEsq()));
p->setDir(libera(p->getDir()));
delete p;
p = NULL;
}
return NULL;
}

void ArvAVL::insere(int val)
{
    raiz = auxInsere(raiz, val);
}

NoArv* ArvAVL::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    
    else 
        if(val < p->getInfo())
            p->setEsq(auxInsere(p->getEsq(), val));
        else
            p->setDir(auxInsere(p->getDir(), val));
        
        cout << p->getInfo();

        int f = altura(p->getDir()) - altura(p->getEsq());
        NoArv *q = p->getDir();
        NoArv *r = p->getEsq();
        int fD = altura(q->getDir()) - altura(q->getEsq());
        int fE = altura(r->getDir()) - altura(r->getEsq());

        if(f == 2 )
        {
            if(fD == 1 || fD == 0)
            {
                rotSimplesEsquerda(p);
            }
            else if(fD == -1)
            {
                rotacionaDuplaEsquerda(p);
            }
        }
        else if(f == -2)
        {
            if(fE == -1 || fE == 0)
            {
                rotacionaSimplesDireita(p);
            }
            else if(fE == 1)
            {
                rotacionaDuplaDireita(p);
            }
        }
    
    return p;
}

void ArvAVL::rotacionaSimplesDireita(NoArv *p)
{
    NoArv *q;
    q = p->getEsq();
    p->setEsq(q->getDir());
    q->setDir(p);
}

void ArvAVL::rotSimplesEsquerda(NoArv *p)
{
    NoArv *q;
    q = p->getDir();
    p->setDir(q->getEsq());
    q->setEsq(p);

}

void ArvAVL::rotacionaDuplaDireita(NoArv *p)
{
    NoArv *q;
    NoArv *r;
    q = p->getEsq();
    r = q->getDir();
    p->setEsq(r->getDir());
    q->setDir(r->getEsq());
    r->setDir(p);
    r->setEsq(q);
}

void ArvAVL::rotacionaDuplaEsquerda(NoArv *p)
{
    NoArv *q = p->getDir();
    NoArv *r = q->getEsq();
    p->setDir(r->getEsq());
    q->setEsq(r->getDir());
    r->setEsq(p);
    r->setDir(q);
}

void ArvAVL::imprime()
{
    cout << "Arvore Binaria em Pre-Ordem: ";
    auxImprime(raiz);
}

void ArvAVL::auxImprime(NoArv *p)
{
    if (p != NULL)
    {
        auxImprime(p->getEsq());
        cout << p->getInfo() << " ";
        auxImprime(p->getDir());
    }
}

int ArvAVL::altura(NoArv *p)
{
     int he, hd;
     if(p == NULL)
     {
         return -1;
     }
     else{
        he = altura(p->getEsq());
        hd = altura(p->getDir());

     return 1 + (he > hd ? he : hd);
     }
}
