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


#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary{
public:
	Dictionary();
	~Dictionary();
	const int MAX_WORDS = 1000;
	void update();
	void sort();
	void display();

	void setWords(char** theWords);
	//int getOccurrences();	// accessor
	char** getWords();		// accessor
private:
	char** words;
	int occurrences[];
};

#endif

