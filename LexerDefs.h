#pragma once
#include <string>

namespace Lexer
{
enum TokenType
{
    ID,
    NumInt,
    NumFloat,
    NumExp,
    Char,
    SDot,
    SCom,
    SSem,
    SBrackO,
    SBrackC,
    SBracsO,
    SBracsC,
    PAssign,
    PPlus,
    PMinus,
    PMulti,
    PDiv,
    PMod,
    PLess,
    PLessEq,
    PGret,
    PGretEq,
    PEquals,
    PNotEq,
    KWvoid,
    KWint,
    KWsigned,
    KWunsigned,
    KWdouble,
    KWchar,
    KWwhile
};

enum MetaLiter
{
    Alpha,          // alphabet
    Digit,          // digit
    Space,          // space, \n, \t
    Semicolon,      // ;
    Dot,            // .
    Comma,          // ,
    Equals,         // =
    Plus,           // +
    Minus,          // -
    Multi,          // *
    Slash,          // /
    Percent,        // %
    SignLess,       // <
    SignGreater,    // >
    Exclamation,    // !
    BracketOpen,    // (
    BracketClose,   // )
    BracesOpen,     // {
    BracesClose,    // }
    Other
};

string tokenNames[50];

}