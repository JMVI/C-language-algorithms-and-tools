/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.h
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/24/2020
 * -----------------------------------------------------------------------------
 */

#ifndef _COMPLEX_H_
#define _COMPLEX_H_

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

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Complex components
typedef enum
{
  RE = 0,   // Real component
  IM,       // Imaginary component
}
Component;

// Argument angle type
typedef enum
{
  RAD = 0,   // Radians
  DEG,       // Degrees
}
Angle_Unit;

// Print parameters
typedef enum
{
  CARTESIAN = 0,  // Cartesian form
  POLAR,          // Polar form
  EULER           // Euler's notation
}
PRINT_FORMAT;

typedef struct
{
  double Real;   // Real part
  double Imag;   // Imaginary part
  double Mod;    // Modulus
  double Arg;    // Argument
}
t_complex;

typedef t_complex Complex;

// Complex number handler
typedef struct
{
  Complex  (*init)(double Real, double Imag);              // Create complex
  uint8_t  (*isNull)(Complex Z);                           // Is a null complex?
  uint8_t  (*areEqual)(Complex Z1, Complex Z2);            // Z1 == Z2?
  double   (*modulus)(Complex Z);                          // Get modulus
  double   (*argument)(Complex Z, Angle_Unit arg);         // Get argument
  uint8_t  (*update)(Complex Z, double val, Component c);  // Update element
  Complex  (*conjugate)(Complex Z);                        // Conjugate
  Complex  (*sum)(Complex Z1, Complex Z2);                 // Complex sum
  Complex  (*product)(Complex Z1, Complex Z2);             // Complex product
  Complex  (*scalar)(Complex Z, double k);                 // Scalar product
  Complex  (*division)(Complex Z1, Complex Z2);            // Complex division
  Complex* (*sqrt)(Complex Z)                              // Square root
  Complex* (*nthroot)(Complex Z, uint8_t n)                // Nth complex root
  uint8_t  (*del)(Complex Z);                              // Delete complex
}t_ComplexHandler;

extern t_ComplexHandler Cmplx_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a complex number
@param  Real: Real component
        Imag: Imaginary component
@retval Pointer to new complex number
*/
extern Complex complex_create(double Real, double Imag);

/**
@brief  Verifies if complex is null
@param  Z: Pointer to complex
@retval TRUE if complex is null, FALSE otherwise
*/
extern uint8_t complex_isNull(Complex Z);

/**
@brief  Verifies if Z1 and Z2 are equal
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval TRUE if complex numbers are equal, FALSE otherwise
*/
extern uint8_t complex_areEqual(Complex Z1, Complex Z2);

/**
@brief  Gets modulus of a complex
@param  Z: Pointer to complex
@retval Modulus value
*/
extern double complex_getModulus(Complex Z);

/**
@brief  Gets argument of a complex
@param  Z:   Pointer to complex
        arg: Return type
             - RAD: Argument in radians
             - DEG: Argument in degrees
@retval Argument value
*/
extern double complex_getArgument(Complex Z, Angle_Unit arg);

/**
@brief  Updates a component of introduced complex
@param  Z:   Pointer to complex
        val: New value
        C:   Component
             - RE: Real component
             - IM: Imaginary component
@retval TRUE if element was updated, FALSE otherwise
*/
extern uint8_t complex_update(Complex Z, double val, Component c);

/**
@brief  Complex conjugation
@param  Z: Pointer to complex
@retval Pointer to conjugated complex
*/
extern Complex complex_conjugate(Complex Z);

/**
@brief  Obtains the algebraic sum of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Pointer to sum complex
*/
extern Complex complex_sum(Complex Z1, Complex Z2);

/**
@brief  Obtains the product of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex product
*/
extern Complex complex_product(Complex Z1, Complex Z2);

/**
@brief  Obtains the product of a complex number and a scalar factor
@param  Z: Pointer to complex
        k: Scalar factor
@retval Pointer to scalated complex
*/
extern Complex complex_scalar(Complex Z, double k);

/**
@brief  Obtains the division of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex division
*/
extern Complex complex_division(Complex Z1, Complex Z2);

/**
@brief  Calculates the square root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
extern Complex* complex_sqrt(Complex Z);

/**
@brief  Calculates the Nth root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
extern Complex* complex_nthroot(Complex Z, uint8_t n);

/**
@brief  Deletes complex and frees allocated memory
@param  Z: Pointer to complex
@retval TRUE if complex was deleted with no error, FALSE otherwise
*/
extern uint8_t complex_delete(Complex Z, uint8_t n);

/**
@brief  Prints complex number on screen
@param  Z:      Pointer to complex
        format: Print format
                - CARTESIAN: Cartesian form
                - POLAR: Polar form
                - EULER: Euler's formula
@retval TRUE if complex was printed with no error, FALSE otherwise
*/
extern uint8_t complex_print(Complex Z, PRINT_FORMAT format);

#endif
