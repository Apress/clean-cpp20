#pragma once

#include "HelloWorldOutputCommand.h"
#include "Server.h"
#include "WaitCommand.h"

class Client {
public:
  void run() {
    Server theServer{ };
    const unsigned int SERVER_DELAY_TIMESPAN{ 3000 };

    CommandPtr waitCommand = std::make_shared<WaitCommand>(SERVER_DELAY_TIMESPAN);
    theServer.acceptCommand(waitCommand);

    CommandPtr helloWorldOutputCommand = std::make_shared<HelloWorldOutputCommand>();
    theServer.acceptCommand(helloWorldOutputCommand);
  }
};
