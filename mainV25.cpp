
/******************		Ver. 25  -  main.cpp		*********************

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
#include "doctxtname.cpp"


#define MAX_STR_LEN 30
#define MAX_STOP_SIZE 500
#define APPEND 0
#define RMV 1 
#define MAX_DOC_LOOP 10
#define DICT_SIZE 1000//dictionary size:total number of tokens of all docs

using namespace std;

ListNode *dummyS; //		global dummy pointer for Sorting


/*------------------------------------------------*/
int main()
{
	FILE * stopFile;
	FILE * beforeStemFile;//After rmvstop( ), write article[] to beforStemFile
	FILE * stemFile;//  R E A D - O N L Y ! stemFile's only for reading
	FILE * stemmingResultFile;//porter( ) writes result into stemmingResultFile

	FILE * newsFile;
	FILE * vectorFile;
	
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
   int docloop = 1;	// docloop ranges form [ 1 ---> 1095 ]



						/*******************************/
						/****   open stopFile   ********/
						/*******************************/
						
	stopFile=fopen( "stopwordfile.txt", "r" );

   txtToArray( stopFile, stopArr, stopSize );    
	clear_array( article );
   rmvStop( article, stopArr, stopSize, tokenSize  );
	// After rmvStop(), rmvStop() first resets tokenSize to zero 
	//and then updates tokenSize

						/**************************************/
						/****   loop every "docloop.txt"  *****/
						/**************************************/
						
for( docloop = 1; docloop <= MAX_DOC_LOOP; docloop++ ){	//	Start-0-for-loop

	create_txtTitle( docloop );


	beforeStemFile = fopen( "afile.txt" , "w" );
	
   if ( beforeStemFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" ); 
   
   else //	2-if-else
   {		   
		
		clear_array( stemByPorter );
		
		//---while-loop to write the stuff in Winto aFile >>
		//---BeforeEnter while-loop,tokenSize's alreadyBeenUpdated by rmvStop()
		while( i <= tokenSize ){ 
						/**************************************/
						/****   write to  beforeStemFile  *****/
						/**************************************/
			fprintf( beforeStemFile, "%s ", article[ i ] );
	 	  i++;  
		} 							//		End-3-while
		fclose( beforeStemFile );

		/*--------------------------------------------------------*/
		stemFile = fopen( "afile.txt" ,"r");
		rewind(stemFile);
  		porter( 1, stemByPorter, tokenSize, stemFile, stemmingResultFile );
  		fclose(stemFile);
  		
		printf("After porter(), tokenSize is %d\n", tokenSize );

					
					
					


 		/*--------------------------------------------------------*/ 
 		
   }  							//		End-2-if-else
  
}	//		End-0-for-loop
 
 

 
 
 
 
 


	printf( "\n\n\n\n\n\n\n" );
	printf( "          -------------\n" );
   printf( "         | Thank you!  |\n" );
	printf( "          -------------\n\n\n\n\n\n\n\n\n\n\n\n\n" );		
   system("PAUSE");
} /* End main( ) */ 
