/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Stack.h
 * Description   : Abstract Data Type for stack. Implementation with integer
 *                 data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 06/24/2020
 * -----------------------------------------------------------------------------
 */
#ifndef _STACK_H_
#define _STACK_H_

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Bool data type
#define TRUE      1
#define FALSE     0

// Data type stored in stack
typedef int Data;

// Stack node
typedef struct t_node
{
  Data            value;    // Stored data
  struct t_node*  next;     // Pointer to next element
} node;

typedef node* Node;

// Stack
typedef struct t_stack
{
  uint32_t  size;       // Stack size
  uint32_t  maxSize;    // Max. Size
  Node      top;        // Pointer to Top
} stack;

typedef stack* Stack;

// Stack handler
typedef struct
{
  Stack    (*init)(uint32_t maxS);
  uint8_t  (*isEmpty)(Stack stck);
  uint8_t  (*isFull)(Stack stck);
  uint8_t  (*push)(Stack stck, Data val);
  uint8_t  (*pop)(Stack stck, Data* poppedVal);
  uint8_t  (*clear)(Stack stck);
  uint8_t  (*del)(Stack stck);
}t_StackHandler;

extern t_StackHandler Stack_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new stack
@param  maxS: Maximum size of stack
@retval Pointer to new stack
*/
extern Stack stack_create(uint32_t maxS);

/**
@brief  Verifies if stack is empty
@param  stck: Pointer to stack
@retval TRUE if stack is empty, FALSE otherwise
*/
extern uint8_t stack_isEmpty(Stack stck);

/**
@brief  Verifies if stack is full
@param  stck: Pointer to stack
@retval TRUE if stack is full, FALSE otherwise
*/
extern uint8_t stack_isFull(Stack stck);

/**
@brief  Inserts an element into the stack
@param  stck: Pointer to stack
        val : Value
@retval TRUE if value was correctly inserted, FALSE otherwise
*/
extern uint8_t stack_push(Stack stck, Data val);

/**
@brief  Pops out an element of the stack
@param  stck: Pointer to stack
        top : Popped value
@retval TRUE if top was correctly popped, FALSE otherwise
*/
extern uint8_t stack_pop(Stack stck, Data* poppedVal);

/**
@brief  Clears all elements in stack
@param  stck: Pointer to stack
@retval TRUE if stack was cleared with no error, FALSE otherwise
*/
extern uint8_t stack_clear(Stack stck);

/**
@brief  Deletes stack and frees allocated memory
@param  stck: Pointer to stack
@retval TRUE if stack was deleted with no error, FALSE otherwise
*/
extern uint8_t stack_delete(Stack stck);

/**
@brief  Prints stack's elements on screen
@param  stck: Pointer to stack
@retval TRUE if there was an error printing, FALSE otherwise
*/
extern uint8_t stack_print(Stack stck);

#endif
