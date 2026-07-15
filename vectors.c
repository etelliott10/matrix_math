#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "vectors.h"


void printVector(Vector vector);

Vector addVectors(Vector vectorA, Vector vectorB);
Vector subtractVectors(Vector vectorA, Vector vectorB);
Vector scaleVectors(Vector vectorA, Vector vectorB);

double findMagnitude(Vector vector);
double findDotProduct(Vector vectorA, Vector vectorB);
double findCosineSimilarity(Vector vectorA, Vector vectorB);

bool sizeMatch(Vector vectorA, Vector vectorB);

Vector createVector(int size) {
  Vector vector;
  vector.size = size;
  vector.capacity = size;
  vector.data = (double *)malloc(size * sizeof(double));
  return vector;
}

void freeVector(Vector vector) {
  free(vector.data);
}

Vector addVectors(Vector vectorA, Vector vectorB) {

  if (sizeMatch(vectorA, vectorB) == false) {
    return createVector(0);
  }
  int size = vectorA.size;

  Vector vectorC = createVector(size);
  
  for (int i = 0; i < size; i++) {
    vectorC.data[i] = vectorA.data[i] + vectorB.data[i];
  }
  return vectorC;
}

Vector subtractVectors(Vector vectorA, Vector vectorB) {

  if (sizeMatch(vectorA, vectorB) == false) {
    return createVector(0);
  }
  Vector vectorC = createVector(vectorA.size);
  
  for (int i = 0; i < vectorA.size; i++) {
    vectorC.data[i] = vectorA.data[i] - vectorB.data[i];
  }
  return vectorC;
}

Vector scaleVectors(Vector vectorA, Vector vectorB) {
  
  if (sizeMatch(vectorA, vectorB) == false) {
    return createVector(0);
  }

  int size = vectorA.size;
  Vector vectorC = createVector(size);

  for (int i = 0; i < size; i++) {
    vectorC.data[i] = vectorA.data[i] * vectorB.data[i];
  }
  return vectorC;
}

double findMagnitude(Vector vector) {
  
  int magnitude = 0;

  for (int i =0; i < vector.size;i++) {
    magnitude += pow(vector.data[i],2);
  }

  magnitude = sqrt(magnitude);

  return magnitude;
}
 
double findDotProduct(Vector vectorA, Vector vectorB) {
  if (sizeMatch(vectorA, vectorB) == false) {
    return 0.0;
  }

  int dotProduct = 0;
  for (int i = 0; i < vectorA.size; i++) {
    dotProduct += vectorA.data[i] * vectorB.data[i];
  }
  return dotProduct;
}

double findCosineSimilarity(Vector vectorA, Vector vectorB) {
  if (sizeMatch(vectorA, vectorB) == false) {
    return 0.0;
  }

  double dotProduct = findDotProduct(vectorA, vectorB);

  double magnitudeA = findMagnitude(vectorA);
  double magnitudeB = findMagnitude(vectorB);

  double cosineSimilarity = dotProduct / (magnitudeA * magnitudeB);

  return cosineSimilarity;
}

bool sizeMatch(Vector vectorA, Vector vectorB) {
  if (vectorA.size != vectorB.size) {
    return false;
  }
  return true;
}

void printVector(Vector vector) {
  for (int i = 0; i < vector.size; i++) {
    printf("%f ", vector.data[i]);
  }
  printf("\n");
}