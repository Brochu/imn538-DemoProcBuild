#ifndef _GRAMMARENGINE_H_
#define _GRAMMARENGINE_H_

#include "ShapeGrammar.h"
#include "glm\glm.hpp"
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

    enum ShapeState{
        terminal = 0,
        nonTerminal = 1
    };

    enum Shape{
        cube = 0,
        cylinder = 1,
        sphere = 2
    };

    void debug();
    void addShape(glm::mat4&, ShapeState, Shape);
    void drawShapes();

private:
    ShapeGrammar* shapeGrammar;

    struct ShapeInfo{
        glm::mat4 transInfo;
        Shape type;
        // 0 = cube;
        // 1 = cylinder
        // 2 = sphere
    };
    vector<ShapeInfo> nonTerminals;
    vector<ShapeInfo> terminals;

};

#endif
