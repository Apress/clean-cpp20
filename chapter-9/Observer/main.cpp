#include "SpreadsheetModel.h"
#include "Views.h"

int main() {
  SpreadsheetModel spreadsheetModel{ };

  ObserverPtr observer1 = std::make_shared<TableView>(spreadsheetModel);
  spreadsheetModel.addObserver(observer1);

  ObserverPtr observer2 = std::make_shared<BarChartView>(spreadsheetModel);
  spreadsheetModel.addObserver(observer2);

  spreadsheetModel.changeCellValue("A", 1, 42);

  spreadsheetModel.removeObserver(observer1);

  spreadsheetModel.changeCellValue("B", 2, 23.1);

  ObserverPtr observer3 = std::make_shared<PieChartView>(spreadsheetModel);
  spreadsheetModel.addObserver(observer3);

  spreadsheetModel.changeCellValue("C", 3, 3.1415926);

  return 0;
}
