/* -----------------------------------------------------------------------------
 * Copyright (C) 2021 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Matrix.h
 * Description   : Abstract Data Type for matrices.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 01/17/2021
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

// Matrix
typedef struct matrix_struct
{
  uint8_t rows;
  uint8_t columns;
  Vector* matrix;
}
t_matrix;

typedef t_matrix* Matrix;

// Matrix handler
typedef struct matrix_handler
{
  Matrix  (*init)(uint8_t Rows, uint8_t Columns);            // Create Matrix
  Matrix  (*eye)(uint8_t Rows, uint8_t Columns);             // Identity Matrix
  Matrix  (*isNull)(Matrix M);                               // Null matrix?
  uint8_t (*row)(Matrix M);                                  // Get #rows
  uint8_t (*col)(Matrix M);                                  // Get #columns
  uint8_t (*update)(Matrix M, Data k, uint8_t i, uint8_t j); // Update element
  uint8_t (*areEqual)(Matrix M1, Matrix M2);                 // M1 == M2?
  Matrix  (*sum)(Matrix M1, Matrix M2);                      // Matrix sum
  Matrix  (*scalar)(Data k, Matrix M);                       // Scalar product
  Matrix  (*product)(Matrix M1, Matrix M2);                  // Matrix product
  Matrix  (*eProduct)(Matrix M1, Matrix M2);                 // Element product
  Matrix  (*eDivision)(Matrix M1, Matrix M2);                // Element division
  uint8_t (*del)(Matrix M);                                  // Delete matrix
}
t_MatrixHandler;

extern t_MatrixHandler Mx_Hdlr;

/*TODO: Complete function prototypes */
// Transpose
// Inverse matrix
// Determinant
// Cofactor
// Minor
// Boolean matrix (compare matrices)
// Element power
// Algebraic power
// Create triangular matrix
// (Other element-wise functions)

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
@param  rows: Number of rows
        columns: Number of columns
@retval Pointer to new matrix
*/
extern Matrix matrix_identity(uint8_t rows, uint8_t columns);

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
