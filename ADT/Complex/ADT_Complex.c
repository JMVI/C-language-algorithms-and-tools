/* -----------------------------------------------------------------------------
 * Copyright (C) 2021 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Complex.c
 * Description   : Abstract Data Type for complex numbers.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 01/17/2021
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
t_ComplexHandler Cmplx_Hdlr =
{
  complex_create,                    // Create complex
  complex_isNull,                    // Is a null complex?
  complex_areEqual,                  // Z1 == Z2?
  complex_getModulus,                // Get modulus
  complex_getArgument,               // Get argument
  complex_update,                    // Update element
  complex_conjugate,                 // Conjugate
  complex_sum,                       // Sum
  complex_subtraction,               // Subtraction
  complex_product,                   // Complex product
  complex_scalar,                    // Scalar product
  complex_division,                  // Division
  complex_reciprocal,                // Reciprocal
  complex_power,                     // Real power
  complex_exp,                       // Natural exponential
  complex_sqrt,                      // Square root
  complex_nthroot,                   // Nth complex root
  complex_log,                       // Natural logarithm
  complex_logn,                      // Base-n logarithm
  complex_sine,                      // Sin(Z)
  complex_cosine,                    // Cos(Z)
  complex_tangent,                   // Tan(Z)
  complex_cosecant,                  // Csc(Z)
  complex_secant,                    // Sec(Z)
  complex_cotangent,                 // Cot(Z)
  complex_arcsine,                   // Asin(Z)
  complex_arccosine,                 // Acos(Z)
  complex_arctangent,                // Atan(Z)
  complex_arccosecant,               // Acsc(Z)
  complex_arcsecant,                 // Asec(Z)
  complex_arccotangent,              // Acot(Z)
  complex_hyperbolic_sine,           // Sinh(Z)
  complex_hyperbolic_cosine,         // Cosh(Z)
  complex_hyperbolic_tangent,        // Tanh(Z)
  complex_hyperbolic_cosecant,       // Csch(Z)
  complex_hyperbolic_secant,         // Sech(Z)
  complex_hyperbolic_cotangent,      // Coth(Z)
  complex_hyperbolic_arcsine,        // Asinh(Z)
  complex_hyperbolic_arccosine,      // Acosh(Z)
  complex_hyperbolic_arctangent,     // Atanh(Z)
  complex_hyperbolic_arccosecant,    // Acsch(Z)
  complex_hyperbolic_arcsecant,      // Asech(Z)
  complex_hyperbolic_arccotangent,   // Acoth(Z)
  complex_delete                     // Delete complex
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
    if(Z->Real > 0 || Z->Imag != 0)
    {
      Z->Arg = 2 * atan(Z->Imag / (Z->Mod + Z->Real) );
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
double complex_getArgument(Complex Z, ANGLE_UNIT arg)
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
uint8_t complex_update(Complex Z, double val, COMPONENT c)
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
    
    // Recalculates modulus and argument
    complex_modulus(Z);
    complex_argument(Z);
  
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
@brief  Obtains the subtraction of two complex numbers (Z1 - Z2)
@param  Z1: Pointer to first complex
        Z2: Pointer to second complex
@retval Pointer to subtraction result
*/
Complex complex_subtraction(Complex Z1, Complex Z2)
{
  Complex Z_sub = NULL;
  double Z_sub_real = 0, Z_sub_imag = 0;
  
  if(Z1 != NULL && Z2 != NULL)
  {
    // Real part
    Z_sub_real = Z1->Real - Z2->Real;
    
    // Imaginary part
    Z_sub_imag = Z1->Imag - Z2->Imag;
    
    // Initialize complex
    Z_sub = Cmplx_Hdlr.init(Z_sub_real, Z_sub_imag);
  }
  
  return Z_sub;
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
    Z_pow_imag = pow(Z->Mod, n) * sin(n * Z->Arg);
    
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
    Z_pow_imag = exp(Z->Real) * sin(Z->Imag);
    
    // Initialize complex
    Z_pow = Cmplx_Hdlr.init(Z_pow_real, Z_pow_imag);
  }
  
  return Z_pow;
}

/**
@brief  Calculates the square root of a complex number
@param  Z: Pointer to complex
@retval Complex square root
*/
Complex complex_sqrt(Complex Z)
{
  Complex Z_root = NULL;
  double Z_root_real = 0, Z_root_imag = 0;
  
  if(Z != NULL)
  {
    // Real part
    Z_root_real = sqrt( (Z->Real + Z->Mod)/2 );
    
    // Imaginary part
    Z_root_imag = sgn(Z->Imag) * sqrt( (-Z->Real + Z->Mod)/2 );
    
    // Initialize complex
    Z_root = Cmplx_Hdlr.init(Z_root_real, Z_root_imag);
  }
  
  return Z_root;
}

/**
@brief  Calculates the Nth root of a complex number
@param  Z: Pointer to complex
@retval Complex nth root
*/
Complex complex_nthroot(Complex Z, uint8_t n)
{
  Complex Z_root = NULL;
  double Z_root_real = 0, Z_root_imag = 0;
  double n_i = (double)(n);
  
  if(Z != NULL && n != 0)
  {
    // Calculate the complex root of Z using De Moivre's Theorem
    
    // Real part
    Z_root_real = pow(Z->Mod, 1/n_i) * cos( (Z->Arg) / n_i );
    
    // Imaginary part
    Z_root_imag = pow(Z->Mod, 1/n_i) * sin( (Z->Arg) / n_i );
    
    // Initialize complex
    Z_root = Cmplx_Hdlr.init(Z_root_real, Z_root_imag);
  }
  
  return Z_root;
}

/**
@brief  Calculates the natural logarithm of a complex number
@param  Z: Pointer to complex
@retval Complex logarithm
*/
Complex complex_log(Complex Z)
{
  Complex Z_log = NULL;
  double Z_log_real = 0, Z_log_imag = 0;
  
  if(Z != NULL)
  {
    // Real part
    Z_log_real = log(Z->Mod);
    
    // Imaginary part
    Z_log_imag = Z->Arg;
    
    // Initialize complex
    Z_log = Cmplx_Hdlr.init(Z_log_real, Z_log_imag);
  }
  
  return Z_log;
}

/**
@brief  Calculates the base-n logarithm of a complex number
@param  Z: Pointer to complex
        n: Logarithm base
@retval Complex logarithm
*/
Complex complex_logn(Complex Z, uint8_t n)
{
  Complex Z_logn = NULL;
  double Z_logn_real = 0, Z_logn_imag = 0;
  
  if(Z != NULL)
  {
    // Real part
    Z_logn_real = log(Z->Mod)/log(n);
    
    // Imaginary part
    Z_logn_imag = Z->Arg/log(n);
    
    // Initialize complex
    Z_logn = Cmplx_Hdlr.init(Z_logn_real, Z_logn_imag);
  }
  
  return Z_logn;
}

/**
@brief  Calculates the complex sine of Z
@param  Z: Pointer to complex
@retval Complex sine
*/
Complex complex_sine(Complex Z)
{
  Complex Z_num = NULL;    // Numerator
  Complex Z_den = NULL;    // Denominator
  Complex Z_sine = NULL;   // Sine
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init(0, 2);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex sine
    Z_sine = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_sine;
}

/**
@brief  Calculates the complex cosine of Z
@param  Z: Pointer to complex
@retval Complex cosine
*/
Complex complex_cosine(Complex Z)
{
  Complex Z_num = NULL;      // Numerator
  Complex Z_cosine = NULL;   // Cosine
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates complex cosine
    Z_cosine = Cmplx_Hdlr.scalar(Z_num, 0.5);
    
    // Frees allocated memory for auxiliary variable
    Cmplx_Hdlr.del(Z_num);
  }
  
  return Z_cosine;
}

/**
@brief  Calculates the complex tangent of Z
@param  Z: Pointer to complex
@retval Complex tangent
*/
Complex complex_tangent(Complex Z)
{
  Complex Z_num = NULL;       // Numerator
  Complex Z_den = NULL;       // Denominator
  Complex Z_tangent = NULL;   // Tangent
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( sin(Z->Real) * ( exp(Z->Imag) - exp(-Z->Imag) ) , 
                             cos(Z->Real) * ( exp(Z->Imag) + exp(-Z->Imag) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex tangent
    Z_tangent = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_tangent;
}

/**
@brief  Calculates the complex cosecant of Z
@param  Z: Pointer to complex
@retval Complex cosecant
*/
Complex complex_cosecant(Complex Z)
{
  Complex Z_num = NULL;        // Numerator
  Complex Z_den = NULL;        // Denominator
  Complex Z_cosecant = NULL;   // Cosecant
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init(0, 2);
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex sine
    Z_cosecant = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_cosecant;
}

/**
@brief  Calculates the complex secant of Z
@param  Z: Pointer to complex
@retval Complex secant
*/
Complex complex_secant(Complex Z)
{
  Complex Z_num = NULL;      // Numerator
  Complex Z_den = NULL;      // Denominator
  Complex Z_secant = NULL;   // Secant
  
  if(Z != NULL)
  {
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) );
    
    if(Z_den == NULL)
    {
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.inv(Z_den);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for denominator
      Cmplx_Hdlr.del(Z_den);
      
      return NULL;
    }
    
    // Calculates complex secant
    Z_secant = Cmplx_Hdlr.scalar(Z_num, 2);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_secant;
}

/**
@brief  Calculates the complex cotangent of Z
@param  Z: Pointer to complex
@retval Complex cotangent
*/
Complex complex_cotangent(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_cotangent = NULL;   // Cotangent
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( sin(Z->Real) * ( exp(Z->Imag) - exp(-Z->Imag) ) , 
                             cos(Z->Real) * ( exp(Z->Imag) + exp(-Z->Imag) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Real) * ( exp(-Z->Imag) - exp(Z->Imag) ) , 
                             sin(Z->Real) * ( exp(-Z->Imag) + exp(Z->Imag) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex cotangent
    Z_cotangent = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_cotangent;
}

/**
@brief  Calculates the complex arcsine of Z
@param  Z: Pointer to complex
@retval Complex arcsine
*/
Complex complex_arcsine(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_asin = NULL;        // Arcsine
  
  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( 1 - pow(Z->Mod, 2) * cos(2 * Z->Arg) ), 
                                     ( - pow(Z->Mod, 2) * sin(2 * Z->Arg)   ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(-Z->Imag, Z->Real);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 1);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arcsine
    Z_asin = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_sum);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_asin;
}

/**
@brief  Calculates the complex arccosine of Z
@param  Z: Pointer to complex
@retval Complex arccosine
*/
Complex complex_arccosine(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_acos = NULL;        // Arccosine
  
  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( 1 - pow(Z->Mod, 2) * cos(2 * Z->Arg) ), 
                                     ( - pow(Z->Mod, 2) * sin(2 * Z->Arg)   ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(-Z->Imag, Z->Real);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 1);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arccosine
    Z_acos = Cmplx_Hdlr.division(Z_num, Z_den);
    Cmplx_Hdlr.update(Z_acos, PI/2 - Z_acos->Real, RE);
    Cmplx_Hdlr.update(Z_acos, -Z_acos->Imag, IM);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_acos;
}

/**
@brief  Calculates the complex arctangent of Z
@param  Z: Pointer to complex
@retval Complex arctangent
*/
Complex complex_arctangent(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_den = NULL;     // Denominator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_atan = NULL;        // Arctangent
  
  if(Z != NULL)
  {
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.init(1 - Z->Imag, Z->Real);
    
    if(Z_aux_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator of logarithm argument
    Z_aux_den = Cmplx_Hdlr.init(1 + Z->Imag, -Z->Real);
    
    if(Z_aux_den == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z_aux_den);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 2);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arctangent
    Z_atan = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_den);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_atan;
}

/**
@brief  Calculates the complex arccosecant of Z
@param  Z: Pointer to complex
@retval Complex arccosecant
*/
Complex complex_arccosecant(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_acsc = NULL;        // Arccosecant

  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( pow(Z->Mod, 2) * cos(2 * Z->Arg) - 1 ), 
                                     ( pow(Z->Mod, 2) * sin(2 * Z->Arg)     ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(0, 1);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 1);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arccosecant
    Z_acsc = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_sum);
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
   
  return Z_acsc;
}

/**
@brief  Calculates the complex arcsecant of Z
@param  Z: Pointer to complex
@retval Complex arcsecant
*/
Complex complex_arcsecant(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_asec = NULL;        // Arcsecant

  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( pow(Z->Mod, 2) * cos(2 * Z->Arg) - 1 ), 
                                     ( pow(Z->Mod, 2) * sin(2 * Z->Arg)     ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(0, 1);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 1);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arcsecant
    Z_asec = Cmplx_Hdlr.division(Z_num, Z_den);
    Cmplx_Hdlr.update(Z_asec, PI/2 - Z_asec->Real, RE);
    Cmplx_Hdlr.update(Z_asec, -Z_asec->Imag, IM);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_sum);
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
   
  return Z_asec;
}

/**
@brief  Calculates the complex arccotangent of Z
@param  Z: Pointer to complex
@retval Complex arccotangent
*/
Complex complex_arccotangent(Complex Z)
{
  Complex Z_num = NULL;         // Numerator
  Complex Z_den = NULL;         // Denominator
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_den = NULL;     // Denominator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_acot = NULL;        // Arccotangent
  
  if(Z != NULL)
  {
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.init(Z->Real, Z->Imag + 1);
    
    if(Z_aux_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator of logarithm argument
    Z_aux_den = Cmplx_Hdlr.init(Z->Real, Z->Imag - 1);
    
    if(Z_aux_den == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z_aux_den);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Allocates memory for denominator
    Z_den = Cmplx_Hdlr.init(0, 2);
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex arccotangent
    Z_acot = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_den);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_acot;
}

/**
@brief  Calculates the complex hyperbolic sine of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic sine
*/
Complex complex_hyperbolic_sine(Complex Z)
{
  Complex Z_num = NULL;    // Numerator
  Complex Z_sinh = NULL;   // Hyperbolic sine
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates complex hyperbolic sine
    Z_sinh = Cmplx_Hdlr.scalar(Z_num, 0.5);
    
    // Frees allocated memory for auxiliary variable
    Cmplx_Hdlr.del(Z_num);
  }
  
  return Z_sinh;
}

/**
@brief  Calculates the complex hyperbolic cosine of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic cosine
*/
Complex complex_hyperbolic_cosine(Complex Z)
{
  Complex Z_num = NULL;    // Numerator
  Complex Z_cosh = NULL;   // Hyperbolic cosine
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates complex hyperbolic cosine
    Z_cosh = Cmplx_Hdlr.scalar(Z_num, 0.5);
    
    // Frees allocated memory for auxiliary variable
    Cmplx_Hdlr.del(Z_num);
  }
  
  return Z_cosh;
}

/**
@brief  Calculates the complex hyperbolic tangent of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic tangent
*/
Complex complex_hyperbolic_tangent(Complex Z)
{
  Complex Z_num = NULL;       // Numerator
  Complex Z_den = NULL;       // Denominator
  Complex Z_tanh = NULL;      // Hyperbolic tangent
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic tangent
    Z_tanh = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_tanh;
}

/**
@brief  Calculates the complex hyperbolic cosecant of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic cosecant
*/
Complex complex_hyperbolic_cosecant(Complex Z)
{
  Complex Z_num = NULL;        // Numerator
  Complex Z_den = NULL;        // Denominator
  Complex Z_csch = NULL;       // Hyperbolic cosecant
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init(2, 0);
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic cosecant
    Z_csch = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_csch;
}

/**
@brief  Calculates the complex hyperbolic secant of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic secant
*/
Complex complex_hyperbolic_secant(Complex Z)
{
  Complex Z_num = NULL;        // Numerator
  Complex Z_den = NULL;        // Denominator
  Complex Z_sech = NULL;       // Hyperbolic secant
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init(2, 0);
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic secant
    Z_sech = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_sech;
}

/**
@brief  Calculates the complex hyperbolic cotangent of Z
@param  Z: Pointer to complex
@retval Complex hyperbolic cotangent
*/
Complex complex_hyperbolic_cotangent(Complex Z)
{
  Complex Z_num = NULL;       // Numerator
  Complex Z_den = NULL;       // Denominator
  Complex Z_coth = NULL;      // Hyperbolic cotangent
  
  if(Z != NULL)
  {
    // Calculates numerator
    Z_num = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) );
    
    if(Z_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator
    Z_den = Cmplx_Hdlr.init( cos(Z->Imag) * ( exp(Z->Real) - exp(-Z->Real) ) , 
                             sin(Z->Imag) * ( exp(Z->Real) + exp(-Z->Real) ) );
    
    if(Z_den == NULL)
    {
      // Frees allocated memory for numerator
      Cmplx_Hdlr.del(Z_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic cotangent
    Z_coth = Cmplx_Hdlr.division(Z_num, Z_den);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_num);
    Cmplx_Hdlr.del(Z_den);
  }
  
  return Z_coth;
}

/**
@brief  Calculates the complex hyperbolic arcsine of Z
@param  Z: Pointer to complex
@retval Complex arcsine
*/
Complex complex_hyperbolic_arcsine(Complex Z)
{
  Complex Z_aux_sqrtarg = NULL;  // Square root argument
  Complex Z_aux_sqrt = NULL;     // Square root
  Complex Z_aux_logarg = NULL;   // Logarithm argument
  Complex Z_asinh = NULL;        // Hyperbolic arcsine
  
  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( pow(Z->Mod, 2) * cos(2 * Z->Arg) + 1 ), 
                                     ( pow(Z->Mod, 2) * sin(2 * Z->Arg)     ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.sum(Z, Z_aux_sqrt);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arcsine
    Z_asinh = Cmplx_Hdlr.log(Z_aux_logarg);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_logarg);
  }
  
  return Z_asinh;
}

/**
@brief  Calculates the complex hyperbolic arccosine of Z
@param  Z: Pointer to complex
@retval Complex arccosine
*/
Complex complex_hyperbolic_arccosine(Complex Z)
{
  Complex Z_aux_sqrtarg = NULL;  // Square root argument
  Complex Z_aux_sqrt = NULL;     // Square root
  Complex Z_aux_logarg = NULL;   // Logarithm argument
  Complex Z_acosh = NULL;        // Hyperbolic arccosine
  
  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( pow(Z->Mod, 2) * cos(2 * Z->Arg) - 1 ), 
                                     ( pow(Z->Mod, 2) * sin(2 * Z->Arg)     ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.sum(Z, Z_aux_sqrt);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arccosine
    Z_acosh = Cmplx_Hdlr.log(Z_aux_logarg);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_logarg);
  }
  
  return Z_acosh;
}

/**
@brief  Calculates the complex hyperbolic arctangent of Z
@param  Z: Pointer to complex
@retval Complex arctangent
*/
Complex complex_hyperbolic_arctangent(Complex Z)
{
  Complex Z_num = NULL;          // Numerator
  Complex Z_aux_num = NULL;      // Numerator of logarithm argument
  Complex Z_aux_den = NULL;      // Denominator of logarithm argument
  Complex Z_aux_logarg = NULL;   // Logarithm argument
  Complex Z_atanh = NULL;        // Hyperbolic arctangent
  
  if(Z != NULL)
  {
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.init(1 + Z->Real, Z->Imag);
    
    if(Z_aux_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator of logarithm argument
    Z_aux_den = Cmplx_Hdlr.init(1 - Z->Real, -Z->Imag);
    
    if(Z_aux_den == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z_aux_den);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arctangent
    Z_atanh = Cmplx_Hdlr.scalar(Z_num, 0.5);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_den);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
  }
  
  return Z_atanh;
}

/**
@brief  Calculates the complex hyperbolic arccosecant of Z
@param  Z: Pointer to complex
@retval Complex arccosecant
*/
Complex complex_hyperbolic_arccosecant(Complex Z)
{
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_acsch = NULL;       // Hyperbolic arccosecant

  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( 1 + pow(Z->Mod, 2) * cos(2 * Z->Arg) ), 
                                     ( pow(Z->Mod, 2) * sin(2 * Z->Arg)     ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(1, 0);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arccosecant
    Z_acsch = Cmplx_Hdlr.log(Z_aux_logarg);

    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_sum);
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_logarg);
  }
   
  return Z_acsch;
}

/**
@brief  Calculates the complex hyperbolic arcsecant of Z
@param  Z: Pointer to complex
@retval Complex arcsecant
*/
Complex complex_hyperbolic_arcsecant(Complex Z)
{
  Complex Z_aux_sum = NULL;     // Summand
  Complex Z_aux_sqrtarg = NULL; // Square root argument
  Complex Z_aux_sqrt = NULL;    // Square root
  Complex Z_aux_num = NULL;     // Numerator of logarithm argument
  Complex Z_aux_logarg = NULL;  // Logarithm argument
  Complex Z_asech = NULL;       // Hyperbolic arcsecant

  if(Z != NULL)
  {
    // Calculates square root argument
    Z_aux_sqrtarg = Cmplx_Hdlr.init( ( 1 - pow(Z->Mod, 2) * cos(2 * Z->Arg) ), 
                                     ( -pow(Z->Mod, 2) * sin(2 * Z->Arg)    ) );
    
    if(Z_aux_sqrtarg == NULL)
    {
      return NULL;
    }
    
    // Calculates square root of logarithm argument
    Z_aux_sqrt = Cmplx_Hdlr.sqrt(Z_aux_sqrtarg);
    
    if(Z_aux_sqrt == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      
      return NULL;
    }
    
    // Allocates memory for sum element
    Z_aux_sum = Cmplx_Hdlr.init(1, 0);
    
    if(Z_aux_sum == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      
      return NULL;
    }
    
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.sum(Z_aux_sum, Z_aux_sqrt);
    
    if(Z_aux_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_sqrtarg);
      Cmplx_Hdlr.del(Z_aux_sqrt);
      Cmplx_Hdlr.del(Z_aux_sum);
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arcsecant
    Z_asech = Cmplx_Hdlr.log(Z_aux_logarg);

    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_sqrtarg);
    Cmplx_Hdlr.del(Z_aux_sqrt);
    Cmplx_Hdlr.del(Z_aux_sum);
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_logarg);
  }
   
  return Z_asech;
}

/**
@brief  Calculates the complex hyperbolic arccotangent of Z
@param  Z: Pointer to complex
@retval Complex arccotangent
*/
Complex complex_hyperbolic_arccotangent(Complex Z)
{
  Complex Z_num = NULL;          // Numerator
  Complex Z_aux_num = NULL;      // Numerator of logarithm argument
  Complex Z_aux_den = NULL;      // Denominator of logarithm argument
  Complex Z_aux_logarg = NULL;   // Logarithm argument
  Complex Z_acoth = NULL;        // Hyperbolic arccotangent
  
  if(Z != NULL)
  {
    // Calculates numerator of logarithm argument
    Z_aux_num = Cmplx_Hdlr.init(Z->Real + 1, Z->Imag);
    
    if(Z_aux_num == NULL)
    {
      return NULL;
    }
    
    // Calculates denominator of logarithm argument
    Z_aux_den = Cmplx_Hdlr.init(Z->Real - 1, Z->Imag);
    
    if(Z_aux_den == NULL)
    {
      // Frees allocated memory for auxiliary variable
      Cmplx_Hdlr.del(Z_aux_num);
      
      return NULL;
    }
    
    // Calculates logarithm argument
    Z_aux_logarg = Cmplx_Hdlr.division(Z_aux_num, Z_aux_den);
    
    if(Z_aux_logarg == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      
      return NULL;
    }
    
    // Calculates numerator
    Z_num = Cmplx_Hdlr.log(Z_aux_logarg);
    
    if(Z_num == NULL)
    {
      // Frees allocated memory for auxiliary variables
      Cmplx_Hdlr.del(Z_aux_num);
      Cmplx_Hdlr.del(Z_aux_den);
      Cmplx_Hdlr.del(Z_aux_logarg);
      
      return NULL;
    }
    
    // Calculates complex hyperbolic arccotangent
    Z_acoth = Cmplx_Hdlr.scalar(Z_num, 0.5);
    
    // Frees allocated memory for auxiliary variables
    Cmplx_Hdlr.del(Z_aux_num);
    Cmplx_Hdlr.del(Z_aux_den);
    Cmplx_Hdlr.del(Z_aux_logarg);
    Cmplx_Hdlr.del(Z_num);
  }
  
  return Z_acoth;
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
      if(Z->Imag > 0)
      {
        printf("%.04f + %.04f i\n", Z->Real, Z->Imag);
      }
      else if(Z->Imag < 0)
      {
        printf("%.04f %.04f i\n", Z->Real, Z->Imag);
      }
      else if(Z->Imag == 0)
      {
        printf("%.04f\n", Z->Real);
      }
      else if(Z->Real == 0)
      {
        printf("%.04f i\n", Z->Real);
      }
      
      break;
    
    // Polar form
    case POLAR:
      printf( "%.04f < %.04f\n", Z->Mod, Cmplx_Hdlr.argument(Z, DEG) );
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

