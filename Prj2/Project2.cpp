// Driver

/*
Simon Sharudin
Project 2
Due: June 4, 2015


*/

#include "InputOutput.h"
#include "Flesch.h"
#include "Dictionary.h"

int main(){
	Flesch f;
	Dictionary d;
	InputOutput io;

	ofstream o;

	char* s;

	io.openInFile("SmallSample1.txt");
	io.openOutFile("Testing.out");

	//o = io.getOut();

	io.generateOutput();

	bool flag = true;
	while (flag){
		flag = io.extractSentence();
		if (flag){
			f.setNumSentences(f.getNumSentences() + 1);
			s = io.getSentence();
			f.analyzeSentence(s, &d);
		}

	}

	f.fleschRating();
	int index = f.getIndex();

	io.getOut() << "Number of sentences: " << f.getNumSentences() << endl;
	io.getOut() << "Number of words: " << f.getNumWords() << endl;
	io.getOut() << "Number of syllables: " << f.getNumSyllables() << endl;
	io.getOut() << "Flesch Readability Index: " << index << " " << f.levelOf(index) << endl << endl;

	io.getOut() << "Dictionary" << endl;
	io.getOut() << "d.display()" << endl;

	//d.display();

	//int* occurs = d.getOccurrences();

	/*int count = f.getNumWords();

	cout << "Num words: " << count << endl;

	for (int i = 0; i < 5; i++){
		cout << "Occurs: " << occurs[i] << endl;

	}*/
	
	return 0;
}