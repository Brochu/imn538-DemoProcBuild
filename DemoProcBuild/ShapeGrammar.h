#ifndef _SHAPEGRAMMAR_H_
#define _SHAPEGRAMMAR_H_

#include <string>
#include <iostream>

using namespace std;

class ShapeGrammar
{
public:
    ShapeGrammar();
    ShapeGrammar(char* filename);
    ~ShapeGrammar();

    void debug();

private:
    struct Rule{
        string LHS;
        string RHS;
        float prob;
    };
};

#endif