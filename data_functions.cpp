#include <iostream>
#include "data_functions.h"

//Basic display of all elements in entries
void displayData(const std::vector<Entry>& entries) {
  for (const Entry& entry : entries) {
    std::cout << entry.date << ": $" << entry.amount << " spent at " << entry.location << " on " << entry.category << std::endl;
  }
}

//Iteration to create sum
double sumAmount(const std::vector<Entry>& entries) {
  double total = 0;
  for (size_t i = 0; i < entries.size(); i++)
  {
    total += entries.at(i).amount;
  }
  return total;
}

//Iteration and division to find and return average
double meanAmount(const std::vector<Entry>& entries) {
  double total = 0;
  for (size_t i = 0; i < entries.size(); i++)
  {
    total += entries.at(i).amount;
  }
  return total / static_cast<double>(entries.size());
}

//Dates are formatted in useful order; can simply compare while iterating and add to return array
std::vector<Entry> getFromDateRange(const std::vector<Entry>& entries, std::string date1, std::string date2) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).date >= date1 && entries.at(i).date <= date2) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for matching date
std::vector<Entry> getOnDay(const std::vector<Entry>& entries, std::string date) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).date == date) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for matching location
std::vector<Entry> getFromLocation(const std::vector<Entry>& entries, std::string location) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).location == location) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for matching category
std::vector<Entry> getFromCategory(const std::vector<Entry>& entries, std::string category) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).category == category) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for eligible to be true
std::vector<Entry> getEligible(const std::vector<Entry>& entries) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).eligibile) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for receipt to be true
std::vector<Entry> getReceipted(const std::vector<Entry>& entries) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).receipt) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}

//Iterate and check for unique category
void getCategories(const std::vector<Entry>& entries) {
  std::vector<std::string> categories;
  for (size_t i = 0; i < entries.size(); i++)
  {
    bool isIn = false;
    for (size_t j = 0; j < categories.size(); j++) {
      if (entries.at(i).category == categories.at(j)) {
        isIn = true;
      }
    }
    if (!isIn) {
      categories.push_back(entries.at(i).category);
    }
  }
  for (size_t i = 0; i < categories.size() - 1; i++) {
    std::cout << categories.at(i) << ", ";
  }
  std::cout << categories.at(categories.size() - 1) << std::endl;
}

//Iterate and check for unique location
void getLocations(const std::vector<Entry>& entries) {
  std::vector<std::string> locations;
  for (size_t i = 0; i < entries.size(); i++)
  {
    bool isIn = false;
    for (size_t j = 0; j < locations.size(); j++) {
      if (entries.at(i).location == locations.at(j)) {
        isIn = true;
      }
    }
    if (!isIn) {
      locations.push_back(entries.at(i).location);
    }
  }
  for (size_t i = 0; i < locations.size() - 1; i++) {
    std::cout << locations.at(i) << ", ";
    if (i % 5 == 0 && i != 0) {
      std::cout << std::endl;
    }
  }
  std::cout << locations.at(locations.size() - 1) << std::endl;
}

//Single line help message
std::string getHelpMessage() {
  return "Use 'all' to denote full entries list.\n\nValid commands:\nhelp: outputs this message.\nlocations: outputs all possible locations.\ncategories: outputs all possible categories.\nsum {entries}: returns the total amount of spending on given entries.\naverage {entries}: returns the average amount of spending on given entries.\ndisplay {entries}: displays a list of the given entries.\n{entries} from {initial date in YYYY-MM-DD} to {end date in YYYY-MM-DD}: returns all entries between the dates.\n{entries} on {date in YYYY-MM-DD}: returns all entries on given date.\n{entries} at {location}: returns all entries from given location.\n{entries} for {category}: returns all entries from given category.\n{entries} eligible: returns all entries eligible for a refund.\n{entries} with receipts: returns all entries with receipts.";
}

//Trims vector of entries to only entries within bounds provided in arguments
void filterEntries(std::vector<Entry>& entries, int argc, char* args[]) {
  for (int i = 2; i < argc; i++) {
    std::string arg = args[i];

    //check for all keyword
    if (arg == "all") {
      continue;
    }

    //check if using 'from' command
    else if (arg == "from" && i + 3 < argc && std::string(args[i + 2]) == "to") {
      std::string startDate = args[i + 1];
      std::string endDate = args[i + 3];
      entries = getFromDateRange(entries, startDate, endDate);
      i += 3;
    }

    //check if using 'on' command
    else if (arg == "on" && i + 1 < argc) {
      std::string date = args[i + 1];
      entries = getOnDay(entries, date);
      i++;
    }

    //check if using 'at' command
    else if (arg == "at" && i + 1 < argc) {
      std::string location = args[i + 1];
      i++;
      //handle locations with multiple words
      while (i + 1 < argc ) {
        std::string next = std::string(args[i + 1]);
        if (next == "from" || next == "on" || next == "at" || next == "for" || next == "eligible" || next == "with") {
          break;
        }
        location += " " + std::string(args[i + 1]);
        i++;
      }
      entries = getFromLocation(entries, location);
    }

    //check if using 'for' command
    else if (arg == "for" && i + 1 < argc) {
      std::string category = args[i + 1];
      i++;
      //handle catefories with multiple words
      while (i + 1 < argc ) {
        std::string next = std::string(args[i + 1]);
        if (next == "from" || next == "on" || next == "at" || next == "for" || next == "eligible" || next == "with") {
          break;
        }
        category += " " + std::string(args[i + 1]);
        i++;
      }
      entries = getFromCategory(entries, category);
    }

    //check if using 'eligible' command
    else if (arg == "eligible") {
      entries = getEligible(entries);
    }

    //check if using 'with receipts' command
    else if (arg == "with" && i + 1 < argc && std::string(args[i + 1]) == "receipts") {
      entries = getReceipted(entries);
      i++;
    }
    else {
      std::cerr << "Unrecognized or improperly formatted filter: " << arg << std::endl;
      return;
    }
  }
}