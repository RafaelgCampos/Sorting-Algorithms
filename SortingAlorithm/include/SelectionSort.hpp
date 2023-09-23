/**
* @file SelectionSort.hpp
* @author Rafael
* @brief Algoritmo de Selection Sort
* @version 0.1
* @date 2023-04-19
* 
* @copyright Copyright (c) 2023
* 
*/


#include <iostream>

/**
 * @brief Algoritmo de Selection Sort
 *        Ordenando os números adicionando os menores no início da lista
 * 
 */
void selectionSort(int lista[], size_t tamanho){

    // Variáveis temporárias de controle
    int menor;

    for (size_t i = 0; i < tamanho - 1; i++){
        menor = lista[i];
        for (size_t index = i + 1; index < tamanho; index++){
            if (lista[index] < menor){
                std::swap (lista[index], menor);
            }
        }
        lista[i] = menor;
    }

}