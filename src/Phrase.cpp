#include "Phrase.h"
Phrase::Phrase() {
	bars = 2;
}

void Phrase::setUniquePhrase(int id) {
 this->uPhraseId = id;
}
UniquePhrase* Phrase::getUniquePhrase() {
 return uniquePhrase;
}
int Phrase::getUniquePhraseID() {
 return uPhraseId;
}
void Phrase::setBars(int bars) {
 this->bars = bars;
}
int Phrase::getBars() {
 return bars;
}
void Phrase::setUniquePhrase(UniquePhrase *uniquePhrase) {
 this->uniquePhrase = uniquePhrase;
}
