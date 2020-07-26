/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_SimplyLinkedList.h
 * Description   : Abstract Data Type for simply linked list. Implementation 
 *                 with integer data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/26/2020
 * -----------------------------------------------------------------------------
 */

#ifndef _SLINKEDLIST_H_
#define _SLINKEDLIST_H_

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
typedef struct t_node
{
  Data            value;    // Stored data
  struct t_node*  next;     // Pointer to next element
} node;

typedef node* Node;

// Simply linked list
typedef struct t_list
{
  uint16_t size;       // List size
  uint16_t maxSize;    // Max. Size
  Node     first;      // First element
  Node     last;       // Last element
} linked_list;

typedef linked_list* LList;

// List handler
typedef struct
{
  LList   (*init)(uint16_t maxS);                         // Create linked list
  uint8_t (*isEmpty)(LList ll);                           // Is list empty?
  uint8_t (*isFull)(LList ll);                            // Is list empty?
  uint8_t (*add)(LList ll, Data val);                     // Add element
  uint8_t (*read)(LList ll, uint16_t index, Data* val);   // Read element
  uint8_t (*update)(LList ll, uint16_t index, Data val);  // Update element
  uint8_t (*del)(LList ll, uint16_t index);               // Delete element
  uint8_t (*clear)(LList ll);                             // Clear list
  uint8_t (*erase)(LList ll);                             // Erase list
}t_LListHandler;

extern t_LListHandler LList_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new list
@param  maxS: Maximum size of list
@retval Pointer to new list
*/
extern LList llist_createLinkedList(uint16_t maxS);

/**
@brief  Verifies if list is empty
@param  ll: Pointer to list
@retval TRUE if list is empty, FALSE otherwise
*/
extern uint8_t llist_isEmpty(LList ll);

/**
@brief  Verifies if list is full
@param  ll: Pointer to list
@retval TRUE if list is full, FALSE otherwise
*/
extern uint8_t llist_isFull(LList ll);

/**
@brief  Adds an element into the list
@param  ll: Pointer to list
        val: Value
@retval TRUE if value was correctly added, FALSE otherwise
*/
extern uint8_t llist_addItem(LList ll, Data val);

/**
@brief  Reads an element of the list
@param  ll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly read, FALSE otherwise
*/
extern uint8_t llist_readItem(LList ll, uint16_t index, Data* val);

/**
@brief  Updates an element of the list
@param  ll: Pointer to list
        index: Element index
        val: Value
@retval TRUE if value was correctly updated, FALSE otherwise
*/
extern uint8_t llist_updateItem(LList ll, uint16_t index, Data val);

/**
@brief  Deletes an element of the list
@param  ll: Pointer to list
        index: Element index
@retval TRUE if value was correctly deleted, FALSE otherwise
*/
extern uint8_t llist_deleteItem(LList ll, uint16_t index);

/**
@brief  Clears all elements of list
@param  ll: Pointer to list
@retval TRUE if list was cleared with no error, FALSE otherwise
*/
extern uint8_t llist_clear(LList ll);

/**
@brief  Erases list and frees allocated memory
@param  ll: Pointer to list
@retval TRUE if list was erased with no error, FALSE otherwise
*/
extern uint8_t llist_erase(LList ll);

/**
@brief  Prints list's elements on screen
@param  ll: Pointer to list
@retval TRUE if there was an error printing, FALSE otherwise
*/
extern uint8_t llist_print(LList ll);

#endif

