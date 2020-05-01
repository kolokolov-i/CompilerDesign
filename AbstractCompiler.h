#pragma once
#include "MessageRecord.h"
#include <string>
#include <list>

class AbstractCompiler
{
public:
    virtual void process(std::list<std::string> text) = 0;
    virtual std::list<MessageRecord> getErrors() = 0;
    virtual std::list<MessageRecord> getWarnings() = 0;
    virtual std::list<std::string> getListing() = 0;
    bool isSuccess();
    protected:
    bool success = false;
};