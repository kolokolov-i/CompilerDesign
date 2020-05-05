#pragma once
#include <string>
#include <map>

namespace Lexer
{
enum class TokenType
{
    ID,         // AAA
    NumInt,     // 15
    NumFloat,   // 0.5
    NumExp,     // 0E+0
    Char,       // 'A'
    SDot,       // .
    SCom,       // ,
    SSem,       // ;
    SBrackO,    // (
    SBrackC,    // )
    SBracsO,    // {
    SBracsC,    // }
    PAssign,    // =
    PPlus,      // +
    PMinus,     // -
    PMulti,     // *
    PDiv,       // /
    PMod,       // %
    PLess,      // <
    PLessEq,    // < =
    PGret,      // >
    PGretEq,    // > =
    PEquals,    // = =
    PNotEq,     // ! =
    KWvoid,     // void
    KWint,      // int
    KWsigned,   // signed
    KWunsigned, // unsigned
    KWdouble,   // double
    KWchar,     // char
    KWwhile     // while
};

enum class MetaLiter
{
    Alpha,        // alphabet
    Digit,        // digit
    Space,        // space, \n, \t
    Semicolon,    // ;
    Dot,          // .
    Comma,        // ,
    Apostrophe,   // '
    Equals,       // =
    Plus,         // +
    Minus,        // -
    Multi,        // *
    Slash,        // /
    Percent,      // %
    SignLess,     // <
    SignGreater,  // >
    Exclamation,  // !
    BracketOpen,  // (
    BracketClose, // )
    BracesOpen,   // {
    BracesClose,  // }
    Other
};

std::map<std::string, TokenType> getKeyWords();

// for debug
std::map<TokenType, std::string> getTokensNames();

} // namespace Lexer