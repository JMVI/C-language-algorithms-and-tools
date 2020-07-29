/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_3dvector.c
 * Description   : Test file for 3D vector ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/28/2020
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
  Vector V1 = NULL, V2 = NULL;    // New vectors
  
  printf("***** BEGIN OF TEST *****\n");
  
  // Initialize vectors
  V1 = V_Hdlr.init(2.5, 1, -4.6);
  V2 = V_Hdlr.init(-1.2, 0, -4.6);
  
  // Validate memory allocation
  if(V1 == NULL || V2 == NULL) 
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("Vectors created \n");
    vector_print(V1);
    vector_print(V2);
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
  
  // Delete vectors
  if( !V_Hdlr.del(V1) || !V_Hdlr.del(V2) )
  {
    printf("ERROR DELETING VECTORS\n");
    exit(-1);
  }

  printf("Vectors deleted\n");

  printf("***** END OF TEST *****");
  
  return 0;
}
