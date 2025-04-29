#include <iostream>
#include "data_functions.h"

void displayData(const std::vector<Entry>& entries) {
  for (const Entry& entry : entries) {
    std::cout << entry.date << ": $" << entry.amount << " spent at " << entry.location << " on " << entry.category << std::endl;
  }
}
double sumAmount(const std::vector<Entry>& entries) {
  double total = 0;
  for (size_t i = 0; i < entries.size(); i++)
  {
    total += entries.at(i).amount;
  }
  return total;
}
double meanAmount(const std::vector<Entry>& entries) {
  double total = 0;
  for (size_t i = 0; i < entries.size(); i++)
  {
    total += entries.at(i).amount;
  }
  return total / static_cast<double>(entries.size());
}
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
std::vector<Entry> getReceipted(const std::vector<Entry>& entries, bool receipt) {
  std::vector<Entry> returnVector;
  for (size_t i = 0; i < entries.size(); i++)
  {
    if (entries.at(i).receipt) {
      returnVector.push_back(entries.at(i));
    }
  }
  return returnVector;
}
void getCategories(const std::vector<Entry>& entries) {
  std::vector<std::string> categories;
  for (size_t i = 0; i < entries.size(); i++)
  {
    bool isIn = true;
    for (size_t j = 0; j < categories.size(); j++) {
      if (entries.at(i).category == categories.at(j)) {
        categories.push_back(entries.at(i).category);
      }
    }
  }
  for (size_t i = 0; i < categories.size() - 1; i++) {
    std::cout << categories.at(i) << ", ";
  }
  std::cout << categories.at(categories.size() - 1);
}
void getLocations(const std::vector<Entry>& entries) {
  std::vector<std::string> locations;
  for (size_t i = 0; i < entries.size(); i++)
  {
    bool isIn = true;
    for (size_t j = 0; j < locations.size(); j++) {
      if (entries.at(i).location == locations.at(j)) {
        locations.push_back(entries.at(i).location);
      }
    }
  }
  for (size_t i = 0; i < locations.size() - 1; i++) {
    std::cout << locations.at(i) << ", ";
  }
  std::cout << locations.at(locations.size() - 1);
}
std::string getHelpMessage() {
  return "Valid commands:\nhelp: outputs this message.\nlocations: outputs all possible locations.\ncategories: outputs all possible categories.\nsum {entries}: returns the total amount of spending on given entries.\naverage {entries}: returns the average amount of spending on given entries.\ndisplay {entries}: displays a list of the given entries.\n{entries} from {initial date in YYYY-MM-DD} to {end date in YYYY-MM-DD}: returns all entries between the dates.\n{entries} on {date in YYYY-MM-DD}: returns all entries on given date.\n{entries} at {location}: returns all entries from given location.\n{entries} for {category}: returns all entries from given category.\n{entries} eligible: returns all entries eligible for a refund.\n{entries} with receipts: returns all entries with receipts.";
}