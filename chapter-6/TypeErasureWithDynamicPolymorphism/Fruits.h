#pragma once

#include <string>
#include <memory>

class Fruit {
public:
  virtual std::string getTypeOfInstanceAsString() const = 0;
};

class Apple final : public Fruit {
  std::string getTypeOfInstanceAsString() const override {
    return "class Apple";
  }
};

class Peach final : public Fruit {
  std::string getTypeOfInstanceAsString() const override {
    return "class Peach";
  }
};

using FruitPointer = std::shared_ptr<Fruit>;