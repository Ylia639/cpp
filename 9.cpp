#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept> 

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        if (rows <= 0 || cols <= 0) {

        }
        data.resize(rows, std::vector<int>(cols));
    }
    void read(std::ifstream& file) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!(file >> data[i][j])) {

                }
            }
        }
    }
    Matrix transpose() const {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }
    double cal() const {
        int z = 0;
        int total = rows * cols;

        for (const auto& row : data) {
            for (int value : row) {
                if (value == 0) {
                    z++;
                }
            }
        }
        return (static_cast<double>(z) / total) * 100;
    }
    void writeToFile(const std::string& filename, const Matrix& transposed,  double sparsity, bool append = true) const {
        std::ofstream outFile(filename, append ? std::ios::app : std::ios::trunc);
        if (!outFile) {
        }

        outFile << "Исходная матрица:" << std::endl;
        for (const auto& row : data) {
            for (int value : row) {
                outFile << value << " ";
            }
            outFile << std::endl;
        }

        outFile << "Транспонированная матрица:" << std::endl;
        for (const auto& row : transposed.data) {
            for (int value : row) {
                outFile << value << " ";
            }
            outFile << std::endl;
        }
        outFile << "Степень разреженности матрицы: " << sparsity << "%" << std::endl;
    }
    void print() const {
        for (const auto& row : data) {
            for (int value : row) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    try {
        std::ifstream file("C:\\Users\\Мой ПК\\OneDrive\\Desktop\\9.txt");
        if (!file) {
        }

        int rows, cols;
        if (!(file >> rows >> cols)) {

        }
        Matrix matrix(rows, cols);
        matrix.read(file);

        file.close();
        std::cout << "Исходная матрица:" << std::endl;
        matrix.print();
        Matrix transp = matrix.transpose();

        std::cout << "Транспонированная матрица:" << std::endl;
        transp.print();

        double sparsity = transp.cal();
        std::cout << "Степень разреженности матрицы: " << sparsity << "%" << std::endl;
        matrix.writeToFile("C:\\Users\\Мой ПК\\OneDrive\\Desktop\\9 results.txt", transp, sparsity);

    }
    catch (const std::exception& e) {

    }

    return 0;
}
