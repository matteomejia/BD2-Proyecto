#include <iostream>
#include <fstream>
#include <cstdio>
#include "randomfile.h"

void Record::setData() {
    std::cout << "Name: ";
    std::cout << "Age: ";
    std::cin >> name;
    std::cin >> age;
    std::cout << "Nationality: ";
    std::cin >> nationality;
    std::cout << "Overall: ";
    std::cin >> overall;
    std::cout << "Club: ";
    std::cin >> club;
    std::cout << "Value: ";
    std::cin >> value;
    std::cout << "Position: ";
    std::cin >> position;
    std::cout << "Number: ";
    std::cin >> jersey_number;
}

void Record::showData() {
    std::cout << "Name: " << name;
    std::cout << "Age: " << age;
    std::cout << "Nationality: " << nationality;
    std::cout << "Overall: " << overall;
    std::cout << "Club: " << club;
    std::cout << "Value: " << value;
    std::cout << "Position: " << position;
    std::cout << "Number: " << jersey_number;
}

long Record::write(std::fstream &stream) {
    long pos_begin = stream.tellp();
    stream.write((char *) &jersey_number, sizeof(jersey_number));
    writeString(stream, name);
    writeString(stream, age);
    writeString(stream, nationality);
    writeString(stream, overall);
    writeString(stream, club);
    writeString(stream, value);
    writeString(stream, position);
    return pos_begin;
}

bool Record::read(std::fstream &stream) {
    stream.read((char *) &jersey_number, sizeof(jersey_number));
    if (stream.fail()) return false;
    name = readString(stream);
    age = readString(stream);
    nationality = readString(stream);
    overall = readString(stream);
    club = readString(stream);
    value = readString(stream);
    position = readString(stream);
    return true;
}

VariableRecordFile::VariableRecordFile(std::string &_fileName) {
    this->fileName = _fileName;
    this->indexName = _fileName + "_index";
}

void VariableRecordFile::writeRecord(Record obj) {
    std::fstream outFile;
    long pos;

    outFile.open(this->fileName, std::ios::binary | std::ios::app);
    if (outFile.is_open()) {
        pos = obj.write(outFile);
        outFile.close();

        outFile.open(this->indexName, std::ios::binary | std::ios::app);
        if (outFile.is_open()) {
            outFile.write((char *) &pos, sizeof(pos));
            outFile.close();
        } else std::cout << "Could not open the file.\n";

    } else std::cout << "Could not open the file.\n";
}

void VariableRecordFile::scanAll() {
    std::fstream inFile;
    inFile.open(this->fileName, std::ios::in | std::ios::binary);
    Record obj;
    if (inFile.is_open()) {
        while (obj.read(inFile)) {
            obj.showData();
        }
        inFile.close();
    } else std::cout << "Could not open the file.\n";
}

Record VariableRecordFile::readRecord(int n) {
    std::fstream inFile;
    long pos;
    Record obj;

    inFile.open(this->indexName, std::ios::in | std::ios::binary);
    if (inFile.is_open()) {
        inFile.seekg(n * sizeof(pos));
        inFile.read((char *) &pos, sizeof(pos));
        inFile.close();

        inFile.open(this->fileName, std::ios::in | std::ios::binary);
        if (inFile.is_open()) {
            inFile.seekg(pos);
            obj.read(inFile);
            inFile.close();
        } else std::cout << "Could not open the file.\n";
    } else std::cout << "Could not open the index-file.\n";

    return obj;
}

int VariableRecordFile::size() {
    int numRecords = 0;
    std::fstream inFile;
    inFile.open(this->indexName, std::ios::in | std::ios::binary);
    if (inFile.is_open()) {
        inFile.seekg(0, std::ios::end);
        numRecords = inFile.tellg() / sizeof(long);
        inFile.close();
    } else std::cout << "Could not open the index-file.\n";
    return numRecords;
}

void writeString(std::fstream &stream, std::string str) {
    int len = str.size();
    stream.write((char *) &len, sizeof(len));
    stream.write(str.c_str(), len);
}

std::string readString(std::fstream &stream) {
    int tam;
    stream.read((char *) &tam, sizeof(tam));
    char *buffer = new char[tam + 1];
    stream.read(buffer, tam);
    buffer[tam] = '\0';
    std::string result = buffer;
    delete [] buffer;
    return result;
}
