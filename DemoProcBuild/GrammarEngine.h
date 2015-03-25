#ifndef _GRAMMARENGINE_H_
#define _GRAMMARENGINE_H_

#include "ShapeGrammar.h"
#include <string>
#include <iostream>

using namespace std;

class GrammarEngine
{
public:
    GrammarEngine();
    GrammarEngine(ShapeGrammar* sg);
    ~GrammarEngine();

    void debug();

private:
    ShapeGrammar* shapeGrammar;

};

#endif