#ifndef PHRASE_H
#define PHRASE_H
#include "Common.h"
#include "UniquePhrase.h"
using namespace std;
class Phrase {
 int bars;
 int uPhraseId;
 UniquePhrase *uniquePhrase;
public:
 Phrase();
 void setUniquePhrase(int);
 UniquePhrase* getUniquePhrase();
 int getUniquePhraseID();
 void setBars(int);
 int getBars();
 void setUniquePhrase(UniquePhrase*);
};
#endif // PHRASE_H
