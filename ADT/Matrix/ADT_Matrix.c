/* -----------------------------------------------------------------------------
 * Copyright (C) 2021 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Matrix.c
 * Description   : Abstract Data Type for matrices. Library file.
 * Version       : 01.00
 * Revision      : 01
 * Last modified : 01/24/2021
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Matrix.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Vector handler
t_MatrixHandler Mx_Hdlr =
{
  matrix_create,            // Create Matrix
  matrix_identity,          // Identity Matrix
  matrix_isNull,            // Null matrix?
  matrix_getRows,           // Get #rows
  matrix_getColumns,        // Get #columns
  matrix_getDeterminant,    // Get determinant
  matrix_update,            // Update element
  matrix_areEqual,          // M1 == M2?
  matrix_sum,               // Matrix sum
  matrix_scalar,            // Scalar product
  matrix_product,           // Matrix product
  matrix_power,             // Matrix power
  matrix_element_product,   // Element product
  matrix_element_division,  // Element division
  matrix_element_power,     // Element power
  matrix_inverse,           // Inverse matrix
  matrix_transpose,         // Transpose
  matrix_minor,             // Minor ij
  matrix_cofactor,          // Cofactor ij
  matrix_diagonal,          // Diagonal matrix
  matrix_delete             // Delete matrix
};


//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new matrix. All values as zero by default
@param  rows: Number of rows
        columns: Number of columns
@retval Pointer to new matrix
*/
Matrix matrix_create(uint8_t rows, uint8_t columns)
{
  Matrix M = NULL;         // New matrix
  uint8_t i = 0, j = 0;    // Iterators

  // Allocates memory for matrix structure
  M = (Matrix)malloc( sizeof(t_matrix) );
  
  // Returns in case of memory allocation error
  if(M == NULL)
  {
    return M;
  }
  
  // Sets matrix dimensions
  M.rows = rows;
  M.columns = columns;
  
  // Initializes determinant pointer
  if(rows == columns)
  {
    // Determinant is defined only if M is a square matrix
    /* TODO: Determinant calculation */
  }
  else
  {
    M.determinant = NULL;
  }
  
  // Allocates memory for pointers array
  M.matrix = (Array)calloc( rows, sizeof(Vector) );

  // Allocates memory each row
  for(i = 0; i < columns; i++)
  {
    M.matrix[i] = (Data*)calloc( columns, sizeof(Data) );
    
    // Returns in case of memory allocation error
    if(M.matrix[i] == NULL)
    {
      // Frees allocated elements in the array
      for(j = 0; j < i; j++)
      {
        free( M.matrix[j] );
      }
      
      // Frees determinant pointer
      if(M.determinant != NULL)
      {
        free(M.determinant);
      }
      
      // Frees memory allocated for matrix structure
      free(M);
      
      return NULL;
    }
  }
  
  // Sets matrix elements as zero
  for(i = 0; i < rows; i++)
  {
    for(j = 0; j < columns; j++)
    {
      M.matrix[i][j] = 0;
    }
  }
   
   return M;
}

/**
@brief  Allocates memory to create a new identity matrix.
@param  dimension: Matrix dimension (n x n)
@retval Pointer to new matrix
*/
Matrix matrix_identity(uint8_t dimension)
{
  Matrix M_eye = NULL;         // New identity matrix
  uint8_t i = 0, j = 0;        // Iterators
  
  // Initializes matrix
  if(dimension != 0)
  {
    M_eye = Mx_Hdlr.init(dimension, dimension);
    
    if(M_eye != NULL)
    {
      // Sets identity matrix elements
      for(i = 0; i < M_eye.rows; i++)
      {
        for(j = 0; j < M_eye.columns; j++)
        {
          if(i == j)
          {
            M_eye.matrix[i][j] = 1;
          }
        }
      }
    }
  }
  
  return M_eye;
}

/**
@brief  Verifies if matrix is null
@param  M: Pointer to matrix
@retval TRUE if matrix is null, FALSE otherwise
*/
uint8_t matrix_isNull(Matrix M)
{
  uint8_t i = 0, j = 0;        // Iterators
  
  if(M != NULL)
  {
    // Verifies matrix elements
    for(i = 0; i < M.rows; i++)
    {
      for(j = 0; j < M.columns; j++)
      {
        if(M.matrix[i][j] != 0)
        {
          return FALSE;
        }
      }
    }
  }
  
  return TRUE;
}

/**
@brief  Gets number of rows of indicated matrix
@param  M: Pointer to matrix
@retval Number of rows
*/
uint8_t matrix_getRows(Matrix M)
{
  return M.rows;
}

/**
@brief  Gets number of columns of indicated matrix
@param  M: Pointer to matrix
@retval Number of columns
*/
uint8_t matrix_getColumns(Matrix M)
{
  return M.columns;
}

/**
@brief  Gets determinant of matrix if defined
@param  M: Pointer to matrix
        detval: Determinant value
@retval TRUE if determinant exists, FALSE otherwise
*/
uint8_t matrix_getDeterminant(Matrix M, double* detval)
{
  // Returns determinant if defined
  if(M.determinant != NULL)
  {
    *detval = *M.determinant;
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Updates a value of introduced matrix
@param  M: Pointer to matrix
        k: Data
        i: Row index
        j: Column index
@retval TRUE if element was updated, FALSE otherwise
*/
uint8_t matrix_update(Matrix M, Data k, uint8_t i, uint8_t j)
{
  if(M != NULL)
  {
    // Updates ijth element
    M.matrix[i][j] = k;
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Verifies if M1 and M2 are equal
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval TRUE if matrices are equal, FALSE otherwise
*/
uint8_t matrix_areEqual(Matrix M1, Matrix M2)
{
  uint8_t i = 0, j = 0;        // Iterators
  
  if(M1 != NULL && M2 != NULL && M1.rows == M2.rows && M1.columns == M2.columns)
  {
    // Verifies matrix elements
    for(i = 0; i < M1.rows; i++)
    {
      for(j = 0; j < M1.columns; j++)
      {
        if(M1.matrix[i][j] != M2.matrix[i][j])
        {
          return FALSE;
        }
      }
    }
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Obtains the algebraic sum of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to sum matrix
@note   If dimensions do not match, the function returns a NULL pointer
*/
Matrix matrix_sum(Matrix M1, Matrix M2)
{
  return NULL;
}

/**
@brief  Obtains the multiplication of a matrix and a scalar factor
@param  V: Pointer to matrix
        k: Scalar factor
@retval Pointer to scalated matrix
*/
Matrix matrix_scalar(Data k, Matrix M)
{
  return NULL;
}

/**
@brief  Obtains the algebraic multiplication of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to product matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
Matrix matrix_product(Matrix M1, Matrix M2)
{
  return NULL;
}

/**
@brief  Obtains the algebraic integer power of a matrix
@param  M: Pointer to matrix
        n: Exponent
@retval Pointer to power matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
Matrix matrix_power(Matrix M, uint8_t n)
{
  return NULL;
}

/**
@brief  Obtains the element-wise multiplication of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to product matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
Matrix matrix_element_product(Matrix M1, Matrix M2)
{
  return NULL;
}

/**
@brief  Obtains the element-wise division of two matrices
@param  M1: Pointer to first matrix
        M2: Pointer to second matrix
@retval Pointer to division matrix
@note If dimensions do not match, the function returns a NULL pointer
*/
Matrix matrix_element_division(Matrix M1, Matrix M2)
{
  return NULL;
}

/**
@brief  Obtains the element-wise power of a matrix
@param  M: Pointer to matrix
        n: Exponent
@retval Pointer to power matrix
*/
Matrix matrix_element_power(Matrix M, double n)
{
  return NULL;
}

/**
@brief  Gets inverse matrix of M if existing
@param  M: Pointer to matrix
@retval Pointer to inverse matrix 
@note Returns NULL if inverse matrix is undefined
*/
Matrix matrix_inverse(Matrix M)
{
  return NULL;
}

/**
@brief  Transposes matrix M
@param  M: Pointer to matrix
@retval Pointer to transposed matrix
*/
Matrix matrix_transpose(Matrix M)
{
  return NULL;
}

/**
@brief  Gets minor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
@retval Pointer to minor 
@note Returns NULL if minor is undefined
*/
Matrix matrix_minor(Matrix M, uint8_t i, uint8_t j)
{
  return NULL;
}

/**
@brief  Gets cofactor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
        cof: Pointer to cofactor value
@retval TRUE if cofactor exists, FALSE otherwise
*/
uint8_t matrix_cofactor(Matrix M, uint8_t i, uint8_t j, double* cf)
{
  return TRUE;
}

/**
@brief  Gets minor ij of matrix M if existing
@param  M: Pointer to matrix
        i: Row index
        j: Column index
@retval Pointer to minor 
@note Returns NULL if minor is undefined
*/
Matrix matrix_minor(Matrix M, uint8_t i, uint8_t j)
{
  return NULL;
}

/**
@brief  Gets a matrix with vector V as main diagonal
@param  D: Main diagonal
@retval Pointer to matrix 
*/
Matrix matrix_diagonal(Vector D)
{
  return NULL;
}

/**
@brief  Deletes matrix and frees allocated memory
@param  M: Pointer to matrix
@retval TRUE if matrix was deleted with no error, FALSE otherwise
*/
uint8_t matrix_delete(Matrix M)
{
  return TRUE;
}

