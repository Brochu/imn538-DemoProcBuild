#include "ShapeGrammar.h"

ShapeGrammar::ShapeGrammar(){}
ShapeGrammar::ShapeGrammar(char* filename)
{
    ifstream file(filename, fstream::in);
    if (!file.good())
    {
        cout << "ERROR reading file ..." << endl;
        return;
    }

    stringstream stream;
    stream << file.rdbuf();
    file.close();

    stream.seekg(stringstream::beg);
    string rule;

    int ruleIdx = 0;
    while (stream >> rule)
    {
        Rule r;
        int separatorIdx = rule.find("->");
        r.LHS = rule.substr(0, separatorIdx);
        r.RHS = rule.substr(separatorIdx + 2, rule.size());

        rules.insert(rules.end(), r);

        ruleIdx++;
    }
}
ShapeGrammar::~ShapeGrammar()
{
}

void ShapeGrammar::debug()
{
    for (int i = 0; i < rules.size(); ++i)
    {
        cout << rules[i].LHS << "-->" << rules[i].RHS << endl;
    }
}