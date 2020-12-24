/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_3DVector.c
 * Description   : Abstract Data Type for 3D Vectors.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/24/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_3DVector.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Vector handler
t_VectorHandler V_Hdlr =
{
  vector_create,         // Create 3D-Vector
  vector_isNull,         // Is null vector?
  vector_areEqual,       // Are V1 and V2 equal?
  vector_length,         // Vector length
  vector_update,         // Update element
  vector_sum,            // Vector sum
  vector_scalar,         // Scalar multiplication
  vector_dotProduct,     // Dot product
  vector_crossProduct,   // Cross product
  vector_angle,          // Angle between V1 and V2
  vector_delete          // Delete vector
};

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
Vector vector_create(Data Vx, Data Vy, Data Vz)
{
  Vector V = (Data*)calloc(VECTOR_DIM, sizeof(Data)); // Memory allocation
  
  V[vx] = Vx;  // X coordinate
  V[vy] = Vy;  // Y coordinate
  V[vz] = Vz;  // Z coordinate
  
  return V;
}

/**
@brief  Verifies if vector is null
@param  V: Pointer to vector
@retval TRUE if vector is null, FALSE otherwise
*/
uint8_t vector_isNull(Vector V)
{
  return (V[vx] == 0 && V[vy] == 0 && V[vz] == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if V1 and V2 are equal
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval TRUE if vectors are equal, FALSE otherwise
*/
uint8_t vector_areEqual(Vector V1, Vector V2)
{
  if(V1[vx] == V2[vx] && V1[vy] == V2[vy] && V1[vz] == V2[vz])
  {
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Calculates vector's euclidean length
@param  V: Pointer to vector
@retval Length
*/
double vector_length(Vector V)
{
  return sqrt( pow(V[vx], 2) + pow(V[vy], 2) + pow(V[vz], 2) );
}

/**
@brief  Updates a coordinate of introduced vector
@param  V: Pointer to vector
        k: Data
        C: Type of coordinate
@retval TRUE if element was updated, FALSE otherwise
*/
uint8_t vector_update(Vector V, Data k, Coordinate C)
{
  // Validates indicated vector
  if(V != NULL)
  {
    switch(C)
    {
      case vx:
        V[vx] = k;  // X coordinate
        break;
        
      case vy:
        V[vy] = k;  // Y coordinate
        break;
      
      case vz:
        V[vz] = k;  // Z coordinate
        break;
        
      default:
        break;
    }
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Obtains the algebraic sum of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Pointer to sum vector
*/
Vector vector_sum(Vector V1, Vector V2)
{
  Vector newV = NULL;
  
  // Validates indicated vectors
  if(V1 != NULL && V2 != NULL)
  {
    newV = V_Hdlr.init( V1[vx] + V2[vx] , V1[vy] + V2[vy], V1[vz] + V2[vz] );
  }
  
  return newV;
}

/**
@brief  Obtains the multiplication of a vector and a scalar factor
@param  V: Pointer to vector
        k: Scalar factor
@retval Pointer to scalated vector
*/
Vector vector_scalar(Data k, Vector V)
{
  Vector newV = NULL;
  
  // Validates indicated vector
  if(V != NULL)
  {
    newV = V_Hdlr.init( k*V[vx], k*V[vy], k*V[vz] );
  }
  
  return newV;
}

/**
@brief  Obtains the dot product of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Dot product
*/
double vector_dotProduct(Vector V1, Vector V2)
{
  double dotP = 0;
  
  // Validates indicated vectors
  if(V1 != NULL && V2 != NULL)
  {
    dotP = V1[vx]*V2[vx] + V1[vy]*V2[vy] + V1[vz]*V2[vz];
  }
  
  return dotP;
}

/**
@brief  Obtains the dot product of two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
@retval Pointer to cross product vector
*/
Vector vector_crossProduct(Vector V1, Vector V2)
{
  Vector newV = NULL;
  
  // Validates indicated vectors
  if(V1 != NULL && V2 != NULL)
  {
    // Initializes null vector
    newV = V_Hdlr.init(0, 0, 0);
    
    if(newV != NULL)
    {
      V_Hdlr.update(newV, V1[vy]*V2[vz] - V1[vz]*V2[vy], vx);  // (V1 x V2)x
      V_Hdlr.update(newV, V1[vz]*V2[vx] - V1[vx]*V2[vz], vy);  // (V1 x V2)y
      V_Hdlr.update(newV, V1[vx]*V2[vy] - V1[vy]*V2[vx], vz);  // (V1 x V2)z
    }
    else
    {
      return newV;
    }
  }
  
  return newV;
}

/**
@brief  Calculates the angle between two vectors
@param  V1: Pointer to first vector
        V2: Pointer to second vector
        arg: Unit of angle (radians / degrees)
@retval Pointer to cross product vector
*/
double vector_angle(Vector V1, Vector V2, Angle_Unit arg)
{
  double cosTheta = 0, Theta = 0;
  
  // Validates indicated vectors
  if(V1 != NULL && V2 != NULL)
  {
    cosTheta = V_Hdlr.dot(V1, V2) / ( (V_Hdlr.length(V1))*(V_Hdlr.length(V2)) );
    Theta = acos(cosTheta);
  }
  
  if(arg == RAD)
  {
    return Theta;
  }
  
  return 180*Theta/3.1416;
}

/**
@brief  Deletes vector and frees allocated memory
@param  V: Pointer to vector
@retval TRUE if vector was deleted with no error, FALSE otherwise
*/
uint8_t vector_delete(Vector V)
{
  // Validates indicated vector
  if(V != NULL)
  {
    // Frees allocated memory
    free(V);
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Prints vector on screen
@param  V: Pointer to vector
@retval TRUE if vector was printed with no error, FALSE otherwise
*/
uint8_t vector_print(Vector V)
{
  // Validates indicated vector
  if(V != NULL)
  {
    printf("(%.03f, %.03f, %.03f)\n", V[vx], V[vy], V[vz]);
    
    return TRUE;
  }
  
  return FALSE;
}

