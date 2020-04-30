#pragma once
#include "AbstractCompiler.h"
#include "MessageRecord.h"
#include <string>
#include <list>

class LLk : public AbstractCompiler
{
private:
    std::list<MessageRecord> errors;
    std::list<MessageRecord> warnings;

public:
    LLk();
    virtual void process(std::list<std::string> text);
    virtual std::list<MessageRecord> getErrors();
    virtual std::list<MessageRecord> getWarnings();
};