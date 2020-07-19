/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_SimplyLinkedList.c
 * Description   : Abstract Data Type for simply liked list. Implementation 
 *                 with integer data type.
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
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Queue handler
t_LListHandler LList_Hdlr =
{
  llist_createLinkedList,  // Create linked list
  llist_isEmpty,           // Is list empty?
  llist_isFull,            // Is list empty?
  llist_addItem,           // Add element
  llist_readItem,          // Read element
  llist_updateItem,        // Update element
  llist_deleteItem,        // Delete element
  llist_clear,             // Clear list
  llist_erase              // Erase list
};

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new list
@param  maxS: Maximum size of list
@retval Pointer to new list
*/
LList llist_createLinkedList(uint16_t maxS)
{
  LList newList = (LList)malloc(sizeof(linked_list)); // Memory allocation
  newList->size = 0;                                  // Initializes empty list
  newList->first = NULL;                              // Initial first element
  newList->last = NULL;                               // Initial last element
  newList->maxSize = maxS;                            // Fix max. size

  return newList;
}

/**
@brief  Verifies if list is empty
@param  ll: Pointer to list
@retval TRUE if list is empty, FALSE otherwise
*/
uint8_t llist_isEmpty(LList ll)
{
  return (ll->size == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if list is full
@param  ll: Pointer to list
@retval TRUE if list is full, FALSE otherwise
*/
uint8_t llist_isFull(LList ll)
{
  return (ll->size == ll->maxSize) ? TRUE : FALSE;
}

/**
@brief  Adds an element into the list
@param  ll: Pointer to list
        val: Value
@retval TRUE if value was correctly added, FALSE otherwise
*/
uint8_t llist_addItem(LList ll, Data val)
{
  Node newNode = (Node)malloc(sizeof(node)); // Memory allocation for node
  
  // Validates memory allocation
  if(newNode == NULL)
  {
    return FALSE;
  }

  // Validates indicated list
  if( ll != NULL && !LList_Hdlr.isFull(ll) )
  {
    // Stores value
    newNode->value = val;
   
    // Adds new node to list
    if(LList_Hdlr.isEmpty(ll))
    {
      ll->first = newNode;
    }
    else
    {
      ll->last->next = newNode;
    }
  
    ll->last = newNode;   // Last element in list
    ll->size++;           // Increases size
    
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
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index < ll->size - 1)
  {
    for(i = 0; i < index; i++)
    {
      selNode = selNode->next;
    }

    // Reads value
    *val = selNode->value;

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
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index < ll->size - 1)
  {
    for(i = 0; i < index; i++)
    {
      selNode = selNode->next;
    }

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
  if(ll != NULL && !LList_Hdlr.isEmpty(ll) && index < ll->size - 1)
  {
    if(index == 0)
    {
      // Deletes first item
      selAux = ll->first;
      ll->first = ll->first->next;
    }
    else
    {
      // Finds previous node
      for(i = 0; i < index - 1; i++)
      {
        selNode = selNode->next;
      }

      selAux = selNode->next;
      selNode->next = selNode->next->next;
    }
      free(selAux);     // Frees allocated memory of selected node
      ll->size--;       // Decreases size
      
      return TRUE;
   }

  return FALSE;
}


/**
@brief  Clears all elements of list
@param  ll: Pointer to list
@retval TRUE if list was cleared with no error, FALSE otherwise
*/
uint8_t llist_clear(LList ll)
{
  uint16_t i = 0;         // Iterator

  // Validates indicated list
  if(ll != NULL) 
  {
    for(i = 0; i < ll->size; i++)
    {
      // Deletes all items from first node
      LList_Hdlr.del(ll, 0);
    }
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Erases list and frees allocated memory
@param  ll: Pointer to list
@retval TRUE if list was erased with no error, FALSE otherwise
*/
uint8_t llist_erase(LList ll)
{
  // Validates indicated list
  if( ll != NULL ) 
  { 
    // Clears list
    if( !LList_Hdlr.clear(ll) )
    {
      return FALSE;
    }

    // Frees allocated memory of list
    free(ll);
    
    return TRUE;
  }
          
  return FALSE;
}

/**
@brief  Prints list's elements on screen
@param  ll: Pointer to list
@retval TRUE if there was an error printing, FALSE otherwise
*/
uint8_t llist_print(LList ll)
{
  Node sel = ll->first;    // Selector
  uint16_t i = 0;          // Iterator

  // Validates indicated list
  if( ll != NULL && !LList_Hdlr.isEmpty(ll) )
  {    
    for(i = 0; i < ll->size; i++)
    {
      printf("L(%d) : %d\n", i, sel->value);
      sel = sel->next;
    }
    
    return TRUE;
  }
  
  return FALSE;
}

