#pragma once
#include "MessageRecord.h"
#include "Token.h"
#include <string>
#include <list>

using namespace std;

namespace Lexer
{
class Lexer
{
public:
    static list<Token> scan(list<string> text, list<MessageRecord> errors, list<MessageRecord> warnings);
};
} // namespace Lexer