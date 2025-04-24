#include <iostream>
#include <vector>

// Diziyi heapify yapan fonksiyon (max-heap)
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;      // En büyük elemanı kök olarak başlat
    int left = 2 * i + 1; // Sol çocuk
    int right = 2 * i + 2; // Sağ çocuk
    
    // Sol çocuk kökten büyükse
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    // Sağ çocuk en büyükse
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    // En büyük eleman kök değilse
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        
        // Alt ağacı recursive olarak heapify yap
        heapify(arr, n, largest);
    }
}

// Heap Sort algoritması
void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Diziyi heap yapısına dönüştür
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // Elemanları heap'ten tek tek çıkar
    for (int i = n - 1; i > 0; i--) {
        // Kök (en büyük eleman) ile son elemanı değiştir
        std::swap(arr[0], arr[i]);
        
        // Küçülen heap üzerinde heapify çağır
        heapify(arr, i, 0);
    }
}

// Diziyi yazdıran fonksiyon
void printArray(const std::vector<int>& arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {23, 3, 5, 9, 1, 4, 7, 6, 0, 2};
    
    std::cout << "Sıralanmamış dizi: ";
    printArray(arr);
    
    heapSort(arr);
    
    std::cout << "Sıralanmış dizi: ";
    printArray(arr);
    
    return 0;
}