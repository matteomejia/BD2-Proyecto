#include <iostream>
#include<fstream>
#include<cstdio>
#include "randomfile.h"

using namespace std;

void Record::setData() {
    cout << "Name: ";
    cin >> name;
    cout << "Age: ";
    cin >> age;
    cout << "Nationality: ";
    cin >> nationality;
    cout << "Overall: ";
    cin >> overall;
    cout << "Club: ";
    cin >> club;
    cout << "Value: ";
    cin >> value;
    cout << "Position: ";
    cin >> position;
    cout << "Number: ";
    cin >> jersey_number;
}

void Record::showData() {
    cout << "Name: " << name;
    cout << "Age: " << age;
    cout << "Nationality: " << nationality;
    cout << "Overall: " << overall;
    cout << "Club: " << club;
    cout << "Value: " << value;
    cout << "Position: " << position;
    cout << "Number: " << jersey_number;
}

long Record::write(fstream &stream) {
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

bool Record::read(fstream &stream) {
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

VariableRecordFile::VariableRecordFile(string &_fileName) {
    this->fileName = _fileName;
    this->indexName = _fileName + "_ind";
}

void VariableRecordFile::writeRecord(Record obj) {
    fstream outFile;
    long pos;

    outFile.open(this->fileName, ios::binary | ios::app);
    if (outFile.is_open()) {
        pos = obj.write(outFile);
        outFile.close();

        outFile.open(this->indexName, ios::binary | ios::app);
        if (outFile.is_open()) {
            outFile.write((char *) &pos, sizeof(pos));
            outFile.close();
        } else cout << "Could not open the file.\n";

    } else cout << "Could not open the file.\n";
}

void VariableRecordFile::scanAll() {
    fstream inFile;
    inFile.open(this->fileName, ios::in | ios::binary);
    Record obj;
    if (inFile.is_open()) {
        while (obj.read(inFile)) {
            obj.showData();
        }
        inFile.close();
    } else cout << "Could not open the file.\n";
}

Record VariableRecordFile::readRecord(int n) {
    fstream inFile;
    long pos;
    Record obj;

    inFile.open(this->indexName, ios::in | ios::binary);
    if (inFile.is_open()) {
        inFile.seekg(n * sizeof(pos));
        inFile.read((char *) &pos, sizeof(pos));
        inFile.close();

        inFile.open(this->fileName, ios::in | ios::binary);
        if (inFile.is_open()) {
            inFile.seekg(pos);
            obj.read(inFile);
            inFile.close();
        } else cout << "Could not open the file.\n";
    } else cout << "Could not open the index-file.\n";

    return obj;
}

int VariableRecordFile::size() {
    int numRecords = 0;
    fstream inFile;
    inFile.open(this->indexName, ios::in | ios::binary);
    if (inFile.is_open()) {
        inFile.seekg(0, ios::end);
        numRecords = inFile.tellg() / sizeof(long);
        inFile.close();
    } else cout << "Could not open the index-file.\n";
    return numRecords;
}

void writeString(fstream &stream, string str) {
    int len = str.size();
    stream.write((char *) &len, sizeof(len));
    stream.write(str.c_str(), len);
}

string readString(fstream &stream) {
    int tam;
    stream.read((char *) &tam, sizeof(tam));
    char *buffer = new char[tam + 1];
    stream.read(buffer, tam);
    buffer[tam] = '\0';
    string result = buffer;
    delete buffer;
    return result;
}