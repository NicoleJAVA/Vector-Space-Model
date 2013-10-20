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

/*-------------------*/
	ListNode dummy;
	ListNode *tail;
/*-------------------*/
	
ListNode *merge(const ListNode *h1, const ListNode *h2, ListNode *&result )
{

	
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
void arrayToListNode()
{
	printf("\nEnter arrayToListNode( ) ." );
	
} /* end arrayToListNode( ) */


