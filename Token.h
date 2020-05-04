#pragma once
#include "LexerDefs.h"
#include <string>

namespace Lexer
{
class Token
{
public:
    TokenType type;
    int posLine;
    int posCol;
    int length;
    std::string image;
    Token(int line, int column, int length, std::string image, TokenType type);
};
}