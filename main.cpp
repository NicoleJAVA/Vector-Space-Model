
//		In Github local repository !



/******************		Ver. 25  -  main( )		*********************

1.)	Nicole does N O T  want to write that sort-list-node STUFF ANYMORE !


************************************************************/


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
ListNode *dummyS; /*global dummy pointer for Sorting*/


/*------------------------------------------------*/
int main()
{
	FILE * stopFile;
	FILE * aFile;
	FILE * stemFile; /* pointer stemFile will be passed to poter( ) */
	FILE * resultFile;
	ListNode *dictNode; /* dictionary list node */
	
	std::string newsSourceTitle ;		//		const char * newsSourceTitle;	
	std::string stemResultTitle ;		//		const char * stemResultTitle;	
	std::string vectorTitle ;			//		const char * vectorTitle;
	
   char stopArr[ MAX_STOP_SIZE ][ MAX_STR_LEN ];
   char article[ 10000 ][ MAX_STR_LEN ];
   char check[ 10000 ][ MAX_STR_LEN ];
   char stemByPorter[ 10000 ][ MAX_STR_LEN ];
   // PPS. Don't name the array as "porter" because it would be confused 
   // with "poter.cpp" and "poter( );"  
   char dict[ DICT_SIZE ][ MAX_STR_LEN ];


   int stopSize = 0;
   int tokenSize = 0;
   int stemSize = 0;
   int currDictSize = 0;
   int i = 0;



						/****************************/
						/****   open stopFile   ****/
						/****************************/
						
	stopFile=fopen( "stopwordfile.txt", "r" );

   txtToArray( stopFile, stopArr, stopSize );    
	clear_array( article );
   rmvStop( article, stopArr, stopSize, tokenSize  );
	// After rmvStop(), rmvStop() first resets tokenSize to zero 
	//and then updates tokenSize

						/*********************************/
						/****   loop every "xxx.txt"  ****/
						/********************************/

	aFile = fopen( "afile.txt" , "w" );
   if ( aFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" ); /*2-if-else*/
   else //	2-if-else
   {		   
		
		clear_array( stemByPorter );
		
		// while-loop to write the stuff in article[][] into aFile >>
		// before enter while-loop, tokenSize has already been updated by rmvStop()
		while( i <= tokenSize ){ 
			fprintf( aFile, "%s ", article[ i ] );
	 	  i++;  
		} 							/* End 3-while */
		fclose( aFile );

		/*--------------------------------------------------------*/
		stemFile = fopen( "afile.txt" ,"r");
		rewind(stemFile);
  		porter( 1, stemByPorter, tokenSize, stemFile, resultFile );
  		fclose(stemFile);
  		
		printf("After porter(), tokenSize is %d\n", tokenSize );

					
					
					


 		/*--------------------------------------------------------*/ 
   }  							/* END 2-if-else */
  

 
 

 
 
 
 
 


	printf( "\n\n\n\n\n\n\n" );
	printf( "          -------------\n" );
   printf( "         | Thank you!  |\n" );
	printf( "          -------------\n\n\n\n\n\n\n\n\n\n\n\n\n" );		
   system("PAUSE");
} /* End main( ) */ 
