#include "entry.h"

Entry::Entry(std::string d, double a, std::string l, std::string c, bool r, bool e) {
    date = d;
    amount = a;
    location = l;
    category = c;
    receipt = r;
    eligibile = e;
}