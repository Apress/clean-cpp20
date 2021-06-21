#pragma once

#include "Command.h"

class Server {
public:
  void acceptCommand(const CommandPtr& command) {
    command->execute();
  }
};
