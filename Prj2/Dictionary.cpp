/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(){
	words = new char*[sizeof(char) * MAX_WORDS];
	occurrences[1000];
}

Dictionary::~Dictionary(){
	delete[] words;
	words = 0;	// reset pointer
}

/*
Update the dictionary
*/
void Dictionary::update(){
	// Sort the list of words
	sort();
	
	// Count the number of occurrences of each word and store -------- incomplete
	char **c = getWords();
	string w[1000];
	int count = 0;

	for (int i = 0; i < MAX_WORDS; i++){
		if (c[i] == NULL){
			break;
		}
		w[i] = string(words[i]);
		count++;
	}

	// ==========

	//map<string, unsigned int> occurs;
	map<string, int> occurs;

	for (int i = 0; i < count; i++){
		if (occurs.find(w[i]) == occurs.end()){	// New word occurrence
			occurs[w[i]] = 1;
		}
		else{	// Already in the dictionary
			occurs[w[i]]++;
		}
	}

	//cout << endl << endl << "========================= Displaying word occurrences" << endl << endl;
	
	int k = 0;
	//typedef std::map<string, unsigned int>::iterator iterator;
	typedef std::map<string, int>::iterator iterator;
	for (iterator i = occurs.begin(); i != occurs.end(); i++){
		//cout << i->first << ": " << i->second << endl;
		k = i->second;
		//k++;
		//cout << "k is: " << k << endl;
	}
}

/*
Sort the dictionary in descending order
*/
void Dictionary::sort(){
	string w[1000];
	int count = 0;

	for (int i = 0; i < MAX_WORDS; i++){
		if (words[i] == NULL){
			break;
		}
		w[i] = string(words[i]);
		count++;
	}

	// Sort the array and then print in reverse
	std::sort(w, w + count);
	for (int i = count-1, j = 0; i >= 0; i--, j++){
		//cout << "String sort: " << w[i] << " \t\t and j = " << w[j] << endl;
	}
}



void Dictionary::display(){
	cout << "This is the dictionary display method... that is all." << endl;
	int count = 0;



}


void Dictionary::setWords(char** theWords){
	words = theWords;
}


int* Dictionary::getOccurrences(){
	return occurrences;
}

char** Dictionary::getWords(){
	return words;
}
