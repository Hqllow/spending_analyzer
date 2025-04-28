#include "data_functions.h"

void displayData(const std::vector<Entry>& entries) {

}
std::vector<Entry> sumAmount(const std::vector<Entry>& entries) {

}
std::vector<Entry> getFromDateRange(const std::vector<Entry>& entries, std::string date1, std::string date2) {

}
std::vector<Entry> getOnDay(const std::vector<Entry>& entries, std::string date) {
}
std::vector<Entry> getFromLocation(const std::vector<Entry>& entries, std::string location) {

}
std::vector<Entry> getFromCategory(const std::vector<Entry>& entries, std::string category) {

}
std::vector<Entry> getEligible(const std::vector<Entry>& entries, bool eligible) {

}
std::vector<Entry> getReceipted(const std::vector<Entry>& entries, bool receipt) {

}
std::string getHelpMessage() {
  return "Valid commands:"
    << "\nsum {entries}: returns the total amount of spending on given entries."
    << "\naverage {entries}: returns the average amount of spending on given entries."
    << "\ndisplay {entries}: displays a list of the given entries."
    << "\nfrom {initial date in MM/DD/YYYY} to {end date in MM/DD/YYYY}: returns all entries between the dates."
    << "\non {date in MM/DD/YYYY}: returns all entries on given date."
    << "\nat {location}: returns all entries from given location."
    << "\nfor {category}: returns all entries from given category."
}