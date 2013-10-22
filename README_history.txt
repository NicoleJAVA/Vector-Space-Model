	
	Github\Vector-Space-Model\README_history.txt

	/************************************************************	
		
		History in Github local repository directory !
		
	************************************************************/


	
	


/******************		Ver. 24  -  doctxtname.cpp		*********************


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


************************************************************/

/*
Ver. 20 - sort_firstDict.cpp

1.)
			previousPtr = new ListNode;
			previousPtr->nextPtr = sPtr;


*/


/* ver. 20 - main( )

1.) Ver. 20 
stemByPorter[] 應該要從 i = 1 而非 i = 0 開始, 去做 insertNode ( )  
Wrong code : 
	for( i = 0; i <= tokenSize; i++ ){
		insertNode( dictNode, stemByPorter[ i ], i );
				
Corrct Code :
	for( i = 1; i <= tokenSize; i++ ){

*/

/* ver. 19

1.)
Ver. 19 : all stuff of homework-1 is cut-and-paste to rmvstop.cpp file.
	
*/
/*
Ver. 19 - sort_firstDict.cpp

1.)
Ver. 19  >> remove debug info.

2.) 
Ver. 19  >> except insertNode(), all the other operations of listnode are move
to nodeoperation.cpp 

3.)
Ver 19 >> 
Wrong code : strncpy( newPtr->data.c_str(), value.c_str(), SORT_LEN );
Correct code : strncpy( const_cast<char*>(newPtr->data.c_str()), value.c_str(), SORT_LEN );
*/

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


/* Ver. 11 - dictCpp.cpp

1.)
still fighting with merge_dictionary( )
but the other functions are OK now :D

2.)
the variable names must be consistemt with sort_firstDict.cpp
Therfore, every "item" in Version.10 will be transformed to "data.c_str()" in Version.11


3.)
Ver 10 : strncpy( tail->nextPtr->item, h2->item, MAX_STR_LEN );
Ver 11 : strncpy( const_cast<char*>(tail->nextPtr->data.c_str()), h2->data.c_str(), MAX_STR_LEN );

 */
 
 /*
Ver. 11

1.)
I don't use arrayname[ ] declaration.
Instead, use std::string stringname declaration.


2.)
pass vlue instead of pass address
previous ver: void insertNode( ListNodePtr *sPtr, std::string value )
now ver : void insertNode( ListNodePtr sPtr, std::string value )

*/

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

 /*--------------------------------------------*/
 /* ver. 6
1.)
Nicole turns the local variable declaration into global variable declaration.
我突然覺得該不會是要把所有變數都變成 global 的吧 !!  
2.)
	Nicole modified names of some variables in txtToArray( ) .
	For example : 
   char tempCharacter_tTA;  
	_tTA is the abbrev. for _textToArray 
3.)
in txtToArray(), I must reset stopNum to zero.
4.)
Discard this line in porter.cpp : system("PAUSE");
5.)
Must add this line of code in function txtToArray( ) : 
	   fclose(txtFile);
 */
 
 	/*--------------------------------------------*/
 
