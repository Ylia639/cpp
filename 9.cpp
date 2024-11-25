#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>
#include <iostream>
#include <iomanip>

using namespace std;

class Matrix {
private:
    vector<int> data;
    size_t rows;
    size_t cols;

public:
    Matrix() : rows(0), cols(0) {}

    bool loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        string line;
        while (getline(file, line)) {
            vector<int> row;
            stringstream ss(line);
            int value;

            while (ss >> value) {
                row.push_back(value);
            }

            if (!row.empty()) {
                if (cols == 0) {
                    cols = row.size();
                }
                for (const auto& val : row) {
                    data.push_back(val);
                }
                ++rows;
            }
        }
        file.close();
        return true;
    }

    void transpose() {
        vector<int> transposedData(cols * rows, 0); 
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                transposedData[j * rows + i] = get(i, j);
            }
        }

        swap(data, transposedData); 
        swap(rows, cols);
    }

    double sparsity() const {
        size_t total_elements = rows * cols;
        size_t non_zero_count = 0;

        for (const auto& value : data) {
            if (value != 0) {
                ++non_zero_count;
            }
        }

        return (static_cast<double>(total_elements - non_zero_count) / total_elements) * 100; 
    }

    void set(size_t row, size_t col, int value) {
        if (row < rows && col < cols) {
            data[row * cols + col] = value;
        }
    }

    int get(size_t row, size_t col) const {
        if (row < rows && col < cols) {
            return data[row * cols + col];
        }
        return 0;
    }

    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }

    void print() const { 
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                cout << setw(5) << get(i, j) << ' ';
            }
            cout << endl;
        }
    }

    void writeToFile(const string& filename) const {
        ofstream file(filename, ios::app); 
        if (!file.is_open()) {
            return;
        }

        file << "\nTransposed Matrix:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                file << setw(5) << get(i, j) << ' ';
            }
            file << endl;
        }

        double sparsityPercent = this->sparsity();
        file << "\nSparsity of the matrix: " << sparsityPercent << "%\n";
        file.close();
    }
};

int main() {
    string filename = "C:\\Users\\Мой ПК\\OneDrive\\Desktop\\9.txt";
    Matrix matrix;

    if (!matrix.loadFromFile(filename)) {
        return 1;
    }

    cout << "Original Matrix:\n";
    matrix.print();
    matrix.transpose();
    matrix.writeToFile(filename);

    return 0;
}
