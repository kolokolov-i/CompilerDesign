#pragma once
#include <string>

using namespace std;

class MessageRecord {
    public:
    int line, column;
    string message;
    MessageRecord(string message);
    MessageRecord(int line, int column, string message);
};

MessageRecord::MessageRecord(int line, int column, string message) {
    this->line = line;
    this->column = column;
    this->message = message;
}

MessageRecord::MessageRecord(string message) : MessageRecord(0,0,message){

}