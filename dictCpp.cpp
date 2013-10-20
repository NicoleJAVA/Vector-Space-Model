/* Ver. 9	-	dictCpp.cpp

1.)
still fighting with merge_dictionary( )
but the other functions are OK now :D

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

#define EARLIER 0
#define LATER 1 
#define SAME 2
using namespace std;



struct ListNode
{
	char item[ MAX_STR_LEN ] ;
	ListNode  *next ;
};

/* - - - - - - - - - - - - - - - */
	ListNode *newTermsNode;
	ListNode *currDictNode;  /* is first updated by duplicate_currDict( ) */
	/* currDictNode currDictNode is just for temporary backup. */
	/* It will hold the copy of ListNode *&dictNode*/
/* - - - - - - - - - - - - - - - */

	ListNode dummy;
	ListNode *tail;
	char buff1[ MAX_STR_LEN ];
	char buff2[ MAX_STR_LEN ];
	
/******************************************************************************/
ListNode *merge_dictionary( ListNode *&h1, ListNode *&h2, ListNode *&result )
{
	/*-------------------*/ 
   int flag;
	/*-------------------*/
	printf("\n\nh1->item : %c. h2->item : %c.", h1->item, h2->item );
	for ( tail=&dummy; h1 != NULL || h2 != NULL; tail=tail->next ){
		printf("\nHello ");
		//tail->next = ListNode;
		printf("\nHello new ");
		buff1[0] = h1->item[0];
		printf("\nHello buff1" );
		flag = strncmp( h1->item, h2->item, MAX_STR_LEN );
		printf("\nHello flag ");
		/* If strncmp( A, B ) > 0, then the order shold be ... -> B -> A -> ... */
	   if( h1==NULL || ( h2 !=NULL && flag > 0 ) ){
	   /* original : if( h1==NULL || h2 !=NULL && h2->item < h1->item)){
			*/
			/* Nicole wants to use a flag instead ! */
			/* original : tail->next->item = h2->item; */
			strncpy( tail->next->item, h2->item, MAX_STR_LEN );
			//printf("\nHello strncpy ");
			h2 = h2->next;
			printf("\nHello h2 = h2->next ");
		} /* end if */
		else if ( h2==NULL || ( h1!=NULL && flag <= 0 ) ){
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
void arrayToListNode(char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *&tail2 )
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
		// 	printf("\n The content of tail2 is %s.", tail2->item ); 
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
	if(h2->item == NULL )
	printf( "\n\n\n         h2->item is NULL ! ");
	while( h2->item != NULL ){
		printf( "\nHello h2->item != NULL        : >> " );
		h1->next = new ListNode;
		strncpy( h1->next->item, h2->item, MAX_STR_LEN );
		printf("\nc The content of currDictNode is %s.", h1->item ); 
		printf("\n\ncurrDictNode->item is : %s.", currDictNode->item );
		h1 = h1->next;
		h2 = h2->next;
	}						/* End while */
	
	h1->next = NULL;
	printf("In duplicate_currDict( ) : \n");
	printf("\n\ncurrDictNode->item is : %s.", currDictNode->item );
}						/* End duplicate_currDict( ) */


ListNode *arrayToDict( char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *&dictNode )
{

	printf(" \n\n\n\n			In arrayToDict : dictNode->item is %s.\n\n\n\n		------------", dictNode->item );
	
	arrayToListNode( inputArr, tokenSize, newTermsNode );
	/* PPS. inputArr[][] is the new coming content of xxx.txt, and the content */
	/* will be converted into newTermsNode */
	
	duplicate_currDict( currDictNode, dictNode );
	/* dictNode is the global dictionary in main(). currDictNode is just for temporary backup */
	printf( "\n\n\n\nHello. After duplicate_currDict( ), newTermsNode->item is %s. ", newTermsNode->item );
	//merge_dictionary( newTermsNode, currDictNode, dictNode );

}

