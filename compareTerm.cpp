
/* Ver. 8 	-	sortTerm.cpp


 */

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
#define EARLIER 0
#define LATER 1  /* term1 shold appear after term2 */
#define SAME 2
using namespace std;

int compare_term( char * term1, char *term2 )
{
   int i = 0; 
   int flag = 0; 
  	char tempchar1;
	char tempchar2;
   for( i = 0; term1[i] != '\0' && term2[i] != '\0' ; i++ ){
		if( term1[i] > term2[i] ){
			flag = 1;
		}				// end if
		
		
		tempchar1 = term1[i];
		tempchar2 = term2[i];
		//printf("\nterm1 : %c. term2 : %c.", tempchar1, tempchar2 );
		//printf("\nIn compare_term() : flag is : %d.\n", flag );
		
	}					/* end for */
	return flag;
}						/* end compare_term( )  */

/*
int main(){
	
	char term1[ MAX_STR_LEN ];
	char term2[ MAX_STR_LEN ];


	strncpy( term1, "Happy", MAX_STR_LEN );
	strncpy( term2, "Happen", MAX_STR_LEN );
	
	compare_term( term1, term2 );
	
	system("PAUSE");

}
*/
