#pragma once
#include "MessageRecord.h"
#include "Token.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace Lexer
{
class Scanner
{
public:
    Scanner(vector<MessageRecord> *errors, vector<MessageRecord> *warnings);
    vector<Token> scan(vector<string> text);

private:
    void reset();
    void scan(string);
    void flushLexem(TokenType type);
    void flushIDKW();
    void expandLex(char c);
    void resetLexem();

    vector<MessageRecord> *errors;
    vector<MessageRecord> *warnings;
    vector<Token> tokens;
    State state;
    stringstream curLexem;
    int curLine, curPos, lexemLen;
};

enum class State
{
    S0,
    S1,
    S2A,
    S2B,
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

MetaLiter translit(char c);

}