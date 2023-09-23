/**
 * @file DoubleSelectionSort.hpp
 * @author Rafael
 * @brief Algoritmo de Double Selection Sort
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Função para fazer selection sort usando ambas as extremidades
 * 
 */
void doubleSelectionSort(int lista[], size_t tamanho){

    // Variáveis temporárias de controle
    int menor;
    int maior;

    for (size_t i = 0; i < tamanho - 1; i++){
        menor = lista[i];
        maior = lista[tamanho - 1 - i];
        for (size_t index = i + 1; index < tamanho - i; index++){
            if (lista[index] < menor){
                std::swap(lista[index], menor);
            }
            if (lista[index] > maior){
                std::swap(lista[index], maior);
            }
        }
        lista[i] = menor;
        lista[tamanho - 1 - i] = maior;
    }

}
