
/* Ver. 17	-	compareTerm.cpp

1.)
Don't use MAX_STR_LEN 30 to allocate term1[ MAX_STR_LEN ]
Instead, just declare term1[ 200 ]

2.)
Discard comments.

3.)
Wrong Code :
	#define CMP_LEN 100
Correct Code :
	#define CMP_LEN 1000
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
#define STRA_NEXT_B 1 /* 定義為 1 是因為認為 A 先於  B 較為直覺直觀, 所以定義為 TRME 值*/
#define STRA_AFTER_B 0  /* term1 shold appear after term2 */
#define SAME 2

#define CMP_LEN 1000
using namespace std;






int compare_term( const char *inputStr1, const char *inputStr2, int index  )
{
   int i = 0; 
   int flag = 1 ;
   int flag_same_string = 2; 
	/* 注意 ! 不是指整個字串都一樣, 而是指目前有比較到的字串都一樣 */ 
	/* 先假設他們是完全一樣的字串 */
   int flag_same_next_ch = 2; /* 先假設他們的下一個字元也是同樣的*/

	char term1[ CMP_LEN ];
	char term2[ CMP_LEN ];
  	char tempchar1;
	char tempchar2;
	
	strncpy( term1, inputStr1, CMP_LEN );
	strncpy( term2, inputStr2, CMP_LEN );
	
	
	
	/**************************************************** M A G I C ***/
if(index < 5 ){ 
	printf("\nHello compare_term >> term1 is >> %s.", term1 );
	printf("\nHello compare_term >> term2 is >> %s.", term2 );
} 
	/*******************************************************/

	
   for( i = 0; term1[i] != '\0' && term2[i] != '\0' ; i++ ){
		
		if( term1[i] > term2[i] ){
			
			if(flag_same_string == 2)
			{
				flag = 0;
				//printf("\n從現在開始,flag 變成 0 了 " ); 
			}
			flag_same_string = -1;
		}				// end if
		
		if( term1[i] < term2[i] ){
			/* 不要改變 flag 的值 */
			flag_same_string = -1;
		}				// end if		
		
		if( term1[i] == term2[i] ){
			//printf("\n兩字元相同" ); 
		}
		
		//printf("\n目前 flag是 %d. ", flag );
		//printf("\n目前 flag_same_string 是 %d. ", flag_same_string ); 
		if( term1[ i+1 ] != term2[ i+1 ] ){
			if( flag_same_string == 2 ){
				//printf("\n注意 -----> 從下一個字元開始, 兩字串開始不一樣了" ); 
			}
		}
		tempchar1 = term1[i];
		tempchar2 = term2[i];
		//printf("\nterm1 : %c. term2 : %c.", tempchar1, tempchar2 );
		//printf("\nIn compare_term() : flag is : %d.\n", flag );
		
						/* --- 以下是處理長短不一的字串 --- */
		
		if( term1[ i+1 ] =='\0' && term2[ i+1 ] != '\0' ){
			flag_same_string = -1;
			if( flag_same_string == 2 ){
				flag = 1;
				//printf("\n\nterm2 比 term1 長. flag 為 %d", flag );
			}
			
		}
		
		if( term1[ i+1 ] !='\0' && term2[ i+1 ] == '\0' ){
			flag_same_next_ch = -1;
			if( flag_same_string == 2 ){
				
				//printf("\nterm1 比 term2 長."); 
			}				/* end if */
		}
		
		
		
	}					/* end for */
	
	if( flag_same_string == 2 && strlen(inputStr1) == strlen(inputStr2) ){
		return 2;
	}
	else{
		return flag;
	}
}						/* end compare_term( )  */


int main3()
{
	int cmpResultAB; /* compare result of compare_term( ) */
	int cmpResultCD; /* compare result of compare_term( ) */
	int cmpResultEF; /* compare result of compare_term( ) */
	std::string strA = "abzssss";
	std::string strB = "ahc";	
	std::string strC = "abzssss";
	std::string strD = "abcss";	
	std::string strE = "abzsssss";
	std::string strF = "abzss";	
	
	//printf("\n字串的長度到底是多少呢 : %d.", strlen( strA.c_str() ) ); 
	//printf("\n字串的長度到底是多少呢 : %d.", strlen( strC.c_str() ) ); 
	//cmpResultAB = compare_term( strA.c_str(), strB.c_str() );	
	cmpResultCD = compare_term( strC.c_str(), strD.c_str(), 0 );
	//cmpResultEF = compare_term( strE.c_str(), strF.c_str() );	
	
	//printf("\n\nA 與 B 的cmpResult 的結果是 : %d.", cmpResultAB ); 
	//printf("\n\nC 與 D 的cmpResult 的結果是 : %d.", cmpResultCD ); 
	//printf("\n\nE 與 F 的cmpResult 的結果是 : %d.", cmpResultEF ); 
	
	char tempbuf[ 30 ];
	strncpy( tempbuf, strA.c_str(), 100 );
	//printf("\n strA is %s.", tempbuf );
	//printf("\n\n\n");
	system("PAUSE");
}
