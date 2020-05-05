#include "Lab1.h"
#include "Lexer.h"
#include "Token.h"
#include "LexerDefs.h"
#include <vector>
#include <map>
#include <fstream>
#include <iostream>

#define DEBUG_LEX

LLk::LLk()
{
    this->errors = new vector<MessageRecord>();
    this->warnings = new vector<MessageRecord>();
}

LLk::~LLk()
{
    delete this->errors;
    delete this->warnings;
}

using namespace Lexer;

void LLk::process(vector<string> text)
{
    Scanner *scanner = new Scanner(this->errors, this->warnings);
    vector<Token> tokens = scanner->scan(text);
#ifdef DEBUG_LEX
    ofstream debugFile("tokens.debug.txt");
    std::map<TokenType, std::string> names = getTokensNames();
    cout << "dbg: tokens count = " << tokens.size() << endl;
    for (Token t : tokens)
    {
        debugFile << t.posLine << '\t' << t.posCol << '\t' << t.length << '\t' << names[t.type] << '\t' << t.image << '\n';
    }
    debugFile.close();
#endif
    this->success = true;
    // TODO syntaxer
}

std::vector<MessageRecord> *LLk::getErrors()
{
    return errors;
}

std::vector<MessageRecord> *LLk::getWarnings()
{
    return warnings;
}

std::vector<std::string> LLk::getListing()
{
    return listing;
}