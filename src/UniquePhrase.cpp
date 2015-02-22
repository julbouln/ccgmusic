#include "UniquePhrase.h"
UniquePhrase::~UniquePhrase(){
	Utils::deleteVector(events);
}

UniquePhrase::UniquePhrase() {
	metrum = 4;
	bars = 2;
}

void UniquePhrase::setBars(int bars) {
 this->bars = bars;
}
int UniquePhrase::getBars() {
 return bars;
}
void UniquePhrase::setMetrum(int metrum) {
 this->metrum = metrum;
}
int UniquePhrase::getMetrum() {
 return metrum;
}
void UniquePhrase::setId(int id) {
 this->id = id;
}
int UniquePhrase::getId() {
 return id;
}
void UniquePhrase::setStartsPart(bool startsPart) {
 this->_startsPart = startsPart;
}
bool UniquePhrase::startsPart() {
 return _startsPart;
}
void UniquePhrase::setEndsPart(bool endsPart) {
 this->_endsPart = endsPart;
}
bool UniquePhrase::endsPart() {
 return _endsPart;
}
void UniquePhrase::setStartsSentence(bool ss) {
 this->_startsSentence = ss;
}
bool UniquePhrase::startsSentence() {
 return _startsSentence;
}
void UniquePhrase::setEndsSentence(bool es) {
 this->_endsSentence = es;
}
bool UniquePhrase::endsSentence() {
 return _endsSentence;
}
void UniquePhrase::addEvent(Time begin,Time end) {
 Event *event = new Event(begin,end);
 events.push_back(event);
}
int UniquePhrase::getEvents() {
 return events.size();
}
Event* UniquePhrase::getEvent(int index) {
 return events.at(index);
}
