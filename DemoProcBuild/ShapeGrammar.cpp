#include "ShapeGrammar.h"

ShapeGrammar::ShapeGrammar(){}
ShapeGrammar::ShapeGrammar(char* filename)
{
    // Step 1 read file
    std::ifstream file(filename, std::ifstream::in);

    if (file.bad())
    {
        cout << "Problem reading the grammar file !";
        return;
    }

    string content;
    file >> content;
    cout << content << endl;
    // Ster 2 create ShapeGrammar from info in file
        // - create rules list
        // - create base symbol
}

ShapeGrammar::~ShapeGrammar()
{
}

void ShapeGrammar::debug()
{
    // Print info about grammar, rules, symbols ...
}