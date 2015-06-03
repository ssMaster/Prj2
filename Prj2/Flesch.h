/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#ifndef IO_H
#define IO_H

#include <iostream>

#endif;

#ifndef FLESCH_H
#define FLESCH_H

#include <math.h>
#include "Dictionary.h"
#include <string>

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
private:
	int index;
	int numWords;
	int numSentences;
	int numSyllables;
	int numWordsInSentence;
};

#endif

