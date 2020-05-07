#include "Lexer.h"
#include "Token.h"
#include "LexerDefs.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

namespace Lexer
{

Scanner::Scanner(vector<MessageRecord> *pErrors, vector<MessageRecord> *pWarnings)
{
    this->errors = pErrors;
    this->warnings = pWarnings;
}

vector<Token> Scanner::scan(vector<string> text)
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
    tokens.push_back(Token(curLine, lexPos, lexemLen, curLexem.str(), type));
    resetLexem();
}

void Scanner::flushError()
{
    errors->push_back(MessageRecord(curLine, curPos, "Unrecognized token \"" + curLexem.str() + "\""));
    resetLexem();
}

void Scanner::flushError(string message)
{
    errors->push_back(MessageRecord(curLine, curPos, message));
    resetLexem();
}

void Scanner::flushWarning(string message)
{
    warnings->push_back(MessageRecord(curLine, curPos, message));
}

void Scanner::flushIDKW()
{
    string s = curLexem.str();
    map<string, TokenType> kw = getKeyWords();
    if (kw.count(s) != 0)
    {
        tokens.push_back(Token(curLine, lexPos, lexemLen, s, kw[s]));
    }
    else
    {
        tokens.push_back(Token(curLine, lexPos, lexemLen, s, TokenType::ID));
    }
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
        char c;
        MetaLiter w;
        if (curPos == s.size())
        {
            c = '\0';
            w = MetaLiter::Space; // space at the end
            lineLoop = false;
        }
        else
        {
            c = s[curPos++];
            w = translit(c);
        }
        switch (state)
        {
        case State::S0:
            lexPos = curPos - 1;
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
                state = State::S8;
                break;
            case MetaLiter::Percent:
                expandLex(c);
                flushLexem(TokenType::PMod);
                break;
            case MetaLiter::Space:
                break;
            default:
                flushError();
            }
            break;
        case State::S1:
            switch (w)
            {
            case MetaLiter::Alpha:
            case MetaLiter::Digit:
                expandLex(c);
                break;
            default:
                flushIDKW();
                curPos--;
            }
            break;
        case State::S2A:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                break;
            case MetaLiter::Dot:
                expandLex(c);
                state = State::S2C;
                break;
            case MetaLiter::Alpha:
                if (c == 'E' || c == 'e')
                {
                    expandLex(c);
                    state = State::S2D;
                }
                else
                {
                    flushError();
                    curPos--;
                }
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::NumInt);
                break;
            default:
                flushLexem(TokenType::NumInt);
                curPos--;
            }
            break;
        case State::S2B:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                state = State::S2C;
                break;
            default:
                flushLexem(TokenType::SDot);
                curPos--;
            }
            break;
        case State::S2C:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                break;
            case MetaLiter::Alpha:
                if (c == 'E' || c == 'e')
                {
                    expandLex(c);
                    state = State::S2D;
                }
                else
                {
                    flushLexem(TokenType::NumFloat);
                    curPos--;
                }
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::NumFloat);
                break;
            default:
                flushLexem(TokenType::NumFloat);
                curPos--;
            }
            break;
        case State::S2D:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                state = State::S2F;
                break;
            case MetaLiter::Plus:
            case MetaLiter::Minus:
                expandLex(c);
                state = State::S2E;
                break;
            case MetaLiter::Space:
                flushError();
                break;
            default:
                curPos--;
                flushError();
            }
            break;
        case State::S2E:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                state = State::S2F;
                break;
            default:
                flushError();
            }
            break;
        case State::S2F:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::NumExp);
                break;
            default:
                flushLexem(TokenType::NumExp);
                curPos--;
            }
            break;
        case State::S3A:
            switch (w)
            {
            case MetaLiter::Apostrophe:
                flushError("Char literal should contain one character");
                break;
            case MetaLiter::BSlash:
                state = State::S3C;
                break;
            default:
                expandLex(c);
                state = State::S3B;
            }
            break;
        case State::S3B:
            switch (w)
            {
            case MetaLiter::Apostrophe:
                flushLexem(TokenType::Char);
                break;
            default:
                flushError("Char literal should contain one character");
            }
            break;
        case State::S3C:
            switch (w)
            {
            case MetaLiter::Alpha:
                switch (c)
                {
                case 't':
                    expandLex('\t');
                    break;
                case 'n':
                    expandLex('\n');
                    break;
                case 'r':
                    expandLex('\r');
                }
                break;
            default:
                flushWarning("Unrecognized escape sequence \\" + c);
            case MetaLiter::Apostrophe:
            case MetaLiter::BSlash:
            case MetaLiter::DQuote:
                expandLex(c);
                state = State::S3B;
            }
            break;
        case State::S4:
            switch (w)
            {
            case MetaLiter::Equals:
                expandLex(c);
                flushLexem(TokenType::PNotEq);
                break;
            case MetaLiter::Space:
                flushError();
                break;
            default:
                flushError();
                curPos--;
            }
            break;
        case State::S5:
            switch (w)
            {
            case MetaLiter::Equals:
                expandLex(c);
                flushLexem(TokenType::PLessEq);
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::PLess);
                break;
            default:
                flushLexem(TokenType::PLess);
                curPos--;
            }
            break;
        case State::S6:
            switch (w)
            {
            case MetaLiter::Equals:
                expandLex(c);
                flushLexem(TokenType::PGretEq);
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::PGret);
                break;
            default:
                flushLexem(TokenType::PGret);
                curPos--;
            }
            break;
        case State::S7:
            switch (w)
            {
            case MetaLiter::Equals:
                expandLex(c);
                flushLexem(TokenType::PEquals);
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::PAssign);
                break;
            default:
                flushLexem(TokenType::PAssign);
                curPos--;
            }
            break;
        case State::S8:
            switch (w)
            {
            case MetaLiter::Slash:
                lineLoop = false; // comment
                break;
            default:
                flushLexem(TokenType::PDiv);
                curPos--;
            }
        }
    }
}

} // namespace Lexer