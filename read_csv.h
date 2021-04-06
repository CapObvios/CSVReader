#ifndef READ_CSV_H
#define READ_CSV_H

#include <string>
#include <unordered_map>
#include <vector>

using CsvColumnValues = std::vector<std::string>;
using CsvColumn = std::pair<std::string, CsvColumnValues>;

std::vector<CsvColumn> ReadCsv(const char* file_name, char delimiter = ';');

#endif  // READ_CSV_H
