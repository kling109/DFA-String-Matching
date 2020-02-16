// Identifier for the string "abab"
#include <iostream>
#include <fstream>
#include <list> 

using namespace std;

/* Each q* is a node in a DFA.  All nodes follow the same style, using the
   ifstream reader to aquire characters from a file.  Each of these characters
   is then compared to the transition function values for that node, taking
   the correct path depending on the input.  When the program reaches an accept
   state, the pos value for that string is added to the list of prevVals.  Once
   the file reader runs out of characters, prevVals is returned. */
list<int>* q0(ifstream &reader, int pos, list<int>* prevVals);
list<int>* q1(ifstream &reader, int pos, list<int>* prevVals);
list<int>* q2(ifstream &reader, int pos, list<int>* prevVals);
list<int>* q3(ifstream &reader, int pos, list<int>* prevVals);
list<int>* driver(string filepath);

list<int>* q0(ifstream &reader, int pos, list<int>* prevVals) {
    if (reader.eof()) {
        return prevVals;
    }
    char newChar = reader.get();
    if (newChar == 'a') {
        return q1(reader, pos+1, prevVals);
    } else {
        return q0(reader, pos+1, prevVals);
    }
}

list<int>* q1(ifstream &reader, int pos, list<int>* prevVals) {
    if (reader.eof()) {
        return prevVals;
    }
    char newChar = reader.get();
    if (newChar == 'b') {
        return q2(reader, pos+1, prevVals);
    } else {
        return q0(reader, pos+1, prevVals);
    }
}

list<int>* q2(ifstream &reader, int pos, list<int>* prevVals) {
    if (reader.eof()) {
        return prevVals;
    }
    char newChar = reader.get();
    if (newChar == 'a') {
        return q3(reader, pos+1, prevVals);
    } else {
        return q0(reader, pos+1, prevVals);
    }
}

list<int>* q3(ifstream &reader, int pos, list<int>* prevVals) {
    if (reader.eof()) {
        return prevVals;
    }
    char newChar = reader.get();
    if (newChar == 'b') {
        prevVals->push_back(pos);
        return q2(reader, pos+1, prevVals);
    } else {
        return q0(reader, pos+1, prevVals);
    }
}

list<int>* driver(string filepath) {
    /* A simple driver method for the DFA.  The function simply takes in a file
       path, then translates it to an ifstream.  Additionally, the program is 
       started with pos = 1 and prevVals as an empty list. */
    ifstream input (filepath, ifstream::in);
    list<int>* vals = new list<int>();
    return q0(input, 1, vals);
}

int main()
{
    /* Main method which handles translating a given command line file name
       into a list of matching positions. */
    string path;
    cout << "Input a file path: ";
    cin >> path;
    list<int>* endVals = driver(path);
    int listLen = endVals->size();
    cout << "[";
    for (int i = 0; i < listLen; ++i) {
        if (i > 0) {
            cout << ", ";
        }
        cout << endVals->front();
        endVals->pop_front();
    }
    cout << "]";
    return 0;
}

