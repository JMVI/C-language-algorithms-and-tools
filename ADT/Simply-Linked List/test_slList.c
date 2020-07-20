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
      printf("ERROR IN ADD OPERATION\n");
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

  // Read an existing element
  printf("Reading an existing element of the list (Size: %d)\n", SLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  if( !LList_Hdlr.read(SLL, i, &val) )
  {
    printf("ERROR IN READ OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val);
  }
  
  // Read a non-existing element
  printf("Reading a non-existing element of the list\n");
  
  i = 7; printf("index = 7\n");
  
  if( !LList_Hdlr.read(SLL, i, &val) )
  {
    printf("ERROR IN READ OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val);
  }
  
  // Update an existing element
  printf("Updating an existing element of the list (Size: %d)\n", SLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  printf("New value = "); scanf("%d", &val); printf("\n");
  
  if( !LList_Hdlr.update(SLL, i, val) )
  {
    printf("ERROR IN UPDATE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  llist_print(SLL);
  printf("\n");
  
  // Update a non-existing element
  printf("Updating a non-existing element of the list\n");
  
  i = 7; printf("index = %d\n", i);
  
  val = 1000; printf("New value = %d\n", val);
  
  if( !LList_Hdlr.update(SLL, i, val) )
  {
    printf("ERROR IN UPDATE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  llist_print(SLL);
  printf("\n");
  
  // Delete first element
  printf("Deleting first element of the list (Size: %d)\n", SLL->size);
  
  i = 0; printf("index = %d\n", i);
  
  if( !LList_Hdlr.del(SLL, i) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  
  // Print list
  llist_print(SLL);
  printf("\n");
  
  // Delete an existing element
  printf("Deleting an existing element of the list (Size: %d)\n", SLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  if( !LList_Hdlr.del(SLL, i) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  
  // Print list
  llist_print(SLL);
  printf("\n");
  
  // Delete a non-existing element
  printf("Deleting a non-existing element of the list\n");
  
  i = 7; printf("index = %d\n", i);
  
  if( !LList_Hdlr.update(SLL, i, val) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  llist_print(SLL);
  printf("\n");
  
  // Fill up list
  printf("* Filling up list *\n");

  i = SLL->size;

  do
  {
    printf("%d elements left \n", SLL->maxSize - SLL->size);

    printf("(%d) = ", i); scanf("%d", &val); printf("\n"); 
    
    printf("Read value = %d\n", val);

    if( !LList_Hdlr.add(SLL, val) )
    {
      printf("ERROR IN ADD OPERATION");
    }

    // Print list
    llist_print(SLL);
    printf("\n");

    printf("List's size: %d\n", SLL->size);
    
    i++;
    
  } while( !LList_Hdlr.isFull(SLL) );

  // Try to insert five elements into full list
  printf("* Try to add to full list *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", SLL->size + 1); scanf("%d", &val); printf("\n");

    if( !LList_Hdlr.add(SLL, val) )
    {
      printf("ERROR IN ADD OPERATION\n");
    }
    
    if( LList_Hdlr.isFull(SLL) )
    {
      printf("List is full\n");
    }
  }
  
  // Erase list
  if( !LList_Hdlr.erase(SLL) )
  {
    printf("ERROR EREASING LIST\n");
    exit(-1);
  }

  printf("List ereased\n");

  printf("***** END OF TEST *****");

  return 0;
}
