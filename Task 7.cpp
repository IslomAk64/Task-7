#include "Sort.h"
#include "Benchmark.h"
#include "vectorGenerator.h"
#include <iostream>
#include <vector>

int main() {
    size_t size = 5000;

    std::vector<int> randomVector = generateRandomVector<int>(size);
    std::vector<int> sortedVector = generateSortedVector<int>(size);
    std::vector<int> reverseSortedVector = generateSortedReverseVector<int>(size);

    auto relation = [](int a, int b) {
        return a < b;
        };

    Benchmark<std::chrono::microseconds> benchmark;

    std::vector<int> v1 = randomVector;
    benchmark.start();
    bubbleSort(v1, relation);
    auto duration1 = benchmark.elapsed();
    std::cout << "Classical Bubble Sort (Random) took: " << duration1.count() << " microseconds." << std::endl;

    std::vector<int> v2 = randomVector;
    benchmark.start();
    bubbleSortReduced(v2, relation);
    auto duration2 = benchmark.elapsed();
    std::cout << "Reduced Bubble Sort (Random) took: " << duration2.count() << " microseconds." << std::endl;

    std::vector<int> v3 = randomVector;
    benchmark.start();
    bubbleSortWithFlag(v3, relation);
    auto duration3 = benchmark.elapsed();
    std::cout << "Bubble Sort with Flag (Random) took: " << duration3.count() << " microseconds." << std::endl;

    std::vector<int> v4 = sortedVector;
    benchmark.start();
    bubbleSort(v4, relation);
    auto duration4 = benchmark.elapsed();
    std::cout << "Classical Bubble Sort (Sorted) took: " << duration4.count() << " microseconds." << std::endl;

    std::vector<int> v5 = sortedVector;
    benchmark.start();
    bubbleSortReduced(v5, relation);
    auto duration5 = benchmark.elapsed();
    std::cout << "Reduced Bubble Sort (Sorted) took: " << duration5.count() << " microseconds." << std::endl;

    std::vector<int> v6 = sortedVector;
    benchmark.start();
    bubbleSortWithFlag(v6, relation);
    auto duration6 = benchmark.elapsed();
    std::cout << "Bubble Sort with Flag (Sorted) took: " << duration6.count() << " microseconds." << std::endl;

    std::vector<int> v7 = reverseSortedVector;
    benchmark.start();
    bubbleSort(v7, relation);
    auto duration7 = benchmark.elapsed();
    std::cout << "Classical Bubble Sort (Reverse Sorted) took: " << duration7.count() << " microseconds." << std::endl;

    std::vector<int> v8 = reverseSortedVector;
    benchmark.start();
    bubbleSortReduced(v8, relation);
    auto duration8 = benchmark.elapsed();
    std::cout << "Reduced Bubble Sort (Reverse Sorted) took: " << duration8.count() << " microseconds." << std::endl;

    std::vector<int> v9 = reverseSortedVector;
    benchmark.start();
    bubbleSortWithFlag(v9, relation);
    auto duration9 = benchmark.elapsed();
    std::cout << "Bubble Sort with Flag (Reverse Sorted) took: " << duration9.count() << " microseconds." << std::endl;

    return 0;
}