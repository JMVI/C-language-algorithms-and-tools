/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.h
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/30/2020
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

// Pi
#define PI (double)(3.141592653)

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Complex components
typedef enum
{
  RE = 0,   // Real component
  IM,       // Imaginary component
}
COMPONENT;

// Argument angle type
typedef enum
{
  RAD = 0,   // Radians
  DEG,       // Degrees
}
ANGLE_UNIT;

// Print parameters
typedef enum
{
  CARTESIAN = 0,  // Cartesian form
  POLAR,          // Polar form
  EULER           // Euler's notation
}
PRINT_FORMAT;

typedef struct complex
{
  double Real;   // Real part
  double Imag;   // Imaginary part
  double Mod;    // Modulus
  double Arg;    // Argument
}
t_complex;

typedef t_complex* Complex;

// Complex number handler
typedef struct complex_handler
{
  Complex  (*init)(double Real, double Imag);             // Create complex
  uint8_t  (*isNull)(Complex Z);                          // Is a null complex?
  uint8_t  (*areEqual)(Complex Z1, Complex Z2);           // Z1 == Z2?
  double   (*modulus)(Complex Z);                         // Get modulus
  double   (*argument)(Complex Z, ANGLE_UNIT arg);        // Get argument
  uint8_t  (*update)(Complex Z, double val, COMPONENT c); // Update element
  Complex  (*conjugate)(Complex Z);                       // Conjugate
  Complex  (*sum)(Complex Z1, Complex Z2);                // Sum
  Complex  (*sub)(Complex Z1, Complex Z2);                // Subtraction
  Complex  (*product)(Complex Z1, Complex Z2);            // Complex product
  Complex  (*scalar)(Complex Z, double k);                // Scalar product
  Complex  (*division)(Complex Z1, Complex Z2);           // Division
  Complex  (*inv)(Complex Z);                             // Reciprocal
  Complex  (*pow)(Complex Z, double n);                   // Real exponential
  Complex  (*exp)(Complex Z);                             // Natural exponential
  Complex* (*sqrt)(Complex Z);                            // Square root
  Complex* (*nthroot)(Complex Z, uint8_t n);              // Nth complex root
  Complex  (*sin)(Complex Z);                             // Sin(Z)
  Complex  (*cos)(Complex Z);                             // Cos(Z)
  Complex  (*tan)(Complex Z);                             // Tan(Z)
  Complex  (*csc)(Complex Z);                             // Csc(Z)
  Complex  (*sec)(Complex Z);                             // Sec(Z)
  Complex  (*cot)(Complex Z);                             // Cot(Z)
  Complex  (*sinh)(Complex Z);                            // Sinh(Z)
  Complex  (*cosh)(Complex Z);                            // Cosh(Z)
  Complex  (*tanh)(Complex Z);                            // Tanh(Z)
  Complex  (*csch)(Complex Z);                            // Csch(Z)
  Complex  (*sech)(Complex Z);                            // Sech(Z)
  Complex  (*coth)(Complex Z);                            // Coth(Z)
  uint8_t  (*del)(Complex Z);                             // Delete complex
}
t_ComplexHandler;

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
extern double complex_getArgument(Complex Z, ANGLE_UNIT arg);

/**
@brief  Updates a component of introduced complex
@param  Z:   Pointer to complex
        val: New value
        C:   Component
             - RE: Real component
             - IM: Imaginary component
@retval TRUE if element was updated, FALSE otherwise
*/
extern uint8_t complex_update(Complex Z, double val, COMPONENT c);

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
@brief  Obtains the subtraction of two complex numbers (Z1 - Z2)
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Pointer to subtraction result
*/
extern Complex complex_subtraction(Complex Z1, Complex Z2);

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
@brief  Obtains the division (Z1/Z2) of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex division
*/
extern Complex complex_division(Complex Z1, Complex Z2);

/**
@brief  Obtains the reciprocal (1/Z) of a complex number
@param  Z: Pointer to complex
@retval Complex reciprocal
*/
extern Complex complex_reciprocal(Complex Z);
   
/**
@brief  Obtains the exponentiation (Z^n) of a complex number
@param  Z: Pointer to complex
        n: Real exponential
@retval Complex power
*/
extern Complex complex_power(Complex Z, double n);

/**
@brief  Obtains the natural exponential function (e^Z) of a complex number
@param  Z: Pointer to complex
@retval Complex power
*/
extern Complex complex_exp(Complex Z);
  
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
@brief  Calculates the complex sine of Z
@param  Z: Pointer to complex
@retval Complex sine
*/
extern Complex complex_sine(Complex Z);

/**
@brief  Calculates the complex cosine of Z
@param  Z: Pointer to complex
@retval Complex cosine
*/
extern Complex complex_cosine(Complex Z);

/**
@brief  Calculates the complex tangent of Z
@param  Z: Pointer to complex
@retval Complex tangent
*/
extern Complex complex_tangent(Complex Z);

/**
@brief  Calculates the complex cosecant of Z
@param  Z: Pointer to complex
@retval Complex cosecant
*/
extern Complex complex_cosecant(Complex Z);

/**
@brief  Calculates the complex secant of Z
@param  Z: Pointer to complex
@retval Complex secant
*/
extern Complex complex_secant(Complex Z);

/**
@brief  Calculates the complex cotangent of Z
@param  Z: Pointer to complex
@retval Complex cotangent
*/
extern Complex complex_cotangent(Complex Z);

/**
@brief  Calculates the complex hyperbolic sine of Z
@param  Z: Pointer to complex
@retval Complex sine
*/
extern Complex complex_hyperbolic_sine(Complex Z);

/**
@brief  Calculates the complex hyperbolic cosine of Z
@param  Z: Pointer to complex
@retval Complex cosine
*/
extern Complex complex_hyperbolic_cosine(Complex Z);

/**
@brief  Calculates the complex hyperbolic tangent of Z
@param  Z: Pointer to complex
@retval Complex tangent
*/
extern Complex complex_hyperbolic_tangent(Complex Z);

/**
@brief  Calculates the complex hyperbolic cosecant of Z
@param  Z: Pointer to complex
@retval Complex cosecant
*/
extern Complex complex_hyperbolic_cosecant(Complex Z);

/**
@brief  Calculates the complex hyperbolic secant of Z
@param  Z: Pointer to complex
@retval Complex secant
*/
extern Complex complex_hyperbolic_secant(Complex Z);

/**
@brief  Calculates the complex hyperbolic cotangent of Z
@param  Z: Pointer to complex
@retval Complex cotangent
*/
extern Complex complex_hyperbolic_cotangent(Complex Z);

/**
@brief  Deletes complex and frees allocated memory
@param  Z: Pointer to complex
@retval TRUE if complex was deleted with no error, FALSE otherwise
*/
extern uint8_t complex_delete(Complex Z);

/**
@brief  Prints complex number on screen
@param  Z:      Pointer to complex
        format: Print format
                - CARTESIAN: Cartesian form
                - POLAR: Polar form
                - EULER: Euler's formula
@retval TRUE if complex was printed with no error, FALSE otherwise
@note Argument is printed in degrees by default in polar form
*/
extern uint8_t complex_print(Complex Z, PRINT_FORMAT format);

#endif

