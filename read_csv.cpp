#include "read_csv.h"

#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::vector<CsvColumn> ReadCsv(const char* file_name, const char delimiter)
{
    std::vector<CsvColumn> result;

    std::ifstream ifs;
    ifs.open(file_name);

    // For now just return an empty dict. Probably should return an option<T> or
    // result<T>.
    if (!ifs.is_open())
    {
        return std::vector<CsvColumn>();
    }

    // Identify headers and initialize the dictionary.
    std::string headers_string;

    getline(ifs, headers_string);

    // Note: this can be done using boost, but attaching whole boost for this
    // simple task is an overkill.
    size_t start = 0;
    size_t pos = 0;
    std::string header;

    while ((pos = headers_string.find(delimiter, start)) != std::string::npos)
    {
        // Omit the delimiter in header: [start, delimiter_pos).
        header = headers_string.substr(start, pos - start);
        // Create entry.
        result.emplace_back(std::move(header), CsvColumnValues());
        // Set the new start to omit the delimiter.
        start = pos + 1;
    }

    // Create the last entry.
    header = headers_string.substr(start);
    result.emplace_back(std::move(header), CsvColumnValues());

    const int columnCount = result.size();

    // Fill in the values of the CSV file.
    while (!ifs.eof())
    {
        for (size_t headerId = 0; headerId < columnCount; ++headerId)
        {
            std::string value;

            // We don't have the delimiter after the last column.
            getline(
                ifs, value, ((headerId + 1) < columnCount) ? delimiter : '\n');
            // Write the value.
            CsvColumnValues& csvValues = result.at(headerId).second;
            csvValues.push_back(std::move(value));
        }
    }

    return result;
}
