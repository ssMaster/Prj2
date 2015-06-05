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

#include "InputOutput.h"
#include "Dictionary.h"

#ifndef FLESCH_H
#define FLESCH_H

class Flesch{
public:
	Flesch();
	~Flesch();
	void fleschRating();
	char* levelOf(int index) const;
	void analyzeSentence(char* sentence, Dictionary *dictionary);
	char** nextWordIn(char* sentence);
	int countSyllablesIn(char* word);

	void setIndex(int i);
	void setNumWords(int n);
	void setNumSentences(int n);
	void setNumWordsInSentence(int n);
	void setNumSyllables(int n);

	int getIndex();
	int getNumWords();
	int getNumSentences();
	int getNumSyllables();
	int getNumWordsInSentence();
	//InputOutput getIO();
private:
	InputOutput io;
	int index;
	int numWords;
	int numSentences;
	int numSyllables;
	int numWordsInSentence;
};

#endif

