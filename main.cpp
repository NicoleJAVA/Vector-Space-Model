
/******************		Ver. 26  -  main.cpp		*********************

1.)	

In txtToArray( )

must return the result 'twoDimArr[][]',

or must pass by address of the argument 'twoDimArr[][] ! 

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
   char NEWSbeforeRmvStop[ 10000 ][ MAX_STR_LEN ]; 
   	// Before rmvStop( ), run the following :
   	// Within every loop==docloop, NEWSbeforeRmvStop will be cleared
   	// and then be passed to txtToArray(fileTitle, $this, token# )


   int stopSize = 0;
   int stopTokenSize = 0;
   int stemSize = 0;
   int currDictSize = 0;
   int NEWStokenSize = 0;
   int i = 0;
   int docloop = 1;	// docloop ranges form [ 1 ---> 1095 ]



						/*******************************/
						/****   open stopFile   ********/
						/*******************************/
						
	stopFile=fopen( "stopwordfile.txt", "r" );

	printf("\nStopFile's opened. Now txtToArray(stopfile)." );
   txtToArray( stopFile, stopArr, stopSize );   
		// txtToArray updates stopSize 
	printf("\nHello main >> stopArr[2] is %s.", stopArr[2] );
	clear_array( article );
   // Ver. 26 Discard : rmvStop( article, stopArr, stopSize, stopTokenSize,   );
	// After rmvStop(), rmvStop() first resets stopTokenSize to zero 
	//and then updates stopTokenSize
	
	
   puts("\n\n");	
	

/********************************************************* M A G I C ****/


	beforeStemFile = fopen( "happy.txt" , "r" );
	// old >> aFile = fopen( "afile.txt" , "w" );
	txtToArray( beforeStemFile, NEWSbeforeRmvStop, NEWStokenSize ); 
		// txtToArray updates NEWStokenSize
	printf("\nHello main >> NEWStokenSize is %d.", NEWStokenSize );
	printf("\nHello main >> beforeStemFile[20] is %s.", beforeStemFile[20] );
	clear_array( article );
	rmvStop( article, stopArr, stopSize, NEWStokenSize, NEWSbeforeRmvStop );

	puts("\nEnd M A G I C \n\n");

	
/********************************************************** M A G I C ******/












						/**************************************/
						/****   loop every "docloop.txt"  *****/
						/**************************************/
						
for( docloop = 1; docloop <= 0; docloop++ ){	//	Start-0-for-loop

	printf("\n\nNow it's in %d-th doloop.\n", docloop ); 
	newsSourceTitle = create_txtTitle( docloop, 1 );
	stemResultTitle = create_txtTitle( docloop, 0 );
	puts( newsSourceTitle.c_str() );
	puts( stemResultTitle.c_str() );
	

	

	beforeStemFile = fopen( newsSourceTitle.c_str() , "w" );
	// old >> aFile = fopen( "afile.txt" , "w" );

	txtToArray( beforeStemFile, NEWSbeforeRmvStop, NEWStokenSize ); 
	printf("\nHello main >> beforeStemFile[2] is %s.", beforeStemFile[2] );
	clear_array( article );
	rmvStop( article, stopArr, stopSize, NEWStokenSize, NEWSbeforeRmvStop );

   if ( beforeStemFile==NULL ) perror ( "\n In main() : File Cannot Be Opened.\n" ); 
   
   else //	2-if-else
   {		   
		
		clear_array( stemByPorter );
		i = 0;
		
		//---while-loop to write the stuff in Winto aFile >>
		//---BeforeEnter while-loop,tokenSize's alreadyBeenUpdated by rmvStop()
		while( i <= stopTokenSize ){ 
						/**************************************/
						/****   write to  beforeStemFile  *****/
						/**************************************/

			fprintf( beforeStemFile, "%s ", article[ i ] );
			// old >> fprintf( aFile, "%s ", article[ i ] );
	 	  i++;  
		} 							//		End-3-while
		fclose( beforeStemFile );

		/*--------------------------------------------------------*/
		stemFile = fopen( newsSourceTitle.c_str() ,"r");
		stemmingResultFile = fopen( stemResultTitle.c_str(), "w" );
		// old >> stemFile = fopen( "afile.txt" ,"r");
		
		rewind(stemFile);
  		porter( 1, stemByPorter, stopTokenSize, stemFile, stemmingResultFile );
  		
  		fclose(stemFile);
  		fclose(stemmingResultFile);
  		
		printf("\nHello main >> After porter(), tokenSize is %d\n", stopTokenSize );

					
					
					


 		/*--------------------------------------------------------*/ 
 		puts("\n-------  \n");	
   }  							//		End-2-if-else
   
  
}	//		End-0-for-loop
 
 

 
 
 
 
 


	printf( "\n\n\n\n\n\n\n" );
	printf( "          -------------\n" );
   printf( "         | Thank you!  |\n" );
	printf( "          -------------\n\n\n\n\n\n\n\n\n\n\n\n\n" );		
   system("PAUSE");
} /* End main( ) */ 
