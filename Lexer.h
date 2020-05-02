#pragma once
#include "MessageRecord.h"
#include "Token.h"
#include <string>
#include <list>
#include <sstream>

using namespace std;

namespace Lexer
{
class Scanner
{
public:
    Scanner(list<MessageRecord> *errors, list<MessageRecord> *warnings);
    list<Token> scan(list<string> text);

private:
    void reset();

    list<MessageRecord> *errors;
    list<MessageRecord> *warnings;
    list<Token> tokens;
    State state;
    stringstream curLexem;
    int curLine, curPos;
};

enum class State
{
    S0,
    S1A,
    S2A,
    S2B,
    S2C,
    S2C,
    S2D,
    S2E,
    S2F,
    S3A,
    S3B,
    S4,
    S5,
    S6,
    S7
};
} // namespace Lexer