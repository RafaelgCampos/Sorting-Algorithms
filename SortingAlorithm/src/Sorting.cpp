/*
*   Arquivo para testar e comparar os algoritmos de ordenação de dados
*/

#include <iostream>
#include <time.h>
#include <random>

#include "../include/BubbleSort.hpp"
#include "../include/CountingSort.hpp"
#include "../include/DoubleSelectionSort.hpp"
#include "../include/HeapSort.hpp"
#include "../include/InsertionSort.hpp"
#include "../include/MergeSort.hpp"
#include "../include/QuickSort.hpp"
#include "../include/SelectionSort.hpp"

#define TAMANHO 100000
#define MAIOR_NUMERO 10000001

int listaDesorganizada[TAMANHO];
int listaDeNumeros[TAMANHO];

enum Algoritmos{
    SelectionSort,
    DoubleSelectionSort,
    BubbleSort,
    InsertionSort,
    MergeSort,
    QuickSort,
    HeapSort,
    CountingSort
};

/**
 * @brief Função para criar a lista desordenada
 * 
 */
void criarListaDesordenada(){

    // Colocando a "semente" de números aleatórios
    srand(time(0));

    // Loop para dar valor a todos os índices da lista
    for (size_t index = 0; index < TAMANHO; index++){
        listaDesorganizada[index] = rand() % MAIOR_NUMERO;
    }
}

void desorganizarLista(){

    for (size_t index = 0; index < TAMANHO; index++){
        listaDeNumeros[index] = listaDesorganizada[index];
    }
}

/**
 * @brief Função para verificar a ordenação crescente dos números da lista
 * 
 * @return True se a lista estiver ordenada
 * @return False se a lista não estiver ordenada
 */
bool isSorted(){

    for (size_t index = 1; index < TAMANHO; index++){
        if (listaDeNumeros[index] < listaDeNumeros[index - 1]){
            return false;
        }
    }

    return true;
}

/**
 * @brief Função para printar todos os elementos de uma lista
 * 
 * @param lista Lista de números a ser printada
 * @param inicio Índice de início da lista
 * @param fim Índice de fim da lista + 1
 *//*
void printarLista(int lista[], size_t inicio, size_t fim){

    for (size_t index = inicio; index < fim; index++){
        std::cout << lista[index] << " ";
    }
    std::cout << std::endl;

}*/

/**
 * @brief Função para escolher o algoritmo para processar
 * 
 * @param algoritmo Algoritmo a ser executado
 * @param nomeDoAlgoritmo Nome do algoritmo a ser printado
 */
void escolherAlgoritmo (Algoritmos algoritmo, const char nomeDoAlgoritmo[]){

    unsigned long tempoInicial = 0;
    unsigned long tempoFinal = 0;  

    desorganizarLista();

    std::cout << "iniciando ordenação " << nomeDoAlgoritmo << std::endl;
    tempoInicial = clock() / 1000;

    switch (algoritmo){
        case Algoritmos::SelectionSort:
            selectionSort(listaDeNumeros, TAMANHO);
            break;
        case Algoritmos::DoubleSelectionSort:
            doubleSelectionSort(listaDeNumeros, TAMANHO);
            break;
        case Algoritmos::BubbleSort:
            bubbleSort(listaDeNumeros, TAMANHO);
            break;
        case Algoritmos::InsertionSort:
            insertionSort(listaDeNumeros, TAMANHO);
            break;
        case Algoritmos::MergeSort:
            mergeSort(listaDeNumeros, 0, TAMANHO);
            break;
        case Algoritmos::QuickSort:
            quickSort(listaDeNumeros, 0, TAMANHO, TAMANHO / 2);
            break;
        case Algoritmos::HeapSort:
            heapSort(listaDeNumeros, TAMANHO);
            break;
        case Algoritmos::CountingSort:
            //heapSort2(listaDeNumeros, TAMANHO);
            quickSort2(listaDeNumeros, 0, TAMANHO, TAMANHO / 2);
            //countingSort(listaDeNumeros, TAMANHO, MAIOR_NUMERO);
            break;
    }

    tempoFinal = clock() / 1000 - tempoInicial;
    std::cout << "Finalizada ordenação em: " << tempoFinal/1000. << std::endl;

    if (isSorted()){
        std::cout << "Ordenação funcionou!" << std::endl;
    }
    else {
        std::cout << "Ordenação falhou!" << std::endl;
    }
}

/**
 * @brief Função para rodar a lógica principal do código
 * 
 * @return 0 se rodar sem problemas
 */
int main (){

    int algoritmosSelecionados[8];
    size_t quantidadeSelecionada = 0;

    criarListaDesordenada();

    //cout << "Lista desorganizada:" << endl;
    //printarLista(listaDesorganizada, 0, TAMANHO);

    std::cout << "Escolha quais algoritmos serão rodados para ordenar " << TAMANHO << " de números de 0 a " << MAIOR_NUMERO - 1 << std::endl;
    std::cout << "1. Selection Sort" << std::endl;
    std::cout << "2. Double Selection Sort" << std::endl;
    std::cout << "3. Bubble Sort" << std::endl;
    std::cout << "4. Insertion Sort" << std::endl;
    std::cout << "5. Merge Sort" << std::endl;
    std::cout << "6. Quick Sort" << std::endl;
    std::cout << "7. Heap Sort" << std::endl;
    std::cout << "8. Counting Sort" << std::endl;
    std::cout << "9. Todos" << std::endl;
    std::cout << "Digite 0 para continuar" << std::endl << std::endl;

    do{
        if (quantidadeSelecionada > 0){
            std::cout << "Algoritmos já selecionados:" << std::endl;
        }
        for (size_t index = 0; index < quantidadeSelecionada; index++){
            switch (algoritmosSelecionados[index]){
                case Algoritmos::SelectionSort:
                    std::cout << "- Selection Sort" << std::endl;
                    break;
                case Algoritmos::DoubleSelectionSort:
                    std::cout << "- Double Selection Sort" << std::endl;
                    break;
                case Algoritmos::BubbleSort:
                    std::cout << "- Bubble Sort" << std::endl;
                    break;
                case Algoritmos::InsertionSort:
                    std::cout << "- Insertion Sort" << std::endl;
                    break;
                case Algoritmos::MergeSort:
                    std::cout << "- Merge Sort" << std::endl;
                    break;
                case Algoritmos::QuickSort:
                    std::cout << "- Quick Sort" << std::endl;
                    break;
                case Algoritmos::HeapSort:
                    std::cout << "- Heap Sort" << std::endl;
                    break;
                case Algoritmos::CountingSort:
                    std::cout << "- Counting Sort" << std::endl;
                    break;
            }
        }

        std::cin >> algoritmosSelecionados[quantidadeSelecionada];
        algoritmosSelecionados[quantidadeSelecionada]--;

        if (algoritmosSelecionados[quantidadeSelecionada] == -1){
            break;
        }
        else if (algoritmosSelecionados[quantidadeSelecionada] == 8){
            quantidadeSelecionada = 8;
            for (size_t index = 0; index < quantidadeSelecionada; index++){
                algoritmosSelecionados[index] = index;
            }
            break;
        }
        else{
            quantidadeSelecionada++;
        }

    }while (algoritmosSelecionados[quantidadeSelecionada] != -1);

    for (size_t index = 0; index < quantidadeSelecionada; index++){
        switch (algoritmosSelecionados[index]){
            case Algoritmos::SelectionSort:
                escolherAlgoritmo(Algoritmos::SelectionSort, "Selection Sort");
                break;
            case Algoritmos::DoubleSelectionSort:
                escolherAlgoritmo(Algoritmos::DoubleSelectionSort, "Double Selection Sort");
                break;
            case Algoritmos::BubbleSort:
                escolherAlgoritmo(Algoritmos::BubbleSort, "Bubble Sort");
                break;
            case Algoritmos::InsertionSort:
                escolherAlgoritmo(Algoritmos::InsertionSort, "Insertion Sort");
                break;
            case Algoritmos::MergeSort:
                escolherAlgoritmo(Algoritmos::MergeSort, "Merge Sort");
                break;
            case Algoritmos::QuickSort:
                escolherAlgoritmo(Algoritmos::QuickSort, "Quick Sort");
                break;
            case Algoritmos::HeapSort:
                escolherAlgoritmo(Algoritmos::HeapSort, "Heap Sort");
                break;
            case Algoritmos::CountingSort:
                escolherAlgoritmo(Algoritmos::CountingSort, "Counting Sort");
                break;
        }
    }    

    //cout << "Lista organizada:" << endl;
    //printarLista(listaDeNumeros, 0, TAMANHO);

    return 0;
}