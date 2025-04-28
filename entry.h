#include <string>
#pragma once

struct Entry {

    std::string date;
    double amount;
    std::string location;
    std::string category;
    bool receipt;
    bool eligibile;

    //constructor
    Entry(std::string d, double a, std::string l, std::string c, bool r, bool e);
};
