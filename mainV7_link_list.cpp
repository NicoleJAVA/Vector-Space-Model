/* ver. 6
1.)
我突然覺得該不會是要把所有變數都變成 global 的吧 !!  
2.)
	Nicole modified names of some variables in txtToArray( ) .
	For example : 
   char tempCharacter_tTA;  
	_tTA is the abbrev. for _textToArray 
3.)
in txtToArray(), I must reset stopNum to zero.
4.)
Discard this line in porter.cpp : system("PAUSE");
5.)
Must add this line of code in function txtToArray( ) : 
	   fclose(txtFile);
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include "porter.cpp"

#define MAX_STR_LEN 30
#define MAX_STOP_SIZE 500
#define APPEND 0
#define RMV 1 
#define MAX_WORD_NUM 10000
#define DOC_NUM 1095
#define DICT_SIZE 1000/* dictionary size : total number of tokens of all docs.*/
using namespace std;
/*((((((((((((((((((((((((((((((((((((((((((((((((*/
/*((((((((((((((((((((((((((((((((((((((((((((((((*/
/*((((((((((((((((((((((((((((((((((((((((((((((((*/


struct ListNode
{
	char item[ MAX_STR_LEN ] ;
	ListNode  *next ;
};

ListNode *merge(const ListNode *h1, const ListNode *h2, ListNode *&result )
{
	ListNode dummy;
	ListNode *tail;
	
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

/*((((((((((((((((((((((((((((((((((((((((((((((((*/
/*((((((((((((((((((((((((((((((((((((((((((((((((*/
/*((((((((((((((((((((((((((((((((((((((((((((((((*/

/******************************************************************************/
void clear_array( char inputArr[ ][ MAX_STR_LEN ] ){ 
	int i = 0;
	int j = 0;
	for( i = 0; i < MAX_WORD_NUM; i++  ){
		for( j = 0; j < MAX_STR_LEN; j++ ){
			inputArr[i][j] = '\0';
		} // End 2-for
	} // End-1-for
}

/******************************************************************************/

   char tempCharacter_tTA;  /* _tTA is the abbrev. for _textToArray */  
   char  oneDimArr[10000];
   char temp_tTA[ MAX_STR_LEN ];
   int charCount = 0;

   char *tokenPtr_tTA;
   int twoDim_i = 0;

    int i = 0;

/* ~ ~ ~ ~ ~ ~ ~ ~ */
void txtToArray( FILE *txtFile, char twoDimArr[][ MAX_STR_LEN ], int & wordCount )
{
	printf("\nEnter txtToArray" );
	/* wordCout must be reset to zero ! 
	*/ 
	wordCount = 0; 
   charCount = 0;
   twoDim_i = 0;
	/*--------------------------------------------*/
   i = 0;
  if ( txtFile==NULL ) perror ( "\nIn txtToArray : File Cannot Be Opened.\n" );
  else
  {
    do {
      tempCharacter_tTA = fgetc ( txtFile );
      oneDimArr[ i ] = tempCharacter_tTA;
      if ( tempCharacter_tTA == '\n' ){
         oneDimArr[ i ] = ' ';
      }
      i++;
    } while ( tempCharacter_tTA != EOF);
    oneDimArr[ i ] = tempCharacter_tTA;
	/*--------------------------------------------*/
	}	
	
	tokenPtr_tTA = strtok( oneDimArr, " ,.-" );
	while( tokenPtr_tTA != NULL  ){
		strncpy( &temp_tTA[ 0 ], tokenPtr_tTA, MAX_STR_LEN );
		strncpy( twoDimArr[ twoDim_i ], temp_tTA, MAX_STR_LEN ); 
		i++;
		tokenPtr_tTA = strtok( NULL, " ,.-" );
		twoDim_i ++;
		wordCount ++;
	}
   fclose(txtFile);
} /* End txtToArray( ) */
/*--------------------------------------------*/

/* ~ ~ ~ ~ ~ ~ */ 
   FILE * pFile;
   char tempCharacter;
   /* int i = 0; */
   int n = 0;
   char content[10000];
   int tokenNum = 0;
	int stop_i = 0;
	int token_i = 0;
	int token_j = 0;
	int rmv_i = 0;
	int tokenIndex = 0;
	int tokenCount = 0;
	int temp_i = 0;
	int flag = APPEND;
   char * tokenPtr;  
	char temp[ MAX_STR_LEN ];
	char token[ 10000 ][ MAX_STR_LEN ];
/* ~ ~ ~ ~ ~ ~ */ 
int rmvStop( char rmvStop[][ MAX_STR_LEN ], char stopList[][ MAX_STR_LEN ], int & stopNum, int & tokenSize )
{
   printf("\nEnter rvmStop( ) ; " );
   tokenSize = 0; /* tokenSize must be reset to zero ! */
   i = 0;
   n = 0;
	stop_i = 0;
 	token_i = 0;
 	token_j = 0;
	rmv_i = 0;
	tokenIndex = 0;
	tokenCount = 0;
	temp_i = 0;
	flag = APPEND;
	pFile=fopen ("input.txt","r");
	
  if (pFile==NULL) perror ("\nIn rmvStop( ) : Error opening file");
  else{
		printf("\nIn rmvStop( ) : Successfully open pFile");
		txtToArray( pFile, token, tokenSize );
		printf("\nIn rmvStop( ) : txtToArray done" );	
		fclose (pFile);
	printf("\nIn rmvStop( ) : stopNum is : %d .", stopNum );
	printf("\nIn rmvStop( ) : tokenSize is : %d .", tokenSize );
	/*-------------------------------------------------------------*/	
	for ( token_i = 0; token_i < tokenSize; token_i++ ){
		flag = APPEND;
  		for ( stop_i = 0;  stop_i  <=  stopNum; stop_i++ ){
			if ( !strcmp( token[ token_i ], stopList[ stop_i ] ) ){
				flag = RMV;
			} // END if
		} //END for
		if( flag == APPEND ){
			strncpy( rmvStop[ rmv_i ], token[ token_i ], MAX_STR_LEN );
			rmv_i ++;		
		} // END if

	} // END for
	printf("\nIn rmvStop( ) : ending this function");
	rmvStop[ rmv_i ][0] = '\0';
  } // END fopen( );
  return 0;
}


/*------------------------------------------------*/


/* ~ ~ ~ ~ ~ ~ ~ ~ */
int main()
{
	FILE * stopFile;
	FILE * aFile;
   char stopArr[ MAX_STOP_SIZE ][ MAX_STR_LEN ];
   char article[ 10000 ][ MAX_STR_LEN ];
   char check[ 10000 ][ MAX_STR_LEN ];
   char stemByPorter[ 10000 ][ MAX_STR_LEN ];
	char dict[ DICT_SIZE ][ MAX_STR_LEN ];
	char **dptr = NULL; /* dictionary pointer */
	dptr = (char**)malloc(sizeof(char*)*20);
	
   // Don't name the array as "porter" because it would be confused
   // with "poter.cpp" and "poter( )" 
   int stopSize = 0;
   int tokenSize = 0;
   int stemSize = 0;
   int currDictSize = 0;
   int i = 0;
    
   
for( int docLoop = 1; docLoop <= DICT_SIZE; docLoop ++ ){    
	printf("\n\ndocument %d.", docLoop );
   stopFile=fopen( "stopwordfile.txt", "r" );
   txtToArray( stopFile, stopArr, stopSize );
   rmvStop( article, stopArr, stopSize, tokenSize  );
   printf("\nrmvStop( ) done ! " ); 
		/*rmvStop() resets tokenSize to zero and then update tokenSize*/
   aFile = fopen( "afile.txt" , "w" );
   printf("\nSuccessfully open file. aFile is now : %d", aFile);
   printf("\naFile = fopen afile.txt, w" );
   if ( aFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" );
   else
   {		   
		clear_array( article );
		clear_array( stemByPorter );
		while( i <= tokenSize ){ /* tokenSize has already been updated by rmvStop()*/
			fprintf( aFile, "%s ", article[ i ] );
	 	  i++;  
		} // End 3-while 
		fclose( aFile );
		printf("\nIn main( ) : fclose aFile." );
		/*--------------------------------------------------------*/
  		porter( 1, stemByPorter, tokenSize );
  		printf("In main( ) : porter done.\n\n");
  		/*--------------------------------------------------------*/ 
   }  // END 2-if-else
} // End 1-for

	   printf( "\n\n\n\n\n\n\n" );
		printf( "          -------------\n" );
	   printf( "         | Thank you!  |\n" );
		printf( "          -------------\n\n\n\n\n\n\n\n\n\n\n\n\n" );		
   system("PAUSE");
}
