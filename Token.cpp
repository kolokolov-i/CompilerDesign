#include "Token.h"
#include "LexerDefs.h"
#include <string>

namespace Lexer
{
Token::Token(int line, int column, int length, std::string image, TokenType type)
{
    posLine = line;
    posCol = column;
    this->length = length;
    this->image = image;
    this->type = type;
}
} // namespace Lexer