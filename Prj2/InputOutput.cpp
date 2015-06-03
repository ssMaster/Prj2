/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#include "InputOutput.h"

InputOutput::~InputOutput(){
	delete[] sentence;
}

bool InputOutput::openInFile(char* filename){
	// Attempt to open the input file
	inFile.open(filename, ifstream::in);

	if (inFile.is_open()){
		cout << "File is open." << endl;
		return true;
	}
	else{
		cout << "File not opened..." << endl;
		return false;
	}

}

bool InputOutput::openOutFile(char* filename){
	// Attempt to open the output file
	outFile.open(filename, ifstream::out);
	
	if (outFile.is_open()){
		cout << "File is open." << endl;
		return true;
	}
	else{
		cout << "File not opened..." << endl;
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

		//cout << "Current sentence: " << sentence << endl;
		return true;
	}
	else{
		return false;
	}

	
}

/*
bool InputOutput::extractSentence(){
	static int count = 0;

	string line = "";
	string file = "";
	const char* endPunc = ".;:?!";
	size_t length;
	char *cstr;
	char* sentenceToken;
	
	while (!inFile.eof()){

		getline(inFile, line);	// reads a line
		
		file.append(line);
		//return true;
	}
	
	// =============================================================

	length = file.size();
	cstr = new char[length + 1];
	
	// copy characters from the line into allocated memory
	file.copy(cstr, length, 0);
	cstr[length] = '\0';	// add null terminator

	sentenceToken = strtok(cstr, endPunc);
	while (sentenceToken != NULL){
		cout << "Token: " << sentenceToken;
		sentenceToken = strtok(NULL, endPunc);

		cout << " and count is: " << count << endl;
		count++;
	}

	delete[] cstr;

	// =============================================================

	//else{
	return false;
	//}
}
*/

void InputOutput::generateOutput(){

}

char* InputOutput::getSentence(){
	return sentence;
}

