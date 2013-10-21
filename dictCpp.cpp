/* Ver. 11 - dictCpp.cpp

1.)
still fighting with merge_dictionary( )
but the other functions are OK now :D

2.)
the variable names must be consistemt with sort_firstDict.cpp
Therfore, every "item" in Version.10 will be transformed to "data.c_str()" in Version.11


3.)
Ver 10 : strncpy( tail->nextPtr->item, h2->item, MAX_STR_LEN );
Ver 11 : strncpy( const_cast<char*>(tail->nextPtr->data.c_str()), h2->data.c_str(), MAX_STR_LEN );

 */

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
//											#include "sort_firstDict.cpp"

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
	std::string data ;
	ListNode  *nextPtr ;
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
	printf("\n\nh1->item : %c. h2->item : %c.", h1->data.c_str(), h2->data.c_str() );
	for ( tail=&dummy; h1 != NULL || h2 != NULL; tail=tail->nextPtr ){
		printf("\nHello ");
		//tail->next = ListNode;
		printf("\nHello new ");
		buff1[0] = h1->data[0];
		printf("\nHello buff1" );
		flag = strncmp( h1->data.c_str(), h2->data.c_str(), MAX_STR_LEN );
		printf("\nHello flag ");
		/* If strncmp( A, B ) > 0, then the order shold be ... -> B -> A -> ... */
	   if( h1==NULL || ( h2 !=NULL && flag > 0 ) ){
	   /* original : if( h1==NULL || h2 !=NULL && h2->item < h1->item)){
			*/
			/* Nicole wants to use a flag instead ! */
			/* original : tail->next->item = h2->item; */
			strncpy( const_cast<char*>(tail->nextPtr->data.c_str()), h2->data.c_str(), MAX_STR_LEN );
			//printf("\nHello strncpy ");
			h2 = h2->nextPtr;
			printf("\nHello h2 = h2->next ");
		} /* end if */
		else if ( h2==NULL || ( h1!=NULL && flag <= 0 ) ){
		   /* original : tail->next->item = h1->item; */
		   strncpy( const_cast<char*>(tail->nextPtr->data.c_str()), h1->data.c_str(), MAX_STR_LEN );
		   h1 = h1->nextPtr;
		} /* end else */
	} /* end for */
	
	tail->nextPtr = NULL;
	
	result = dummy.nextPtr;
}

/******************************************************************************/
/*-------------------*/
	
/*-------------------*/
void arrayToListNode(char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *&tail2 )
{
	printf("\n進入Enter : arrayToListNode( ) ." );
	printf("\nIn arrayToListNode : tokenSize is : %d.\n\n\n\n", tokenSize );
	
	ListNode * dummy2; 
	dummy2 = new ListNode; /* 原來關鍵是要加上這一句呵呵呵 */
	/* PPS. address of dummy2 is fixed bcause dummy2 is statically allocated*/
	int i = 0;	
	tail2 = dummy2;
	//printf("\nHello tail2 = dummy2 拉拉拉拉." ); 
	for( i = 0; i < tokenSize; i++ ){
		printf("\n\nIn arrayToListNode : the %d-th loop.", i );
		tail2->nextPtr = new ListNode;
		//printf("\nHello the %d-th dynamic allocate 第 %d 次的動態記憶體", i, i ); 
		strncpy( const_cast<char*>( tail2->nextPtr->data.c_str() ), inputArr[i], MAX_STR_LEN );
		printf("\n The content of tail2 is %s. ( Chinese: tail2->data.c_str() 的內容 ) ", tail2->data.c_str() ); 
		tail2 = tail2->nextPtr;
	}						/* End for */
	tail2->nextPtr = NULL;
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
	if(h2->data.c_str()  == NULL )
	printf( "\n\n\n         h2->item is NULL ! ");
	while( h2->data.c_str()  != NULL ){
		printf( "\nHello h2->item != NULL        : >> " );
		h1->nextPtr = new ListNode;
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

