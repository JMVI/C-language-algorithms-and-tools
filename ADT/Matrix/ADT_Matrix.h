/* -----------------------------------------------------------------------------
 * Copyright (C) 2021 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Matrix.h
 * Description   : Abstract Data Type for matrices. Header file.
 * Version       : 01.00
 * Revision      : 02
 * Last modified : 01/24/2021
 * -----------------------------------------------------------------------------
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//----------------------------------------------------------------------------//
//                                  Macros                                    //
//----------------------------------------------------------------------------//

// Bool data type
#define TRUE      (uint8_t)(1)
#define FALSE     (uint8_t)(0)

// Max. dimension
#define MAX_DIM (uint8_t)(100)

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Data type stored in matrix
typedef double Data;

// Vector (1-D array)
typedef Data* Vector;

// 2-D Array definition
typedef Vector* Array;

// Matrix
typedef struct matrix_struct
{
  uint8_t rows;
  uint8_t columns;
  double* determinant;
  Array matrix;
}
t_matrix;

typedef t_matrix* Matrix;

// Matrix handler
typedef struct matrix_handler
{
  Matrix  (*init)(uint8_t Rows, uint8_t Columns);            // Create Matrix
  Matrix  (*eye)(uint8_t dimension);                         // Identity Matrix
  Matrix  (*isNull)(Matrix M);                               // Null matrix?
  uint8_t (*row)(Matrix M);                                  // Get #rows
  uint8_t (*col)(Matrix M);                                  // Get #columns
  uint8_t (*det)(Matrix M, double* detval);                  // Get determinant
  uint8_t (*update)(Matrix M, Data k, uint8_t i, uint8_t j); // Update element
  uint8_t (*areEqual)(Matrix M1, Matrix M2);                 // M1 == M2?
  Matrix  (*sum)(Matrix M1, Matrix M2);                      // Matrix sum
  Matrix  (*scalar)(Data k, Matrix M);                       // Scalar product
  Matrix  (*product)(Matrix M1, Matrix M2);                  // Matrix product
  Matrix  (*pow)(Matrix M, uint8_t n);                       // Matrix power
  Matrix  (*eProduct)(Matrix M1, Matrix M2);                 // Element product
  Matrix  (*eDivision)(Matrix M1, Matrix M2);                // Element division
  Matrix  (*ePow)(Matrix M, double n);                       // Element power
  Matrix  (*inv)(Matrix M);                                  // Inverse matrix
  Matrix  (*transp)(Matrix M);                               // Transpose
  Matrix  (*minor)(Matrix M, uint8_t i, uint8_t j);          // Minor ij
  uint8_t (*cof)(Matrix M, uint8_t i, uint8_t j, double* cf);// Cofactor ij
  Matrix  (*diag)(Vector D)                                  // Diagonal matrix
  uint8_t (*del)(Matrix M);                                  // Delete matrix
}
t_MatrixHandler;

extern t_MatrixHandler Mx_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new matrix. All values as zero by default
@param  rows: Number of rows
        columns: Number of columns
@retval Pointer to new matrix
*/
extern Matrix matrix_create(uint8_t rows, uint8_t columns);

/**
@brief  Allocates memory to create a new identity matrix.
@param  dimension: Matrix dimension (n x n)
@retval Pointer to new matrix
*/
extern Matrix matrix_identity(uint8_t dimension);

/**
@brief  Verifies if matrix is null
@param  M: Pointer to matrix
@retval TRUE if matrix is null, FALSE otherwise
*/
extern uint8_t matrix_isNull(Matrix M);

/**
@brief  Gets number of rows of indicated matrix
@param  M: Pointer to matrix
@retval Number of rows
*/
extern uint8_t matrix_getRows(Matrix M);

/**
@brief  Gets number of columns of indicated matrix
@param  M: Pointer to matrix
@retval Number of columns
*/
extern uint8_t matrix_getColumns(Matrix M);

/**
@brief  Gets determinant of matrix if defined
@param  M: Pointer to matrix
        detval: Determinant value
@retval TRUE if determinant exists, FALSE otherwise
*/
extern uint8_t matrix_getDeterminant(Matrix M, double* detval);

/**
@brief  Updates a value of introduced matrix
@param  M: Pointer to matrix
        k: Data
        i: Row index
        j: Column index
@retval TRUE if element was updated, FALSE otherwise
*/
extern uint8_t matrix_update(Matrix M, Data k, uint8_t i, uint8_t j);

/**
@brief  Verifies if M1 and M2 are equal
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval TRUE if matrices are equal, FALSE otherwise
*/
extern uint8_t matrix_areEqual(Matrix M1, Matrix M2);

/**
@brief  Obtains the algebraic sum of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to sum matrix
@note   If dimensions do not match, the function returns a NULL pointer
*/
extern Matrix matrix_sum(Matrix M1, Matrix M2);

/**
@brief  Obtains the multiplication of a matrix and a scalar factor
@param  V: Pointer to matrix
        k: Scalar factor
@retval Pointer to scalated matrix
*/
extern Matrix matrix_scalar(Data k, Matrix M);

/**
@brief  Obtains the algebraic multiplication of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to product matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
extern Matrix matrix_product(Matrix M1, Matrix M2);

/**
@brief  Obtains the algebraic integer power of a matrix
@param  M: Pointer to matrix
        n: Exponent
@retval Pointer to power matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
extern Matrix matrix_power(Matrix M, uint8_t n);

/**
@brief  Obtains the element-wise multiplication of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to product matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
extern Matrix matrix_element_product(Matrix M1, Matrix M2);

/**
@brief  Obtains the element-wise division of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to division matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
extern Matrix matrix_element_division(Matrix M1, Matrix M2);

/**
@brief  Obtains the element-wise power of a matrix
@param  M: Pointer to matrix
        n: Exponent
@retval Pointer to power matrix
*/
extern Matrix matrix_element_power(Matrix M, double n);

/**
@brief  Gets inverse matrix of M if existing
@param  M: Pointer to matrix
@retval Pointer to inverse matrix 
@note Returns NULL if inverse matrix is undefined
*/
extern Matrix matrix_inverse(Matrix M);

/**
@brief  Transposes matrix M
@param  M: Pointer to matrix
@retval Pointer to transposed matrix
*/
extern Matrix matrix_transpose(Matrix M);

/**
@brief  Gets minor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
@retval Pointer to minor 
@note Returns NULL if minor is undefined
*/
extern Matrix matrix_minor(Matrix M, uint8_t i, uint8_t j);

/**
@brief  Gets cofactor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
        cof: Pointer to cofactor value
@retval TRUE if cofactor exists, FALSE otherwise
*/
extern uint8_t matrix_cofactor(Matrix M, uint8_t i, uint8_t j, double* cf);

/**
@brief  Gets minor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
@retval Pointer to minor 
@note Returns NULL if minor is undefined
*/
extern Matrix matrix_minor(Matrix M, uint8_t i, uint8_t j);

/**
@brief  Gets a matrix with vector V as main diagonal
@param  D: Main diagonal
@retval Pointer to matrix 
*/
extern Matrix matrix_diagonal(Vector D);

/**
@brief  Deletes matrix and frees allocated memory
@param  M: Pointer to matrix
@retval TRUE if matrix was deleted with no error, FALSE otherwise
*/
extern uint8_t matrix_delete(Matrix M);

/**
@brief  Prints matrix on screen
@param  M: Pointer to matrix
@retval TRUE if matrix was printed with no error, FALSE otherwise
*/
extern uint8_t matrix_print(Matrix M);

#endif

