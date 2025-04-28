#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {

//check that the operator < is well defined	
template<typename T>
concept Sortable = requires(T& t) {
    {t < t} -> convertible_to<bool>;
};

template<Sortable T>
void BubbleSort(vector<T>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
		}
	}
}




template<Sortable T>
void heapify(vector<T>& arr, int n, int i) {
    int largest = i;          // nodo radice
    int left    = 2*i + 1;    // figlio sinistro
    int right   = 2*i + 2;    // figlio destro

    // se il figlio sinistro è più grande della radice
    if (left < n && arr[largest] < arr[left]) {
        largest = left;
    }
    // se il figlio destro è più grande del massimo finora
    if (right < n && arr[largest] < arr[right]) {
        largest = right;
    }
    // se il massimo non è la radice, scambia e continua a heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap-sort 
template<Sortable T>
void HeapSort(vector<T>& arr) {
    size_t n = arr.size();

    //max-heap
    for (int i = n/2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    //Estrazione un elemento alla volta dall’heap
    for (int i = n - 1; i > 0; --i) {
        //sposta la radice (massimo) in fondo
        std::swap(arr[0], arr[i]);
        //ricostruisce l’heap ridotto
        heapify(arr, i, 0);
    }
}


}


