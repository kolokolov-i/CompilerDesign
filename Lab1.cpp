#include "Lab1.h"
#include "Lexer.h"
#include "Token.h"
#include "LexerDefs.h"
#include <list>
#include <fstream>

#define DEBUG_LEX

LLk::LLk()
{
    this->errors = new list<MessageRecord>();
    this->warnings = new list<MessageRecord>();
}
using namespace Lexer;

void LLk::process(list<string> text)
{
    Scanner *scanner = new Scanner(this->errors, this->warnings);
    list<Token> tokens = scanner->scan(text);
#ifdef DEBUG_LEX
    ofstream debugFile("tokens.debug.txt");
    string* names = getTokensNames();
    for (Token t : tokens)
    {
        debugFile << t.posLine << '\t' << t.posCol << '\t' << t.length << '\t' << names[static_cast<int>(t.type)] << '\t' << t.image << '\n';
    }
    debugFile.close();
#endif
    // TODO syntaxer
}
