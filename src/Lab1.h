#pragma once
#include "AbstractCompiler.h"
#include "MessageRecord.h"
#include "Token.h"
#include <string>
#include <vector>

using namespace Lexer;

class LLk : public AbstractCompiler
{
private:
    std::vector<MessageRecord> *errors;
    std::vector<MessageRecord> *warnings;
    std::vector<Token> tokens;
    std::vector<std::string> listing;

public:
    LLk();
    virtual ~LLk();
    virtual void process(std::vector<std::string> text);
    virtual std::vector<MessageRecord>* getErrors();
    virtual std::vector<MessageRecord>* getWarnings();
    virtual std::vector<std::string> getListing();
};