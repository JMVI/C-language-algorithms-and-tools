/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Stack.c
 * Description   : Abstract Data Type for stack. Implementation with integer
 *                 data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/12/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Stack.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Stack handler
t_StackHandler Stack_Hdlr =
{
  stack_create,     // Create new stack
  stack_isEmpty,    // Is stack empty?
  stack_isFull,     // Is stack full?
  stack_push,       // Push
  stack_pop,        // Pop
  stack_clear,      // Clear
  stack_delete      // Delete
};

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new stack
@param  maxS: Maximum size of stack
@retval Pointer to new stack
*/
Stack stack_create(uint16_t maxS)
{
  Stack newStack = (Stack)malloc(sizeof(stack));  // Memory allocation
  newStack->size = 0;                             // Initialize empty stack
  newStack->top = NULL;                           // Initial top
  newStack->maxSize = maxS;                       // Fix max. size

  return newStack;
}

/**
@brief  Verifies if stack is empty
@param  stck: Pointer to stack
@retval TRUE if stack is empty, FALSE otherwise
*/
uint8_t stack_isEmpty(Stack stck)
{
  return (stck->size == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if stack is full
@param  stck: Pointer to stack
@retval TRUE if stack is full, FALSE otherwise
*/
uint8_t stack_isFull(Stack stck)
{
  return (stck->size == stck->maxSize) ? TRUE : FALSE;
}

/**
@brief  Inserts an element into the stack
@param  stck: Pointer to stack
        val : Value
@retval TRUE if value was correctly inserted, FALSE otherwise
*/
uint8_t stack_push(Stack stck, Data val)
{
  Node newNode = (Node)malloc(sizeof(node)); // Memory allocation for node

  // Validates memory allocation
  if(newNode == NULL)
  {
    return FALSE;
  }

  // Validates indicated stack
  if( stck != NULL && !Stack_Hdlr.isFull(stck) )
  {
    newNode->value = val;        // Stores inserted value
    newNode->next = stck->top;   // Links node to stack
    stck->top = newNode;         // Updates the top
    stck->size++;                // Increments size
    
    return TRUE;
  }

  // Frees allocated memory if there was an error
  free(newNode);

  return FALSE;
}

/**
@brief  Pops out an element of the stack
@param  stck      : Pointer to stack
        poppedVal : Popped value
@retval TRUE if top was correctly popped, FALSE otherwise
*/
uint8_t stack_pop(Stack stck, Data* poppedVal)
{
  Node auxSel = stck->top;     // Auxiliary pointer

  // Validates indicated stack
  if( stck != NULL && !Stack_Hdlr.isEmpty(stck) )
  {
    *poppedVal = auxSel->value;   // Reads popped element
    stck->top = stck->top->next;  // Updates top pointer
    free(auxSel);                 // Frees allocated memory of popped node
    stck->size--;                 // Decreases size
    
    return TRUE;
  }

  return FALSE;
}

/**
@brief  Clears all elements in stack
@param  stck: Pointer to stack
@retval TRUE if stack was cleared with no error, FALSE otherwise
*/
uint8_t stack_clear(Stack stck)
{
  uint16_t i = 0;   // Iterator
  Data auxVal;      // Auxiliary value

  // Validates indicated stack
  if( stck != NULL ) 
  { 
    // Pops out all elements
    for(i = 0; i < stck->size; i++)
    {
      Stack_Hdlr.pop(stck, &auxVal);
    }
    
    return TRUE;
  }
  
  return FALSE;
}

/**
@brief  Deletes stack and frees allocated memory
@param  stck: Pointer to stack
@retval TRUE if stack was deleted with no error, FALSE otherwise
*/
uint8_t stack_delete(Stack stck)
{
  // Validates indicated stack
  if( stck != NULL ) 
  { 
    // Clear stack
    if( !Stack_Hdlr.clear(stck) )
    {
      return FALSE;
    }

    // Frees allocated memory of stack 
    free(stck);
    
    return TRUE;
  }
          
  return FALSE;
}

/**
@brief  Prints stack's elements on screen
@param  stck: Pointer to stack
@retval TRUE if there was an error printing, FALSE otherwise
*/
uint8_t stack_print(Stack stck)
{
  Node sel = stck->top;    // Selector
  uint16_t i = 0;          // Iterator

  // Validates indicated stack
  if( stck != NULL && !Stack_Hdlr.isEmpty(stck) )
  {
    for(i = 0; i < stck->size; i++)
    {
      printf("S(%d) : %d\n", i, sel->value);
      sel = sel->next;
    }

    return TRUE;
  }
  
  return FALSE;
}

