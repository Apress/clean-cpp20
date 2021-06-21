#pragma once

#include <string>

class Apple {
public:
  std::string getTypeOfInstanceAsString() const {
    return "class Apple";
  }
};

class Peach {
public:
  std::string getTypeOfInstanceAsString() const {
    return "class Peach";
  }
};