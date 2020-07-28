/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_3DVector.h
 * Description   : Abstract Data Type for 3D Vectors.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/26/2020
 * -----------------------------------------------------------------------------
 */

#ifndef _3DVECTOR_H_
#define _3DVECTOR_H_

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

// Vector dimension
#define VECTOR_DIM (uint8_t)(3)

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Data type stored in vector
typedef double Data;

// Vector
typedef Data* Vector;

// Vector components
typedef enum
{
  vx = 0,   // X coordinate
  vy,       // Y coordinate
  vz        // Z coordinate
}
Coordinate;

// Vector handler
typedef struct
{
  Vector  (*init)(Data Vx, Data Vy, Data Vz);        // Create 3D-Vector
  uint8_t (*isNull)(Vector V);                       // Is null vector?
  uint8_t (*areEqual)(Vector V1, Vector V2);         // Are V1 and V2 equal?
  double  (*length)(Vector V);                       // Vector length
  uint8_t (*update)(Vector V, Data k, Coordinate C); // Update element
  Vector  (*sum)(Vector V1, Vector V2);              // Vector sum
  Vector  (*scalar)(Data k, Vector V);               // Scalar multiplication
  double  (*dot)(Vector V1, Vector V2);              // Dot product
  Vector  (*cross)(Vector V1, Vector V2);            // Cross product
  double  (*angle)(Vector V1, Vector V2);            // Angle between V1 and V2
  uint8_t (*del)(Vector V);                          // Delete vector
}t_VectorHandler;

extern t_VectorHandler V_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new vector
@param  Vx: X coordinate
        Vy: Y coordinate
        Vz: Z coordinate
@retval Pointer to new vector value
*/
extern Vector vector_create(Data Vx, Data Vy, Data Vz);

/**
@brief  Verifies if vector is null
@param  V: Pointer to vector
@retval TRUE if vector is null, FALSE otherwise
*/
extern uint8_t vector_isNull(Vector V);

/**
@brief  Verifies if V1 and V2 are equal
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval TRUE if vectors are equal, FALSE otherwise
*/
extern uint8_t vector_areEqual(Vector V1, Vector V2);

/**
@brief  Calculates vector's euclidean length
@param  V: Pointer to vector
@retval Length
*/
extern double vector_length(Vector V);

/**
@brief  Updates a coordinate of introduced vector
@param  V: Pointer to vector
        k: Data
        C: Type of coordinate
@retval TRUE if element was updated, FALSE otherwise
*/
extern uint8_t vector_update(Vector V, Data k, Coordinate C);

/**
@brief  Obtains the algebraic sum of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Pointer to sum vector
*/
extern Vector vector_sum(Vector V1, Vector V2);

/**
@brief  Obtains the multiplication of a vector and a scalar factor
@param  V: Pointer to vector
        k: Scalar factor
@retval Pointer to scalated vector
*/
extern Vector vector_scalar(Data k, Vector V);

/**
@brief  Obtains the dot product of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Dot product
*/
extern double vector_dotProduct(Vector V1, Vector V2);

/**
@brief  Obtains the dot product of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Pointer to cross product vector
*/
extern Vector vector_crossProduct(Vector V1, Vector V2);

/**
@brief  Calculates the angle between two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Pointer to cross product vector
*/
extern double vector_angle(Vector V1, Vector V2);

/**
@brief  Deletes vector and frees allocated memory
@param  V: Pointer to vector
@retval TRUE if vector was deleted with no error, FALSE otherwise
*/
extern uint8_t vector_delete(Vector V);

/**
@brief  Prints vector on screen
@param  V: Pointer to vector
@retval TRUE if vector was printed with no error, FALSE otherwise
*/
extern uint8_t vector_print(Vector V);

#endif

