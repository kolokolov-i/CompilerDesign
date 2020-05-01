#pragma once
#include "AbstractCompiler.h"
#include "MessageRecord.h"
#include "Token.h"
#include <string>
#include <list>

using namespace Lexer;

class LLk : public AbstractCompiler
{
private:
    std::list<MessageRecord> errors;
    std::list<MessageRecord> warnings;
    std::list<Token> tokens;
    std::list<std::string> listing;

public:
    LLk();
    virtual void process(std::list<std::string> text);
    virtual std::list<MessageRecord> getErrors();
    virtual std::list<MessageRecord> getWarnings();
    virtual std::list<std::string> getListing();
};