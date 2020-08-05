/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_dlList.c
 * Description   : Test file for doubly linked list ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 08/05/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_DoublyLinkedList.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//

int main() 
{
  DList DLL = NULL;       // New list
  Data val = 0;           // Read value
  uint8_t maxSize = 10;   // Maximum list size
  uint16_t i = 0;         // Iterator

  printf("***** BEGIN OF TEST *****\n");

  // Create empty list (max. 10 elements)
  DLL = DList_Hdlr.init(maxSize);

  // Validate memory allocation
  if(DLL == NULL)
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("List created (Max. size: %d)\n", DLL->maxSize);
  }

  // Verify if list is empty
  if( DList_Hdlr.isEmpty(DLL) )
  {
    printf("New list is empty\n");
  }

  // Insert five (5) elements
  printf("* Add five elements *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", i); scanf("%d", &val); printf("\n");

    if( !DList_Hdlr.add(DLL, val) )
    {
      printf("ERROR IN ADD OPERATION\n");
    }

    // Print list
    dlist_print(DLL);
    printf("\n");
  }
  
  // Verify if list is not empty
  if( !DList_Hdlr.isEmpty(DLL) )
  {
    printf( "List is not empty (%d)\n", DList_Hdlr.isEmpty(DLL) );
  }

  // Verify if list is not full
  if( !DList_Hdlr.isFull(DLL) )
  {
    printf( "List is not full (%d)\n", DList_Hdlr.isFull(DLL) );
  }

  // Read an existing element
  printf("Reading an existing element of the list (Size: %d)\n", DLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  if( !DList_Hdlr.read(DLL, i, &val) )
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
  
  if( !DList_Hdlr.read(DLL, i, &val) )
  {
    printf("ERROR IN READ OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val);
  }
  
  // Update an existing element
  printf("Updating an existing element of the list (Size: %d)\n", DLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  printf("New value = "); scanf("%d", &val); printf("\n");
  
  if( !DList_Hdlr.update(DLL, i, val) )
  {
    printf("ERROR IN UPDATE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  dlist_print(DLL);
  printf("\n");
  
  // Update a non-existing element
  printf("Updating a non-existing element of the list\n");
  
  i = 7; printf("index = %d\n", i);
  
  val = 1000; printf("New value = %d\n", val);
  
  if( !DList_Hdlr.update(DLL, i, val) )
  {
    printf("ERROR IN UPDATE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  dlist_print(DLL);
  printf("\n");
  
  // Delete first element
  printf("Deleting first element of the list (Size: %d)\n", DLL->size);
  
  i = 0; printf("index = %d\n", i);
  
  if( !DList_Hdlr.del(DLL, i) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  
  // Print list
  dlist_print(DLL);
  printf("\n");
  
  // Delete an existing element
  printf("Deleting an existing element of the list (Size: %d)\n", DLL->size);
  
  printf("index = "); scanf("%d", &i); printf("\n");
  
  if( !DList_Hdlr.del(DLL, i) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  
  // Print list
  dlist_print(DLL);
  printf("\n");
  
  // Delete a non-existing element
  printf("Deleting a non-existing element of the list\n");
  
  i = 7; printf("index = %d\n", i);
  
  if( !DList_Hdlr.update(DLL, i, val) )
  {
    printf("ERROR IN DELETE OPERATION\n");
  }
  else
  {
    printf("L(%d) : %d\n", i, val); printf("\n");
  }
  
  // Print list
  dlist_print(DLL);
  printf("\n");
  
  // Fill up list
  printf("* Filling up list *\n");

  i = DLL->size;

  do
  {
    printf("%d elements left \n", DLL->maxSize - DLL->size);

    printf("(%d) = ", i); scanf("%d", &val); printf("\n"); 
    
    printf("Read value = %d\n", val);

    if( !DList_Hdlr.add(DLL, val) )
    {
      printf("ERROR IN ADD OPERATION");
    }

    // Print list
    dlist_print(DLL);
    printf("\n");

    printf("List's size: %d\n", DLL->size);
    
    i++;
    
  } while( !DList_Hdlr.isFull(DLL) );

  // Try to insert five elements into full list
  printf("* Try to add to full list *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", DLL->size + 1); scanf("%d", &val); printf("\n");

    if( !DList_Hdlr.add(DLL, val) )
    {
      printf("ERROR IN ADD OPERATION\n");
    }
    
    if( DList_Hdlr.isFull(DLL) )
    {
      printf("List is full\n");
    }
  }
  
  // Erase list
  if( !DList_Hdlr.erase(DLL) )
  {
    printf("ERROR EREASING LIST\n");
    exit(-1);
  }

  printf("List ereased\n");

  printf("***** END OF TEST *****");

  return 0;
}
