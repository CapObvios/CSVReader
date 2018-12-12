#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using std::string;
using std::istream;
using std::ifstream;
using std::unordered_map;
using std::unordered_set;
using std::istream;

unordered_map<string, unordered_set<string>> readCSV(const string& fname, const char& delimiter = ';');

#endif // CSVREADER_H
