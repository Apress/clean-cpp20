#include "Print.h"

enum Enumeration1 {
  Literal1,
  Literal2
};

enum class Enumeration2 : int {
  Literal1,
  Literal2
};

class Clazz { };

int main() {
  Enumeration1 enumVar1{ };
  print(enumVar1);

  Enumeration2 enumVar2{ };
  print(enumVar2);

  print(42);

  Clazz instance{ };
  print(instance);

  print(42.0f);

  print(42.0);

  return 0;
}
