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
    cout << "Information about GrammarEngine class: " << endl;
    cout << "\t nb of terminal shapes : " << terminals.size() << endl;
    cout << "\t nb of non-terminal shapes : " << nonTerminals.size() << endl;
}

void GrammarEngine::addShape(glm::mat4& transValues, ShapeState state, Shape s)
{
    vector<ShapeInfo>* toadd = 0;

    if (state == GrammarEngine::ShapeState::terminal)
        toadd = &terminals;
    else if (state == GrammarEngine::ShapeState::nonTerminal)
        toadd = &nonTerminals;

    ShapeInfo si;
    si.transInfo = transValues;
    si.type = s;

    toadd->insert(toadd->end(), si);
}

void GrammarEngine::drawShapes()
{
    vector<ShapeInfo>::iterator i;
    for (i = nonTerminals.begin(); i != nonTerminals.end(); ++i)
    {
        // draw shape
    }

    for (i = terminals.begin(); i != terminals.end(); ++i)
    {
        // draw shape
    }
}
