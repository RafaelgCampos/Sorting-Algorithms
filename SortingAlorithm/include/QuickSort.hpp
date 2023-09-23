/**
 * @file QuickSort.hpp
 * @author Rafael
 * @brief Algoritmo de Quick Sort
 * @version 0.1
 * @date 2023-04-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>

/**
 * @brief Algoritmo de Quick Sort
 *        Divisão da lista em partes baseado no pivot, separando ao longo do caminho
 * 
 * @param lista 
 * @param inicio
 * @param fim 
 * @param indexPivot 
 */
void quickSort(int lista[], size_t inicio, size_t fim, size_t indexPivot){

    if (fim <= inicio + 1){
        return;
    }

    int *listaMenor;
    size_t fimMenor = 0;
    int *listaMaior;
    size_t fimMaior = 0;

    listaMenor = (int*) malloc ((fim - inicio) * sizeof(int));
    listaMaior = (int*) malloc ((fim - inicio) * sizeof(int));

    if (!listaMenor || !listaMaior){
        std::cout << "Erro" << std::endl;
        std::cout << "Inicio = " << inicio << std::endl;
        std::cout << "Fim = " << fim << std::endl;
        return;
    }

    for (size_t index = inicio; index < fim; index++){
        if (index == indexPivot){
            continue;
        }
        if (lista[index] <= lista[indexPivot]){
            listaMenor[fimMenor] = lista[index];
            fimMenor++;
        }
        else{
            listaMaior[fimMaior] = lista[index];
            fimMaior++;
        }
    }

    std::swap (lista[fimMenor + inicio], lista[indexPivot]);

    for (size_t index = inicio; index < fimMenor + inicio; index++){
        lista[index] = listaMenor[index - inicio];
    }
    for (size_t index = fimMenor + 1 + inicio; index < fim; index++){
        lista[index] = listaMaior[index - fimMenor - 1 - inicio];
    }

    free(listaMenor);
    free(listaMaior);

    quickSort(lista, inicio, fimMenor + inicio, inicio + (fimMenor) / 2);
    quickSort(lista, fimMenor + 1 + inicio, fim, fimMenor + 1 + inicio + (fim - fimMenor - 1 - inicio) / 2);

}

void quickSort2(int *lista, size_t inicio, size_t fim, size_t indexPivot){

    if (fim <= inicio + 1){
        return;
    }

    int pivot = lista[indexPivot];
    size_t fimMenor = inicio;

    for (size_t index = inicio; index < fim; index++){
        if (lista[index] < pivot){
            if (fimMenor == indexPivot){
                indexPivot = index;
            }
            std::swap (lista[index], lista[fimMenor]);
            fimMenor++;
        }
    }

    std::swap (lista[fimMenor], lista[indexPivot]);

    quickSort2(lista, inicio, fimMenor, inicio + (fimMenor - inicio) / 2);
    quickSort2(lista, fimMenor + 1, fim, (fimMenor + 1 + fim) / 2);
}