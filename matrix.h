// matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include "vectors.h"



typedef struct {
  Vector *rows;   // An array of Vector structs
  double row_count;  // Total number of rows (height)
} Matrix;

// List your function signatures here so main can see them:
Matrix createMatrix(int row_count, int col_count);
Matrix matrixMultiplication(Matrix matrix1, Matrix matrix2);
Matrix matrixAddition(Matrix matrix1, Matrix matrix2);
Matrix findInverse(Matrix matrix);
Matrix transpose(Matrix matrix);
Matrix matrixSubtraction(Matrix matrix1, Matrix matrix2);

void freeMatrix(Matrix m);
void printMatrix(Matrix matrix);
bool isShapeMatch(Matrix matrix1, Matrix matrix2);
bool isDotProductMatch(Matrix matrix1, Matrix matrix2);
bool isSquareMatrix(Matrix matrix);
void printMatrix(Matrix matrix);
int findDeterminant(Matrix matrix);



#endif
