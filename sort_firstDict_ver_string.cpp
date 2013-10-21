/*
Ver. 11

1.)
I don't use arrayname[ ] declaration.
Instead, use std::string stringname declaration.
2.)
If currentPtr->data is the first node, this node is empty, and strncmp() will crash becuse this is NULL.
So, Nicole adds the following : 
		...
		if( previousPtr != NULL ){   
			termOrder = strncmp( value.c_str(), currentPtr->data.c_str(), value.size());
		}
		while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
		...
*/

/* Fig. 12.3: fig12_03.c
   Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_STR_LEN 40

using namespace std;
/* self-referential structure */
struct listNode {            
   std::string data; /* each listNode contains a character */
   struct listNode *nextPtr; /* pointer to next node*/ 
}; /* end structure listNode */

typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, std::string value );
char deleteNode( ListNodePtr *sPtr, char * value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );

int main( void )
{ 
   ListNodePtr startPtr = NULL; /* initially there are no nodes */
   int choice; /* user's choice */
   char item[ MAX_STR_LEN ];  /* char entered by user */

   instructions(); /* display the menu */
   printf( "? " );
   scanf( "%d", &choice );

   /* loop while user does not choose 3 */
   while ( choice != 3 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Enter a character: " );
            scanf( "\n%s", &item );
            insert( &startPtr, item ); /* insert item in list */
            // original code : printList( startPtr );
            break;

         case 2:

            /* if list is not empty */
            if ( !isEmpty( startPtr ) ) { 
               printf( "Enter character to be deleted: " );
               scanf( "\n%c", &item );

               /* if character is found, remove it */
               if ( deleteNode( &startPtr, item ) ) { /* remove item */
                  printf( "%c deleted.\n", item );
                  printList( startPtr );
               } /* end if */
               else {
                  printf( "%c not found.\n\n", item );
               } /* end else */

            } /* end if */
            else {
               printf( "List is empty.\n\n" );
            } /* end else */

            break;

         default:
            printf( "Invalid choice.\n\n" );
            instructions();
            break;
      
      } /* end switch */

      printf( "? " );
      scanf( "%d", &choice );
   } /* end while */

   printf( "End of run.\n" );
   
   return 0; /* indicates successful termination */

} /* end main */

/* display program instructions to user */
void instructions( void )
{ 
   printf( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" );
} /* end function instructions */

/* Insert a new value into the list in sorted order */
void insert( ListNodePtr *sPtr, std::string value )
{ 
   ListNodePtr newPtr;      /* pointer to new node */
   ListNodePtr previousPtr; /* pointer to previous node in list */
   ListNodePtr currentPtr;  /* pointer to current node in list */
   int termOrder;
   int currDataSize ;

   // original code : newPtr = (ListNode *) malloc( sizeof( ListNode ) ); /* create node */
	newPtr = new ListNode; /* new will return the address */
	printf("\nHello insert >> newPtr = new ListNode." );
	
	/*									->		if newPtr is space available */
   if ( newPtr != NULL ) { 

      newPtr->nextPtr = NULL; /* node does not link to another node */

      previousPtr = NULL;
      currentPtr = *sPtr;
		
		/* - - - - - - - - - - - - - - - - - - - - - - */
		value[ sizeof(value) - 1 ]  = '\0';	
		/* - - - - - - - - - - - - - - - - - - - - - - */
		
		if( previousPtr != NULL ){
			termOrder = strncmp( value.c_str(), currentPtr->data.c_str(), value.size());
		}

      /* loop to find the correct location in the list */
      while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
			printf("\nHello insert >>  while ( currentPtr != NULL && termOrder > 0 ) { " );
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      } /* end while */

      /* insert new node at beginning of list */
      if ( previousPtr == NULL ) {
			printf("\nS P E C I A L   C A S E : first listNode to be inserted." ); 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } /* end if */
      else { /* insert new node between previousPtr and currentPtr */
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } /* end else */
   
   } /* end if */
   else {
      printf( "%c not inserted. No memory available.\n", value.c_str() );
   } /* end else */

} /* end function insert */


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

/* Delete a list element */
char deleteNode( ListNodePtr *sPtr, char value[ MAX_STR_LEN ] )
{ 
   ListNodePtr previousPtr; /* pointer to previous node in list */
   ListNodePtr currentPtr;  /* pointer to current node in list */
   ListNodePtr tempPtr;     /* temporary node pointer */

   /* delete first node */
   // oringinal code : if ( value == ( *sPtr )->data ) { 
	if ( strncmp( value , ( *sPtr )->data.c_str(), MAX_STR_LEN ) == 0 ) { 
      tempPtr = *sPtr; /* hold onto node being removed */
      *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
      free( tempPtr ); /* free the de-threaded node */
      return value[0];
   } /* end if */
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      /* loop to find the correct location in the list */
      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr;         /* walk to ...   */
         currentPtr = currentPtr->nextPtr; /* ... next node */  
      } /* end while */

      /* delete node at currentPtr */
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value[0];
      } /* end if */
     
   } /* end else */

   return '\0';

} /* end function delete */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{ 
   return sPtr == NULL;

} /* end function isEmpty */

/* Print the list */
void printList( ListNodePtr currentPtr )
{ 

   /* if list is empty */
   if ( currentPtr == NULL ) {
      printf( "List is empty.\n\n" );
   } /* end if */
   else { 
      printf( "The list is:\n" );

      /* while not the end of the list */
      while ( currentPtr != NULL ) { 
         printf( "%c --> ", currentPtr->data.c_str() );
         currentPtr = currentPtr->nextPtr;   
      } /* end while */

      printf( "NULL\n\n" );
   } /* end else */

} /* end function printList */



/**************************************************************************
 * (C) Copyright 1992-2007 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
