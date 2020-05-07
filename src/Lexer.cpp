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
    tokens.push_back(Token(curLine, curPos, lexemLen, curLexem.str(), type));
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

void Scanner::flushIDKW()
{
    string s = curLexem.str();
    cout << "dbg: lexema > " << s << endl;
    map<string, TokenType> kw = getKeyWords();
    if (kw.count(s) != 0)
    {
        tokens.push_back(Token(curLine, curPos, lexemLen, s, kw[s]));
    }
    else
    {
        tokens.push_back(Token(curLine, curPos, lexemLen, s, TokenType::ID));
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
    // cout << "dbg: scan line > " << s << endl;
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
            // cout << "dbg: scan char > " << c << endl;
        }
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
                state = State::S8;
                break;
            case MetaLiter::Percent:
                expandLex(c);
                flushLexem(TokenType::PMod);
                break;
            case MetaLiter::Space:
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
                curPos--;
                flushIDKW();
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
                if(c == 'E' || c == 'e'){
                    expandLex(c);
                    state = State::S2D;
                }
                else{
                    curPos--;
                    flushLexem(TokenType::NumInt);
                }
                break;
            case MetaLiter::Space:
                flushLexem(TokenType::NumInt);
                break;
            default:
                curPos--;
                flushError();
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
                expandLex(c);
                flushLexem(TokenType::SDot);
                state = State::S0;
            }
            break;
        case State::S2C:
            switch (w)
            {
            case MetaLiter::Digit:
                expandLex(c);
                break;
            case MetaLiter::Alpha:
                if(c == 'E' || c == 'e'){
                    expandLex(c);
                    state = State::S2D;
                }
                else{
                    curPos--;
                    flushLexem(TokenType::NumFloat);
                }
                break;
            default:
                curPos--;
            case MetaLiter::Space:
                state = State::S0;
                break;
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
            default:
                curPos--;
            case MetaLiter::Space:
                flushError();
                break;
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
            default:
                curPos--;
            case MetaLiter::Space:
                state = State::S0;
                break;
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
            switch(w)
            {
            case MetaLiter::Alpha:
                switch(c)
                {
                    case 't':
                        expandLex('\t'); break;
                    case 'n':
                        expandLex('\n'); break;
                    case 'r':
                        expandLex('\r'); break;
                }
                break;
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
            default:
                curPos--;
            case MetaLiter::Space:
                flushError();
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
                state = State::S0;
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
                state = State::S0;
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
                state = State::S0;
            }
            break;
        case State::S8:
            switch(w)
            {
                case MetaLiter::Slash:
                    lineLoop = false;
                    break;
                default:
                    curPos--;
                    flushLexem(TokenType::PDiv);
                    break;
            }
            break;
        }
    }
}

} // namespace Lexer