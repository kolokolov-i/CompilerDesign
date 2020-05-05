#include "Lexer.h"

namespace Lexer
{

MetaLiter translit(char c)
{
    if (c > 0x40 && c < 0x5B)
    {
        return MetaLiter::Alpha;
    }
    if (c > 0x60 && c < 0x7B)
    {
        return MetaLiter::Alpha;
    }
    if (c >= 0x30 && c <= 0x39)
    {
        return MetaLiter::Digit;
    }
    switch (c)
    {
        case ' ': case '\t': return MetaLiter::Space;
        case '_': return MetaLiter::Alpha;
        case ';': return MetaLiter::Semicolon;
        case '.': return MetaLiter::Dot;
        case ',': return MetaLiter::Comma;
        case '\'': return MetaLiter::Apostrophe;
        case '=': return MetaLiter::Equals;
        case '+': return MetaLiter::Plus;
        case '-': return MetaLiter::Minus;
        case '/': return MetaLiter::Slash;
        case '%': return MetaLiter::Percent;
        case '<': return MetaLiter::SignLess;
        case '>': return MetaLiter::SignGreater;
        case '!' : return MetaLiter::Exclamation;
        case '(' : return MetaLiter::BracketOpen;
        case ')' : return MetaLiter::BracketClose;
        case '{' : return MetaLiter::BracesOpen;
        case '}' : return MetaLiter::BracesClose;
        default: return MetaLiter::Other;
    }
}
}