/**
 * @file CountingSort.hpp
 * @author Rafael
 * @brief Algoritmo de Counting Sort
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Algoritmo de Counting Sort
 *        Conta quantos elementos de cada valor existem e depois os insere em ordem
 * 
 * @param lista 
 */
void countingSort(int lista[], size_t tamanho, int maiorNumero){

    //int *numeros;
    size_t index = 0;

    //numeros = (int*) calloc (MAIOR_NUMERO, sizeof(int));

    int *numeros = new int[maiorNumero];

    for (index = 0; index < tamanho; index++){
        numeros[lista[index]]++;
    }

    index = 0;

    for (size_t indexNumero = 0; indexNumero < (size_t) maiorNumero; indexNumero++){
        for (size_t quantidadeNumero = numeros[indexNumero]; quantidadeNumero > 0; quantidadeNumero--, index++){
            lista[index] = indexNumero;
        }
    }
}