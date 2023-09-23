/**
 * @file InsertionSort.hpp
 * @author Rafael
 * @brief Algoritmo de Insertion Sort
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Algoritmo de Insertion Sort.
 *        Implementando Selection sort com a lógica do Bubble Sort
 * 
 */
void insertionSort(int lista[], size_t tamanho){

    for (size_t index = 1; index < tamanho; index++){
        if (lista[index] < lista[index-1]){
            std::swap (lista[index], lista[index-1]);
            for (size_t insertionIndex = index - 1; insertionIndex > 0; insertionIndex--){
                if (lista[insertionIndex] < lista[insertionIndex-1]){
                    std::swap (lista[insertionIndex], lista[insertionIndex-1]);
                }
                else{
                    break;
                }
            }
        }
    }
}