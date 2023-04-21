#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include "heap.h"

Heap::Heap(int tamanho)
{
    tam = tam;    
    hp = new int[tam];
    n_elementos = 0;
}

Heap::~Heap()
{
    delete [] hp;
}

int Heap::seleciona_maior()
{
    return hp[0];
}

void Heap::insere(int val)
{
    if(n_elementos <= tam)
    {
      hp[n_elementos] = val;

      subir(n_elementos);

      n_elementos++;  
    } 
    
    else std::cout << "Heap Cheia" << std::endl;
}

void Heap::descer(int n, int i)
{
    int maior = i; // índice do maior elemento
    int left = i * 2 + 1; // índide do filho à esquerda
    int right = i * 2 + 2;// índide do filho à direita

    if(left <= n && hp[left] < hp[maior])   maior = left;
    if(right <= n && hp[right] > hp[maior]) maior = right;

    if(maior != i)
    {
        std::swap(hp[i], hp[maior]);
        descer(n, maior);
    }
}

void Heap::subir(int i)
{
    int ind_pai = (i - 1) / 2;

    if(ind_pai >= 0)
    {
        if(hp[i] > hp[ind_pai])
        {
            std::swap(hp[ind_pai], hp[i]);
            subir(ind_pai);
        }
    }
}

int Heap::remove()
{
    if(n_elementos < 1){ std::cout << "ERRO: Heap Underflow" << std::endl; exit(1);}

    int max = hp[maior_elemento];
    hp[0] = hp[n_elementos - 1];
    n_elementos -= 1;
    descer(n_elementos - 1, maior_elemento);

    return max;
}

void Heap::imprime()
{
    for(int i = 0; i < n_elementos; i++)
        std::cout << hp[i] << "; " ;
    
    std::cout << std::endl;
}