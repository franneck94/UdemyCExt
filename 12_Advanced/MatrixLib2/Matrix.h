#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdint.h>

#include "Vector.h"

/**********************/
/* DEFINES AND TYPES  */
/**********************/

typedef struct
{
    float *data;
    size_t num_rows;
    size_t num_cols;
} Matrix;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);

Matrix *freeMatrix(Matrix *matrix);

/**********************/
/*  HELPER FUNCTIONS  */
/**********************/

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);

size_t matrixNumElements(const Matrix *const matrix);

bool matrixSameSize(const Matrix *const matrix1, const Matrix *const matrix2);

bool matrixMultiplyPossible(const Matrix *const matrix1, const Matrix *const matrix2);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printMatrix(const Matrix *matrix);

/**********************/
/*  MATH FUNCTIONS    */
/**********************/

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);

#endif // MATRIX_H
