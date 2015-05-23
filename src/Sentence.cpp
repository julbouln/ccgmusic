#include "Sentence.h"
 Sentence::~Sentence() {
 	Utils::deleteVector(phrases);
 }

void Sentence::setPhrases(int count) {
	for(int i=0;i<count;i++) {
		phrases.push_back(new Phrase());
	}
}
int Sentence::getPhrases() {
 return phrases.size();
}
Phrase* Sentence::getPhrase(int index) {
 int toAdd = index - phrases.size() + 1;
 for(int i = 0;i < toAdd;i++   ){
 	phrases.push_back(new Phrase());
 }
 return phrases.at(index);
}
int Sentence::getBars() {
 int sum = 0;
 	for(std::vector<Phrase*>::iterator p = phrases.begin(); p != phrases.end(); ++p) {
     sum += (*p)->getBars();
 }
 return sum;
}
