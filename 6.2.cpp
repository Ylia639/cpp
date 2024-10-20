#include <iostream>
#include <random>
#include <algorithm>
int help()
{
    std::cout << "ERROR\n";
    return 0;
}
bool varl(char* str) {
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]) && str[i] != ' ') {
            return false;
        }
    }    return true;
}
int prov(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) {
        if (!varl(argv[i])) {
            return -1;
        }
    }
    return 1;
}
int* sort(int argc, char* argv[]) {
    int* n = new int[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        n[i - 1] = atoi(argv[i]);
    }
    std::sort(n, n + argc - 1);
    return n;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    int l = prov(argc, argv);
    if (l == -1)
    {
        help();
        return 0;
    }
    std::cout << "Введенные числа: ";
    for (int i = 1; i < argc; i++)
    {
        int a = atoi(argv[i]);
        std::cout << a << " ";
    }
    std::cout << std::endl;
    int* sortarr = sort(argc, argv);
    int* sumOfDig = new int[argc - 1];
    for (int j = 0; j < argc - 1; j++)
    {
        int temp = sortarr[j];
        int c = 0;
        while (temp > 0)
        {
            int digit = temp % 10;
            c += digit;
            temp /= 10;
        }
        sumOfDig[j] = c;
    }
    std::cout << "Отсортированный массив: ";
    for (int j = 0; j < argc - 1; j++)
    {
        std::cout << sortarr[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Массив сумм цифр: ";
    for (int j = 0; j < argc - 1; j++)
    {
        std::cout << sumOfDig[j] << " ";
    }
    std::cout << std::endl;

    std::cout << "Min: " << sumOfDig[0] << std::endl;

    int f = argc - 1;
    for (int i = 0; i <= f - 1; i++) {
        if (i = f - 1) {

            std::cout << "Max: " << sumOfDig[i];
        }
    }
    delete[] sortarr;
    delete[] sumOfDig;

    return 0;
}
