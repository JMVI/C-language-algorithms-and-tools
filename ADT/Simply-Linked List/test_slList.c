/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_slList.c
 * Description   : Test file for simply linked list ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/19/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_SimplyLinkedList.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//

int main() 
{
  LList SLL = NULL;       // New list
  Data val = 0;           // Read value
  uint8_t maxSize = 10;   // Maximum list size
  uint16_t i = 0;         // Iterator

  printf("***** BEGIN OF TEST *****\n");

  // Create empty list (max. 10 elements)
  SLL = LList_Hdlr.init(maxSize);

  // Validate memory allocation
  if(SLL == NULL)
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("List created (Max. size: %d)\n", SLL->maxSize);
  }

  // Verify if list is empty
  if( LList_Hdlr.isEmpty(SLL) )
  {
    printf("New list is empty\n");
  }

  // Insert five (5) elements
  printf("* Add five elements *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", i); scanf("%d", &val); printf("\n");

    if( !LList_Hdlr.add(SLL, val) )
    {
      printf("ERROR IN ADD OPERATION");
    }

    // Print list
    llist_print(SLL);
    printf("\n");
  }
  
  // Verify if list is not empty
  if( !LList_Hdlr.isEmpty(SLL) )
  {
    printf( "List is not empty (%d)\n", LList_Hdlr.isEmpty(SLL) );
  }

  // Verify if list is not full
  if( !LList_Hdlr.isFull(SLL) )
  {
    printf( "List is not full (%d)\n", LList_Hdlr.isFull(SLL) );
  }

  // Read, update, delete tests
  // (...)
  
  // Delete list
  if( !LList_Hdlr.erase(SLL) )
  {
    printf("ERROR DELETING LIST\n");
    exit(-1);
  }

  printf("List deleted\n");

  printf("***** END OF TEST *****");

  return 0;
}
