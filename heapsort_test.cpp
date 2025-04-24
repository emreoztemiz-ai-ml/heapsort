#include <iostream>
#include <vector>
#include <string>

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

// Test senaryolarını çalıştıran fonksiyon
void runTest(int testCase) {
    // Test senaryoları için diziler
    std::vector<std::vector<int>> testArrays = {
        {23, 3, 5, 9, 1, 4, 7, 6, 0, 2},           // Test 1: Karışık sayılar
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},           // Test 2: Ters sıralı
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},           // Test 3: Zaten sıralı
        {5, 2, 7, 2, 5, 8, 3, 7, 5, 1},            // Test 4: Tekrarlı elemanlar
        {100, 50, 75, 25, 60, 10, 80, 90, 40, 30}, // Test 5: Büyük sayılar
        {-5, -2, -10, -1, -8, -7, -3, -9, -4, -6}, // Test 6: Negatif sayılar
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},            // Test 7: Az sayıda farklı değer
        {42}                                       // Test 8: Tek elemanlı dizi
    };
    
    // Test senaryoları açıklamaları
    std::vector<std::string> testDescriptions = {
        "Karışık sayılar",
        "Ters sıralı dizi",
        "Zaten sıralı dizi",
        "Tekrarlı elemanlar içeren dizi",
        "Büyük sayılar içeren dizi",
        "Negatif sayılar içeren dizi",
        "Az sayıda farklı değer içeren dizi",
        "Tek elemanlı dizi"
    };
    
    // Geçerli test senaryosu kontrolü
    if (testCase < 1 || testCase > testArrays.size()) {
        std::cout << "Geçersiz test senaryosu!" << std::endl;
        return;
    }
    
    // İndeksi ayarla (kullanıcı 1-8 girerken, dizi indeksi 0-7)
    testCase -= 1;
    
    // Test açıklaması
    std::cout << "\n--- Test " << (testCase + 1) << ": " << testDescriptions[testCase] << " ---\n";
    
    // Test dizisini al
    std::vector<int> arr = testArrays[testCase];
    
    // Sıralanmamış diziyi göster
    std::cout << "Sıralanmamış dizi: ";
    printArray(arr);
    
    // Heap Sort uygula
    heapSort(arr);
    
    // Sıralanmış diziyi göster
    std::cout << "Sıralanmış dizi: ";
    printArray(arr);
    
    // Doğrulama yaparak sıralamanın doğru olduğunu kontrol et
    bool isSorted = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i-1]) {
            isSorted = false;
            break;
        }
    }
    
    // Sonucu bildir
    std::cout << "\nSıralama sonucu: " << (isSorted ? "DOĞRU ✓" : "HATALI ✗") << std::endl;
}

int main() {
    int choice;
    
    std::cout << "╔══════════════════════════════════════════╗" << std::endl;
    std::cout << "║          HEAP SORT TEST PROGRAMI         ║" << std::endl;
    std::cout << "╚══════════════════════════════════════════╝" << std::endl;
    std::cout << std::endl;
    
    // Test senaryolarının listesi
    std::cout << "Mevcut test senaryoları:" << std::endl;
    std::cout << "1. Karışık sayılar" << std::endl;
    std::cout << "2. Ters sıralı dizi" << std::endl;
    std::cout << "3. Zaten sıralı dizi" << std::endl;
    std::cout << "4. Tekrarlı elemanlar içeren dizi" << std::endl;
    std::cout << "5. Büyük sayılar içeren dizi" << std::endl;
    std::cout << "6. Negatif sayılar içeren dizi" << std::endl;
    std::cout << "7. Az sayıda farklı değer içeren dizi" << std::endl;
    std::cout << "8. Tek elemanlı dizi" << std::endl;
    std::cout << "0. Çıkış" << std::endl;
    
    // Kullanıcı arayüzü döngüsü
    do {
        std::cout << "\nLütfen test etmek istediğiniz senaryo numarasını girin (1-8, Çıkış için 0): ";
        std::cin >> choice;
        
        if (choice == 0) {
            std::cout << "Program sonlandırılıyor..." << std::endl;
            break;
        } 
        else if (choice >= 1 && choice <= 8) {
            runTest(choice);
        } 
        else {
            std::cout << "Geçersiz seçim! Lütfen 0-8 arasında bir değer girin." << std::endl;
        }
        
    } while (true);
    
    return 0;
}