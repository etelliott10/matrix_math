// Matrices, matrix multiplication, shapes, transpose
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "matrix.h"


// typedef struct {
//     double *data;      // A 1D array of integers
//     int size;       // Number of elements currently inside & acts as the number of columns (width)
//     int capacity;   // Max elements it can hold before resizing
// } Vector;


// typedef struct {
//   Vector *rows;   // An array of Vector structs
//   double row_count;  // Total number of rows (height)
// } Matrix;

Matrix createMatrix (int row_count, int col_count) {
  Matrix matrix;
  matrix.row_count = row_count;

  // 1. Allocate memory for the array of Vector structs (the rows)
    matrix.rows = (Vector *)malloc(row_count * sizeof(Vector));

    // 2. Initialize each individual Vector row
    for (int i = 0; i < row_count; i++) {
        matrix.rows[i].size = col_count;
        matrix.rows[i].capacity = col_count;
        
        // Allocate the raw integer array inside the vector
        matrix.rows[i].data = (double *)malloc(col_count * sizeof(double));
    }

  return matrix;
}

void freeMatrix(Matrix m) {
    // 1. Free the inner raw integer array inside EVERY vector row first
    for (int i = 0; i < m.row_count; i++) {
        free(m.rows[i].data);
    }

    // 2. Free the outer array of Vector structs
    free(m.rows);
}

// Matrix multiplication
// Addition
// Subtraction
// Transpose
// Determinant
// Inverse

bool isShapeMatch(Matrix matrix1, Matrix matrix2);
bool isDotProductMatch(Matrix matrix1, Matrix matrix2);
bool isSquareMatrix(Matrix matrix);
void printMatrix(Matrix matrix);
Matrix matrixMultiplication(Matrix matrix1, Matrix matrix2);
Matrix matrixAddition(Matrix matrix1, Matrix matrix2);
Matrix transpose(Matrix matrix);
int findDeterminant(Matrix matrix);
Matrix findInverse(Matrix matrix);
Matrix matrixSubtraction(Matrix matrix1, Matrix matrix2);




Matrix matrixMultiplication(Matrix matrix1, Matrix matrix2)
{

  int matrix1X = matrix1.row_count;
  int matrix1Y = matrix1.rows[0].size;
  int matrix2X = matrix2.row_count;
  int matrix2Y = matrix2.rows[0].size;

  if (isDotProductMatch(matrix1, matrix2) == false)
  { 
    return createMatrix(0,0);
  } else {
  
    Matrix matrix3 = createMatrix(matrix1.row_count, matrix2.rows[0].size);

    for (int i = 0; i < matrix1X; i++)
    {
      for (int j = 0; j < matrix2Y; j++)
      {
        matrix3.rows[i].data[j] = 0;
        for (int k = 0; k < matrix1Y; k++)
        {
          matrix3.rows[i].data[j] += matrix1.rows[i].data[k] * matrix2.rows[k].data[j];
          
        }
      }
    }
    return matrix3;
  }
}

Matrix matrixAddition(Matrix matrix1, Matrix matrix2)
{ 
  if (isShapeMatch(matrix1, matrix2) == false)
  { 
    return createMatrix(0,0);
  } else {
    Matrix matrix3 = createMatrix(matrix1.row_count, matrix2.rows[0].size);

      for (int i = 0; i < matrix1.row_count; i++)
        {
          for (int j = 0; j < matrix2.rows[0].size; j++)
          {
            matrix3.rows[i].data[j] = matrix1.rows[i].data[j] + matrix2.rows[i].data[j];
          }
        }
    return matrix3;
    }
    return createMatrix(0,0);
}

Matrix matrixSubtraction(Matrix matrix1, Matrix matrix2)
{ 
  if (isShapeMatch(matrix1, matrix2) == false)
  { 
    return createMatrix(0,0);
  } else {
    Matrix matrix3 = createMatrix(matrix1.row_count, matrix2.rows[0].size);

      for (int i = 0; i < matrix1.row_count; i++)
        {
          for (int j = 0; j < matrix2.rows[0].size; j++)
          {
            matrix3.rows[i].data[j] = matrix1.rows[i].data[j] - matrix2.rows[i].data[j];
          }
        }
    return matrix3;
    }
}

Matrix transpose(Matrix matrix)
{ 
  printf("Reading transpose function...\n");
  // If the matrix has no rows, return an empty matrix
    if (matrix.row_count == 0) {
        return createMatrix(0, 0);
    }
  printf("After if\n");
  

   // Get the dimensions: new rows = old columns, new columns = old rows
    int new_rows = matrix.rows[0].size; 
    int new_cols = matrix.row_count;
  printf("After new_rows and new_cols\n");

  // Allocate the new transposed matrix structure
  Matrix matrixT = createMatrix(new_rows, new_cols);
  printf("After creating matrixT\n");

  for (int i = 0; i < new_cols; i++){
    for (int j = 0; j < new_rows; j++){
      matrixT.rows[i].data[j] = matrix.rows[j].data[i];
    }
  }
  printf("After for loops\n");

  return matrixT;
}

int findDeterminant(Matrix matrix)
{ 
  if (matrix.row_count != matrix.rows[0].size) {
    return 0;
  } else if (matrix.row_count == 1 && matrix.rows[0].size == 1) {
    return matrix.rows[0].data[0];
  }
  else if (matrix.row_count == 2 && matrix.rows[0].size == 2) {
    return matrix.rows[0].data[0] * matrix.rows[1].data[1] - matrix.rows[0].data[1] * matrix.rows[1].data[0];
  }

   else {
    int determinant = 0;
    int sign = 1;
    for (int i = 0; i < matrix.row_count; i++) {
      Matrix subMatrix = createMatrix(matrix.row_count - 1, matrix.rows[0].size - 1);
      for (int j = 1; j < matrix.row_count; j++) {
        for (int k = 0; k < matrix.rows[0].size; k++) {
          if (k < i) {
            subMatrix.rows[j - 1].data[k] = matrix.rows[j].data[k];
          } else if (k > i) {
            subMatrix.rows[j - 1].data[k - 1] = matrix.rows[j].data[k];
          }
        }
      }
     determinant += sign * matrix.rows[0].data[i] * findDeterminant(subMatrix);
     sign = -sign;
     freeMatrix(subMatrix);
    }

  return determinant;
  }
}

Matrix findInverse(Matrix matrix)
{ 
  if (matrix.row_count == 0|| matrix.rows[0].size == 0) {
    return createMatrix(0,0);
  } 
  else if (isSquareMatrix(matrix) == false){
    return createMatrix(0,0);
  }
  else {
    double determinant = findDeterminant(matrix);
    if (determinant == 0) {
      return createMatrix(0,0);
    }
    Matrix inverse = createMatrix(matrix.row_count, matrix.rows[0].size);
    int sign = 1;
    for (int i = 0; i < matrix.row_count; i++) {
      for (int j = 0; j < matrix.rows[0].size; j++) {
        Matrix subMatrix = createMatrix(matrix.row_count - 1, matrix.rows[0].size - 1);

        // --- EXTRACTION LOOP STARTS ---
        int sub_row = 0;
        for (int r = 0; r < matrix.row_count; r++) {
          if (r == i) {
            continue;
          } 
          
          int sub_col = 0;
          for (int c = 0; c < matrix.rows[0].size; c++) {
            if (c == j) {
              continue;
            }
            subMatrix.rows[sub_row].data[sub_col] = matrix.rows[r].data[c];
            sub_col++;
          }
          sub_row++;
        }
        // --- EXTRACTION LOOP ENDS ---

        // Now that the subMatrix is completely full, evaluate it!
        double sub_det = findDeterminant(subMatrix);
        
        if ((i + j) % 2 != 0) {
            sub_det = -sub_det;
        }
        
        inverse.rows[i].data[j] = sub_det;
        freeMatrix(subMatrix);
      } // Ends j loop

    }
    
    Matrix adjugate = transpose(inverse);
    freeMatrix(inverse); // Free the untransposed one so it doesn't leak!
    inverse = adjugate;  // Re-assign it
    for (int i =0; i < matrix.row_count; i++){
      for (int j = 0; j < matrix.rows[0].size; j++) {
        inverse.rows[i].data[j] = inverse.rows[i].data[j] / determinant;
      }
    }
    return inverse;
  }
}


bool isSquareMatrix(Matrix matrix){
  if (matrix.row_count != matrix.rows[0].size)
  { 
    return false;
  }
 return true;
}
bool isShapeMatch(Matrix matrix1, Matrix matrix2)
{
  if (matrix1.row_count != matrix2.row_count || matrix1.rows[0].size != matrix2.rows[0].size)
  { 
    return false;
  }
 return true;
}

bool isDotProductMatch(Matrix matrix1, Matrix matrix2)
{
  if (matrix1.rows[0].size  != matrix2.row_count)
  { 
    return false;
  }
 return true;
}

void printMatrix(Matrix matrix)
{
  for (int i = 0; i < matrix.row_count;i++){
    for (int j = 0; j < matrix.rows[0].size; j++) {
      printf("%f ", matrix.rows[i].data[j]);
    }
    printf("\n");
  }
}