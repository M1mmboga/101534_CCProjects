/*MIRIAM MMBOGA 101534 ICS4A*/
/*This program uses flex to output hello world on the console*/

/*In this section %, variables are declared by a user*/
%{

#undef yywrap
#define yywrap() 1

%}


/*In this section %%, patterns to be executed are stated; patterns can be numbers 0-9 or alphabet a-z/A-Z*/
%%

[\n] {
/*Prints Hello World on the console*/
	printf("Hello World\n");	
}
	
%%
main()
{
/*this function retrieves tokens from the compiler*/

	yylex(); //calling the rules section
}