#include <iostream>

#include "read_csv.h"

int main()
{
    // The file was taken from the following link:
    // https://people.sc.fsu.edu/~jburkardt/data/csv/csv.html
    const auto csv = ReadCsv("../airtravel.csv", ',');

    for (const auto& column : csv)
    {
        std::cout << "column name: " << column.first << std::endl;
        std::cout << "values:";

        for (const auto& value : column.second)
        {
            std::cout << " " << value;
        }
        std::cout << std::endl;
    }
}