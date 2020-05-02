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

    return this->tokens;
}

void Scanner::reset()
{
    tokens.clear();
    state = State::S0;
    curLexem.str("");
}

} // namespace Lexer