#ifndef RANDOM_FILE_H_
#define RANDOM_FILE_H_

#include <iostream>
#include <fstream>
#include <cstdio>

void writeString(std::fstream &stream, std::string str);

std::string readString(std::fstream &stream);

class Record {
private:
    std::string name;
    std::string age;
    std::string nationality;
    std::string overall;
    std::string club;
    std::string value;
    std::string position;
    std::string jersey_number;

public:
    void setData();
    void showData();
    long write(std::fstream &stream);
    bool read(std::fstream &stream);
};

class VariableRecordFile {

private:
    std::string fileName;
    std::string indexName;

public:
    VariableRecordFile(std::string &_fileName);
    void writeRecord(Record obj);
    void scanAll();
    Record readRecord(int n);
    int size();
};

void writeString(std::fstream &stream, std::string str);
std::string readString(std::fstream &stream);

#endif
