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
 
