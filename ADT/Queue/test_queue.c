/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_queue.c
 * Description   : Test file for queue ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 07/12/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Queue.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//

int main()
{
  Queue Q = NULL;         // New queue
  Data val = 0;            // Read value
  uint8_t maxSize = 10;   // Maximum stack size
  uint16_t i = 0;         // Iterator

  printf("***** BEGIN OF TEST *****\n");

  // Create empty stack (max. 10 elements)
  Q = Queue_Hdlr.init(maxSize);

  // Validate memory allocation
  if(Q == NULL)
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }
  else
  {
    printf("Queue created (Max. size: %d)\n", Q->maxSize);
  }

  // Verify if queue is empty
  if( Queue_Hdlr.isEmpty(Q) )
  {
    printf("New queue is empty\n");
  }

  // Insert five (5) elements
  printf("* Enqueue five elements *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", i + 1); scanf("%d", &val); printf("\n");

    if( !Queue_Hdlr.enqueue(Q, val) )
    {
      printf("ERROR IN ENQUEUE OPERATION\n");
    }

    // Print queue
    queue_print(Q);
    printf("\n");
  }
  
  // Verify if queue is not empty
  if( !Queue_Hdlr.isEmpty(Q) )
  {
    printf("Queue is not empty (%d)\n", Queue_Hdlr.isEmpty(Q));
  }

  // Verify if queue is not full
  if( !Queue_Hdlr.isFull(Q) )
  {
    printf("Queue is not full (%d)\n", Queue_Hdlr.isFull(Q));
  }

  // Dequeue front
  printf("* Dequeues front *\n");

  if( !Queue_Hdlr.dequeue(Q, &val) )
  {
    printf("ERROR IN DEQUEUE OPERATION");
  }

  printf("Dequeued element: %d\n", val);

  // Reprint queue
  queue_print(Q);
  printf("\n");

  // Fill up queue.
  printf("* Filling up queue *\n");

  i = Q->size + 1;

  do
  {
    printf("%d elements left \n", Q->maxSize - Q->size);

    printf("(%d) = ", Q->size + 1); scanf("%d", &val); printf("\n");

    if( !Queue_Hdlr.enqueue(Q, val) )
    {
      printf("ERROR IN ENQUEUE OPERATION");
    }

    // Print queue
    queue_print(Q);
    printf("\n");

    printf("Queue's size: %d\n", Q->size);

  } while( !Queue_Hdlr.isFull(Q) );

  // Try to insert five elements into full queue
  printf("* Try to insert into full queue *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", Q->size + 1); scanf("%d", &val); printf("\n");

    if( !Queue_Hdlr.enqueue(Q, val) )
    {
      printf("ERROR IN ENQUEUE OPERATION\n");
    }
    
    if( Queue_Hdlr.isFull(Q) )
    {
      printf("Queue is full\n");
    }
  }

  // Delete queue
  if( !Queue_Hdlr.del(Q) )
  {
    printf("ERROR DELETING QUEUE\n");
    exit(-1);
  }

  printf("Queue deleted\n");

  printf("***** END OF TEST *****");

  return 0;
}

