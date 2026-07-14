#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main() {
  int *vectorA = (int *)malloc(10 * sizeof(int));
  int *vectorB = (int *)malloc(10 * sizeof(int));
  int *vectorC = (int *)malloc(10 * sizeof(int));

  int matrix = 0;
}


int addVectors(int *vectorA, int *vectorB, int *vectorC, int size) {
  for (int i = 0; i < size; i++) {
    vectorC[i] = vectorA[i] + vectorB[i];
  }
  return 0;
}

int scaleVectors(int *vectorA, int *vectorB, int *vectorC, int size) {
  for (int i = 0; i < size; i++) {
    vectorC[i] = vectorA[i] * vectorB[i];
  }
  return 0;
}

int findMagnitude(int *vector, int size) {
  int magnitude = 0;

  for (int i =0; i < size;i++) {
    magnitude += pow(vector[i],2);
  }

  magnitude = sqrt(magnitude);

  return magnitude;
}

int findCosineSimilarity(int *vectorA, int *vectorB, int size) {
  int dotProduct = 0;
  int magnitudeA = findMagnitude(vectorA, size);
  int magnitudeB = findMagnitude(vectorB, size);
  int cosineSimilarity = 0;
  return cosineSimilarity;
}
  
int findDotProduct(int *vectorA, int *vectorB, int size) {
  int dotProduct = 0;
  for (int i = 0; i < size; i++) {
    dotProduct += vectorA[i] * vectorB[i];
  }
  return dotProduct;
}
