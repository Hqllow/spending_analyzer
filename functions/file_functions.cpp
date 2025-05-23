#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../util/entry.h"

std::vector<Entry> readFile() {
    std::ifstream file("./util/spending.csv");
    if (!file) {
        return {};
    }

    std::string line;
    std::vector<Entry> items;
    //Remove first line
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
        }

        if (row.size() < 6) {
            continue;
        }
        bool receipt = row[4] == "Yes";
        bool eligible = row[5] == "Yes";
        items.push_back(Entry(row[0], stod(row[1]), row[2], row[3], receipt, eligible));
    }

    file.close();
    return items;
}

void addEntry(Entry newEntry) {
    std::ofstream file;
    if (!file) {
      return;
    }

    std::string receipt;
    std::string eligible;
    file.open("./util/spending.csv", std::ios::app);
    newEntry.receipt ? receipt = "Yes" : "No";
    newEntry.eligibile ? eligible = "Yes" : "No";
    file << "\n" << newEntry.date << "," << newEntry.amount << "," << newEntry.location << "," << newEntry.category << "," << receipt << "," << eligible <<std::endl;
    file.close();
}