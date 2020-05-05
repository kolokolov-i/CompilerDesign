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
