#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Simple program of a lexical analyzer in C++ by MIRIAM MMBOGA 101534 ICS4A
/*
A lexical analyzer reads program input/code and breaks it down into specific tokens or groups such as
identifiers (a), keywords(int), operators(+)
Identifiers refer to the names that one chooses when programming
Keywords refer to names that have been chosen to have a special meaning in a programming language
Operators are symbols used for arithmetic calculations

*/
using namespace std;

//Function isKeyword states the 32 common keywords that are used in programming languages
int isKeyword(char buffer[]) {
	char keywords[32][10] = { "void","auto","int","break","const",
							"do","double","typedef","union","else","enum","extern",
							"float","for","goto","if","long","return","short","signed",
							"sizeof","continue","default","static","struct","switch","register",
							"unsigned","volatile","while""case","char"};
	int i, flag = 0;

	//This if statement loops through the provided code segment to check for a keyword
	for (i = 0; i < 32; ++i) {
		if (strcmp(keywords[i], buffer) == 0) {
			flag = 1;
			break;
		}
	}

	//If it finds a keyword, it raises a flag of 1 else 0
	return flag;
}

int main() {
	//The keywords are in characters and the operators are stated, there are 6 operators
	char ch, buffer[15], operators[] = "/+%*=-";


	//The sample code to be analyzed is in a file called mysamplecode.txt which is saved in the same location as lexicalAnalyzer.cpp
	fstream fin("mysamplecode.txt");

	//these are the parameters that save the loop data
	int opCharacter, j = 0;

	if (!fin.is_open()) {
		//if the mysamplecode.txt file does not exist at the above location, this error is output on the screen
		cout << "There is an error when opening the file\n";
		exit(0);
	}

	cout << "The code (formula) to calculate gross pay is as described by the lexical analyzer below; \n \n";


	while (!fin.eof()) {
		//if the mysamplecode.txt is successfully located, the lexical analyzer reads the entire file line by line
		ch = fin.get();

		//here the code loops to search for the 6 operators and saves them as opCharacter in a buffer
		for (opCharacter = 0; opCharacter < 6; ++opCharacter) {
			if (ch == operators[opCharacter])
				cout << ch << " this is an operator\n";
		}

		//isalnum is a C++ function to look for alphabets and numbers in the txt file, these are added to the buffer
		if (isalnum(ch)) {
			buffer[j++] = ch;
		}
		 //at this part, the code checks for spaces and line breaks
		else if ((ch == ' ' || ch == '\n') && (j != 0)) {
			buffer[j] = '\0';
			j = 0;

			if (isKeyword(buffer) == 1)
				cout << buffer << " this is a keyword\n";
			else
				cout << buffer << " this is an identifier\n";
		}

	}

	//here we close the file after reading its contents
	fin.close();

	return 0;
}