#include <iostream>
#include <cmath>

const int MAX_SIZE = 100;

void gauss_seidel(double mat[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], int n, double tolerance, int max_iter) {
    double x[MAX_SIZE] = {0};

    for (int iter = 0; iter < max_iter; ++iter) {
        double max_diff = 0.0;

        for (int i = 0; i < n; ++i) {
            double sum = b[i];

            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= mat[i][j] * x[j];
                }
            }

            double new_x = sum / mat[i][i];
            max_diff = std::max(max_diff, std::abs(new_x - x[i]));
            x[i] = new_x;
        }

        if (max_diff < tolerance) {
            std::cout << "Converged at iteration " << iter + 1 << std::endl;
            break;
        }
    }

    std::cout << "Solution of the system of linear equations:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
    }
}

int main() {
    // Example system of linear equations
    double mat[MAX_SIZE][MAX_SIZE] = {{4, 1, 2, 7}, {3, 5, 1, 6}, {1, 1, 3, 5}};
    int n = 3; // Number of variables
    double tolerance = 0.0001;
    int max_iter = 100;

    gauss_seidel(mat, mat[n], n, tolerance, max_iter);

    return 0;
}
