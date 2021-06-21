#pragma once

#include "Command.h"
#include <iostream>

class HelloWorldOutputCommand : public Command {
public:
  void execute() override {
    std::cout << "Hello World!" << "\n";
  }
};
