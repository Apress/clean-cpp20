#include "CommandProcessor.h"
#include "CompositeCommand.h"
#include "DrawCircleCommand.h"
#include "DrawRectangleCommand.h"
#include "DrawingProcessor.h"

int main() {
  CommandProcessor commandProcessor{ };
  DrawingProcessor drawingProcessor{ };

  auto macroRecorder = std::make_shared<CompositeCommand>();

  Point circleCenterPoint{ 20, 20 };
  CommandPtr drawCircleCommand = std::make_shared<DrawCircleCommand>(drawingProcessor,
    circleCenterPoint, 10);
  commandProcessor.execute(drawCircleCommand);
  macroRecorder->addCommand(drawCircleCommand);

  Point rectangleCenterPoint{ 30, 10 };
  CommandPtr drawRectangleCommand = std::make_shared<DrawRectangleCommand>(drawingProcessor,
    rectangleCenterPoint, 5, 8);
  commandProcessor.execute(drawRectangleCommand);
  macroRecorder->addCommand(drawRectangleCommand);

  commandProcessor.execute(macroRecorder);
  commandProcessor.undoLastCommand();

  return 0;

}
