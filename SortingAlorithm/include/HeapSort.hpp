/**
* @file HeapSort.hpp
* @author Rafael
* @brief Algoritmo de Heap Sort
* @version 0.1
* @date 2023-04-19
* 
* @copyright Copyright (c) 2023
* 
*/

#include <iostream>
#include <cmath>

/**
 * @brief Função para printar todos os elementos de uma lista
 * 
 * @param lista Lista de números a ser printada
 * @param inicio Índice de início da lista
 * @param fim Índice de fim da lista + 1
 */
void printarLista(int lista[], size_t inicio, size_t fim){

    for (size_t index = inicio; index < fim; index++){
        std::cout << lista[index] << " ";
    }
    std::cout << std::endl;

}

/**
 * @brief Algoritmo de Heap Sort
 *        Organiza os números com base em uma ordenação de árvore binária
 * 
 * @param lista 
 * @param fim
 */
void heapSort (int lista[], size_t fim){

    if (fim <= 1){
        return;
    }

    size_t altura = 0;
    size_t coluna = 0;
    size_t indexFilhos;
/*
0 = 1
1 2 = 2
3 4|5 6 = 4
7 8|9 10|11 12|13 14 = 8
15 16|17 18|19 20|21 22|23 24|25 26|27 28|29 30 = 16
*/  

    // Deixar a árvore em max heap
    for (size_t index = 0; index < fim; index++){
        altura = (size_t) log2(index + 1);
        //std::cout << "Altura = " << altura << ", Controle da altura = " << controleAltura << std::endl;
        coluna = (index + 1) % (size_t) pow(2,altura);
        indexFilhos = (size_t) pow (2, altura + 1) - 1;
        indexFilhos += 2 * coluna;
        //std::cout << "Index = " << index << "\nAltura = " << altura << "\nColuna = " << coluna << "\nIndexFilhos = " << indexFilhos << std::endl;
        for (size_t indexFilho = 0; indexFilho < 2; indexFilho++){
            if (indexFilhos + indexFilho >= fim){
                index = fim;
                break;
            }

            if (lista[index] < lista[indexFilho + indexFilhos]){
                //cout << lista[index] << " < " << lista[indexFilhos + indexFilho] << endl;
                std::swap(lista[index], lista[indexFilho + indexFilhos]);
                //printarLista(lista, 0, fim);
                if (index == 0){
                    continue;
                }
                else{
                    // Voltando a análise para o pai
                    altura = altura - 1;
                    coluna = coluna / 2;
                    index = coluna + pow(2, altura) - 1 - 1; // Adicionando um -1 extra para ser anulado com o for
                    break;
                }  
            }

        }
    }

    std::swap (lista[0], lista[fim-1]);

    //printarLista(listaDeNumeros, 0, TAMANHO);
    //printarLista(lista, 0, fim);

    heapSort(lista, fim - 1);

}

void heapify (int lista[], size_t index, size_t fim){

    size_t indexFilhoEsquerdo = 2 * index + 1;
    size_t indexFilhoDireito = 2 * index + 2;

    if (indexFilhoEsquerdo >= fim){
        return;
    }

    if (lista[index] < lista[indexFilhoEsquerdo]){
        std::swap(lista[index], lista[indexFilhoEsquerdo]);
    }

    if (indexFilhoDireito >= fim){
        return;
    }

    if (lista[index] < lista[indexFilhoDireito]){
        std::swap(lista[index], lista[indexFilhoDireito]);
    }
}

/**
 * @brief Algoritmo de Heap Sort
 *        Organiza os números com base em uma ordenação de árvore binária
 * 
 * @param lista 
 * @param fim
 */
void heapSort2 (int lista[], size_t fim){

    if (fim <= 1){
        return;
    }

    // Deixar a árvore em max heap
    for (int index = (fim - 1) / 2; index >= 0; index--){

        heapify(lista, (size_t) index, fim);
    }

    std::swap (lista[0], lista[fim-1]);

    //printarLista(listaDeNumeros, 0, TAMANHO);
    //printarLista(lista, 0, fim);

    heapSort2(lista, fim - 1);

}