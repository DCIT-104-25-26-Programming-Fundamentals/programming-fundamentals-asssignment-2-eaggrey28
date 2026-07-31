// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns,
                const string& name) {
    cout << "Enter elements for matrix " << name << ":" << endl;

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << "Enter element [" << row << "][" << column << "]: ";
            cin >> matrix[row][column];
        }
    }
}

void displayMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cout << setw(5) << matrix[row][column];
        }
        cout << endl;
    }
}

void transposeMatrix(const int matrix[MAX_SIZE][MAX_SIZE],
                     int transposed[MAX_SIZE][MAX_SIZE],
                     int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            transposed[column][row] = matrix[row][column];
        }
    }
}

void addMatrices(const int first[MAX_SIZE][MAX_SIZE],
                 const int second[MAX_SIZE][MAX_SIZE],
                 int result[MAX_SIZE][MAX_SIZE],
                 int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            result[row][column] = first[row][column] + second[row][column];
        }
    }
}

void multiplyMatrices(const int first[MAX_SIZE][MAX_SIZE],
                      const int second[MAX_SIZE][MAX_SIZE],
                      int result[MAX_SIZE][MAX_SIZE],
                      int firstRows, int sharedSize, int secondColumns) {
    for (int row = 0; row < firstRows; row++) {
        for (int column = 0; column < secondColumns; column++) {
            result[row][column] = 0;

            for (int index = 0; index < sharedSize; index++) {
                result[row][column] +=
                    first[row][index] * second[index][column];
            }
        }
    }
}

bool validDimension(int dimension) {
    return dimension > 0 && dimension <= MAX_SIZE;
}

int main() {
    int rows;
    int columns;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    cout << "PART A - Transpose a Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;

    if (!validDimension(rows) || !validDimension(columns)) {
        cout << "Error: Dimensions must be between 1 and 10." << endl;
        return 0;
    }

    readMatrix(matrixA, rows, columns, "A");

    cout << endl << "Original Matrix:" << endl;
    displayMatrix(matrixA, rows, columns);

    transposeMatrix(matrixA, result, rows, columns);
    cout << endl << "Transposed Matrix:" << endl;
    displayMatrix(result, columns, rows);

    cout << endl << "PART B - Add Two Matrices" << endl;
    readMatrix(matrixA, rows, columns, "A");
    readMatrix(matrixB, rows, columns, "B");
    addMatrices(matrixA, matrixB, result, rows, columns);

    cout << endl << "Sum Matrix:" << endl;
    displayMatrix(result, rows, columns);

    int firstRows;
    int sharedSize;
    int secondColumns;

    cout << endl << "PART C - Multiply Two Matrices" << endl;
    cout << "Enter rows for matrix A: ";
    cin >> firstRows;
    cout << "Enter columns for matrix A / rows for matrix B: ";
    cin >> sharedSize;
    cout << "Enter columns for matrix B: ";
    cin >> secondColumns;

    if (!validDimension(firstRows) || !validDimension(sharedSize) ||
        !validDimension(secondColumns)) {
        cout << "Error: Dimensions must be between 1 and 10." << endl;
        return 0;
    }

    readMatrix(matrixA, firstRows, sharedSize, "A");
    readMatrix(matrixB, sharedSize, secondColumns, "B");
    multiplyMatrices(matrixA, matrixB, result, firstRows, sharedSize,
                     secondColumns);

    cout << endl << "Product Matrix:" << endl;
    displayMatrix(result, firstRows, secondColumns);

    return 0;
}
