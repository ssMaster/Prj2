/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#include "InputOutput.h"

InputOutput::InputOutput(){

}

InputOutput::~InputOutput(){
	//delete[] sentence;
}

bool InputOutput::openInFile(char* filename){
	// Attempt to open the input file
	inFile.open(filename, ifstream::in);

	if (inFile.is_open()){
		cout << "Input file is open." << endl;
		return true;
	}
	else{
		cout << "Input file not opened..." << endl;
		return false;
	}

}

bool InputOutput::openOutFile(char* filename){
	// Attempt to open the output file
	outFile.open(filename, ofstream::out);
	
	if (outFile.is_open()){
		cout << "Output file is open." << endl;
		return true;
	}
	else{
		cout << "Output file not opened..." << endl;
		return false;
	}
}

bool InputOutput::extractSentence(){
	string str = "";
	size_t length;

	char c;
	if (!inFile.eof()){	// while not at the end of a file
		c = inFile.get();

		while (c != '.' && c != ';' && c != ':' && c != '?' && c != '!'){	// delimiters that mark the end of a sentence

			if (c == '\n' || c == '\t' || c == '\r'){	// skip newlines, carriage returns, and tabs
				c = inFile.get();
			}

			if (c == EOF){	// end of file reached
				return false;
			}

			// add the character to the current sentence string
			str = str + c;
			c = inFile.get();
		}
		
		length = str.size();
		sentence = new char[length + 1];
		str.copy(sentence, length, 0);
		sentence[length] = '\0';

		return true;
	}
	else{
		return false;
	}

	
}

void InputOutput::generateOutput(){
	outFile << "Constructing a new report..." << endl << endl;

	
}

char* InputOutput::getSentence(){
	return sentence;
}

ofstream & InputOutput::getOut(){
	return outFile;
}





