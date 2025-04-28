#include <vector>
#include "entry.h"
#pragma once

void displayData(const std::vector<Entry>& entries);
std::vector<Entry> getFromDateRange(const std::vector<Entry>& entries, std::string date1, std::string date2);
std::vector<Entry> getOnDay(const std::vector<Entry>& entries, std::string date);
std::vector<Entry> getFromLocation(const std::vector<Entry>& entries, std::string location);
std::vector<Entry> getFromCategory(const std::vector<Entry>& entries, std::string category);
std::vector<Entry> getEligible(const std::vector<Entry>& entries, bool eligible);
std::vector<Entry> getReceipted(const std::vector<Entry>& entries, bool receipt);
std::vector<Entry> sumAmount(const std::vector<Entry>& entries);
std::string getHelpMessage();