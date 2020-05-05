#include "AbstractCompiler.h"

AbstractCompiler::AbstractCompiler()
{
}

AbstractCompiler::~AbstractCompiler()
{
}

bool AbstractCompiler::isSuccess()
{
    return this->success;
}