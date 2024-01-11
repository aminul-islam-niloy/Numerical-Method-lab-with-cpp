#include <iostream>

const int MAX_SIZE = 100;

void gauss_jordan(double mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        // Making the diagonal elements 1
        double pivot = mat[i][i];
        for (int j = i; j <= n * 2; j++)
            mat[i][j] /= pivot;

        // Making other elements in the column 0
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double factor = mat[k][i];
                for (int j = i; j <= n * 2; j++)
                    mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Displaying the solution
    std::cout << "Solution of the system of linear equations:" << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << "x" << i + 1 << " = " << mat[i][n] << std::endl;
}

int main() {
    // Example system of linear equations
    double mat[MAX_SIZE][MAX_SIZE] = {{2, -1, 1, 8}, {-3, -2, 1, -11}, {-2, 1, 2, -3}};
    int n = 3; // Number of variables

    gauss_jordan(mat, n);

    return 0;
}
