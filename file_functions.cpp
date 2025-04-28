#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "entry.h"

std::vector<Entry> readFile() {
    std::ifstream file("spending.csv");
    if (!file) {
        return {};
    }

    std::string line;
    std::vector<Entry> items;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::istringstream ss(line);
        std::string value;

        while (std::getline(ss, value, ',')) {
            row.push_back(value);
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
    if (!file.open("spending.csv", std::ios::app) {
      return;
    }
    newEntry.receipt ? std::string receipt = "Yes" : "No";
    newEntry.eligible ? std::string eligible = "Yes" : "No";
    file << newEntry.date << "," << newEntry.amount << "," << newEntry.location << "," << newEntry.category << "," << receipt << "," << eligible <<std::endl;
    file.close();
}