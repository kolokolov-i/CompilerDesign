#include "Lab1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> readText(string fileName);
void report(AbstractCompiler *compiler, ostream &out);
void writeText(string fileName, vector<string> text);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Error: Input file not specified." << endl;
        return 1;
    }
    string srcFileName(argv[1]);
    string outFileName;
    if (argc >= 3)
    {
        outFileName = argv[2];
    }
    else
    {
        outFileName = "out.asm";
    }
    vector<string> text = readText(srcFileName);
    AbstractCompiler *compiler = new LLk();
    compiler->process(text);
    report(compiler, cout);
    if (compiler->isSuccess())
    {
        writeText(outFileName, compiler->getListing());
    }
    delete compiler;
    return 0;
}

vector<string> readText(string fileName)
{
    cout << "Source file: " << fileName << endl;
    ifstream srcFile(fileName);
    vector<string> text;
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

void writeText(string fileName, vector<string> text)
{
    cout << "Output file: " << fileName << endl;
    ofstream outFile(fileName);
    if (outFile.is_open())
    {
        for (string line : text)
        {
            outFile << line << '\n';
        }
        outFile.close();
    }
}

void report(AbstractCompiler *compiler, ostream &out)
{
    if (compiler->isSuccess())
    {
        out << "Compilation completed successfully.\n";
    }
    else
    {
        out << "Compilation completed unsuccessfully.\n";
    }
    vector<MessageRecord>::iterator iter;
    int i;
    vector<MessageRecord>* ee = compiler->getErrors();
    out << "Errors " << ee->size() << "\n";
    for (i = 1, iter = ee->begin(); iter != ee->end(); ++iter, ++i)
    {
        MessageRecord r = *iter;
        out << i << ".[" << r.line << ", " << r.column << "]:" << r.message << "\n";
    }
    vector<MessageRecord>* ww = compiler->getWarnings();
    out << "Warnings " << ww->size() << "\n";
    for (i = 1, iter = ww->begin(); iter != ww->end(); ++iter, ++i)
    {
        MessageRecord r = *iter;
        out << i << ".[" << r.line << ", " << r.column << "]:" << r.message << "\n";
    }
}