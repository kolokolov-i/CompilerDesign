#include "MessageRecord.h"

MessageRecord::MessageRecord(int line, int column, string message)
{
    this->line = line;
    this->column = column;
    this->message = message;
}

MessageRecord::MessageRecord(string message) : MessageRecord(0, 0, message)
{
}