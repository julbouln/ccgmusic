#ifndef SENTENCE_H
#define SENTENCE_H
#include "Common.h"
#include "Phrase.h"
using namespace std;
class Sentence {
 vector<Phrase*> phrases;
public:
 ~Sentence();
 void setPhrases(int);
 int getPhrases();
 Phrase* getPhrase(int);
 int getBars();
};
#endif // SENTENCE_H
