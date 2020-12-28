/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.c
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/28/2020
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
  complex_reciprocal,      // Complex reciprocal
  complex_power,           // Real exponential
  complex_exp,             // Natural exponential
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
void complex_modulus(Complex Z)
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
void complex_argument(Complex Z)
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

/**
@brief Custom signum function. Returns the sign of introduced value
@param: val: Numerical value
@retval (-1) if val < 0, (0) if val == 0, (1) if val > 0
*/
int8_t sgn(double val)
{
  if(val < 0)
  {
    return -1;
  }
  else if(val > 0)
  {
    return 1;
  }
  
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
  Complex Z = (Complex)malloc( sizeof(t_complex) ); // Memory allocation
  
  if(Z != NULL)
  {
    Z->Real = Real;       // Real part
    Z->Imag = Imag;       // Imaginary part
    
    complex_modulus(Z);   // Modulus
    complex_argument(Z);  // Argument    
  }
  
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
@brief  Obtains the reciprocal (1/Z) of a complex number
@param  Z: Pointer to complex
@retval Complex reciprocal
*/
Complex complex_reciprocal(Complex Z)
{
  Complex Z_inv = NULL;
  double Z_inv_real = 0, Z_inv_imag = 0;
  
  if(Z != NULL)
  {
    // Verifies if Z is a null complex
    if( !Cmplx_Hdlr.isNull(Z) )
    {
      // Real part
      Z_inv_real = (Z->Real) / pow(Z->Mod, 2);
      
      // Imaginary part
      Z_inv_imag = (Z->Imag) / pow(Z->Mod, 2);
      
      // Initialize complex
      Z_inv = Cmplx_Hdlr.init(Z_inv_real, Z_inv_imag);
    }
  }
  
  return Z_inv;
}

/**
@brief  Obtains the exponentiation (Z^n) of a complex number
@param  Z: Pointer to complex
        n: Real exponential
@retval Complex power
*/
Complex complex_power(Complex Z, double n)
{
  Complex Z_pow = NULL;
  double Z_pow_real = 0, Z_pow_imag = 0;
  
  if(Z != NULL)
  {
    // Real part
    Z_pow_real = pow(Z->Mod, n) * cos(n * Z->Arg);
    
    // Imaginary part
    Z_pow_imag = pow(Z->Mod, n) * sin(n * Z->Arg);;
    
    // Initialize complex
    Z_pow = Cmplx_Hdlr.init(Z_pow_real, Z_pow_imag);
  }
  
  return Z_pow;
}

/**
@brief  Obtains the natural exponential function (e^Z) of a complex number
@param  Z: Pointer to complex
@retval Complex power
*/
Complex complex_exp(Complex Z)
{
  Complex Z_pow = NULL;
  double Z_pow_real = 0, Z_pow_imag = 0;
  
  if(Z != NULL)
  {
    // Real part
    Z_pow_real = exp(Z->Real) * cos(Z->Imag);
    
    // Imaginary part
    Z_pow_imag = exp(Z->Real) * sin(Z->Imag);;
    
    // Initialize complex
    Z_pow = Cmplx_Hdlr.init(Z_pow_real, Z_pow_imag);
  }
  
  return Z_pow;
}

/**
@brief  Calculates the square root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
Complex* complex_sqrt(Complex Z)
{
  Complex* Z_roots = NULL;
  double Z_root_real = 0, Z_root_imag = 0;
  
  Z_roots = (Complex*)calloc( 2, sizeof(t_complex) ); // Memory allocation
  
  if(Z_roots != NULL)
  {
    // First complex root
    Z_root_real = sqrt( (Z->Real + Z->Mod)/2 );
    Z_root_imag = sgn(Z->Imag) * sqrt( (-Z->Real + Z->Mod)/2 );
    
    Z_roots[0] = Cmplx_Hdlr.init(Z_root_real, Z_root_imag);
    
    // Second complex root
    Z_root_real = -sqrt( (Z->Real + Z->Mod)/2 );
    Z_root_imag = -sgn(Z->Imag) * sqrt( (-Z->Real + Z->Mod)/2 );
    
    Z_roots[1] = Cmplx_Hdlr.init(Z_root_real, Z_root_imag);
  }
  
  return Z_roots;
}

/**
@brief  Calculates the Nth root of a complex number
@param  Z: Pointer to complex
@retval Array to complex results
*/
Complex* complex_nthroot(Complex Z, uint8_t n)
{
  Complex* Z_roots = NULL;
  double Z_root_real = 0, Z_root_imag = 0;
  uint8_t k = 0;
  
  Z_roots = (Complex*)calloc( n, sizeof(t_complex) ); // Memory allocation
  
  if(Z_roots != NULL)
  {
    // Calculate the n roots of Z using De Moivre's Theorem
    for(k = 0; k <= n - 1; i++)
    {
      // Real part of (k+1)th root
      Z_root_real = pow(Z->Mod, 1/n) * cos( (Z->Arg + 2*PI*k) / n );
      
      // Imaginary part of (k+1)th root
      Z_root_imag = pow(Z->Mod, 1/n) * sin( (Z->Arg + 2*PI*k) / n );
      
      // Initialize complex
      Z_roots[k] = Cmplx_Hdlr.init(Z_root_real, Z_root_imag);
    }
  }
  
  return Z_roots;
}

/**
@brief  Deletes complex and frees allocated memory
@param  Z: Pointer to complex
@retval TRUE if complex was deleted with no error, FALSE otherwise
*/
uint8_t complex_delete(Complex Z)
{
  // Validates indicated vector
  if(Z != NULL)
  {
    // Frees allocated memory
    free(Z);
    
    return TRUE;
  }
  
  return FALSE;
}

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
uint8_t complex_print(Complex Z, PRINT_FORMAT format)
{
  switch(format)
  {
    // Cartesian form
    case CARTESIAN:
      printf("%.04f %.04f i\n", Z->Real, Z->Imag);
      break;
    
    // Polar form
    case POLAR:
      printf( "%.04f < %.04f i\n", Z->Mod, Cmplx_Hdlr.argument(Z, DEG) );
      break;
    
    // Euler's formula
    case EULER:
      printf( "%.04f exp(i %.04f)\n", Z->Mod, Cmplx_Hdlr.argument(Z, RAD) );
      break;
    
    // Invalid arguments
    default:
      return FALSE;
  }
  
  return TRUE;
}

