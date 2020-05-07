#include "LexerDefs.h"

namespace Lexer
{

std::map<TokenType, std::string> getTokensNames()
{
    std::map<TokenType, std::string> result;
    result[TokenType::ID] = "ID";
    result[TokenType::NumInt] = "NumInt";
    result[TokenType::NumFloat] = "NumFloat";
    result[TokenType::NumExp] = "NumExp";
    result[TokenType::Char] = "Char";
    result[TokenType::SDot] = "SDot";
    result[TokenType::SCom] = "SCom";
    result[TokenType::SSem] = "SSem";
    result[TokenType::SBrackO] = "SBrackO";
    result[TokenType::SBrackC] = "SBrackC";
    result[TokenType::SBracsO] = "SBracsO";
    result[TokenType::SBracsC] = "SBracsC";
    result[TokenType::PAssign] = "PAssign";
    result[TokenType::PPlus] = "PPlus";
    result[TokenType::PMinus] = "PMinus";
    result[TokenType::PMulti] = "PMulti";
    result[TokenType::PDiv] = "PDiv";
    result[TokenType::PMod] = "PMod";
    result[TokenType::PLess] = "PLess";
    result[TokenType::PLessEq] = "PLessEq";
    result[TokenType::PGret] = "PGret";
    result[TokenType::PGretEq] = "PGretEq";
    result[TokenType::PEquals] = "PEquals";
    result[TokenType::PNotEq] = "PNotEq";
    result[TokenType::KWvoid] = "KWvoid";
    result[TokenType::KWint] = "KWint";
    result[TokenType::KWsigned] = "KWsigned";
    result[TokenType::KWunsigned] = "KWunsigned";
    result[TokenType::KWdouble] = "KWdouble";
    result[TokenType::KWchar] = "KWchar";
    result[TokenType::KWwhile] = "KWwhile";
    result[TokenType::KWstruct] = "KWstruct";
    return result;
}

std::map<std::string, TokenType> getKeyWords()
{
    std::map<std::string, TokenType> result;
    result["void"] = TokenType::KWvoid;
    result["signed"] = TokenType::KWsigned;
    result["unsigned"] = TokenType::KWunsigned;
    result["int"] = TokenType::KWint;
    result["char"] = TokenType::KWchar;
    result["double"] = TokenType::KWdouble;
    result["while"] = TokenType::KWwhile;
    result["struct"] = TokenType::KWstruct;
    return result;
}
} // namespace Lexer