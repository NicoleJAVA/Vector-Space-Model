/*
Ver. 19 - sort_firstDict.cpp

1.)
Ver. 19  >> remove debug info.

2.) 
Ver. 19  >> except insertNode(), all the other operations of listnode are move
to nodeoperation.cpp 

3.)
Ver 19 >> 
Wrong code : strncpy( newPtr->data.c_str(), value.c_str(), SORT_LEN );
Correct code : strncpy( const_cast<char*>(newPtr->data.c_str()), value.c_str(), SORT_LEN );
*/

   
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

   	if ( newPtr != NULL ) { //printf("\n 若 newPtr 的記憶體是 ok 的 " );
   	
			/************************************	開始註解		******************/
			if( sPtr == NULL ){
				printf("\n第 %d 個。\n傳進來的 dictPtr 是 NULL\n ", index);
			}
			else{
				if(index<5){printf("\n第 %d 個。\n傳進來的 dictPtr 不是 NULL ", index);} }
			/******************************************************/
		
		strncpy( const_cast<char*>(newPtr->data.c_str()), value.c_str(), SORT_LEN );
      newPtr->nextPtr = NULL; /* node does not link to another node */

		
      previousPtr = NULL;
      currentPtr = sPtr;

			/************************************	開始註解		******************/
			if( currentPtr == NULL ){
				printf("\n第 %d 個。\n currentPtr 是 NULL\n ", index);
			}
			else{
				if(index<5){
					printf("\n第 %d 個。\ncurrentPtr 不是 NULL。 ", index);
					printf("   --->  字串 : %s." , currentPtr->data.c_str() );
					} // end if 
					
			} // end else
				
			/******************************************************/



		if( currentPtr != NULL ){
			strncpy( buf1, value.c_str(), SORT_LEN );
			strncpy( buf2, currentPtr->data.c_str(), SORT_LEN );
			termOrder = compare_term( sPtr->data.c_str(), value.c_str() );
			//printf("\n完成了字串比對. termOrder 是  %d", termOrder); 
		}
	
		/********************	開始註解		******************/
		if( currentPtr != NULL ) {
      // loop to find the correct location in the list 
      // Ver. 14 嘗試修改 : while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
		while ( currentPtr != NULL && termOrder == 0 ) { 
			//printf("\n從現在開始 previousPtr 才會開始不為 NULL 喔" );
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
         
         
			
			/******************************************  M  G  I  C  */
			sPtr = newPtr;
			/******************************************  M  G  I  C  */
			
			
			
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

	
   



   /*************************************************/

   printf( "End of run.\n" );
   system("PAUSE");
   return 0; //* indicates successful termination 

} //* end main 



/*****************************************************************************/





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
