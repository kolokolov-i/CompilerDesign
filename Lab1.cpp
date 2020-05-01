#include "Lab1.h"
#include "Lexer.h"
#include "Token.h"
#include "LexerDefs.h"
#include <list>
#include <fstream>

#define DEBUG_LEX

LLk::LLk()
{
}

void LLk::process(list<string> text)
{
    list<Token> tokens = Lexer::Lexer::scan(text, this->errors, this->warnings);
#ifdef DEBUG_LEX
    ofstream debugFile("tokens.debug.txt");
    for (Token t : tokens)
    {
        debugFile << t.posLine << '\t' << t.posCol << '\t' << t.length << '\t' << tokenNames[t.type] << '\t' << t.image << '\n';
    }
    debugFile.close();
#endif
    // TODO syntaxer
}
