#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>

using namespace std;

void bubbleSort(string& vet, int tam, int &comparacao, int &troca)
{  
    char aux;
        
        for(int i = 0; i < tam;i++)
    {
        for(int j = 0; j < tam - 1;j++)
        {
            comparacao++;
            if(vet[j] > vet[j + 1])
            {
                troca++;
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j+ 1] = aux;
            }
            
        }
    }
}
void selecao(string& vet, int tam, int &comparacao, int &troca)
{
    for(int i = 0; i < tam - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < tam; j++)
        {
            comparacao++;
            if(vet[j] < vet[min])
            min = j;
        }    
        if(min != 1)
        {
            troca++;
            char aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}
void insercao(string& vet, int tam, int &comparacao, int &troca)
{
    for(int j = 1; j < tam; j++)
    {
        char pivo = vet[j];
        int i = j - 1;
        while (i >= 0 && vet[i] > pivo)
        {
            comparacao++;
            vet[i+1] = vet[i];
            i = i - 1;
            troca++;
        }
    comparacao++;
    vet[i+1] = pivo;
        }        
}
void merge(string& vet, int inicio, int meio, int fim, int &comparacao, int &troca) {
    int i = inicio, j = meio + 1, k = 0;
    string temp(fim - inicio + 1, ' ');

    while (i <= meio && j <= fim) {
        comparacao++;
        if (vet[i] <= vet[j]) {
            temp[k] = vet[i];
            i++;
        }
        else {
            temp[k] = vet[j];
            j++;
        }
        troca++;
        k++;
    }

    while (i <= meio) {
        temp[k] = vet[i];
        i++;
        k++;
        troca++;
    }

    while (j <= fim) {
        temp[k] = vet[j];
        j++;
        k++;
        troca++;
    }

    for (i = inicio; i <= fim; i++) {
        vet[i] = temp[i - inicio];
    }
}
void mergeSort(string& vet, int inicio, int fim, int &comparacao, int &troca) {

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort(vet, inicio, meio, comparacao, troca);
        mergeSort(vet, meio + 1, fim, comparacao, troca);
        merge(vet, inicio, meio, fim, comparacao, troca);
    }
}
int partition(string &vet, int low, int high, int &comparacao, int &troca)
{
    char pivot = vet[high];
    int i = low - 1;
    
    for(int j = low; j <= high - 1; j++)
    {
        comparacao++;
        if(vet[j] < pivot)
        {
            i++;
            troca++;
            swap(vet[i], vet[j]);
        }
    }
    troca++;
    swap(vet[i+1], vet[high]);

    return(i+1);
}
void quickSort(string& vet, int low, int high, int &comparacao, int &troca)
{
    if(low < high)
    {
    int pi = partition(vet, low, high, comparacao, troca);
    quickSort(vet, low, pi - 1, comparacao, troca);
    quickSort(vet, pi + 1, high, comparacao, troca);
  }
}

int main()
{
    
    string vet = "ordena";
    int tam = vet.length();
    int  comparacao = 0, troca = 0;

    cout << endl << "String Original: " << vet << endl << endl;
    
    
    cout << "Implementacao BubbleSort" << endl ;
   
    bubbleSort(vet, tam, comparacao, troca);
   
    cout << "String em ordem: " << vet << endl;
    cout << "Numero de comparacoes: " << comparacao << endl;
    cout << "Numero de trocas: " << troca << endl << endl;

    vet = "ordena";
    comparacao = 0; troca = 0;

    
    cout << "Implementacao Selecao" << endl;
    
    selecao(vet, tam, comparacao, troca);
    
    cout << "String em ordem: " << vet << endl;
    cout << "Numero de comparacoes: " << comparacao << endl;
    cout << "Numero de trocas: " << troca << endl << endl;
    

    vet = "ordena";
    comparacao = 0; troca = 0;

    
    cout << "Implementacao Insercao" << endl;
    
    insercao(vet, tam, comparacao, troca);
    
    cout << "String em ordem: " << vet<< endl ;
    cout << "Numero de comparacoes: " << comparacao << endl;
    cout << "Numero de trocas: " << troca << endl << endl;
    
    vet = "ordena";
    comparacao = 0; troca = 0;
    
    
    cout << "Implementacao MergeSort" << endl;
    
    mergeSort(vet, 0, tam-1, comparacao, troca);
    
    cout << "String em ordem: " << vet<< endl ;
    cout << "Numero de comparacoes: " << comparacao << endl;
    cout << "Numero de trocas: " << troca << endl << endl;
    
    
    vet = "ordena";
    comparacao = 0; troca = 0;
    
    
    cout << "Implementacao QuickSort" << endl;
    
    quickSort(vet, 0, tam - 1, comparacao, troca);
    
    cout << "String em ordem: " << vet<< endl ;
    cout << "Numero de comparacoes: " << comparacao << endl;
    cout << "Numero de trocas: " << troca << endl << endl;

    return 0;
}