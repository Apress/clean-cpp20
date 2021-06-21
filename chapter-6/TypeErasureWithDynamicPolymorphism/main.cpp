#include "Fruits.h"
#include <iostream>
#include <vector>

using Fruits = std::vector<FruitPointer>;

int main() {
  FruitPointer fruit1 = std::make_shared<Apple>();
  FruitPointer fruit2 = std::make_shared<Peach>();
  Fruits fruits{ fruit1, fruit2 };

  for (const auto fruit : fruits) {
    std::cout << fruit->getTypeOfInstanceAsString() << ", ";
  }
  std::cout << std::endl;

  return 0;
}
