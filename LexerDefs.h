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

// for debug
string *getTokensNames()
{
    string names[30];
    names[static_cast<int>(TokenType::ID)] = "ID";
    names[static_cast<int>(TokenType::NumInt)] = "NumInt";
    names[static_cast<int>(TokenType::NumFloat)] = "NumFloat";
    names[static_cast<int>(TokenType::NumExp)] = "NumExp";
    names[static_cast<int>(TokenType::Char)] = "Char";
    names[static_cast<int>(TokenType::SDot)] = "SDot";
    names[static_cast<int>(TokenType::SCom)] = "SCom";
    names[static_cast<int>(TokenType::SSem)] = "SSem";
    names[static_cast<int>(TokenType::SBrackO)] = "SBrackO";
    names[static_cast<int>(TokenType::SBrackC)] = "SBrackC";
    names[static_cast<int>(TokenType::SBracsO)] = "SBracsO";
    names[static_cast<int>(TokenType::SBracsC)] = "SBracsC";
    names[static_cast<int>(TokenType::PAssign)] = "PAssign";
    names[static_cast<int>(TokenType::PPlus)] = "PPlus";
    names[static_cast<int>(TokenType::PMinus)] = "PMinus";
    names[static_cast<int>(TokenType::PMulti)] = "PMulti";
    names[static_cast<int>(TokenType::PDiv)] = "PDiv";
    names[static_cast<int>(TokenType::PMod)] = "PMod";
    names[static_cast<int>(TokenType::PLess)] = "PLess";
    names[static_cast<int>(TokenType::PLessEq)] = "PLessEq";
    names[static_cast<int>(TokenType::PGret)] = "PGret";
    names[static_cast<int>(TokenType::PGretEq)] = "PGretEq";
    names[static_cast<int>(TokenType::PEquals)] = "PEquals";
    names[static_cast<int>(TokenType::PNotEq)] = "PNotEq";
    names[static_cast<int>(TokenType::KWvoid)] = "KWvoid";
    names[static_cast<int>(TokenType::KWint)] = "KWint";
    names[static_cast<int>(TokenType::KWsigned)] = "KWsigned";
    names[static_cast<int>(TokenType::KWunsigned)] = "KWunsigned";
    names[static_cast<int>(TokenType::KWdouble)] = "KWdouble";
    names[static_cast<int>(TokenType::KWchar)] = "KWchar";
    names[static_cast<int>(TokenType::KWwhile)] = "KWwhile";
    return names;
}

map<string, TokenType> getKeyWords()
{
    map<string, TokenType> result;
    result["void"] = TokenType::KWvoid;
    return result;
}

} // namespace Lexer