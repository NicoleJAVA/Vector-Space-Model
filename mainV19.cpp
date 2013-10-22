/* ver. 19

1.)
Ver. 19 : all stuff of homework-1 is cut-and-paste to rmvstop.cpp file.
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include "rmvstop.cpp"
//			#include "porter.cpp"
#include "dictCpp.cpp"
#include "sort_firstDict.cpp"
#include "ir.hpp"


#define MAX_STR_LEN 30
#define MAX_STOP_SIZE 500
#define APPEND 0
#define RMV 1 
#define MAX_WORD_
#ifndef DOC_NUM
#define DOC_NUM 1095
#endif
#define DICT_SIZE 1000/* dictionary size : total number of tokens of all docs.*/
using namespace std;



/*------------------------------------------------*/
int main()
{
	FILE * stopFile;
	FILE * aFile;
	FILE * stemFile; /* pointer stemFile will be passed to poter( ) */
	ListNode *dictNode; /* dictionary list node */
   char stopArr[ MAX_STOP_SIZE ][ MAX_STR_LEN ];
   char article[ 10000 ][ MAX_STR_LEN ];
   char check[ 10000 ][ MAX_STR_LEN ];
   char stemByPorter[ 10000 ][ MAX_STR_LEN ];
   /* PPS. Don't name the array as "porter" because it would be confused */
   /* with "poter.cpp" and "poter( );"  */
	char dict[ DICT_SIZE ][ MAX_STR_LEN ];
	char **dptr = NULL; /* dictionary pointer */
	dptr = (char**)malloc(sizeof(char*)*20);

   int stopSize = 0;
   int tokenSize = 0;
   int stemSize = 0;
   int currDictSize = 0;
   int i = 0;
   
	stopFile=fopen( "stopwordfile.txt", "r" );
   txtToArray( stopFile, stopArr, stopSize );    
 
							 
							 
							 	/* Testing arrayToListNode */
 
 
 
	printf("\n\n\n\n\n			------------------------------" );
	printf("\n			Testing arrayToListNode\n\n\n\n\n" );	
   
	clear_array( article );
   rmvStop( article, stopArr, stopSize, tokenSize  );
		/* PPS. Now rmvStop() resets tokenSize to zero and then updates tokenSize*/
   //printf("\nrmvStop( ) done ! " ); 
   
	aFile = fopen( "afile.txt" , "w" );
   if ( aFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" );
   else
   {		   
		
		clear_array( stemByPorter );
		
		/* 						->		write the stuff in article[][] into aFile */
		while( i <= tokenSize ){ /* tokenSize has already been updated by rmvStop()*/
			fprintf( aFile, "%s ", article[ i ] );
	 	  i++;  
		} 							/* End 3-while */
		fclose( aFile );

		/*--------------------------------------------------------*/
		stemFile = fopen( "afile.txt" ,"r");
		rewind(stemFile);
  		porter( 1, stemByPorter, tokenSize, stemFile );
  		fclose(stemFile);
  		
		printf("After porter(), tokenSize is %d\n", tokenSize );
  		
	/* pre-condition : after porter() is done, stemByPorter[][] now */
	/* holds the stemming result of afile.txt. */					
	/* pre-condition : tokenSize is correctly updated*/					
					
					
					/*              H E L L O                      */
					
					
					
	printf("\n先把字典變成 listnode"); 
	/* Ver. 14 開始, deprecate 這行 : arrayToListNode( stemByPorter, tokenSize, dictNode ); */ 
	/* Ver. 14 開始, deprecate 這行 : arrayToDict( stemByPorter, tokenSize, dictNode ); */
	for( i = 0; i < tokenSize; i++ ){
		//printf("先看看作業 1 的 stemByPorter[i] 是 %s.", stemByPorter[i] ); 
		insertNode( dictNode, stemByPorter[ i ], i );
	}					/* end for */	

 		/*--------------------------------------------------------*/ 
   }  							/* END 2-if-else */
   	printf("\n\n		 E N D - Testing arrayToListNode - E N D - \n\n\n\n\n" );	
 
 
 
 
 
 
 
 
 
 
 							 	/*  E N D - Testing arrayToListNode - E N D - */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
for( int docLoop = 1; docLoop <= 0; docLoop ++ )
{    
	printf("\n\n\n\n\n------------------------------" );
	printf("\ndocument %d.txt", docLoop );	
   
	clear_array( article );
   rmvStop( article, stopArr, stopSize, tokenSize  );
		/* PPS. Now rmvStop() resets tokenSize to zero and then updates tokenSize*/
   printf("\nrmvStop( ) done ! " ); 
   aFile = fopen( "afile.txt" , "w" );
   printf("\nSuccessfully open file. aFile is now : %d", aFile);
   printf("\naFile = fopen afile.txt, w" );
   if ( aFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" );
   else
   {		   
		
		clear_array( stemByPorter );
		
		/* 						->		write the stuff in article[][] into aFile */
		while( i <= tokenSize ){ /* tokenSize has already been updated by rmvStop()*/
			fprintf( aFile, "%s ", article[ i ] );
	 	  i++;  
		} 							/* End 3-while */
		fclose( aFile );
		printf("\nIn main( ) : fclose aFile." );
		/*--------------------------------------------------------*/
		stemFile = fopen( "afile.txt" ,"r");
		rewind(stemFile);
  		porter( 1, stemByPorter, tokenSize, stemFile );
  		fclose(stemFile);
  		printf("In main( ) : porter is done.\n And tokenSize is %d\n", tokenSize );



					/* - - - - - - - - - - - - - - - */
							
							
								/* dictCpp.cpp*/
								
								
								
					/* - - - - - - - - - - - - - - - */
					
					
	/* pre-condition : after porter() is done, stemByPorter[][] now */
	/* holds the stemming result of afile.txt. */					
	/* pre-condition : tokenSize is correctly updated*/					
					
				
					
					
					/* - - - - - - - - - - - - - - - */




  		/*--------------------------------------------------------*/ 
   }  							/* END 2-if-else */
} 									/* End 1-for */

	printf( "\n\n\n\n\n\n\n" );
	printf( "          -------------\n" );
   printf( "         | Thank you!  |\n" );
	printf( "          -------------\n\n\n\n\n\n\n\n\n\n\n\n\n" );		
   system("PAUSE");
} /* End main( ) */ 
