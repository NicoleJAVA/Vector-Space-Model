/*
Ver. 11

1.)
I don't use arrayname[ ] declaration.
Instead, use std::string stringname declaration.


2.)
pass vlue instead of pass address
previous ver: void insertNode( ListNodePtr *sPtr, std::string value )
now ver : void insertNode( ListNodePtr sPtr, std::string value )

*/

/* Fig. 12.3: fig12_03.c
   Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#define MAX_STR_LEN 30

using namespace std;
/* self-referential structure */
#ifndef _IR_HPP_
#define _IR_HPP_
struct ListNode {            
   std::string data; /* each listNode contains a character */
   struct ListNode *nextPtr; /* pointer to next node*/ 
}; /* end structure listNode */
#endif

//typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insertNode( ListNodePtr &sPtr, std::string value );
char deleteNode( ListNodePtr *sPtr, char * value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );

int main2( void )
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
            insertNode( startPtr, item ); /* insert item in list */
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



/*****************************************************************************/



/* display program instructions to user */
void instructions( void )
{ 
   printf( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" );
} /* end function instructions */






/****************************************************************************/ 



/* Insert a new value into the list in sorted order */
void insertNode( ListNodePtr &sPtr, std::string value )
{ 
	printf("\n\n嗨	嗨	嗨	嗨	嗨	嗨	" ); 
	
   ListNodePtr newPtr;      /* pointer to new node */
   ListNodePtr previousPtr; /* pointer to previous node in list */
   ListNodePtr currentPtr;  /* pointer to current node in list */
   int termOrder = 0;
   int currDataSize ;
	char buf1[ MAX_STR_LEN ];
	char buf2[ MAX_STR_LEN ];
   // original code : newPtr = (ListNode *) malloc( sizeof( ListNode ) ); /* create node */
	newPtr = new ListNode; /* new will return the address */
	printf("\n new 回傳一個位址給了 newPtr" ); 
	
	/*									->		if newPtr is space available */
   if ( newPtr != NULL ) { 
		if( sPtr == NULL ){
			printf("\n傳進來的 dictPtr 是 NULL "); 
		}

      newPtr->nextPtr = NULL; /* node does not link to another node */
		printf("\n哈哈哈"); 
		
      previousPtr = NULL;
      currentPtr = sPtr;
		printf("\n newPtr 的記憶體是 ok 的 " ); 
		/* - - - - - - - - - - - - - - - - - - - - - - */
		value[ sizeof(value) - 1 ]  = '\0';	
		printf("\n有辦法嗎:"); 
		/* - - - - - - - - - - - - - - - - - - - - - - */
		
		if( previousPtr != NULL ){
			printf("\npreviousPtr 不是 NULL 唷" ); 
			termOrder = strncmp( value.c_str(), currentPtr->data.c_str(), value.size());
		}
		if( previousPtr == NULL ){
			printf("\npreviousPtr 是 NULL 所以是第一個唷" ); 
			strncpy
			termOrder = strncmp( value.c_str(), currentPtr->data.c_str(), MAX_STR_LEN );
			printf("\n完成了字串比對"); 
		}

		/* D E B U G  */

	

		if( currentPtr != NULL ) {
      /* loop to find the correct location in the list */
      while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
			printf("\nHello insert >>  while ( currentPtr != NULL && termOrder > 0 ) { " );
			printf("\n從現在開始 previousPtr 才會開始不為 NULL 喔" );
         previousPtr = currentPtr;          /* walk to ...   */
         currentPtr = currentPtr->nextPtr;  /* ... next node */
      } /* end while */
		} /* END if */
		
		
      /* insert new node at beginning of list */
      if ( previousPtr == NULL ) {
			printf("\nS P E C I A L   C A S E : first listNode to be inserted." ); 
         newPtr->nextPtr = sPtr;
         sPtr = newPtr;
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
