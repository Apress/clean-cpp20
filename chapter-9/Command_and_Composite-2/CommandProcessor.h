#pragma once

#include "Command.h"
#include <stack>

class CommandProcessor {
public:
  void execute(const CommandPtr& command) {
    command->execute();
    commandHistory.push(command);
  }

  void undoLastCommand() {
    if (commandHistory.empty()) {
      return;
    }
    commandHistory.top()->undo();
    commandHistory.pop();
  }

private:
  std::stack<std::shared_ptr<Revertable>> commandHistory;
};
