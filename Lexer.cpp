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
        MetaLiter w = translit(c);
        switch (state)
        {
        case State::S0:
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
        case State::S1A:
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

}