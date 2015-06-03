// Driver

/*
Simon Sharudin
Project 2
Due: June 4, 2015


*/

#include "InputOutput.h"
#include "Flesch.h"

int main(){
	InputOutput io;

	// Attempt to open the input file
	io.openInFile("SmallSample2.txt");

	// Attempt to open the output file


	// Test the extract sentence method --- works, but may need some tuning
	bool flag = true;
	while (flag){
		flag = io.extractSentence();
		if (flag){
			cout << "The current sentence is: " << io.getSentence() << endl;
		}
	}
	
	// =================================

	// Test fleschRating method --- works
	Flesch f;
	double index;
	f.fleschRating();
	index = f.getIndex();
	cout << "Flesch index for " << f.getNumWords() << " words and " << f.getNumSentences() << " sentence(s) and " << f.getNumSyllables() << " syllable(s) is " << index << endl;

	cout << endl << "================" << endl << endl;

	// ================================================================= Testing analyzeSentence and Dictionary methods

	Dictionary dict;
	Flesch fle;

	char* sentence = "This is the sentence that, I, will use and usee.";
	char* sentence2 = "This is, of course the second sentence";
	cout << "The sentence: " << sentence << endl;
	
	fle.analyzeSentence(sentence, &dict);
	cout << endl << "-------------" << endl << endl << "Analyzing next sentence..." << endl;
	fle.analyzeSentence(sentence2, &dict);

	cout << "Total words: " << fle.getNumWords() << endl;

	// print out words in dictionary: ------- working!!
	/*char** words = dict.getWords();
	int numWords = fle.getNumWords();

	for (int i = 0; i < numWords; i++){
		cout << "Dictionary: " << i << ":\t" << words[i] << endl;
	}*/
	
	return 0;
}