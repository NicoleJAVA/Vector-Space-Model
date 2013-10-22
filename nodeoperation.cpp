 
/*
Ver. 19

1.)
Ver. 19  >> remove debug info.

2.) 
Ver. 19  >> except insertNode(), all the other operations of listnode are move
to nodeoperation.cpp 

*/

/* Fig. 12.3: fig12_03.c
   Operating and maintaining a list */
   
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include "compareTerm.cpp"
#define MAX_STR_LEN 30
#define SORT_LEN 1000
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



/****************************************************************************/ 

/* Insert a new value into the list in sorted order */
void insertNode( ListNodePtr &sPtr, std::string value, int index )
{ 
	char chbuf[ 1000 ];
	strncpy( chbuf, value.c_str(), 1000 );
	//printf("\n\n嗨	嗨	嗨	嗨	嗨	嗨	sPtr is %s.", chbuf ); 
	
   ListNodePtr newPtr;      /* pointer to new node */
   ListNodePtr previousPtr; /* pointer to previous node in list */
   ListNodePtr currentPtr;  /* pointer to current node in list */
   int termOrder = 0;
   int currDataSize ;
	char buf1[ SORT_LEN ];
	char buf2[ SORT_LEN ];
   // original code : newPtr = (ListNode *) malloc( sizeof( ListNode ) ); /* create node */
	newPtr = new ListNode; /* new will return the address */
	
	/*									->		if newPtr is space available */

   	if ( newPtr != NULL ) { 
		//printf("\n newPtr 的記憶體是 ok 的 " );
		if( sPtr == NULL ){
			printf("\n第 %d 個。\n傳進來的 dictPtr 是 NULL\n ", index);
		}
		else{
			if(index<5){printf("\n第 %d 個。\n傳進來的 dictPtr 不是 NULL ", index);} 
		}

      newPtr->nextPtr = NULL; /* node does not link to another node */

		
      previousPtr = NULL;
      currentPtr = sPtr;
		if( currentPtr == NULL ){
			//printf("\n現在 currentPtr 是 NULL "); 
		}
		else{
			//printf("\n現在 currentPtr  不是 NULL "); 
		}      
		 
	
		if( currentPtr != NULL ){
			//printf("\npreviousPtr 不是 NULL 呢" ); 
			strncpy( buf1, value.c_str(), SORT_LEN );
			strncpy( buf2, currentPtr->data.c_str(), SORT_LEN );
			termOrder = compare_term( sPtr->data.c_str(), value.c_str() );
			//printf("\n完成了字串比對. termOrder 是  %d", termOrder); 
		}
	
		/********************	開始註解		******************
		if( currentPtr != NULL ) {
      // loop to find the correct location in the list 
      // Ver. 14 嘗試修改 : while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
		while ( currentPtr != NULL && termOrder > 0 ) { 
			printf("\n從現在開始 previousPtr 才會開始不為 NULL 喔" );
         previousPtr = currentPtr;          //* walk to ...   
         currentPtr = currentPtr->nextPtr;  //* ... next node 
      }					//* end while 
		}					//* END if */
		/**************************************/
		
      /* insert new node at beginning of list */
      if ( previousPtr == NULL ) {
			//printf("\nS P E C I A L   C A S E : first listNode to be inserted." ); 
			//printf("\npreviousPtr 是 NULL 所以是第一個唷" ); 
         newPtr->nextPtr = sPtr;
         sPtr = newPtr;
      }					/* end if */
      else { /* insert new node between previousPtr and currentPtr */
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      }					/* end else */
   
   }						/* end if */
   else {
      printf( "%c not inserted. No memory available.\n", value.c_str() );
   } /* end else */

}						/* ----- end function insertNode( ) ----- */




/***************************************************************************/

int main2( void )
{ 
   ListNodePtr startPtr = NULL; //* initially there are no nodes */
   int choice; /* user's choice */
   char item[ MAX_STR_LEN ];  //* char entered by user */

	
   






	/***********************************

   instructions(); //* display the menu 
   printf( "? " );
   scanf( "%d", &choice );

   //* loop while user does not choose 3 
   while ( choice != 3 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Enter a character: " );
            scanf( "\n%s", &item );
            insertNode( startPtr, item ); 
            
            break;

         case 2:

            //* if list is not empty 
            if ( !isEmpty( startPtr ) ) { 
               printf( "Enter character to be deleted: " );
               scanf( "\n%c", &item );

               //* if character is found, remove it 
               if ( deleteNode( &startPtr, item ) ) { //* remove item 
                  printf( "%c deleted.\n", item );
                  printList( startPtr );
               } //* end if 
               else {
                  printf( "%c not found.\n\n", item );
               } //* end else 

            } //* end if 
            else {
               printf( "List is empty.\n\n" );
            } //* end else 

            break;

         default:
            printf( "Invalid choice.\n\n" );
            instructions();
            break;
      
      } //* end switch 

      printf( "? " );
      scanf( "%d", &choice );
   } //* end while 
   /*************************************************/

   printf( "End of run.\n" );
   system("PAUSE");
   return 0; //* indicates successful termination 

} //* end main 



/*****************************************************************************/



/* display program instructions to user */
void instructions( void )
{ 
   printf( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" );
} /* end function instructions */





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


