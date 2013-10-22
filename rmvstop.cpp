
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
#ifndef DOC_NUM
#define DOC_NUM 1095
#endif
#define DICT_SIZE 1000/* dictionary size : total number of tokens of all docs.*/
using namespace std;


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
   char *tokenPtr_tTA;
   int twoDim_i = 0;
   int i = 0;

/* ~ ~ ~ ~ ~ ~ ~ ~ */
void txtToArray( FILE *txtFile, char twoDimArr[][ MAX_STR_LEN ], int & wordCount )
{

	/* wordCout must be reset to zero ! */ 
	wordCount = 0; 
   twoDim_i = 0;
   i = 0;
/*--------------------------------------------*/
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

/******************************************************************************/
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
		
		clear_array( token );
		
		txtToArray( pFile, token, tokenSize );

		fclose (pFile);

	printf("\nIn rmvStop( ) : After txtToArray( ) tokenSize is : %d .", tokenSize );
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

	rmvStop[ rmv_i ][0] = '\0';
  } // END fopen( );
  return 0;
}

/******************************************************************************/
/*------------------------------------------------*/
