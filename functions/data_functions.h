#include <vector>
#include "../util/entry.h"
#pragma once

void displayData(const std::vector<Entry>& entries);
double sumAmount(const std::vector<Entry>& entries);
double meanAmount(const std::vector<Entry>& entries);
std::vector<Entry> getFromDateRange(const std::vector<Entry>& entries, std::string date1, std::string date2);
std::vector<Entry> getOnDay(const std::vector<Entry>& entries, std::string date);
std::vector<Entry> getFromLocation(const std::vector<Entry>& entries, std::string location);
std::vector<Entry> getFromCategory(const std::vector<Entry>& entries, std::string category);
std::vector<Entry> getEligible(const std::vector<Entry>& entries);
std::vector<Entry> getReceipted(const std::vector<Entry>& entries);
void getCategories(const std::vector<Entry>& entries);
void getLocations(const std::vector<Entry>& entries);
std::string getHelpMessage();
void filterEntries(std::vector<Entry>& entries, int argc, char* args[]);