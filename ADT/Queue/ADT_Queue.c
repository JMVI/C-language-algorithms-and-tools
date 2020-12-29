/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Queue.c
 * Description   : Abstract Data Type for queue. Implementation with integer
 *                 data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 12/29/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Queue.h"

//----------------------------------------------------------------------------//
//                            General definitions                             //
//----------------------------------------------------------------------------//

// Queue handler
t_QueueHandler Queue_Hdlr =
{
  queue_create,     // Create new queue
  queue_isEmpty,    // Is queue empty?
  queue_isFull,     // Is queue full?
  queue_insert,     // Enqueue
  queue_remove,     // Dequeue
  queue_clear,      // Clear
  queue_delete      // Delete
};

//----------------------------------------------------------------------------//
//                              Public functions                              //
//----------------------------------------------------------------------------//

/**
@brief  Allocates memory to create a new queue
@param  maxS: Maximum size of queue
@retval Pointer to new queue
*/
Queue queue_create(uint16_t maxS)
{
  Queue newQueue = (Queue)malloc(sizeof(queue)); // Memory allocation
  newQueue->size = 0;                            // Initializes empty queue
  newQueue->front = NULL;                        // Initial front
  newQueue->tail = NULL;                         // Initial tail
  newQueue->maxSize = maxS;                      // Fix max. size
  
  return newQueue;
}

/**
@brief  Verifies if queue is empty
@param  q: Pointer to queue
@retval TRUE if queue is empty, FALSE otherwise
*/
uint8_t queue_isEmpty(Queue q)
{
   return (q->size == 0) ? TRUE : FALSE;
}

/**
@brief  Verifies if queue is full
@param  q: Pointer to queue
@retval TRUE if queue is full, FALSE otherwise
*/
uint8_t queue_isFull(Queue q)
{
   return (q->size == q->maxSize) ? TRUE : FALSE;
}

/**
@brief  Inserts an element into the queue
@param  q   : Pointer to queue
        val : Value
@retval TRUE if value was correctly inserted, FALSE otherwise
*/
uint8_t queue_insert(Queue q, Data val)
{
  Node newNode = (Node)malloc(sizeof(t_node)); // Memory allocation for node

  // Validates memory allocation
  if(newNode == NULL)
  {
    return FALSE;
  }

  // Validates indicated queue
  if( q != NULL && !Queue_Hdlr.isFull(q) )
  {
    newNode->value = val;       // Stores inserted value
    newNode->next = NULL;
    
    // Verifies if there are no elements
    if(q->front == NULL)
    {
      q->front = newNode;       // New element becomes the front of queue
    }
    else
    {
      q->tail->next = newNode;  // Updates tail's pointer to next element
    }
   
    q->tail = newNode;     // Last element in queue
    q->size++;             // Increases size
    
    return TRUE;
  }

  // Frees allocated memory if there was an error
  free(newNode);

  return FALSE;
}

/**
@brief  Removes an element of the queue
@param  q      : Pointer to queue
        deqVal : Dequeued value
@retval TRUE if value was correctly dequeued, FALSE otherwise
*/
uint8_t queue_remove(Queue q, Data* deqVal)
{
  Node selAux = q->front;          // Auxiliary pointer

  // Validates indicated queue
  if( q != NULL && !Queue_Hdlr.isEmpty(q) )
  {
    *deqVal = selAux->value;       // Reads dequeued element
     q->front = q->front->next;    // Updates front pointer
     free(selAux);                 // Frees allocated memory of dequeued node
     q->size--;                    // Decreases size

    return TRUE;
  }

  return FALSE;
}

/**
@brief  Clears all elements in queue
@param  q: Pointer to queue
@retval TRUE if queue was cleared with no error, FALSE otherwise
*/
uint8_t queue_clear(Queue q)
{
  uint16_t i = 0;     // Iterator
  Data auxVal;        // Auxiliary value

  // Validates indicated queue
  if( q != NULL && !Queue_Hdlr.isEmpty(q) )
  {
    // Dequeues all elements
    for(i = 0; i < q->size; i++)
    {
      Queue_Hdlr.dequeue(q, &auxVal);
    }

    return TRUE;
  }

  return FALSE;
}

/**
@brief  Deletes queue and frees allocated memory
@param  q: Pointer to queue
@retval TRUE if queue was deleted with no error, FALSE otherwise
*/
uint8_t queue_delete(Queue q)
{
  // Validates indicated queue
  if( q != NULL ) 
  { 
    // Clears queue
    if( !Queue_Hdlr.clear(q) )
    {
      return FALSE;
    }

    // Frees allocated memory of queue
    free(q);
    
    return TRUE;
  }
          
  return FALSE;
}

/**
@brief  Prints queue's elements on screen
@param  q: Pointer to queue
@retval TRUE if there was an error printing, FALSE otherwise
*/
uint8_t queue_print(Queue q)
{
  Node sel = q->front;  // Selector
  uint16_t i = 0;       // Iterator

  // Validates indicated stack
  if( q != NULL && !Queue_Hdlr.isEmpty(q) )
  { 
    for(i = 0; i < q->size; i++)
    {
      if(sel == q->front && sel == q->tail)
      {
        // Printing a single-value queue
        printf("(F) %d (T)\n", sel->value);
      }
      else if(sel == q->front)
      {
        // Printing first element (front)
        printf("(F) %d ", sel->value);
      }
      else if(sel == q->tail)
      {
        // Printing last element (tail)
        printf("- %d (T)\n", sel->value);
      }
      else
      {
        // Printing inner element
        printf("- %d ", sel->value);
      }
      
      sel = sel->next;
    }

    return TRUE;
  }

  return FALSE;
}

