#include <iostream>
using namespace std;

// Structure to store a sparse matrix element
struct Element {
    int row;
    int col;
    int value;
};

class SparseMatrix {
private:
    int rows, cols, numNonZero;
    Element* elements;

public:
    // Constructor
    SparseMatrix(int r, int c, int n) {
        rows = r;
        cols = c;
        numNonZero = n;
        elements = new Element[n];
    }

    // Destructor
    ~SparseMatrix() {
        delete[] elements;
    }

    // Input non-zero elements
    void read() {
        cout << "Enter row, column, and value for " << numNonZero << " non-zero elements:\n";
        for (int i = 0; i < numNonZero; i++) {
            cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }

    // Display sparse matrix in triplet form
    void displayTriplet() {
        cout << "Row\tCol\tValue\n";
        for (int i = 0; i < numNonZero; i++) {
            cout << elements[i].row << "\t" << elements[i].col << "\t" << elements[i].value << endl;
        }
    }

    // Display full matrix
    void displayFull() {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (k < numNonZero && elements[k].row == i && elements[k].col == j) {
                    cout << elements[k].value << " ";
                    k++;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols, numNonZero;
    cout << "Enter number of rows, cols, and non-zero elements: ";
    cin >> rows >> cols >> numNonZero;

    SparseMatrix sm(rows, cols, numNonZero);

    sm.read();

    cout << "\nSparse Matrix (Triplet Form):\n";
    sm.displayTriplet();

    cout << "\nFull Matrix Representation:\n";
    sm.displayFull();

    return 0;
}
