/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

#include "Dictionary.h"
#include <algorithm>

using namespace std;

Dictionary::Dictionary(){
	words = new char*[sizeof(char) * MAX_WORDS];
}

Dictionary::~Dictionary(){
	delete[] words;
}

/*
Update the dictionary
*/
void Dictionary::update(){
	cout << "Preparing update..." << endl;
	
	// Sort the list of words
	sort();
	
	// Count the number of occurrences of each word and store -------- incomplete
	
	
	cout << "Update complete." << endl;
}

/*
Sort the dictionary in descending order
*/
void Dictionary::sort(){
	
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

	// Sort the array and then print in reverse
	std::sort(w, w + count);
	for (int i = count - 1, j = 0; i > 0; i--){
		cout << "String: " << w[i] << endl;
	}

}

void Dictionary::display(){
	cout << "This is the dictionary display method... that is all." << endl;
}


void Dictionary::setWords(char** theWords){
	words = theWords;
}

/*
int Dictionary::getOccurrences(){
return *occurrences;
}
*/
char** Dictionary::getWords(){
	return words;
}
