/*
Simon Sharudin
Project 2
Due: June 4, 2015
*/

using namespace std;

#include "Flesch.h"
//#include "Dictionary.h"

// Constructor
Flesch::Flesch(){
	numWords = 0;
	numSentences = 0;
	numSyllables = 0;
}

// Destructor
Flesch::~Flesch(){

}

/*
Return the education level based on the input numeric index
*/
char* Flesch::levelOf(int index) const{
	if (index >= 91){
		return "5th grader";
	}
	else if (index >= 81){
		return "6th grader";
	}
	else if (index >= 71){
		return "7th grader";
	}
	else if (index >= 66){
		return "8th grader";
	}
	else if (index >= 61){
		return "9th grader";
	}
	else if (index >= 51){
		return "High school student";
	}
	else if (index >= 31){
		return "College student";
	}
	else if (index >= 0){
		return "College graduate";
	}
	else{
		return "Law school graduate";
	}
}

/*
Compute the Flesch Readability Index
*/
void Flesch::fleschRating(){
	index = round(206.835 - 84.6 * (double)numSyllables / (double)numWords - 1.015 * (double)numWords / (double)numSentences);
}

/*
Analyze the given sentence and update the parameters for the Flesch Readability index
computation and dictionary.
*/
void Flesch::analyzeSentence(char* sentence, Dictionary *dictionary){
	cout << "The given sentence: " << sentence << endl;

	cout << "Dictionary: " << dictionary << endl;
	(*dictionary).display();

	// =====================================================================================

	cout << "============================== Extracting words from sentence" << endl << endl;
	char **tok;
	int *syl;
	int words;

	tok = nextWordIn(sentence);
	words = getNumWordsInSentence();
	
	syl = new int[words];

	for (int i = 0; i < words; i++){
		// Count the number of syllables in each word
		syl[i] = countSyllablesIn(tok[i]);

		cout << "The word: \t" << tok[i] << " has:\t" << syl[i] << " syllables." << endl;
	}

	cout << "Words in sentence: " << words << endl;

	char** dictWords = (*dictionary).getWords();
	
	for (int i = numWords, j = 0; i < (numWords + words); i++){

		// Add words to the dictionary
		dictWords[i] = tok[j];
		cout << "Place for word: \t" << i << " and the word is: " << tok[j] << endl;

		j++;
	}

	// Place null character 
	dictWords[numWords + words] = '\0';
	(*dictionary).setWords(dictWords);
	numWords += words;

	// Update the dictionary
	(*dictionary).update();

	// =====================================

	// Deallocate the memory -- error when using loop
	//if (tok != NULL){
	//	int words = getNumWordsInSentence();
	//	for (int i = 0; i < words-1; i++){
	//		//delete[] tok;
	//	}
	//}

	delete[] tok;
	delete[] syl;
}

/*
Tokenize each word from the input argument, sentence.
Return the tokenized word to the calling method.
*/
char** Flesch::nextWordIn(char* sentence){
	
	char *theSentence = new char[sizeof(char) * 300 + 1];
	char **words = new char*[sizeof(char) * 1000];
	char *token;
	int count = 0;

	strcpy(theSentence, sentence);
	token = strtok(theSentence, " ");
	
	// Tokenize the sentence and get the number of words in the given sentence
	while (token != NULL) {
		words[count] = token;
		count++;
		token = strtok(NULL, " ");
	}
	//setNumWordsInSentence(count);
	numWordsInSentence = count;

	// ==================

	// delete[] theSentence; --- this is the one that gives the error

	return words;
}

/*
Count the syllables of a word and return the number of syllables
*/
int Flesch::countSyllablesIn(char* word){
	int count = 0;
	
	for (int i = 0; word[i] != '\0'; i++){
		tolower(word[i]);
		//cout << word[i] << " ";

		if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' || word[i] == 'y'){
			if (word[i + 1] == 'a' || word[i + 1] == 'e' || word[i + 1] == 'i' || word[i + 1] == 'o' || word[i + 1] == 'u' || word[i + 1] == 'y'){
				// counts as one syllable
			}
			else{
				if (word[i + 1] >= 'a' || word[i + 1] <= 'z'){
					count++;
				}
			}
			if (word[i] == 'e' && word[i + 1] == '\0'){
				count--;
			}
		}
	}
	// ============
	if (count == 0){
		return 1;
	}
	else{
		return count;
	}
}

// ============================================================================

// ======================= Mutator methods

void Flesch::setIndex(int i){
	index = i;
}

void Flesch::setNumWords(int n){
	numWords = n;
}

void Flesch::setNumSentences(int n){
	numSentences = n;
}

void Flesch::setNumSyllables(int n){
	numSyllables = n;
}

void Flesch::setNumWordsInSentence(int n){
	numWordsInSentence = n;
}

// ======================= Accessor methods

int Flesch::getIndex(){
	return index;
}

int Flesch::getNumWords(){
	return numWords;
}

int Flesch::getNumSentences(){
	return numSentences;
}

int Flesch::getNumSyllables(){
	return numSyllables;
}

int Flesch::getNumWordsInSentence(){
	return numWordsInSentence;
}