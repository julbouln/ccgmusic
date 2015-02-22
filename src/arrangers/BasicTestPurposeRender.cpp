#include "BasicTestPurposeRender.h"
BasicTestPurposeRender::BasicTestPurposeRender(int seed) {
// TODO_stmt#<Java::JapaParserAstStmt::ExplicitConstructorInvocationStmt:0x7f9d98ba>;
/*super();*/
}
void BasicTestPurposeRender::arrange(Song *s) {
 int bars = s->getBars();
 s->addTrack("Melody",1,127,63,false);
 s->addTrack("Drums",1,127,63,true);
 s->addRenderEvent("Simple Melody",this->rndInt(0,32000),0,0,bars,0,this->createTime(0,0),1);
 s->addRenderEvent("Metronome",this->rndInt(0,32000),1,0,bars,0,this->createTime(0,0),1);
}
