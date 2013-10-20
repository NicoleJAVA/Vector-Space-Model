/* Ver. 8 	-	dictCpp.cpp


 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_STR_LEN 30
#define MAX_STOP_SIZE 500
#define APPEND 0
#define RMV 1 
#define MAX_WORD_NUM 10000
#define DOC_NUM 1095
#define DICT_SIZE 1000/* dictionary size : total number of tokens of all docs.*/
using namespace std;



struct ListNode
{
	char item[ MAX_STR_LEN ] ;
	ListNode  *next ;
};

/******************************************************************************/
ListNode *merge_dictionary(const ListNode *h1, const ListNode *h2, ListNode *&result )
{

	/*-------------------*/
	ListNode dummy;
	ListNode *tail;
	/*-------------------*/
	
	for ( tail=&dummy; h1 != NULL || h2 != NULL; tail=tail->next ){
		tail->next = new ListNode;
		 
	   if( h1==NULL || h2 !=NULL ){
	   /* original : if( h1==NULL || h2 !=NULL && h2->item < h1->item)){
			*/
			/* Nicole wants to use a flag instead ! */
			/* original : tail->next->item = h2->item; */
			strncpy( tail->next->item, h2->item, MAX_STR_LEN );
			h2 = h2->next;
		} /* end if */
		else{
		   /* original : tail->next->item = h1->item; */
		   strncpy( tail->next->item, h1->item, MAX_STR_LEN );
		   h1 = h1->next;
		} /* end else */
	} /* end for */
	
	tail->next = NULL;
	
	result = dummy.next;
}

/******************************************************************************/
/*-------------------*/
	
/*-------------------*/
void arrayToListNode(char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *tail2 )
{
	printf("\nEnter : arrayToListNode( ) ." );
	printf("\nIn arrayToListNode : tokenSize is : %d.", tokenSize );
	ListNode dummy2; 
	/* PPS. address of dummy2 is fixed bcause dummy2 is statically allocated*/
	int i = 0;	
	tail2 = &dummy2;
	for( i = 0; i < tokenSize; i++ ){
		
		tail2->next = new ListNode;
		strncpy( tail2->next->item, inputArr[i], MAX_STR_LEN );
		printf("\n The content of tail2 is %s.", tail2->item ); 
		tail2 = tail2->next;
	}						/* End for */
	tail2->next = NULL;
	printf("\nIn arrayToListNode : token[ %d ].", i );

}						/* end arrayToListNode( ) */

/******************************************************************************/

ListNode *duplicate_currDict( ListNode *&h1, ListNode *&h2 )
{
	/* h2 : global dictionary */
	
	/* h1 will be the copy of h2. */
	/* h2 is global in main.cpp. h1 can only be seen in dictCpp.cpp  */
	
	int i = 0;	
	
	/* first node : special case : */
	h1 = new ListNode;
	
	while( h2 != NULL ){
		
		h1->next = new ListNode;
		strncpy( h1->next->item, h2->item, MAX_STR_LEN );
		printf("\n The content of currDictNode is %s.", h1->item ); 
		h1 = h1->next;
		h2 = h2->next;
	}						/* End while */
	
	h1->next = NULL;
	
}						/* End duplicate_currDict( ) */

/* - - - - - - - - - - - - - - - */

/* - - - - - - - - - - - - - - - */
void arrayToDict( char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *&dictNode )
{
	ListNode *newTermsNode;
	ListNode *currDictNode;  /* is first updated by duplicate_currDict( ) */
	/* currDictNode currDictNode is just for temporary backup. */
	/* It will hold the copy of ListNode *&dictNode*/
	
	arrayToListNode( inputArr, tokenSize, newTermsNode );
	/* PPS. inputArr[][] is the new coming content of xxx.txt, and the content */
	/* will be converted into newTermsNode */
	
	duplicate_currDict( currDictNode, dictNode );
	/* dictNode is the global dictionary in main(). currDictNode is just for temporary backup */
	
	merge_dictionary( newTermsNode, currDictNode, dictNode );

}

