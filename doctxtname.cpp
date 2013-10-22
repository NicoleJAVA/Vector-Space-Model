/*
Ver. 24

1.)
Bug : cannot pass objects of non-POD type 'struct std::string' through '...'
Wrong Code : 
	snprintf( titleBuf, TXT_NAME_LEN, "%d%s", 20, txtSuffixTitle );
Correct Code :  
	snprintf( titleBuf, TXT_NAME_LEN, "%d%s", 20, txtSuffixTitle.c_str() );
	
2.)
char*到 const char*直接給值就可以了, 所以在 snprintf 存到 char * buf 後, 
可以直接將 buf 內容 assign 給 std::string newsSourceTitle 。
	snprintf( titleBuf, TXT_NAME_LEN, "%d%s", 20, txtSuffixTitle.c_str() );
	newsSourceTitle = titleBuf; 
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>

#define TXT_NAME_LEN 100
using namespace std;

std::string create_txtTitle( int titleNumericPart )
{
// titleNumericPart is the numeric part in the txt file name
// eg, '28' of "28.txt" 

	FILE * newsFile;
	FILE * stemmingFile;
	FILE * stemmingResultFile;
	FILE * vectorFile;
	

	//std::string num_newsSourceTitle; //	const char * num_newsSourceTitle;
	//std::string num_stemResultTitle;	//	const char * num_stemResultTitle;
	//std::string num_vectorTitle;		//	const char * num_vectorTitle;
	std::string newsSourceTitle ;		//		const char * newsSourceTitle;	
	std::string stemResultTitle ;		//		const char * stemResultTitle;	
	std::string vectorTitle ;			//		const char * vectorTitle;
	std::string txtSuffixTitle = ".txt" ;
	
	char titleBuf[ TXT_NAME_LEN ];	
	
	snprintf( titleBuf, TXT_NAME_LEN, "%d%s", titleNumericPart, txtSuffixTitle.c_str() );
	newsSourceTitle = titleBuf; 
	//puts( newsSourceTitle.c_str() );
	return newsSourceTitle ; 
	//newsFile = fopen( newsSourceTitle.c_str(), "w" );
	//stemmingFile= fopen( "", "r" );

	
	system("PAUSE");
} // end  create_TxtTitle( ) 



/**********************************************************************/

int main()
{
	std::string lala ; 
	lala = create_txtTitle( 33 );
	puts( lala.c_str() );
	
	system("PAUSE");	
}
