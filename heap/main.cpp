#include <iostream>
#include <string>
#include <math.h>
#include "heap.h"

int main()
{
    Heap hp(9);
    hp.insere(39);
    hp.insere(95);
    hp.insere(78);
    hp.insere(60);
    hp.insere(28);
    hp.insere(66);
    hp.insere(70);
    hp.insere(33);


    std::cout << "O maior elemento: " << hp.seleciona_maior() << std::endl;
    std::cout << "Imprimindo a Heap " << std::endl;
    hp.imprime();

    return 0;
}