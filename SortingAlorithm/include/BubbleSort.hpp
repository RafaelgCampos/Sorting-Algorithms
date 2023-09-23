/**
 * @file BubbleSort.hpp
 * @author Rafael
 * @brief Algoritmo de Bubble Sort
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Algoritmo de Bubble Sort
 *        Passagens pela lista ordenando aos pares por todas as passagens
 * 
 */
void bubbleSort(int lista[], size_t tamanho){

    bool isOrdered;

    do{
        isOrdered = true;
        for (size_t index = 1; index < tamanho; index++){
            if (lista[index] < lista[index - 1]){
                std::swap (lista[index], lista[index-1]);
                isOrdered = false;
            }
        }
    }while (!isOrdered);
}