#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include <iostream>
#include <fstream>

using namespace std;

class InputOutput{
public:
	bool openInFile(char *filename);
	bool openOutFile(char *filename);
	bool extractSentence();
	void generateOutput();
	char* getSentence();
private:
	ifstream inFile;
	ofstream outfile;
	char* sentence;
};

#endif