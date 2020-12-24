/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.c
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/24/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Complex.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Complex handler
t_ComplexHandler Cmplx_Hdlr
{
  complex_create,          // Create complex
  complex_isNull,          // Is a null complex?
  complex_areEqual,        // Z1 == Z2?
  complex_getModulus,      // Get modulus
  complex_getArgument,     // Get argument
  complex_update,          // Update element
  complex_conjugate,       // Conjugate
  complex_sum,             // Complex sum
  complex_product,         // Complex product
  complex_scalar,          // Scalar product
  complex_division,        // Complex division
  complex_sqrt,            // Square root
  complex_nthroot,         // Nth complex root
  complex_delete           // Delete complex
};


//----------------------------------------------------------------------------//
//                              Private functions                             //
//----------------------------------------------------------------------------//

/**
@brief  Calculates the complex number modulus
@param  Z: Complex number
@retval Modulus value
*/
double vector_modulus(Complex Z)
{
  return 0;
}

/**
@brief  Calculates the complex number argument
@param  Z: Complex number
@retval Argument value
*/
double vector_argument(Complex Z)
{
  return 0;
}

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a complex number
@param  Real: Real component
        Imag: Imaginary component
@retval Pointer to new complex number
*/
Complex complex_create(double Real, double Imag)
{
  return NULL;
}

/**
@brief  Verifies if complex is null
@param  Z: Pointer to complex
@retval TRUE if complex is null, FALSE otherwise
*/
uint8_t complex_isNull(Complex Z)
{
  return TRUE;
}

/**
@brief  Verifies if Z1 and Z2 are equal
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval TRUE if complex numbers are equal, FALSE otherwise
*/
uint8_t complex_areEqual(Complex Z1, Complex Z2)
{
  return TRUE;
}

/**
@brief  Gets modulus of a complex
@param  Z: Pointer to complex
@retval Modulus value
*/
double complex_getModulus(Complex Z)
{
  return 0;
}

/**
@brief  Gets argument of a complex
@param  Z:   Pointer to complex
        arg: Return type
             - RAD: Argument in radians
             - DEG: Argument in degrees
@retval Argument value
*/
double complex_getArgument(Complex Z, Angle_Unit arg)
{
  return 0;
}

/**
@brief  Updates a component of introduced complex
@param  Z:   Pointer to complex
        val: New value
        C:   Component
             - RE: Real component
             - IM: Imaginary component
@retval TRUE if element was updated, FALSE otherwise
*/
uint8_t complex_update(Complex Z, double val, Component c)
{
  return TRUE;
}

/**
@brief  Complex conjugation
@param  Z: Pointer to complex
@retval Pointer to conjugated complex
*/
Complex complex_conjugate(Complex Z)
{
  return NULL;
}

/**
@brief  Obtains the algebraic sum of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Pointer to sum complex
*/
Complex complex_sum(Complex Z1, Complex Z2)
{
  return NULL;
}

/**
@brief  Obtains the product of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex product
*/
Complex complex_product(Complex Z1, Complex Z2)
{
  return NULL;
}

/**
@brief  Obtains the product of a complex number and a scalar factor
@param  Z: Pointer to complex
        k: Scalar factor
@retval Pointer to scalated complex
*/
Complex complex_scalar(Complex Z, double k)
{
  return NULL;
}

/**
@brief  Obtains the division of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex division
*/
Complex complex_division(Complex Z1, Complex Z2)
{
  return NULL;
}

/**
@brief  Calculates the square root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
Complex* complex_sqrt(Complex Z)
{
  return NULL;
}

/**
@brief  Calculates the Nth root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
Complex* complex_nthroot(Complex Z, uint8_t n)
{
  return NULL;
}

/**
@brief  Deletes complex and frees allocated memory
@param  Z: Pointer to complex
@retval TRUE if complex was deleted with no error, FALSE otherwise
*/
uint8_t complex_delete(Complex Z, uint8_t n)
{
  return TRUE;
}

/**
@brief  Prints complex number on screen
@param  Z:      Pointer to complex
        format: Print format
                - CARTESIAN: Cartesian form
                - POLAR: Polar form
                - EULER: Euler's formula
@retval TRUE if complex was printed with no error, FALSE otherwise
*/
uint8_t complex_print(Complex Z, PRINT_FORMAT format)
{
  return TRUE;
}

