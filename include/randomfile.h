#ifndef RANDOM_FILE_H_
#define RANDOM_FILE_H_

#include <iostream>
#include<fstream>
#include<cstdio>

using namespace std;

void writeString(fstream &stream, string str);

string readString(fstream &stream);

class Record {
private:
    string name;
    string age;
    string nationality;
    string overall;
    string club;
    string value;
    string position;
    string jersey_number;

public:
    void setData();

    void showData();

    long write(fstream &stream);

    bool read(fstream &stream);
};

class VariableRecordFile {

private:
    string fileName;
    string indexName;

public:
    VariableRecordFile(string &_fileName);

    void writeRecord(Record obj);

    void scanAll();

/*
* function to read a record
*/
    Record readRecord(int n);

    int size();
};

void writeString(fstream &stream, string str);

string readString(fstream &stream);

#endif
