#pragma once

#include "Command.h"
#include <chrono>
#include <thread>

class WaitCommand : public Command {
public:
  explicit WaitCommand(const unsigned int durationInMilliseconds) noexcept :
    durationInMilliseconds{ durationInMilliseconds } { };

  void execute() override {
    std::chrono::milliseconds timespan(durationInMilliseconds);
    std::this_thread::sleep_for(timespan);
  }

private:
  unsigned int durationInMilliseconds{ 1000 };
};
