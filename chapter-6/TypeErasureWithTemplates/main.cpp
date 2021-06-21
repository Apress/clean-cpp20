#include "Fruits.h"
#include "PolymorphicObjectWrapper.h"
#include <iostream>
#include <string>
#include <vector>

using Fruits = std::vector<PolymorphicObjectWrapper>;

int main() {
  Fruits fruits{ Apple(), Peach() };

  for (const auto& fruit : fruits) {
    std::cout << fruit.getTypeOfInstanceAsString() << ", ";
  }
  std::cout << std::endl;
}
