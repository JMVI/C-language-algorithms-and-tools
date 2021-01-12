/* -----------------------------------------------------------------------------
 * Copyright (C) 2021 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_complex.c
 * Description   : Test file for complex numbers ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 01/12/2021
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Complex.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//
int main()
{
  // New complex numbers
  Complex Z1 = NULL, Z2 = NULL, Z3 = NULL, Z4 = NULL, Z5 = NULL;
  
  printf("***** BEGIN OF TEST *****\n");
  printf("\n");
  
  // Initialize complex numbers
  Z1 = Cmplx_Hdlr.init(2.0, 3.0);        // Z1 = 2 + 3i
  Z2 = Cmplx_Hdlr.init(-1.0, 5.6);       // Z2 = -1 + 5.6i
  Z3 = Cmplx_Hdlr.init(0.0, 0.0);        // Z3 = 0 + 0i
  Z4 = Cmplx_Hdlr.init(10.0, 0.0);       // Z4 = 10 + 0i
  Z5 = Cmplx_Hdlr.init(0.0, 5.0);        // Z5 = 0 + 5i
  
  // Validate memory allocation
  if(Z1 == NULL || Z2 == NULL || Z3 == NULL || Z4 == NULL || Z5 == NULL) 
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("Complex numbers created \n");
    
    printf("Z1: \n");
    printf("Rectangular form: Z1 = "); complex_print(Z1, CARTESIAN);
    printf("Polar form: Z1 = "); complex_print(Z1, POLAR);
    printf("Euler's' formula: Z1 = "); complex_print(Z1, EULER);
    printf("| Z1 | = %.04f\n", Cmplx_Hdlr.modulus(Z1) );
    printf("< Z1 = %.04f deg | Z1 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z1, DEG), 
            Cmplx_Hdlr.argument(Z1, RAD) );
    
    printf("\n");
    
    printf("Z2: \n");
    printf("Rectangular form: Z2 = "); complex_print(Z2, CARTESIAN);
    printf("Polar form: Z2 = "); complex_print(Z2, POLAR);
    printf("Euler's' formula: Z2 = "); complex_print(Z2, EULER);
    printf("| Z2 | = %.04f\n", Cmplx_Hdlr.modulus(Z2) );
    printf("< Z2 = %.04f deg | Z2 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z2, DEG), 
            Cmplx_Hdlr.argument(Z2, RAD) );
    
    printf("\n");
    
    printf("Z3: \n");
    printf("Rectangular form: Z3 = "); complex_print(Z3, CARTESIAN);
    printf("Polar form: Z3 = "); complex_print(Z3, POLAR);
    printf("Euler's' formula: Z3 = "); complex_print(Z3, EULER);
    printf( "| Z3 | = %.04f\n", Cmplx_Hdlr.modulus(Z3) );
    printf( "< Z3 = %.04f deg | Z3 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z3, DEG), 
            Cmplx_Hdlr.argument(Z3, RAD) );
            
    printf("\n");
    
    printf("Z4: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
    
    printf("Z5: \n");
    printf("Rectangular form: Z5 = "); complex_print(Z5, CARTESIAN);
    printf("Polar form: Z5 = "); complex_print(Z5, POLAR);
    printf("Euler's' formula: Z5 = "); complex_print(Z5, EULER);
    printf( "| Z5 | = %.04f\n", Cmplx_Hdlr.modulus(Z5) );
    printf( "< Z5 = %.04f deg | Z5 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z5, DEG), 
            Cmplx_Hdlr.argument(Z5, RAD) );
    
    printf("\n");
  }
  
  // Verify if complex numbers are null
  if( Cmplx_Hdlr.isNull(Z1) )
  {
    printf("Z1 is a null complex\n");
  }
  
  if( Cmplx_Hdlr.isNull(Z2) )
  {
    printf("Z2 is a null complex\n");
  }
  
  if( Cmplx_Hdlr.isNull(Z3) )
  {
    printf("Z3 is a null complex\n");
  }
  
  if( Cmplx_Hdlr.isNull(Z4) )
  {
    printf("Z4 is a null complex\n");
  }
  
  if( Cmplx_Hdlr.isNull(Z5) )
  {
    printf("Z5 is a null complex\n");
  }
  
  printf("\n");
  
  // Verify if Z4 and Z5 are equal
  if( !Cmplx_Hdlr.areEqual(Z4, Z5) )
  {
    printf("Z4 and Z5 are not equal\n");
  }
  
  printf("\n");
  
  // Update Z4 and Z5
  if( Cmplx_Hdlr.update(Z4, 5.0, IM) && Cmplx_Hdlr.update(Z5, 10.0, RE) )
  {
    printf("Z4: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
    
    printf("Z5: \n");
    printf("Rectangular form: Z5 = "); complex_print(Z5, CARTESIAN);
    printf("Polar form: Z5 = "); complex_print(Z5, POLAR);
    printf("Euler's' formula: Z5 = "); complex_print(Z5, EULER);
    printf( "| Z5 | = %.04f\n", Cmplx_Hdlr.modulus(Z5) );
    printf( "< Z5 = %.04f deg | Z5 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z5, DEG), 
            Cmplx_Hdlr.argument(Z5, RAD) );
            
    printf("\n");
  }
  else
  {
    printf("ERROR UPDATING COMPLEX NUMBERS\n");
    exit(-1);
  }
    
  // Verify again if Z4 and Z5 are equal
  if( Cmplx_Hdlr.areEqual(Z4, Z5) )
  {
    printf("Z4 and Z5 are equal\n");
  }
  
  printf("\n");
  
  // Complex conjugation
  
  // Delete Z5
  if( !Cmplx_Hdlr.del(Z5)   )
  {
    printf("ERROR DELETING Z5\n");
    exit(-1);
  }
  
  // Z5 = Conj(Z4)
  Z5 = Cmplx_Hdlr.conjugate(Z4);
  
  if(Z5 == NULL)
  {
    printf("ERROR CONJUGATING Z4\n");
    exit(-1);
  }
  else
  {
    printf("Z4: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
    
    printf("Z5 = Conj(Z4): \n");
    printf("Rectangular form: Z5 = "); complex_print(Z5, CARTESIAN);
    printf("Polar form: Z5 = "); complex_print(Z5, POLAR);
    printf("Euler's' formula: Z5 = "); complex_print(Z5, EULER);
    printf( "| Z5 | = %.04f\n", Cmplx_Hdlr.modulus(Z5) );
    printf( "< Z5 = %.04f deg | Z5 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z5, DEG), 
            Cmplx_Hdlr.argument(Z5, RAD) );
            
    printf("\n");
  }
  
  printf("\n");
  
  // Complex operations
  printf("Complex mathematic operations:\n");
  
  printf("\n");
  
  // 1. Sum
  
  // Delete Z3 to allocate result
  if( !Cmplx_Hdlr.del(Z3)   )
  {
    printf("ERROR DELETING Z3\n");
    exit(-1);
  }
  
  // Calculate complex sum
  Z3 = Cmplx_Hdlr.sum(Z1, Z2);
  
  if(Z3 == NULL)
  {
    printf("ERROR IN SUM OPERATION\n");
    exit(-1);
  }
  else
  {
    printf("Z3 = Z1 + Z2: \n");
    printf("Rectangular form: Z3 = "); complex_print(Z3, CARTESIAN);
    printf("Polar form: Z3 = "); complex_print(Z3, POLAR);
    printf("Euler's' formula: Z3 = "); complex_print(Z3, EULER);
    printf( "| Z3 | = %.04f\n", Cmplx_Hdlr.modulus(Z3) );
    printf( "< Z3 = %.04f deg | Z3 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z3, DEG), 
            Cmplx_Hdlr.argument(Z3, RAD) );
            
    printf("\n");
  }
  
  // 2. Subtraction
  
  // Delete Z3 to allocate result
  if( !Cmplx_Hdlr.del(Z3)   )
  {
    printf("ERROR DELETING Z3\n");
    exit(-1);
  }
  
  // Calculate complex subtraction
  Z3 = Cmplx_Hdlr.sub(Z1, Z2);
  
  if(Z3 == NULL)
  {
    printf("ERROR IN SUBTRACTION OPERATION\n");
    exit(-1);
  }
  else
  {
    printf("Z3 = Z1 - Z2: \n");
    printf("Rectangular form: Z3 = "); complex_print(Z3, CARTESIAN);
    printf("Polar form: Z3 = "); complex_print(Z3, POLAR);
    printf("Euler's' formula: Z3 = "); complex_print(Z3, EULER);
    printf( "| Z3 | = %.04f\n", Cmplx_Hdlr.modulus(Z3) );
    printf( "< Z3 = %.04f deg | Z3 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z3, DEG), 
            Cmplx_Hdlr.argument(Z3, RAD) );
            
    printf("\n");
  }
  
  // 3. Complex product
  
  // Delete Z3 to allocate result
  if( !Cmplx_Hdlr.del(Z3)   )
  {
    printf("ERROR DELETING Z3\n");
    exit(-1);
  }
  
  // Calculate complex product
  Z3 = Cmplx_Hdlr.product(Z1, Z2);
  
  if(Z3 == NULL)
  {
    printf("ERROR IN PRODUCT OPERATION\n");
    exit(-1);
  }
  else
  {
    printf("Z3 = Z1 * Z2: \n");
    printf("Rectangular form: Z3 = "); complex_print(Z3, CARTESIAN);
    printf("Polar form: Z3 = "); complex_print(Z3, POLAR);
    printf("Euler's' formula: Z3 = "); complex_print(Z3, EULER);
    printf( "| Z3 | = %.04f\n", Cmplx_Hdlr.modulus(Z3) );
    printf( "< Z3 = %.04f deg | Z3 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z3, DEG), 
            Cmplx_Hdlr.argument(Z3, RAD) );
            
    printf("\n");
  }
  
  // 4. Scalar product
  
  // Delete Z3 to allocate result
  if( !Cmplx_Hdlr.del(Z3)   )
  {
    printf("ERROR DELETING Z3\n");
    exit(-1);
  }
  
  // Calculate scalar product
  Z3 = Cmplx_Hdlr.scalar(Z1, 10);
  
  if(Z3 == NULL)
  {
    printf("ERROR IN SCALAR PRODUCT OPERATION\n");
    exit(-1);
  }
  else
  {
    printf("Z3 = 10*Z1: \n");
    printf("Rectangular form: Z3 = "); complex_print(Z3, CARTESIAN);
    printf("Polar form: Z3 = "); complex_print(Z3, POLAR);
    printf("Euler's' formula: Z3 = "); complex_print(Z3, EULER);
    printf( "| Z3 | = %.04f\n", Cmplx_Hdlr.modulus(Z3) );
    printf( "< Z3 = %.04f deg | Z3 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z3, DEG), 
            Cmplx_Hdlr.argument(Z3, RAD) );
            
    printf("\n");
  }
  
  // 5. Division
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Update Z3 to a null Complex
  if( !Cmplx_Hdlr.update(Z3, 0.0, IM) || !Cmplx_Hdlr.update(Z3, 0.0, RE) )
  {
    printf("ERROR UPDATING COMPLEX NUMBER\n");
    exit(-1);
  }
  
  // Calculate division
  Z4 = Cmplx_Hdlr.division(Z1, Z2);
  
  if(Z4 == NULL)
  {
    printf("ERROR IN DIVISION OPERATION\n");
  }
  else
  {
    printf("Z4 = Z1 / Z2: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete Z5 to allocate result
  if( !Cmplx_Hdlr.del(Z5)   )
  {
    printf("ERROR DELETING Z5\n");
    exit(-1);
  }
  
  // Try to calculate division with a null complex
  Z5 = Cmplx_Hdlr.division(Z1, Z3);
  
  if(Z5 == NULL)
  {
    printf("ERROR IN DIVISION OPERATION (NULL COMPLEX)\n");
  }
  
  printf("\n");
  
  // Reinitialize Z5 to a null complex
  Z5 = Cmplx_Hdlr.init(0.0, 0.0);
  
  // 6. Reciprocal
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate reciprocal
  Z4 = Cmplx_Hdlr.inv(Z1);
  
  if(Z4 == NULL)
  {
    printf("ERROR IN DIVISION OPERATION\n");
  }
  else
  {
    printf("Z4 = 1 / Z1: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete Z5 to allocate result
  if( !Cmplx_Hdlr.del(Z5)   )
  {
    printf("ERROR DELETING Z5\n");
    exit(-1);
  }
  
  // Try to calculate reciprocal of a null complex
  Z5 = Cmplx_Hdlr.inv(Z3);
  
  if(Z5 == NULL)
  {
    printf("ERROR IN DIVISION OPERATION (NULL COMPLEX)\n");
  }
  
  printf("\n");
  
  // Reinitialize Z5 to a null complex
  Z5 = Cmplx_Hdlr.init(0.0, 0.0);
  
  // 7. Real exponential
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate exponential
  Z4 = Cmplx_Hdlr.pow(Z1, 3) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = Z1^3: \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate exponential
  Z4 = Cmplx_Hdlr.pow(Z1, -2.5) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = Z1^(-2.5): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // 8. Natural exponential
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate exponential
  Z4 = Cmplx_Hdlr.exp(Z1) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = exp(Z1): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate exponential
  Z4 = Cmplx_Hdlr.exp(Z5) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = exp(Z5): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // 9. Square root
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate square root
  Z4 = Cmplx_Hdlr.sqrt(Z1) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = sqrt(Z1): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate square root
  Z4 = Cmplx_Hdlr.sqrt(Z5) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = sqrt(Z5): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // 10. Nth root
  
  // Delete Z4 to allocate result
  if( !Cmplx_Hdlr.del(Z4)   )
  {
    printf("ERROR DELETING Z4\n");
    exit(-1);
  }
  
  // Calculate 5th root
  Z4 = Cmplx_Hdlr.nthroot(Z1, 5) ;
  
  if(Z4 == NULL)
  {
    printf("ERROR IN POWER OPERATION\n");
  }
  else
  {
    printf("Z4 = Z1^(1/5): \n");
    printf("Rectangular form: Z4 = "); complex_print(Z4, CARTESIAN);
    printf("Polar form: Z4 = "); complex_print(Z4, POLAR);
    printf("Euler's' formula: Z4 = "); complex_print(Z4, EULER);
    printf( "| Z4 | = %.04f\n", Cmplx_Hdlr.modulus(Z4) );
    printf( "< Z4 = %.04f deg | Z4 = %.04f rad\n", 
            Cmplx_Hdlr.argument(Z4, DEG), 
            Cmplx_Hdlr.argument(Z4, RAD) );
            
    printf("\n");
  }
  
  // Delete complex numbers
  if( !Cmplx_Hdlr.del(Z1) || !Cmplx_Hdlr.del(Z2) || !Cmplx_Hdlr.del(Z3) ||
      !Cmplx_Hdlr.del(Z4) || !Cmplx_Hdlr.del(Z5)   )
  {
    printf("ERROR DELETING COMPLEX NUMBERS\n");
    exit(-1);
  }
  
  printf("Complex numbers deleted\n");
  printf("\n");
  
  printf("***** END OF TEST *****");
  
  return 0;
}
