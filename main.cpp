#include "Lab1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

list<string> readText(string fileName);
void report(AbstractCompiler &compiler, ostream &out);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Error: Input file not specified." << endl;
        return 1;
    }
    string srcFileName(argv[1]);
    list<string> text = readText(srcFileName);
    LLk compiler;
    compiler.process(text);
    report(compiler, cout);
    return 0;
}

list<string> readText(string fileName)
{
    cout << "Source file: " << fileName << endl;
    ifstream srcFile(fileName);
    list<string> text;
    if (srcFile.is_open())
    {
        string line;
        while (getline(srcFile, line))
        {
            text.push_back(line);
        }
        srcFile.close();
    }
    return text;
}

void report(AbstractCompiler &compiler, ostream &out)
{
    list<MessageRecord>::iterator iter;
    int i;
    list<MessageRecord> ww = compiler.getWarnings();
    out << "Warnings " << ww.size() << "\n";
    for (i = 1, iter = ww.begin(); iter != ww.end(); ++iter)
    {
        MessageRecord r = *iter;
        out << i << ".[" << r.line << ", " << r.column << "]:" << r.message << "\n";
    }
    list<MessageRecord> ee = compiler.getErrors();
    out << "Errors " << ee.size() << "\n";
    for (i = 1, iter = ee.begin(); iter != ee.end(); ++iter)
    {
        MessageRecord r = *iter;
        out << i << ".[" << r.line << ", " << r.column << "]:" << r.message << "\n";
    }
}