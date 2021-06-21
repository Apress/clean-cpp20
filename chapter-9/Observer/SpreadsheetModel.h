#pragma once

#include "Subject.h"
#include <iostream>
#include <string_view>

class SpreadsheetModel : public Subject {
public:
  void changeCellValue(std::string_view column, const int row, const double value) {
    std::cout << "Cell [" << column << ", " << row << "] = " << value << std::endl;
    // Change value of a spreadsheet cell, and then...
    notifyAllObservers();
  }
};
