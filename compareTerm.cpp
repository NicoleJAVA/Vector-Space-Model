
/* Ver. 15	-	compareTerm.cpp

1.)
Don't use the official strncmp/strcmp anymore.
Why not write a compare_term( ) function yourself? 
�O�Ωx�誺 strncmp�A�󤣰��ܦۤv�g�@�� compare_term( ) ? 

2.)
[���G]
strlen(s1) = 5
strlen(s2) = 5
[����]
strlen():�^�Ǧr�ꪺ����("��"�]�Aterminated null character)
 
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
#define STRA_NEXT_B 1 /* �w�q�� 1 �O�]���{�� A ����  B ������ı���[, �ҥH�w�q�� TRME ��*/
#define STRA_AFTER_B 0  /* term1 shold appear after term2 */
#define SAME 2
using namespace std;

int compare_term( const char *inputStr1, const char *inputStr2  )
{
   int i = 0; 
   int flag = 1 ;
   int flag_same_string = 2; /* �����]�L�̬O�����@�˪��r�� */
   int flag_same_next_ch = 2; /* �����]�L�̪��U�@�Ӧr���]�O�P�˪�*/
	char term1[ MAX_STR_LEN ];
	char term2[ MAX_STR_LEN ];
  	char tempchar1;
	char tempchar2;
	
	strncpy( term1, inputStr1, MAX_STR_LEN );
	strncpy( term2, inputStr2, MAX_STR_LEN );
	
	printf("\nHello compare_term >> term1 is >> %s.", term1 );
	printf("\nHello compare_term >> term2 is >> %s.", term2 );
	
   for( i = 0; term1[i] != '\0' && term2[i] != '\0' ; i++ ){
		printf("\n\n\n�i�J %d �j��\n", i ); 
		if( term1[i] > term2[i] ){
			flag = 0;
			flag_same_string = -1;
			printf("\n�X�l�ܦ� 0 �F" ); 
		}				// end if
		if( term1[i] < term2[i] ){
			/* ���n���� flag ���� */
			printf("\n�٨S�}�l���� flag ����. >> the value of flag hasn't been alterd yet." ); 
			flag_same_string = -1;
		}				// end if		
		if( term1[i] == term2[i] ){
			printf("\n��r���ۦP" ); 
		}
		
		printf("\n�ثe flag�O %d. ", flag );
		printf("\n�ثe flag_same_string �O %d. ", flag_same_string ); 
		if( term1[ i+1 ] != term2[ i+1 ] ){
			if( flag_same_next_ch == 2 ){
				printf("\n�`�N -----> �q�U�@�Ӧr���}�l, ��r��}�l���@�ˤF" ); 
			}
		}
		tempchar1 = term1[i];
		tempchar2 = term2[i];
		//printf("\nterm1 : %c. term2 : %c.", tempchar1, tempchar2 );
		//printf("\nIn compare_term() : flag is : %d.\n", flag );
		
		if( term1[ i+1 ] =='\0' && term2[ i+1 ] != '\0' ){
			if( flag_same_string == 2 ){
				flag = 1;
				printf("\n\nterm2 �� term1 ��. flag �� %d", flag );
			}
			
		}
		if( term1[ i+1 ] !='\0' && term2[ i+1 ] == '\0' ){
			printf("\nterm2 �� term1 ��."); 
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
	
	printf("\n�r�ꪺ���ר쩳�O�h�֩O : %d.", strlen( strA.c_str() ) ); 
	
	cmpResult = compare_term( strA.c_str(), strB.c_str() );	
	printf("\n\ncmpResult �����G�O : %d.\n\n", cmpResult ); 
	
	system("PAUSE");
}
