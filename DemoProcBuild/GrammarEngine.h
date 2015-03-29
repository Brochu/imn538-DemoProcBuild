#ifndef _GRAMMARENGINE_H_
#define _GRAMMARENGINE_H_

#include "ShapeGrammar.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class GrammarEngine
{
public:
    GrammarEngine();
    GrammarEngine(ShapeGrammar* sg);
    ~GrammarEngine();

    void debug();
    void drawShapes();

private:
    ShapeGrammar* shapeGrammar;
    vector<ShapeInfo> nonTerminals;
    vector<ShapeInfo> terminals;

};

#endif
