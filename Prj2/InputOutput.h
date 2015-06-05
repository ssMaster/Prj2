/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#ifndef OTHER_H
#define OTHER_H

#include <iostream>
#include <math.h>
#include <string>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>

#endif;

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

using namespace std;

class InputOutput{
public:
	InputOutput();
	~InputOutput();
	bool openInFile(char *filename);
	bool openOutFile(char *filename);
	bool extractSentence();
	void generateOutput();

	char* getSentence();
	ofstream & getOut();
private:
	ifstream inFile;
	ofstream outFile;
	char* sentence;
};

#endif