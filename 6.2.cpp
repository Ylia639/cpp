#include <iostream>
#include <algorithm>

int help() {
    std::cout << "ERROR\n";
    return 0;
}

bool varl(char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

int prov(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (!varl(argv[i])) {
            return -1;
        }
    }
    return 1;
}

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
bool comp(int a, int b) {
    return sum_of_digits(a) < sum_of_digits(b);
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    int l = prov(argc, argv);
    if (l == -1) {
        help();
        return 0;
    }
    int* numbers = new int[argc - 1];
    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    std::cout << "Введенные числа: ";
    for (int i = 0; i < argc - 1; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::sort(numbers, numbers + (argc - 1), comp);
    int* sumOfDig = new int[argc - 1];
    for (int i = 0; i < argc - 1; i++) {
        sumOfDig[i] = sum_of_digits(numbers[i]);
    }

    std::cout << "Сортированный массив суммы цифр: ";
    for (int i = 0; i < argc - 1; i++) {
        std::cout << sumOfDig[i] << " ";
    }
    std::cout << std::endl;

    int minSum = sumOfDig[0];
    int maxSum = sumOfDig[0];
    for (int i = 1; i < argc - 1; i++) {
        if (sumOfDig[i] < minSum) {
            minSum = sumOfDig[i];
        }
        if (sumOfDig[i] > maxSum) {
            maxSum = sumOfDig[i];
        }
    }

    std::cout << "Min: " << minSum << std::endl;
    std::cout << "Max: " << maxSum << std::endl;

    delete[] numbers;
    delete[] sumOfDig;

    return 0;
}

