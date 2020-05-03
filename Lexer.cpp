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
    resetLexem();
}

void Scanner::flushLexem(TokenType type)
{
    tokens.push_back(Token(curLine, curPos, lexemLen, curLexem.str(), type));
    resetLexem();
}

void Scanner::resetLexem()
{
    state = State::S0;
    curLexem.str("");
    lexemLen = 0;
}

void Scanner::expandLex(char c)
{
    curLexem.put(c);
    lexemLen++;
}

void Scanner::scan(string s)
{
    bool lineLoop = true;
    curPos = 0;
    while (lineLoop)
    {
        char c = s[curPos];
        MetaLiter w = translit(c);
        switch (state)
        {
        case State::S0:
            switch (w)
            {
            case MetaLiter::Alpha:
                expandLex(c);
                state = State::S1;
                break;
            case MetaLiter::Digit:
                expandLex(c);
                state = State::S2A;
                break;
            case MetaLiter::Dot:
                expandLex('0');
                expandLex(c);
                state = State::S2B;
                break;
            case MetaLiter::Apostrophe:
                state = State::S3A;
                break;
            case MetaLiter::Exclamation:
                expandLex(c);
                state = State::S4;
                break;
            case MetaLiter::SignLess:
                expandLex(c);
                state = State::S5;
                break;
            case MetaLiter::SignGreater:
                expandLex(c);
                state = State::S6;
                break;
            case MetaLiter::Equals:
                expandLex(c);
                state = State::S7;
                break;
            case MetaLiter::Comma:
                expandLex(c);
                flushLexem(TokenType::SCom);
                break;
            case MetaLiter::Semicolon:
                expandLex(c);
                flushLexem(TokenType::SSem);
                break;
            case MetaLiter::BracketOpen:
                expandLex(c);
                flushLexem(TokenType::SBrackO);
                break;
            case MetaLiter::BracketClose:
                expandLex(c);
                flushLexem(TokenType::SBrackC);
                break;
            case MetaLiter::BracesOpen:
                expandLex(c);
                flushLexem(TokenType::SBracsO);
                break;
            case MetaLiter::BracesClose:
                expandLex(c);
                flushLexem(TokenType::SBracsC);
                break;
            case MetaLiter::Plus:
                expandLex(c);
                flushLexem(TokenType::PPlus);
                break;
            case MetaLiter::Minus:
                expandLex(c);
                flushLexem(TokenType::PMinus);
                break;
            case MetaLiter::Multi:
                expandLex(c);
                flushLexem(TokenType::PMulti);
                break;
            case MetaLiter::Slash:
                expandLex(c);
                flushLexem(TokenType::PDiv);
                break;
            case MetaLiter::Percent:
                expandLex(c);
                flushLexem(TokenType::PMod);
                break;
            case MetaLiter::Space:
            default:
                resetLexem();
            }
            break;
        case State::S1:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2A:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2B:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2C:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2D:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2E:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S2F:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S3A:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S3B:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S4:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S5:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S6:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        case State::S7:
            switch (w)
            {
            case MetaLiter::Alpha:
                break;
            case MetaLiter::Digit:
                break;
            case MetaLiter::Space:
                break;
            case MetaLiter::Semicolon:
                break;
            case MetaLiter::Dot:
                break;
            case MetaLiter::Comma:
                break;
            case MetaLiter::Apostrophe:
                break;
            case MetaLiter::Equals:
                break;
            case MetaLiter::Plus:
                break;
            case MetaLiter::Minus:
                break;
            case MetaLiter::Multi:
                break;
            case MetaLiter::Slash:
                break;
            case MetaLiter::Percent:
                break;
            case MetaLiter::SignLess:
                break;
            case MetaLiter::SignGreater:
                break;
            case MetaLiter::Exclamation:
                break;
            case MetaLiter::BracketOpen:
                break;
            case MetaLiter::BracketClose:
                break;
            case MetaLiter::BracesOpen:
                break;
            case MetaLiter::BracesClose:
                break;
            default:
            }
            break;
        }
    }
}

} // namespace Lexer