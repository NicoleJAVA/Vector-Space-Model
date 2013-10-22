/*
Ver. 24- sort_firstDict.cpp


1.)
No sorting function

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

ListNode *globMem = NULL;

/****************************************************************************/ 

/* Insert a new value into the list in sorted order */
void insertNode( ListNodePtr &sPtr, std::string value, int index, ListNodePtr dummyS )
{ 
	printf("\n\n\n Hello insert >> index is %d.", index );
   printf("\ndummyS", dummyS->data.c_str() );
	char chbuf[ 1000 ];
	strncpy( chbuf, value.c_str(), 1000 );
	
   ListNodePtr newPtr;      /* pointer to new node */
   ListNodePtr previousPtr; /* pointer to previous node in list */
   ListNodePtr currentPtr;  /* pointer to current node in list */
   int termOrder = 0;
   int currDataSize ;
	char buf1[ SORT_LEN ];
	char buf2[ SORT_LEN ];

	newPtr = new ListNode; /* new will return the address */
	/*	->		if newPtr is space available */
   if ( newPtr != NULL ) { //printf("\n �Y newPtr ���O����O ok �� " );
   	
		strncpy( const_cast<char*>(newPtr->data.c_str()), value.c_str(), SORT_LEN );
      newPtr->nextPtr = NULL; /* node does not link to another node */
      previousPtr = NULL;
      
      
      
      /******************************************************/
     
	   currentPtr = sPtr;
	   
			// 	�@�w�n���� currentPtr = sPtr 
			// 	�M��~�i�H�� sPtr = new ListNode 
      	// 	The assignment that << currentPtr = sPtr >> must be done before 
      	// 	The allocating << sPtr = new ListNode >> 
      
   	if( sPtr == NULL ){ // �e�L�j�H ��L�Ӫ� 
				printf( "\n\n\n�Ƕi�Ӫ��O NULL.  \n\n\n ");
				sPtr = new ListNode; /* dummy node */
				sPtr->data = '\0'; /* dummy data */
				sPtr->nextPtr = new ListNode;
				sPtr->nextPtr->nextPtr = NULL;
				if(sPtr == NULL ){printf("\n\n FAIL TO ALLOC sPtr");}
		}	
		else{ 		// ���O�Ĥ@�ӳQ�[�J�� 
			printf("\n sPtr ���r�� : %s.", sPtr->data.c_str() );
			printf("\n sPtr->next ���r�� : %s.", sPtr->nextPtr->data.c_str() );		
		}
		/******************************************************/



		if( currentPtr != NULL ){
			
			printf("\n curr ���r�� : %s.", currentPtr->data.c_str() );
			strncpy( buf1, value.c_str(), SORT_LEN );
			strncpy( buf2, currentPtr->data.c_str(), SORT_LEN );			
			/******************************************************/
			currentPtr = dummyS->nextPtr;
			termOrder = compare_term( currentPtr->data.c_str(), value.c_str(), index );
			printf("\n�����F�r����. termOrder �O  %d", termOrder); 
			/******************************************************/
			
		}
	
	
	
		/********************	�}�l����		******************/
      // Ver. 14 ���խק� : while ( currentPtr != NULL && termOrder > 0 && previousPtr != NULL ) { 
		// Ver. 19 : while ( currentPtr != NULL && termOrder == 0 ) { 
		while ( currentPtr != NULL ) { 
			//printf("\n�q�{�b�}�l previousPtr �~�|�}�l���� NULL ��" );
         previousPtr = currentPtr;          //* walk to ...  
			
         currentPtr = currentPtr->nextPtr;  //* ... next node 
      }					//* end while 
		
		/**************************************/
		if( currentPtr == NULL ){
			printf("\ncurr ����F����\n" );	
		}
		
		
		
		
      /* insert new node at beginning of list */
      if ( previousPtr == NULL ) {
         newPtr->nextPtr = sPtr->nextPtr;
         sPtr->nextPtr = newPtr;
  			printf("\n �b��m �@ ���J�`�I�CsPtr->next ���r�� : %s.", sPtr->nextPtr->data.c_str() );
			/******************************************  M  G  I  C  */
			
			
			/******************************************  M  G  I  C  */
			printf("\n HELOO" );			
			previousPtr = new ListNode;
			previousPtr->nextPtr = sPtr;			
			printf("\n -----------------------\n\n\n" );
			
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
