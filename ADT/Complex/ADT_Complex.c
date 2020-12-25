/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.c
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/25/2020
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
@retval none
*/
void vector_modulus(Complex Z)
{
  if(Z != NULL)
  {
    Z->Mod = sqrt( pow(Z->Real, 2) + pow(Z->Imag, 2) );
  }
}

/**
@brief  Calculates the complex number argument
@param  Z: Complex number
@retval none
@note Argument is calculated by default in radians
*/
void vector_argument(Complex Z)
{
  if(Z != NULL)
  {
    if(Z->Real > 0 && Z->Imag != 0)
    {
      Z->Arg = 2 * atan(Z->Imag / (Z->Mod + Z->Real) )
    }
    else if(Z->Real < 0 && Z->Imag == 0)
    {
      Z->Arg = PI;
    }
    else
    {
      Z->Arg = 0;
    }
  }
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
  Complex Z = (Complex)malloc( sizeof(t_complex) ); // Memory allocation
  
  // Error in memory allocation
  if(Z == NULL)
  {
    return Z;
  }
  
  Z->Real = Real;      // Real part
  Z->Imag = Imag;      // Imaginary part
  
  vector_modulus(Z);   // Modulus
  vector_argument(Z);  // Argument
  
  return Z;
}

/**
@brief  Verifies if complex is null
@param  Z: Pointer to complex
@retval TRUE if complex is null, FALSE otherwise
*/
uint8_t complex_isNull(Complex Z)
{
  return (Z->Mod == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if Z1 and Z2 are equal
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval TRUE if complex numbers are equal, FALSE otherwise
*/
uint8_t complex_areEqual(Complex Z1, Complex Z2)
{
  return (Z1->Real == Z2->Real && Z1->Imag == Z2->Imag) ? TRUE : FALSE;
}

/**
@brief  Gets modulus of a complex
@param  Z: Pointer to complex
@retval Modulus value
@note Previous validation of input argument is expected before function call
*/
double complex_getModulus(Complex Z)
{
  return Z->Mod;
}

/**
@brief  Gets argument of a complex
@param  Z:   Pointer to complex
        arg: Return type
             - RAD: Argument in radians
             - DEG: Argument in degrees
@retval Argument value
@note Previous validation of input arguments is expected before function call
*/
double complex_getArgument(Complex Z, Angle_Unit arg)
{
  if(arg == DEG)
  {
    // Return value in degrees
    return 180 * Z->Arg / PI;
  }
  
  // Return value in radians
  return Z->Arg;
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
  if(Z != NULL)
  {
    switch(c)
    {
      case RE:
        Z->Real = val;   // Update real part
        break;
        
      case IM:
        Z->Imag = val;   // Update imaginary part
        break;
        
      default:
        return FALSE;    // Invalid arguments
    }
  
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Complex conjugation
@param  Z: Pointer to complex
@retval Pointer to conjugated complex
*/
Complex complex_conjugate(Complex Z)
{
  Complex Z_conj = NULL;
  
  if(Z != NULL)
  {
    Z_conj = Cmplx_Hdlr.init(Z->Real, -Z->Imag);
  }
  
  return Z_conj;
}

/**
@brief  Obtains the algebraic sum of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Pointer to sum complex
*/
Complex complex_sum(Complex Z1, Complex Z2)
{
  Complex Z_sum = NULL;
  double Z_sum_real = 0, Z_sum_imag = 0;
  
  if(Z1 != NULL && Z2 != NULL)
  {
    // Real part
    Z_sum_real = Z1->Real + Z2->Real;
    
    // Imaginary part
    Z_sum_imag = Z1->Imag + Z2->Imag;
    
    // Initialize complex
    Z_sum = Cmplx_Hdlr.init(Z_sum_real, Z_sum_imag);
  }
  
  return Z_sum;
}

/**
@brief  Obtains the product of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex product
*/
Complex complex_product(Complex Z1, Complex Z2)
{
  Complex Z_prod = NULL;
  double Z_prod_real = 0, Z_prod_imag = 0;
  
  if(Z1 != NULL && Z2 != NULL)
  {
    // Real part
    Z_prod_real = Z1->Real * Z2->Real - Z1->Imag * Z2->Imag;
    
    // Imaginary part
    Z_prod_imag = Z1->Real * Z2->Imag + Z1->Imag * Z2->Real;
    
    // Initialize complex
    Z_prod = Cmplx_Hdlr.init(Z_prod_real, Z_prod_imag);
  }
  
  return Z_prod;
}

/**
@brief  Obtains the product of a complex number and a scalar factor
@param  Z: Pointer to complex
        k: Scalar factor
@retval Pointer to scalated complex
*/
Complex complex_scalar(Complex Z, double k)
{
  Complex Z_scl = NULL;
  
  if(Z != NULL)
  {
    // Initialize complex
    Z_scl = Cmplx_Hdlr.init(k * Z->Real, k * Z->Imag);
  }
  
  return Z_scl;
}

/**
@brief  Obtains the division (Z1/Z2) of two complex numbers
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Complex division
*/
Complex complex_division(Complex Z1, Complex Z2)
{
  Complex Z_div = NULL;
  double Z_div_real = 0, Z_div_imag = 0;
  
  if(Z1 != NULL && Z2 != NULL)
  {
    // Verifies if divisor Z2 is a null complex
    if( !Cmplx_Hdlr.isNull(Z2) )
    {
      // Real part
      Z_div_real = (Z1->Real * Z2->Real + Z1->Imag * Z2->Imag)/pow(Z2->Mod, 2);
      
      // Imaginary part
      Z_div_imag = (Z1->Imag * Z2->Real - Z1->Real * Z2->Imag)/pow(Z2->Mod, 2);
      
      // Initialize complex
      Z_div = Cmplx_Hdlr.init(Z_div_real, Z_div_imag);
    }
  }
  
  return Z_div;
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

