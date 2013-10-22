
/* Ver. 15	-	compareTerm.cpp

1.)
Don't use the official strncmp/strcmp anymore.
Why not write a compare_term( ) function yourself? 
別用官方的 strncmp，何不乾脆自己寫一個 compare_term( ) ? 

2.)
[結果]
strlen(s1) = 5
strlen(s2) = 5
[說明]
strlen():回傳字串的長度("不"包括terminated null character)
 
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
using namespace std;

int compare_term( const char *inputStr1, const char *inputStr2  )
{
   int i = 0; 
   int flag = 1 ;
   int flag_same_string = 2; /* 先假設他們是完全一樣的字串 */
   int flag_same_next_ch = 2; /* 先假設他們的下一個字元也是同樣的*/
	char term1[ MAX_STR_LEN ];
	char term2[ MAX_STR_LEN ];
  	char tempchar1;
	char tempchar2;
	
	strncpy( term1, inputStr1, MAX_STR_LEN );
	strncpy( term2, inputStr2, MAX_STR_LEN );
	
	printf("\nHello compare_term >> term1 is >> %s.", term1 );
	printf("\nHello compare_term >> term2 is >> %s.", term2 );
	
   for( i = 0; term1[i] != '\0' && term2[i] != '\0' ; i++ ){
		printf("\n\n\n進入 %d 迴圈\n", i ); 
		if( term1[i] > term2[i] ){
			flag = 0;
			flag_same_string = -1;
			printf("\n旗子變成 0 了" ); 
		}				// end if
		if( term1[i] < term2[i] ){
			/* 不要改變 flag 的值 */
			printf("\n還沒開始改變 flag 的值. >> the value of flag hasn't been alterd yet." ); 
			flag_same_string = -1;
		}				// end if		
		if( term1[i] == term2[i] ){
			printf("\n兩字元相同" ); 
		}
		
		printf("\n目前 flag是 %d. ", flag );
		printf("\n目前 flag_same_string 是 %d. ", flag_same_string ); 
		if( term1[ i+1 ] != term2[ i+1 ] ){
			if( flag_same_next_ch == 2 ){
				printf("\n注意 -----> 從下一個字元開始, 兩字串開始不一樣了" ); 
			}
		}
		tempchar1 = term1[i];
		tempchar2 = term2[i];
		//printf("\nterm1 : %c. term2 : %c.", tempchar1, tempchar2 );
		//printf("\nIn compare_term() : flag is : %d.\n", flag );
		
		if( term1[ i+1 ] =='\0' && term2[ i+1 ] != '\0' ){
			if( flag_same_string == 2 ){
				flag = 1;
				printf("\n\nterm2 比 term1 長. flag 為 %d", flag );
			}
			
		}
		if( term1[ i+1 ] !='\0' && term2[ i+1 ] == '\0' ){
			printf("\nterm2 比 term1 長."); 
		}
		
		
		
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
int main()
{
	int cmpResult; /* compare result of compare_term( ) */
	std::string strA = "atloooss";
	std::string strB = "aHeoool";	
	
	printf("\n字串的長度到底是多少呢 : %d.", strlen( strA.c_str() ) ); 
	
	cmpResult = compare_term( strA.c_str(), strB.c_str() );	
	printf("\n\ncmpResult 的結果是 : %d.\n\n", cmpResult ); 
	
	system("PAUSE");
}
