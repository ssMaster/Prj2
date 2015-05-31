#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary{
public:
	Dictionary();
	~Dictionary();
	const int MAX_WORDs = 1000;
	int getOccurrences();	// accessor
	char* getWords();		// accessor
	void update();
	void sort();
	void display();
private:
	char* words[];
	int occurrences[];
};

#endif