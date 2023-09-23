/**
 * @file MergeSort.hpp
 * @author Rafael
 * @brief Algoritmo de Merge Sort
 * @version 0.1
 * @date 2023-04-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Algoritmo de Merge Sort.
 *        Separando a lista na metade recursivamente, e ordenando ao juntar as partes
 * 
 * @param lista Lista a ser ordenada
 * @param inicio Índice de início da lista
 * @param fim Índice de fim da lista + 1 (marcação de fim após o fim da lista)
 */
void mergeSort(int *lista, size_t inicio, size_t fim){

    if (fim - inicio <= 1){
        return;
    }

    size_t meio = inicio + (fim - inicio) / 2. + 0.5;

    mergeSort(lista, inicio, meio);
    mergeSort(lista, meio, fim);

    //cout << "Lista merge:" << endl;
    //printarLista(lista, inicio, fim);

    size_t sortingIndex;
    size_t quantidade = 0;

    for (size_t index = inicio; index < meio && meio + quantidade <= fim; index++){
        if (lista[index + quantidade] <= lista[meio + quantidade]){
            //cout << lista[meio+quantidade] << " > " << lista[index + quantidade] << endl;
            continue;
        }
        //cout << lista[meio + quantidade] << " < " << lista[index + quantidade] << endl;
        std::swap (lista[meio + quantidade], lista[index + quantidade]);
        //printarLista(lista, inicio, fim);
        for (sortingIndex = meio + quantidade + 1; sortingIndex < fim; sortingIndex++){
            if (lista[sortingIndex] < lista[sortingIndex-1]){
                std::swap (lista[sortingIndex], lista[sortingIndex-1]);
                //printarLista(lista, inicio, fim);
            }
            else{         
                break;
            }
        }
        for (size_t n = sortingIndex - 1 - meio - quantidade; n > 0; quantidade++, n--){
            //cout << "Sorting Index = " << sortingIndex << endl;
            //cout << "Index = " << index << endl;
            //cout << "Quantidade = " << quantidade << ", Meio = " << meio << ", Fim = " << fim <<endl;
            if (quantidade + meio >= fim){
                return;
            }
            for (size_t i = index + quantidade + 1; i < meio + quantidade; i++){
                //cout << "Trocando: " << lista[meio+quantidade] << " " << lista[i] << endl;
                std::swap (lista[meio + quantidade], lista[i]);
                //printarLista(lista, inicio, fim);
            }
        }
        if (quantidade + meio >= fim){
            return;
        }
    }
}