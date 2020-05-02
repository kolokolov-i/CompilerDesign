#include "Lexer.h"
#include "Token.h"
#include <list>
#include <string>

namespace Lexer
{

Scanner::Scanner(list<MessageRecord> *pErrors, list<MessageRecord> *pWarnings)
{
    this->errors = pErrors;
    this->warnings = pWarnings;
}

list<Token> Scanner::scan(list<string> text)
{
    reset();
    curLine = 0;
    for (string line : text)
    {
        scan(line);
        curLine++;
    }
    return this->tokens;
}

void Scanner::reset()
{
    tokens.clear();
    state = State::S0;
    curLexem.str("");
}

void Scanner::scan(string s)
{
    bool lineLoop = true;
    curPos = 0;
    while (lineLoop)
    {
        char c = s[curPos];
        
    }
}

} // namespace Lexer