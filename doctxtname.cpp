   /*******************************************************
   char * buf = "s""p";
   char buf2[ MAX_STR_LEN ];
   //* �z�������������� ���M�o��n�� 
   itoa( 2, buf2, 10 );
  
   string sym( 1, buf2[0] );
	const char * CONST_firstHalfOfFileName;
	CONST_firstHalfOfFileName = sym.c_str();
   const char * stopwordfile ;
	stopwordfile = CONST_firstHalfOfFileName;
	
	//*���T : stopwordfile = CONST_firstHalfOfFileName; 
	//* ���~ : stopwordfile = CONST_firstHalfOfFileName + "Hello World"; 
   /****************************************************************/
