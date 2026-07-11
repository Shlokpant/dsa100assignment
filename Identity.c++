// Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

// Input:
// - First line: integer n representing number of rows and columns
// - Next n lines: n integers each representing the matrix elements

// Output:
// - Print "Identity Matrix" if the matrix satisfies the condition
// - Otherwise, print "Not an Identity Matrix"

// Example:
// Input:
// 3
// 1 0 0
// 0 1 0
// 0 0 1

// Output:
// Identity Matrix

// code

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int matrix[n][n];

    // Input the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    bool isIdentity = true;

    // Check identity matrix conditions
    for (int i = 0; i < n && isIdentity; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = false;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = false;
                    break;
                }
            }
        }
    }

    if (isIdentity)
        cout << "Identity Matrix";
    else
        cout << "Not an Identity Matrix";

    return 0;
}