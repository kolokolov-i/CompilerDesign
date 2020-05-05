#pragma once
#include "MessageRecord.h"
#include <string>
#include <vector>

class AbstractCompiler
{
public:
    AbstractCompiler();
    virtual ~AbstractCompiler();
    virtual void process(std::vector<std::string> text) = 0;
    virtual std::vector<MessageRecord>* getErrors() = 0;
    virtual std::vector<MessageRecord>* getWarnings() = 0;
    virtual std::vector<std::string> getListing() = 0;
    bool isSuccess();

protected:
    bool success = false;
};