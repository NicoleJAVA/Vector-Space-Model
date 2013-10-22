/* Ver. 14 - dictCpp.cpp

1.)
Ver. 14 : delete this function : duplicate_currDict( ) 
And only use insertNode( ) to handle the node insertion 
Niole >> 我想整個 刪掉 duplicate_currDict( )  這個函數，假裝它從未存在 
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

#ifndef _IR_HPP_
#define _IR_HPP_
struct ListNode
{
	std::string data ;
	struct ListNode  *nextPtr ;
};
#endif



using namespace std;

/*********************************************/

/* - - - - - - - - - - - - - - - */
	ListNode *newTermsNode;
	ListNode *currDictNode;  /* is first updated by duplicate_currDict( ) */
	/* currDictNode currDictNode is just for temporary backup. */
	/* It will hold the copy of ListNode *&dictNode*/




/******************************************************************************/

	ListNode dummy;
	ListNode *tail;
	char buff1[ MAX_STR_LEN ];
	char buff2[ MAX_STR_LEN ];
	
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
	printf("\n\n\nEnter : arrayToListNode( ) >> 此函數負責把陣列轉換成鏈結串列" );
	printf("\nIn arrayToListNode : tokenSize is : %d.\n", tokenSize );
	
	ListNode * dummy2; 
	dummy2 = new ListNode; /* 原來關鍵是要加上這一句呵呵呵 */
	/* PPS. address of dummy2 is fixed bcause dummy2 is statically allocated*/
	int i = 0;	
	tail2 = dummy2;
	for( i = 0; i < tokenSize; i++ ){
		tail2->nextPtr = new ListNode;
		strncpy( const_cast<char*>( tail2->nextPtr->data.c_str() ), inputArr[i], MAX_STR_LEN );
		tail2 = tail2->nextPtr;
	}						/* End for */
	tail2->nextPtr = NULL;

}						/* ----- end arrayToListNode( ) ----- */



/******************************************************************************
ListNode *duplicate_currDict( ListNode *&h1, ListNode *&h2 )
{	
						 在 Ver. 14 以前. 這裡是有 duplicate_currDict( ) 的程式碼的 
}						
/******************************************************************************/
						/* End duplicate_currDict( ) */


ListNode *arrayToDict( char inputArr[][ MAX_STR_LEN ], int & tokenSize, ListNode *&dictNode )
{

	printf(" \n\n\nIn arrayToDict : dictNode->data.c_str() is %s.\n------------", dictNode->data.c_str() );
	printf(" \narrayToDict( ) 會先把 array 變成 listnode( via. arrayToListNode() ), 再把 listnode 變成字典 ( via. insertNode ).\n"); 
	arrayToListNode( inputArr, tokenSize, newTermsNode );
	/* PPS. inputArr[][] is the new coming content of xxx.txt, and the content */
	/* will be converted into newTermsNode */
	
	
	
	printf( "\nHello arrayToDict >> newTermsNode->data.c_str() is %s. ", newTermsNode->data.c_str() );
	//merge_dictionary( newTermsNode, currDictNode, dictNode );

}

