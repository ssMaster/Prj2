#ifndef FLESCH_H
#define FLESCH_H

class Flesch{
public:
	Flesch();
	~Flesch();
	void fleschRating();
	char* levelOf(int index) const;
	void analyzeSentence(char* sentence, Dictionary *dictionary);
	char* nextWordIn(char* sentence);
	int countSyllablesIn(char* word);
private:
	// no data members
};

#endif