#include <stdio.h>
#include <iostream>

void swap(int* a, int* b);
int partition(int arr[], int low, int high, int& swap_count) {
    std::cout << "l: " << low << " h: " << high << std::endl;
    int pivot = arr[high];
    int i = low - 1;
    int swaps = 0;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            swaps++;
            swap_count++;
        }
    }
    std::cout << "pivot[" << high << "]= " << pivot << '\n';
    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
    swap(&arr[i + 1], &arr[high]);
    swaps++;
    swap_count++;
    std::cout << " Swaps: " << swaps << std::endl;
    std::cout << std::endl;
    return i + 1;

}

void quickSort(int arr[], int low, int high, int& swap_count) {
    if (low < high) {
        int pi = partition(arr, low, high, swap_count);
        quickSort(arr, low, pi - 1, swap_count);
        quickSort(arr, pi + 1, high, swap_count);
    }

}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    setlocale(LC_ALL, "rus");
    int arr[] = { 2, 3, 5, 8, 6, 4, 7, 1, 9, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int swap_count = 0;

    quickSort(arr, 0, n - 1, swap_count);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    std::cout << "\nОбщее количество swap-ов: " << swap_count << std::endl;
    return 0;
}
