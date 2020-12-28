/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_DoublyLinkedList.h
 * Description   : Abstract Data Type for doubly linked list. Implementation 
 *                 with integer data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/28/2020
 * -----------------------------------------------------------------------------
 */

#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

//----------------------------------------------------------------------------//
//                                  Macros                                    //
//----------------------------------------------------------------------------//

// Bool data type
#define TRUE      (uint8_t)(1)
#define FALSE     (uint8_t)(0)

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Data type stored in list
typedef int Data;

// List node
typedef struct node
{
  Data            value;    // Stored data
  struct node*  next;     // Pointer to next element
  struct node*  previous; // Pointer to previous element
}
t_node;

typedef t_node* Node;

// Doubly linked list
typedef struct list
{
  uint16_t size;       // List size
  uint16_t maxSize;    // Max. Size
  Node     first;      // First element
  Node     last;       // Last element
} 
t_linked_list;

typedef t_linked_list* DList;

// List handler
typedef struct list_handler
{
  DList   (*init)(uint16_t maxS);                         // Create linked list
  uint8_t (*isEmpty)(DList dll);                          // Is list empty?
  uint8_t (*isFull)(DList dll);                           // Is list empty?
  uint8_t (*add)(DList dll, Data val);                    // Add element
  uint8_t (*read)(DList dll, uint16_t index, Data* val);  // Read element
  uint8_t (*update)(DList dll, uint16_t index, Data val); // Update element
  uint8_t (*del)(DList dll, uint16_t index);              // Delete element
  uint8_t (*clear)(DList dll);                            // Clear list
  uint8_t (*erase)(DList dll);                            // Erase list
}
t_DListHandler;

extern t_DListHandler DList_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new list
@param  maxS: Maximum size of list
@retval Pointer to new list
*/
extern DList dlist_createLinkedList(uint16_t maxS);

/**
@brief  Verifies if list is empty
@param  dll: Pointer to list
@retval TRUE if list is empty, FALSE otherwise
*/
extern uint8_t dlist_isEmpty(DList dll);

/**
@brief  Verifies if list is full
@param  dll: Pointer to list
@retval TRUE if list is full, FALSE otherwise
*/
extern uint8_t dlist_isFull(DList dll);

/**
@brief  Adds an element into the list
@param  dll: Pointer to list
        val: Value
@retval TRUE if value was correctly added, FALSE otherwise
*/
extern uint8_t dlist_addItem(DList dll, Data val);

/**
@brief  Reads an element of the list
@param  dll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly read, FALSE otherwise
*/
extern uint8_t dlist_readItem(DList dll, uint16_t index, Data* val);

/**
@brief  Updates an element of the list
@param  dll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly updated, FALSE otherwise
*/
extern uint8_t dlist_updateItem(DList dll, uint16_t index, Data val);

/**
@brief  Deletes an element of the list
@param  dll: Pointer to list
        index: Element index
@retval TRUE if value was correctly deleted, FALSE otherwise
*/
extern uint8_t dlist_deleteItem(DList dll, uint16_t index);

/**
@brief  Clears all elements of list
@param  dll: Pointer to list
@retval TRUE if list was cleared with no error, FALSE otherwise
*/
extern uint8_t dlist_clear(DList dll);

/**
@brief  Erases list and frees allocated memory
@param  dll: Pointer to list
@retval TRUE if list was erased with no error, FALSE otherwise
*/
extern uint8_t dlist_erase(DList dll);

/**
@brief  Prints list's elements on screen
@param  dll: Pointer to list
@retval TRUE if there was an error printing, FALSE otherwise
*/
extern uint8_t dlist_print(DList dll);

#endif

