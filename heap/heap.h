#include <iostream>
#include <string>
#include <math.h>


class Heap
{
    public:
    Heap(int tam); // Construtor
    ~Heap();
    int seleciona_maior();
    void insere(int val);
    int remove();
    void imprime();
    
    private:
    int n_elementos;
    int* hp;
    int tam;
    int maior_elemento = 0;
    void descer(int n_elementos, int maior_elemento);
    void subir(int i);
};