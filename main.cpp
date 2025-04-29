#include <iostream>
#include "./util/entry.h"
#include "./functions/file_functions.h"
#include "./functions/data_functions.h"

int main(int argc, char* argv[]) {
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

  //Check for add command
  else if (initCommand == "add") {
    //check for correct length
    if (argc < 8) {
      std::cerr << "Please provide all fields for the 'add' command. See 'help command for more details." << std::endl;
      return -3;
    }
    //basic check for correct date
    if (!(std::string(argv[2]).size() == 10 && std::string(argv[2]).at(4) == '-' && std::string(argv[2]).at(7) == '-')) {
      std::cerr << "Incorrect date format. Please try again in YYYY-MM-DD format." << std::endl;
      return -4;
    }
    addEntry(Entry(argv[2], stod(std::string(argv[3])), argv[4], argv[5], std::string(argv[6]) == "Yes", std::string(argv[7]) == "Yes"));
    std::cout << "Item successfully added!" << std::endl;
  }

  //Check for categories command
  else if (initCommand == "categories") {
    std::vector<Entry> entries = readFile();
    getCategories(entries);
  }

  //Check for locations command
  else if (initCommand == "locations") {
    std::vector<Entry> entries = readFile();
    getLocations(entries);
  }

  //Check for display command, uses filterEntries function to trim based on following commands.
  else if (initCommand == "display") {
    std::vector<Entry> entries = readFile();
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
    std::vector<Entry> entries = readFile();
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
    std::vector<Entry> entries = readFile();
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