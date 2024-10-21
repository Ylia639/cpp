#include <iostream>
#include <random>
#include <cstdlib>

const char empty = ' ';
const char fill = '+';

void ff(char* mat, int n, int m, int x, int y, char fillSymbol) {
    if (x >= 0 && x < n && y >= 0 && y < m && mat[x * m + y] == empty) {
        mat[x * m + y] = fillSymbol;
        ff(mat, n, m, x, y + 1, fillSymbol);
        ff(mat, n, m, x, y - 1, fillSymbol);
        ff(mat, n, m, x + 1, y, fillSymbol);
        ff(mat, n, m, x - 1, y, fillSymbol);
    }
}

void printMatrix(char* mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << mat[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void a(char* mat, int n, int m, int& e, int& fc, int& b) {
    e = 0;
    fc = 0;
    b = 0;

    for (int i = 0; i < n * m; i++) {
        if (mat[i] == empty) {
            e++;
        }
        else if (mat[i] == fill) {
            fc++;
        }
        else {
            b++;
        }
    }
}

template <typename T>
bool check(T& value) {
    std::cin >> value;
    if (std::cin.fail()) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);
    int n, m, b;
    char f;

    std::cout << "Введите размеры матрицы (n, m): ";
    while (!check(n) || !check(m)) {
        std::cout << "Ошибка ввода. Пожалуйста, введите два целых числа: ";
    }

    std::cout << "Введите вероятность появления блока: ";
    while (!check(b)) {
        std::cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
    }

    std::cout << "Введите символ для заполнения: ";
    std::cin >> f;

    char* mat = new char[n * m];
    for (int i = 0; i < n * m; i++) {
        mat[i] = empty;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dis(gen) < b) {
                mat[i * m + j] = fill;
            }
        }
    }
    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(mat, n, m);

    int x, y;
    std::cout << "Введите координаты (x, y) для начала заливки: ";
    while (!check(x) || !check(y) || x < 0 || x >= n || y < 0 || y >= m) {
        std::cout << "Ошибка ввода. Пожалуйста, введите корректные координаты (x, y): ";
    }

    if (mat[x * m + y] == fill) {
        std::cout << "Выбрана ячейка с блоком, заливка невозможна." << std::endl;
        delete[] mat; 
        return 1;
    }

    ff(mat, n, m, x, y, f);

    std::cout << "Матрица после заливки:" << std::endl;
    printMatrix(mat, n, m);

    int emptyCount, fillCount, blockCount;
    a(mat, n, m, emptyCount, fillCount, blockCount);
    std::cout << "Пустые ячейки: " << emptyCount << std::endl;
    std::cout << "Количество заполнений: " << fillCount << std::endl;
    std::cout << "Блокированные ячейки: " << blockCount << std::endl;

    delete[] mat; 
    return 0;
}
