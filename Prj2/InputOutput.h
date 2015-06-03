/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#ifndef IO_H
#define IO_H

#include <iostream>
#include <string>

#endif;

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

//#include <iostream>
#include <fstream>


using namespace std;

class InputOutput{
public:
	~InputOutput();
	bool openInFile(char *filename);
	bool openOutFile(char *filename);
	bool extractSentence();
	void generateOutput();
	char* getSentence();
private:
	ifstream inFile;
	ofstream outFile;
	char* sentence;
};

#endif