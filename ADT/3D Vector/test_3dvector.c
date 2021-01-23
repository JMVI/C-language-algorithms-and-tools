/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_3dvector.c
 * Description   : Test file for 3D vector ADT.
 * Version       : 01.00
 * Revision      : 01
 * Last modified : 08/09/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_3DVector.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//

int main()
{
  // New vectors
  Vector V1 = NULL, V2 = NULL, V3 = NULL, V4 = NULL, V5 = NULL;
  
  printf("***** BEGIN OF TEST *****\n");
  
  // Initialize vectors
  V1 = V_Hdlr.init(2.5, 1.0, -4.6);
  V2 = V_Hdlr.init(-1.2, 0.0, -3.3);
  
  // Validate memory allocation
  if(V1 == NULL || V2 == NULL) 
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("Vectors created \n");
    printf("V1 = "); vector_print(V1);
    printf("V2 = "); vector_print(V2);
    printf("\n");
  }
  
  // Verify if vectors are null
  if( !V_Hdlr.isNull(V1) )
  {
    printf("V1 is not null\n");
  }
  
  if( !V_Hdlr.isNull(V2) )
  {
    printf("V2 is not null\n");
  }
  
  // Verify if vectors are equal
  if( !V_Hdlr.areEqual(V1, V2) )
  {
    printf("V1 and V2 are not equal\n");
  }
  
  // Print vector lengths
  printf("Vector lengths:\n");
  printf( "|| V1 || = %.03f \n", V_Hdlr.length(V1) );
  printf( "|| V2 || = %.03f \n", V_Hdlr.length(V2) );
  
  // Update vector element
  printf("Update X coordinate (V1x = 10)\n");
  
  if( V_Hdlr.update(V1, 10.0, vx) )
  {
    printf("V1 = "); vector_print(V1);
  }
  else
  {
    printf("ERROR IN UPDATE OPERATION\n");
  }
  
  // Sum vectors
  printf("Sum of vectors V1 and V2\n");
  
  V3 = V_Hdlr.sum(V1, V2);
  
  if(V3 != NULL)
  {
    printf("V3 = V1 + V2 = "); vector_print(V3);
  }
  else
  {
    printf("ERROR IN SUM OPERATION\n");
  }
  
  // Scalar product
  printf("Scalar product of vector V1 and k = 2.0\n");
  
  V4 = V_Hdlr.scalar(2.0, V1);
  
  if(V4 != NULL)
  {
    printf("V4 = k*V1 = "); vector_print(V4);
  }
  else
  {
    printf("ERROR IN SCALAR PRODUCT OPERATION\n");
  }
  
  // Dot product
  printf("Dot product of vectors V1 and V2\n");
  
  printf( "V5 = V1.V2 = %.03f\n", V_Hdlr.dot(V1, V2) );
  
  // Cross product
  printf("Cross product of vectors V1 and V2\n");
  
  V5 = V_Hdlr.cross(V1, V2);
  
  if(V5 != NULL)
  {
    printf("V5 = V1xV2 = "); vector_print(V5);
  }
  else
  {
    printf("ERROR IN CROSS PRODUCT OPERATION\n");
  }
    
  // Verifiy orthogonality
  printf("Verify orthogonality V1-V5 and V2-V5 \n");
  
  if(V5 != NULL)
  {
    if( abs(V_Hdlr.dot(V1, V5) ) == 0 )
    {
      printf("V1 and V5 are orthogonal (V1.V5 = %.03f)\n", V_Hdlr.dot(V1, V5));
    }
    
    if( abs(V_Hdlr.dot(V2, V5) ) == 0 )
    {
      printf("V2 and V5 are orthogonal (V2.V5 = %.03f)\n", V_Hdlr.dot(V2, V5));
    }
  }
    
  // Angle
  printf("Angle between vectors (degrees)\n");
  printf( "<(V1,V2) = %.03f\n", V_Hdlr.angle(V1, V2, DEG) );
  printf( "<(V1,V5) = %.03f\n", V_Hdlr.angle(V1, V5, DEG) );
  printf( "<(V2,V5) = %.03f\n", V_Hdlr.angle(V2, V5, DEG) );
  
  // Delete vectors
  if( !V_Hdlr.del(V1) || !V_Hdlr.del(V2) || !V_Hdlr.del(V3) ||
      !V_Hdlr.del(V4) || !V_Hdlr.del(V5)   )
  {
    printf("ERROR DELETING VECTORS\n");
    exit(-1);
  }

  printf("Vectors deleted\n");

  printf("***** END OF TEST *****");
  
  return 0;
}
