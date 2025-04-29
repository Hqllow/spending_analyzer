#include <iostream>
#include "entry.h"
#include "file_functions.h"
#include "data_functions.h"

int main(int argc, char* argv[]) {
  std::vector<Entry> entries = readFile();

  //Check if no arguments are given
  if (argc <= 1) {
    std::cerr << "Provide more arguments. See 'help' command for more details." << std::endl;
    return -1;
  }
  std::string initCommand = argv[1];

  //Check for help command
  if (initCommand == "help") {
    std::cout << getHelpMessage() << std::endl;
  }

  //Check for categories command
  else if (initCommand == "categories") {
    getCategories(entries);
  }

  //Check for locations command
  else if (initCommand == "locations") {
    getLocations(entries);
  }

  //Check for display command, uses filterEntries function to trim based on following commands.
  else if (initCommand == "display") {
    if (argc <= 2) {
      std::cerr << "Please specify entries for 'display'. Use 'all' to include all entries." << std::endl;
      return -3;
    }
    filterEntries(entries, argc, argv);
    if (entries.empty()) {
      std::cout << "No entries provided within bounds given." << std::endl;
    }
    else {
      displayData(entries);
    }
  }

  //Check for sum command, uses filterEntries function to trim based on following commands.
  else if (initCommand == "sum") {
    if (argc <= 2) {
      std::cerr << "Please specify entries for 'sum'. Use 'all' to include all entries." << std::endl;
      return -3;
    }
    filterEntries(entries, argc, argv);
    if (entries.empty()) {
      std::cout << "No entries provided within bounds given." << std::endl;
    }
    else {
      std::cout << "$" << sumAmount(entries) << std::endl;
    }
  }

  //Check for average command, uses filterEntries function to trim based on following commands.
  else if (initCommand == "average") {
    if (argc <= 2) {
      std::cerr << "Please specify entries for 'average'. Use 'all' to include all entries." << std::endl;
      return -3;
    }
    filterEntries(entries, argc, argv);
    if (entries.empty()) {
      std::cout << "No entries provided within bounds given.";
    }
    else {
      std::cout << "$" << meanAmount(entries) << std::endl;
    }
  }

  //Else, command is not valis
  else {
    std::cerr << "Incorrect command at position 1. See 'help' command for more details." << std::endl;
    return -2;
  }
  return 0;
}