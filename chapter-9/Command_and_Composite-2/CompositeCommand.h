#pragma once

#include "Command.h"
#include <ranges>
#include <vector>

class CompositeCommand final : public UndoableCommand {
public:
  void addCommand(CommandPtr& command) {
    commands.push_back(command);
  }

  void execute() override {
    for (const auto& command : commands) {
      command->execute();
    }
  }

  void undo() override {
    const auto& commandsInReverseOrder = std::ranges::reverse_view(commands);
    for (const auto& command : commandsInReverseOrder) {
      command->undo();
    }
  }

private:
  std::vector<CommandPtr> commands;
};
