<p align="center">
  <img src="https://raw.githubusercontent.com/emreoztemiz-ai-ml/heapsort/b8e1ca188c52833bb2f0d6529331ce215a874ad9/heapsort.svg" alt="HeapSihirbazi SVG" width="500">
</p>

# Heap Sort Algoritması

## 📚 Algoritmanın Tanımı

Heap Sort, verimli ve kararlı bir karşılaştırma tabanlı sıralama algoritmasıdır. Binary heap veri yapısını kullanarak elemanları sıralar. İlk olarak diziyi bir max-heap (veya min-heap) olarak düzenler, ardından en büyük elemanı (max-heap kullanıldığında) dizinin sonuna yerleştirir ve heapify işlemini küçültülmüş heap üzerinde tekrar eder. Bu işlem, tüm dizi sıralanana kadar devam eder.

Heap Sort, büyük veri kümeleriyle çalışırken tercih edilen bir algoritma olup, özellikle bellek kısıtlaması olan sistemlerde kullanışlıdır çünkü sıralama işlemini yerinde (in-place) gerçekleştirir ve önemli ölçüde ekstra bellek gerektirmez.

## 🏷️ Algoritma Kategorisi

- **Karşılaştırma Tabanlı Sıralama Algoritması**
- **Yığın(Heap) ve Yığın Sıralama(Heap Sort)** 
- **Yerinde (In-place) Sıralama**
- **Binary Heap Temelli**
- **Kararlı Olmayan (Unstable) Sıralama**

## ⚙️ Çözüm Yaklaşımı

### Zaman Karmaşıklığı
- **En İyi Durum**: O(n log n)
- **Ortalama Durum**: O(n log n)
- **En Kötü Durum**: O(n log n)

Heap Sort'un en önemli özelliklerinden biri, tüm durumlarda O(n log n) zaman karmaşıklığına sahip olmasıdır. Bu, algoritmanın giriş dizisinin durumundan bağımsız olarak tutarlı performans göstermesini sağlamaktadır.
Neden O(n log n) adımda biter? Çünkü ekleme ya da çıkarma dahi yapılsa Heap te bulunan elemanların hiç birisi ile muhatap olmaz, atadan ataya en kısa yoldan yani maksimum derinlik kadar gider, tepeye doğru giden bu yol yani derinlik formülü ise O(n log n) dir. [Youtube ta paylaşılmış güzel bir anlatım bırakıyorum](https://www.youtube.com/watch?v=HYLiT2wffUE&t=390s)

### Uzay Karmaşıklığı
- **Auxiliary Space**: O(1)
Introduction to Algorithms isimli kitapta 396. Sf. da Zamanda ve mekanda önemli önemli asimptotik tasarruf sağladığından bahsetmektedir. Asimptotik verimlilik, bir algoritmanın girdi boyutu sonsuza doğru büyüdükçe nasıl performans gösterdiğini ifade eder.
Heap Sort, yerinde (in-place) çalışır ve sabit miktarda ekstra bellek kullanır. Bu özellik, büyük veri setleriyle çalışırken önemli bir avantaj sağlar.

## 🕒 Ne Zaman ve Neden Kullanılır?

Heap Sort şu durumlarda tercih edilir:

1. **Bellek Kısıtlaması Varsa**: Yerinde (in-place) çalıştığı ve ek bellek gerektirmediği için bellek sınırlı ortamlarda idealdir.
2. **Sabit Zaman Sınırlaması Gerektiğinde**: Her durumda O(n log n) zaman karmaşıklığı garanti ettiği için, performans tutarlılığının önemli olduğu durumlarda tercih edilir.
3. **En Kötü Durum Performansı Önemliyse**: Quick Sort gibi bazı algoritmalar en kötü durumda O(n²) performans gösterirken, Heap Sort her zaman O(n log n) karmaşıklığını korur.
4. **Öncelik Kuyruğu Uygulamalarında**: Heap veri yapısı, öncelik kuyruklarının uygulanmasında kullanılır. Heap Sort, bu yapı üzerine inşa edildiği için, öncelik kuyruğu tabanlı uygulamalarda pratik bir seçimdir.

## 🔄 Algoritmanın Adımları

1. **Heap Oluşturma (Build Heap)**:
   - Verilen diziyi binary heap yapısına dönüştür.
   - Bu işlem için dizinin ortasından başlayarak geriye doğru her elemanı heapify işlemine tabi tut.

2. **Heapify İşlemi**:
   - Belirli bir düğümü ve alt ağaçlarını heap özelliklerine uymak için düzenle.
   - Max-heap için, ebeveyn düğüm her zaman çocuklarından büyük olmalıdır.

3. **Sıralama**:
   - Heap'in kök düğümü (en büyük eleman) ile dizinin son elemanını değiştir.
   - Heap boyutunu bir azalt.
   - Yeni kök düğümüne heapify işlemi uygula.
   - Bu adımları heap boşalana kadar tekrarla.

## 🌟 Kullanım Örnekleri

1. **Veritabanı Sistemleri**: Büyük veri setlerini sıralamak için kullanılır.
2. **İşletim Sistemleri**: Süreç önceliklerini yönetmek için.
3. **Grafik Algoritmaları**: Dijkstra ve Prim algoritmaları gibi öncelik kuyruğu gerektiren grafik algoritmalarında.
4. **Dış Sıralama (External Sorting)**: Bellek kapasitesinden daha büyük dosyaları sıralamak için.
5. **Medyan ve k. en büyük eleman bulma**: Heap yapısı kullanılarak verimli şekilde gerçekleştirilebilir.

## ✅ Avantajlar ve Dezavantajlar

### Avantajlar
- **Tutarlı Performans**: Her durumda O(n log n) zaman karmaşıklığı sunar.
- **Bellek Verimliliği**: Yerinde (in-place) çalışır, ek bellek alanı gerektirmez.
- **Öncelik Kuyruğu Entegrasyonu**: Heap veri yapısı, öncelik kuyrukları için doğal bir temel sağlar.
- **Büyük Veri Setleri**: Bellek kısıtlaması olan ortamlarda büyük veri setlerini sıralamak için uygundur.

### Dezavantajlar

- ***Algorithms*, Fourth Edition Kitap sf.342, PDF sf.355**: Kullanım yönü ile diğer sıralamalara göre kullanım alanı özellikle aynı değere sahip elemanların sırasını korumaz, yani kararlı değil (Unstable). 
- **Pratik Uygulamalarda Yavaşlık**: Genellikle Quick Sort ve Merge Sort gibi diğer O(n log n) algoritmalardan daha yavaş çalışır, çünkü sabit faktörleri daha yüksektir.
- **Önbellek Kullanımı**: Heap yapısı, rastgele erişim modeliyle çalıştığından, modern CPU önbelleklerinde verimsiz olabilir.
- **Uygulaması Karmaşık**: Quicksort gibi bazı alternatiflere göre uygulaması daha karmaşıktır.

## 💻 Heap Sort Test Uygulaması

```cpp
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
```

## 🧪 Senaryo Dosyası

Senaryo dosyası olarak aşağıdaki kodu kullanabilirsiniz. Bu kod, Heap Sort algoritmasının çeşitli senaryolarda hangi tepkiler verdiğini incelememizi sağlamaktadır.

```cpp
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

// Test fonksiyonu
void testHeapSort() {
    // Test Case 1: Karışık sıralı dizi
    std::vector<int> test1 = {23, 3, 5, 9, 1, 4, 7, 6, 0, 2};
    std::cout << "Test 1 - Karışık dizi:" << std::endl;
    std::cout << "Sıralanmamış: ";
    printArray(test1);
    heapSort(test1);
    std::cout << "Sıralanmış: ";
    printArray(test1);
    std::cout << std::endl;
    
    // Test Case 2: Ters sıralı dizi
    std::vector<int> test2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::cout << "Test 2 - Ters sıralı dizi:" << std::endl;
    std::cout << "Sıralanmamış: ";
    printArray(test2);
    heapSort(test2);
    std::cout << "Sıralanmış: ";
    printArray(test2);
    std::cout << std::endl;
    
    // Test Case 3: Zaten sıralı dizi
    std::vector<int> test3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Test 3 - Zaten sıralı dizi:" << std::endl;
    std::cout << "Sıralanmamış: ";
    printArray(test3);
    heapSort(test3);
    std::cout << "Sıralanmış: ";
    printArray(test3);
    std::cout << std::endl;
    
    // Test Case 4: Tekrarlanan elemanlar içeren dizi
    std::vector<int> test4 = {5, 2, 7, 2, 5, 8, 3, 7, 5};
    std::cout << "Test 4 - Tekrarlanan elemanlar içeren dizi:" << std::endl;
    std::cout << "Sıralanmamış: ";
    printArray(test4);
    heapSort(test4);
    std::cout << "Sıralanmış: ";
    printArray(test4);
}

int main() {
    testHeapSort();
    return 0;
}
```

## 🔗 Kaynaklar

- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein. *Introduction to Algorithms*, Third Edition. MIT Press, 2009.
- Robert Sedgewick and Kevin Wayne. *Algorithms*, Fourth Edition. Addison-Wesley Professional, 2011. 
- [Heap Sort - GeeksforGeeks](https://www.geeksforgeeks.org/heap-sort/)
- [Binary Heap - Wikipedia](https://en.wikipedia.org/wiki/Binary_heap)
- [Sadi Evren Şeker YT](https://www.youtube.com/@Sadievrenseker_BK)
- [Markdown Kullanımı](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

:man_technologist: :blush: Bilgi paylaştıkça çoğalır. :blush: :man_technologist: Bu arada görülen emojiler için  [Markdown da kullanılabilecek Emoji Listesi ](https://github.com/ikatyang/emoji-cheat-sheet/blob/master/README.md#symbols)
