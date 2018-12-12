#include "csvreader.h"

unordered_map<string, unordered_set<string>> readCSV(const string& fname, const char& delimiter)
{
	unordered_map<string, unordered_set<string>> result;

	ifstream ifs;
	ifs.open(fname);

	//for now just return an empty dict
	if (!ifs.is_open()) return unordered_map<string, unordered_set<string>>();

	//identify headers and initialize a dict
	string headers;
	ifs >> headers;

	size_t pos = 0;
	string header;

	while ((pos = headers.find(delimiter)) != std::string::npos) {
		header = headers.substr(0, pos);
		result[header]; // create entry
		headers.erase(0, pos + 1);
	}
	result[headers]; // last entry

	int headerCount = result.size();

	// fill in the dictionary
	while (!ifs.eof()) {

		int curHeader = 1;
		for (const auto& k : result)
		{
			// for everything except the last column
			if (curHeader++ >= headerCount) break;
			string value;
			getline(ifs, value, delimiter);
			result[k.first].insert(value);
		}
		//the last column
		string value; ifs >> value;
		result[headers].insert(value);
	}

	return result;
}
