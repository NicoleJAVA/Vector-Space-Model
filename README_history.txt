 

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
 
