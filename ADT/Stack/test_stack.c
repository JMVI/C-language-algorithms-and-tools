/* -----------------------------------------------------------------------------
 * Copyright (C) 2020 Jaime M. Villegas I. <jaime7592@gmail.com>
 * -----------------------------------------------------------------------------
 * Filename      : test_stack.c
 * Description   : Test file for stack ADT.
 * Version       : 01.00
 * Revision      : 00
 * Last modified : 06/24/2020
 * -----------------------------------------------------------------------------
 */

//----------------------------------------------------------------------------//
//                                Header files                                //
//----------------------------------------------------------------------------//

#include"ADT_Stack.h"

//----------------------------------------------------------------------------//
//                                Main Program                                //
//----------------------------------------------------------------------------//

int main() 
{
  Stack S = NULL;         // New stack
  int val = 0;            // Read value
  uint8_t maxSize = 10;   // Maximum stack size
  uint16_t i = 0;         // Iterator

  printf("***** BEGIN OF TEST *****");

  // Create empty stack (max. 10 elements)
  S = Stack_Hdlr.init(maxSize);

  // Validate memory allocation
  if(S == NULL)
  {
    printf("ERROR IN MEMORY ALLOCATION\n");
    exit(-1);
  }

  printf("Stack created\n");

  // Verify if stack is empty
  if( Stack_Hdlr.isEmpty(S) )
  {
    printf("New stack is empty\n");
  }

  // Insert five (5) elements
  printf("* Push five elements *\n");

  for(i = 0; i < 5; i++)
  {
    printf("(%d) = ", i + 1); scanf("%d", &val); printf("\n");

    if( !Stack_Hdlr.push(S, val) )
    {
      printf("ERROR IN PUSH OPERATION");
    }

    printf("Stack's top: %d \n", S->top->value );
  }
  
  // Verify if stack is not empty
  if( !Stack_Hdlr.isEmpty(S) )
  {
    printf("Stack is not empty\n");
  }

  // Verify if stack is not full
  if( !Stack_Hdlr.isFull(S) )
  {
    printf("Stack is not full\n");
  }

  // Print stack
  stack_print(S);
  printf("\n");

  // Pop out top
  printf("* Pops top *\n");

  if( !Stack_Hdlr.pop(S, &val) )
  {
    printf("ERROR IN POP OPERATION");
  }

  printf("Popped element: %d\n", val);

  // Reprint stack
  stack_print(S);
  printf("\n");

  // Delete stack
  if( !Stack_Hdlr.del(S) )
  {
    printf("ERROR DELETING STACK\n");
    exit(-1);
  }

  printf("Stack deleted\n");

  printf("***** END OF TEST *****");

/*
   
   
   
   // Reimprimir
   printStack(S);
   
   // Llenar pila
   printf("Llenar pila, restan seis (6) elementos:\n");
   for(i = 0; i < 6; i++)
   {
      printf("(%d) = ", i + 1); scanf("%d", &n); printf("\n");
      push(S, n);
      printf("Tope de pila: %d \n", S->top->value);
   }
   
   // Reimprimir
   printStack(S);
   
   // Intentar llenar
   push(S, 2);
   
   // Verificar pila llena
   if(isFullStack(S))
   {
      printf("Pila llena\n");
   }
   
   // Reimprimir
   printStack(S);
   
   // Vaciar pila
   cleanStack(S);
   printf("PILA ELIMINADA\n");
      */

  return 0;
}
