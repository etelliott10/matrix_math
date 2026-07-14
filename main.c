#include <stdio.h>
#include "matrix.h" // Links main.c to your Vector and Matrix structures

// Helper function to quickly populate your dynamic matrices in test cases
void fillMatrix(Matrix m, double values[]) {
    int index = 0;
    for (int i = 0; i < m.row_count; i++) {
        for (int j = 0; j < m.rows[i].size; j++) {
            m.rows[i].data[j] = values[index++];
        }
    }
}

int main() {
    printf("=== TESTING YOUR MATRIX LIBRARY SYSTEM ===\n\n");

    // ----------------------------------------------------
    // TEST 1: Creation and Matrix Addition / Subtraction
    // ----------------------------------------------------
    Matrix A = createMatrix(2, 2);
    Matrix B = createMatrix(2, 2);
    
    double valA[] = {1.0, 2.0, 3.0, 4.0};
    double valB[] = {5.0, 6.0, 7.0, 8.0};
    fillMatrix(A, valA);
    fillMatrix(B, valB);

    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);

    Matrix C_add = matrixAddition(A, B);
    printf("Addition (A + B):\n");
    printMatrix(C_add);

    Matrix C_sub = matrixSubtraction(B, A);
    printf("Subtraction (B - A):\n");
    printMatrix(C_sub);

    // ----------------------------------------------------
    // TEST 2: Matrix Transposition & Multiplication
    // ----------------------------------------------------
    Matrix T_input = createMatrix(2, 3);
    double valT[] = {1, 2, 3, 4, 5, 6};
    fillMatrix(T_input, valT);
    printf("Original 2x3 Matrix:\n");
    printMatrix(T_input);

    Matrix T_output = transpose(T_input);
    printf("Transposed 3x2 Matrix:\n");
    printMatrix(T_output);

    // Multiply a (2x3) matrix by a (3x2) matrix -> resulting in a (2x2) matrix
    Matrix Mult_result = matrixMultiplication(T_input, T_output);
    printf("Multiplication (2x3 * 3x2):\n");
    printMatrix(Mult_result);

    // ----------------------------------------------------
    // TEST 3: Recursive Determinant & Matrix Inverse
    // ----------------------------------------------------
    Matrix Inv_input = createMatrix(3, 3);
    double valInv[] = {
        1, 0, 2,
        2, -1, 3,
        4, 1, 8
    };
    fillMatrix(Inv_input, valInv);
    printf("3x3 Matrix for Advanced Math:\n");
    printMatrix(Inv_input);

    double det = findDeterminant(Inv_input);
    printf("Calculated Determinant: %.2f\n\n", det);

    Matrix Inverse_result = findInverse(Inv_input);
    printf("Calculated Inverse Matrix:\n");
    printMatrix(Inverse_result);

    // The Grand Finale: A matrix multiplied by its inverse yields the Identity Matrix
    Matrix Identity_check = matrixMultiplication(Inv_input, Inverse_result);
    printf("Verification (Matrix * Its Inverse) -> Identity Matrix:\n");
    printMatrix(Identity_check);

    // ----------------------------------------------------
    // TEST 4: MEMORY CLEANUP (The Baton Pass rule)
    // ----------------------------------------------------
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C_add);
    freeMatrix(C_sub);
    freeMatrix(T_input);
    freeMatrix(T_output);
    freeMatrix(Mult_result);
    freeMatrix(Inv_input);
    freeMatrix(Inverse_result);
    freeMatrix(Identity_check);

    printf("=== TESTING COMPLETE. ALL MEMORY SAFELY WIPED FROM HEAP ===\n");
    return 0;
}
