/* ver. 7

for ver.8 : be aware that for testing purpose, the loop in main 
only execute 5 times rather than DICT_SIZE times.

1.)
Nicole creates dictionaryCpp.cpp .

2.) 
add this line of code in rmvStop( ) : clear_array( token );

3.)
For stopwordfile.txt,
main( ) knows the existence of function txtToAarray( ).
But for every xxx.txt,
main( ) DOES NOT KNOW the existence of function txtToAarray( ).
Only rmvStop( ) knows it.

4.)
porter( ) now recives one more argument : FILE * f 
Therefore, this line of code is discarded in porter( ) : 
		f = fopen( "afile.txt" ,"r");
And then, these lines of code are added into main( ) :
		FILE * stemFile;    pointer stemFile will be passed to poter( ) 
		stemFile = fopen( "afile.txt" ,"r");
  		porter( 1, stemByPorter, tokenSize, stemFile );
  		fclose(stemFile);
  		
5.) 
Nicole adds this line of code in porter( ) : 	rewind(f);
( Because if f is not rewound, then int & tokenSize won't get the correct value )
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include "porter.cpp"
#include "dictCpp.cpp"

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
   char *tokenPtr_tTA;
   int twoDim_i = 0;
   int i = 0;

/* ~ ~ ~ ~ ~ ~ ~ ~ */
void txtToArray( FILE *txtFile, char twoDimArr[][ MAX_STR_LEN ], int & wordCount )
{
	printf("\nEnter txtToArray" );
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
		
		clear_array( token );
		
		txtToArray( pFile, token, tokenSize );
		printf("\nIn rmvStop( ) : txtToArray done" );	
		fclose (pFile);
	printf("\nIn rmvStop( ) : stopNum is : %d .", stopNum );
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
	printf("\nIn rmvStop( ) : ending this function");
	rmvStop[ rmv_i ][0] = '\0';
  } // END fopen( );
  return 0;
}

/******************************************************************************/
/*------------------------------------------------*/
int main()
{
	FILE * stopFile;
	FILE * aFile;
	FILE * stemFile; /* pointer stemFile will be passed to poter( ) */
	
	
					/* - - - - - - - - - - - - - - - */
	

	
					/* - - - - - - - - - - - - - - - */
	
	
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
   
   
   
   char * buf = "s""p";
   char buf2[ MAX_STR_LEN ];
   /* �z�������������� ���M�o��n�� */
   itoa( 2, buf2, 10 );
  
   string sym( 1, buf2[0] );
	const char * CONST_firstHalfOfFileName;
	CONST_firstHalfOfFileName = sym.c_str();
   const char * stopwordfile ;
	stopwordfile = CONST_firstHalfOfFileName;
	
	/*���T : stopwordfile = CONST_firstHalfOfFileName; */
	/* ���~ : stopwordfile = CONST_firstHalfOfFileName + "Hello World"; */
   
	
	
	stopFile=fopen( "stopwordfile.txt", "r" );
   txtToArray( stopFile, stopArr, stopSize );    
 
 							
							 
							 
							 
							 
							 
							 
							 	/* Testing arrayToListNode */
 
 
 
 
   
	printf("\n\n\n\n\n			------------------------------" );
	printf("\n			Testing arrayToListNode\n\n\n\n\n" );	
   
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
	/* pre-condition : after porter() is done, stemByPorter[][] now */
	/* holds the stemming result of afile.txt. */					
	/* pre-condition : tokenSize is correctly updated*/					
					
	arrayToListNode( stemByPorter, tokenSize );				
 		/*--------------------------------------------------------*/ 
   }  							/* END 2-if-else */
   	printf("\n\n\n\n\n			  E N D - Testing arrayToListNode - E N D - \n\n\n\n\n" );	
 
 
 
 
 
 
 
 
 
 
 							 	/*  E N D - Testing arrayToListNode - E N D - */
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   
for( int docLoop = 1; docLoop <= 5; docLoop ++ )
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
					
	arrayToListNode( stemByPorter, tokenSize );				
					
					
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
