/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Queue.h
 * Description   : Abstract Data Type for queue. Implementation with integer
 *                 data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/12/2020
 * -----------------------------------------------------------------------------
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_

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
#define TRUE      (uint8_t) 1
#define FALSE     (uint8_t) 0

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Data type stored in queue
typedef int Data;

// Stack node
typedef struct t_node
{
  Data            value;    // Stored data
  struct t_node*  next;     // Pointer to next element
} node;

typedef node* Node;

// Queue
typedef struct t_queue
{
  uint16_t  size;       // Queue size
  uint16_t  maxSize;    // Max. Size
  Node      front;      // Pointer to front
  Node      tail;       // Pointer to tail
} queue;

typedef queue* Queue;

// Queue handler
typedef struct
{
  Queue    (*init)(uint16_t maxS);                  // Create new queue
  uint8_t  (*isEmpty)(Queue q);                     // Is queue empty?
  uint8_t  (*isFull)(Queue q);                      // Is queue full?
  uint8_t  (*enqueue)(Queue q, Data val);           // Enqueue
  uint8_t  (*dequeue)(Queue q, Data* removedVal);   // Dequeue
  uint8_t  (*clear)(Queue q);                       // Clear
  uint8_t  (*del)(Queue q);                         // Delete
}t_QueueHandler;

extern t_QueueHandler Queue_Hdlr;

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new queue
@param  maxS: Maximum size of queue
@retval Pointer to new queue
*/
extern Queue queue_create(uint16_t maxS);

/**
@brief  Verifies if queue is empty
@param  q: Pointer to queue
@retval TRUE if queue is empty, FALSE otherwise
*/
extern uint8_t queue_isEmpty(Queue q);

/**
@brief  Verifies if queue is full
@param  q: Pointer to queue
@retval TRUE if queue is full, FALSE otherwise
*/
extern uint8_t queue_isFull(Queue q);

/**
@brief  Inserts an element into the queue
@param  q   : Pointer to queue
        val : Value
@retval TRUE if value was correctly inserted, FALSE otherwise
*/
extern uint8_t queue_insert(Queue q, Data val);

/**
@brief  Removes an element of the queue
@param  q      : Pointer to queue
        deqVal : Dequeued value
@retval TRUE if value was correctly dequeued, FALSE otherwise
*/
extern uint8_t queue_remove(Queue q, Data* deqVal);

/**
@brief  Clears all elements in queue
@param  q: Pointer to queue
@retval TRUE if queue was cleared with no error, FALSE otherwise
*/
extern uint8_t queue_clear(Queue q);

/**
@brief  Deletes queue and frees allocated memory
@param  q: Pointer to queue
@retval TRUE if queue was deleted with no error, FALSE otherwise
*/
extern uint8_t queue_delete(Queue q);

/**
@brief  Prints queue's elements on screen
@param  q: Pointer to queue
@retval TRUE if there was an error printing, FALSE otherwise
*/
extern uint8_t queue_print(Queue q);

#endif

