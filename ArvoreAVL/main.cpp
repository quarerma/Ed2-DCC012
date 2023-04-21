#include <iostream>
#include "ArvAVL.h"
using namespace std;

int main()
{
    ArvAVL arv;
    arv.insere(5);
    arv.insere(7);
    arv.insere(6);
    arv.insere(10);
    arv.insere(1);
    arv.insere(2);
    arv.insere(3);
    
    arv.imprime();

    return 0;
}