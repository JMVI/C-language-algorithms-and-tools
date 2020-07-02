/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : ADT_Queue.c
 * Description   : Abstract Data Type for queue. Implementation with integer
 *                 data type.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/01/2020
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
  Queue newQueue = (Queue)malloc(sizeof(queue));
  newQueue->size = 0;
  newQueue->front = NULL;
  newQueue->tail = NULL;
  newQueue->maxSize = maxS;
  
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
  Node newNode = (Node)malloc(sizeof(node)); // Memory allocation for node

  // Validates memory allocation
  if(newNode == NULL)
  {
    return FALSE;
  }

  // Validates indicated queue
  if( q != NULL && !Queue_Hdlr.isFull(q) )
  {
    newNode->value = val;         // Stores inserted value
    newNode->next = NULL;
    
    // Verifies if there are no elements
    if(q->front == NULL)
    {
      q->front = newNode;       
    }
    else
    {
      q->tail->next = newNode;  
    }
   
    q->tail = newNode;     // Last element in queue
    q->size++;             // Increments size
    
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
  Node aux = q->front;       // Auxiliary pointer

  // Validates indicated queue
  if( q != NULL && !Queue_Hdlr.isEmpty(q) )
  {
    *deqVal = aux->value;
     q->front = q->front->next;
     free(aux);
     q->size--;

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
/*
   if( q != NULL ) 
   {
      int i;
      
      for(i = 0; i < q->size; i++)
      {
         dequeue(q);
      }
      
      free(q);
   }
*/
  return FALSE;
}

/**
@brief  Deletes queue and frees allocated memory
@param  q: Pointer to queue
@retval TRUE if queue was deleted with no error, FALSE otherwise
*/
uint8_t queue_delete(Queue q)
{
  return FALSE;
}

/**
@brief  Prints queue's elements on screen
@param  q: Pointer to queue
@retval TRUE if there was an error printing, FALSE otherwise
*/
uint8_t queue_print(Queue q)
{
/*
   if( q != NULL && !isEmptyQueue(q) )
   {
      Node* sel = q->front;
      int i = 0;
      
      for(i = 0; i < q->size; i++)
      {
         if(sel == q->tail)
         {
            printf("- %d (T)\n", sel->value);
         }
         else if(sel == q->front)
         {
            printf("(F) %d ", sel->value);
         }
         else
         {
            printf("- %d ", sel->value);
         }
         sel = sel->next;
      }
   }
*/
}

