#pragma once

#include "Observer.h"
#include "SpreadsheetModel.h"

class TableView : public Observer {
public:
  explicit TableView(SpreadsheetModel& theModel) :
    model{ theModel } { }

  int getId() const noexcept override {
    return 1;
  }

  void update() override {
    std::cout << "Update of TableView." << std::endl;
  }

private:
  SpreadsheetModel& model;
};

class BarChartView : public Observer {
public:
  explicit BarChartView(SpreadsheetModel& theModel) :
    model{ theModel } { }

  int getId() const noexcept override {
    return 2;
  }

  void update() override {
    std::cout << "Update of BarChartView." << std::endl;
  }

private:
  SpreadsheetModel& model;
};

class PieChartView : public Observer {
public:
  explicit PieChartView(SpreadsheetModel& theModel) :
    model{ theModel } { }

  int getId() const noexcept override {
    return 3;
  }

  void update() override {
    std::cout << "Update of PieChartView." << std::endl;
  }

private:
  SpreadsheetModel& model;
};
