#include <iostream>
#include <fstream>
#include <vector>

int main() {
    
    std::ifstream file("C:\\Users\\Мой ПК\\OneDrive\\Desktop\\result.txt");
    if (!file) {
        return 1;
    }
    int rows, cols;
    file >> rows;
    file >> cols;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
        }
    }
    file.close(); 

    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    for (const auto& row : transposed) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    std::ofstream outFile("C:\\Users\\Мой ПК\\OneDrive\\Desktop\\result.txt", std::ios::app); // открываем файл в режиме добавления
    if (!outFile) {
    
        return 1;
    }
    outFile << "\n" << cols << std::endl; 
    outFile << rows << std::endl; 
    for (const auto& row : transposed) {
        for (int value : row) {
            outFile << value << " ";
        }
        outFile << std::endl;
    }

    outFile.close();

    return 0;
}
