/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_DoublyLinkedList.c
 * Description   : Abstract Data Type for doubly linked list. Implementation 
 *                 with integer data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/22/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_DoublyLinkedList.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// List handler
t_DListHandler DList_Hdlr =
{
  dlist_createLinkedList,  // Create linked list
  dlist_isEmpty,           // Is list empty?
  dlist_isFull,            // Is list empty?
  dlist_addItem,           // Add element
  dlist_readItem,          // Read element
  dlist_updateItem,        // Update element
  dlist_deleteItem,        // Delete element
  dlist_clear,             // Clear list
  dlist_erase              // Erase list
};

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new list
@param  maxS: Maximum size of list
@retval Pointer to new list
*/
DList dlist_createLinkedList(uint16_t maxS)
{
  DList newList = (DList)malloc(sizeof(linked_list)); // Memory allocation
  newList->size = 0;                                  // Initializes empty list
  newList->first = NULL;                              // Initial first element
  newList->last = NULL;                               // Initial last element
  newList->maxSize = maxS;                            // Fix max. size

  return newList;
}

/**
@brief  Verifies if list is empty
@param  dll: Pointer to list
@retval TRUE if list is empty, FALSE otherwise
*/
uint8_t dlist_isEmpty(DList dll)
{
  return (dll->size == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if list is full
@param  dll: Pointer to list
@retval TRUE if list is full, FALSE otherwise
*/
uint8_t dlist_isFull(DList dll)
{
  return (dll->size == dll->maxSize) ? TRUE : FALSE;
}

/**
@brief  Adds an element into the list
@param  dll: Pointer to list
        val: Value
@retval TRUE if value was correctly added, FALSE otherwise
*/
uint8_t dlist_addItem(DList dll, Data val)
{
  Node newNode = (Node)malloc(sizeof(node)); // Memory allocation for node
  
  // Validates memory allocation
  if(newNode == NULL)
  {
    return FALSE;
  }

  // Validates indicated list
  if( dll != NULL && !DList_Hdlr.isFull(dll) )
  {
    // Stores value
    newNode->value = val;
    
    // Initializes pointers
    newNode->next = NULL;
    newNode->previous = NULL;
    
    // Adds new node to list
    if(DList_Hdlr.isEmpty(dll))
    {
      dll->first = newNode;
    }
    else
    {
      dll->last->next = newNode;
      newNode->previous = dll->last
    }
  
    dll->last = newNode;    // Last element in list
    dll->size++;            // Increases size
    
    return TRUE;
  }

  // Frees allocated memory if there was an error
  free(newNode);

  return FALSE;   
}

/**
@brief  Reads an element of the list
@param  ll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly read, FALSE otherwise
*/
uint8_t llist_readItem(LList ll, uint16_t index, Data* val)
{
  Node selNode = ll->first;   // Selector
  uint16_t i = 0;             // Iterator

  // Validates indicated list
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index >= 0 && index <= ll->size-1)
  {
    // Binary search
    // (...)
    
    return TRUE;
  }

  return FALSE;
}

/**
@brief  Updates an element of the list
@param  ll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly updated, FALSE otherwise
*/
uint8_t llist_updateItem(LList ll, uint16_t index, Data val)
{
  Node selNode = ll->first;   // Selector
  uint16_t i = 0;             // Iterator

  // Validates indicated list
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index >= 0 && index <= ll->size-1)
  {
    // Binary search
    // (...)

    // Updated value
    selNode->value = val;

    return TRUE;
  }

  return FALSE;
}

/**
@brief  Deletes an element of the list
@param  ll: Pointer to list
        index: Element index
@retval TRUE if value was correctly deleted, FALSE otherwise
*/
uint8_t llist_deleteItem(LList ll, uint16_t index)
{
  Node selNode = ll->first;   // Selector
  Node selAux = NULL;         // Auxiliary pointer (element to be deleted)
  uint16_t i = 0;             // Iterator

  // Validates indicated list
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index >= 0 && index <= ll->size-1)
  {
    // (...)
    
    free(selAux);     // Frees allocated memory of selected node
    ll->size--;       // Decreases size
    
    return TRUE;
  }

  return FALSE;
}


/**
@brief  Clears all elements of list
@param  dll: Pointer to list
@retval TRUE if list was cleared with no error, FALSE otherwise
*/
uint8_t dlist_clear(DList dll)
{
  uint16_t i = 0;         // Iterator

  // Validates indicated list
  if(dll != NULL) 
  {
    for(i = 0; i < dll->size; i++)
    {
      // Deletes all items from first node
      DList_Hdlr.del(dll, 0);
    }
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Erases list and frees allocated memory
@param  dll: Pointer to list
@retval TRUE if list was erased with no error, FALSE otherwise
*/
uint8_t dlist_erase(DList dll)
{
  // Validates indicated list
  if( dll != NULL ) 
  { 
    // Clears list
    if( !DList_Hdlr.clear(dll) )
    {
      return FALSE;
    }

    // Frees allocated memory of list
    free(dll);
    
    return TRUE;
  }
          
  return FALSE;
}

/**
@brief  Prints list's elements on screen
@param  dll: Pointer to list
@retval TRUE if there was an error printing, FALSE otherwise
*/
uint8_t dlist_print(DList dll)
{
  Node sel = dll->first;    // Selector
  uint16_t i = 0;           // Iterator

  // Validates indicated list
  if( dll != NULL && !DList_Hdlr.isEmpty(dll) )
  {    
    for(i = 0; i < dll->size; i++)
    {
      printf("L(%d) : %d\n", i, sel->value);
      sel = sel->next;
    }
    printf("\n");
    
    printf("First element: %d\n", dll->first->value);
    
    printf("Last element: %d\n", dll->last->value);
    
    return TRUE;
  }
  
  return FALSE;
}

