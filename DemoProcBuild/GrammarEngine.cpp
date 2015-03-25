#include "GrammarEngine.h"

GrammarEngine::GrammarEngine(){}
GrammarEngine::GrammarEngine(ShapeGrammar* sg)
{
    shapeGrammar = sg;
}

GrammarEngine::~GrammarEngine()
{
    delete shapeGrammar;
}

void GrammarEngine::debug()
{
    // Print some information about the engine, state, to see if everything is working fine.
}