#include <concepts>
#include <iostream>
#include <ranges>

template <typename T>
concept Streamable = requires(std::ostream & os, const T & value) {
  { os << value };
};

int main() {
  auto toSquare = [](const auto value) { return value * value; };
  auto isAnEvenNumber = [] <std::integral T> (const T value) {
    return (value % 2) == 0;
  };
  auto print = [] <Streamable T> (const T& printable) {
    std::cout << printable << '\n';
  };

  for (const auto& value : std::views::iota(0, 100)
    | std::views::transform(toSquare)
    | std::views::filter(isAnEvenNumber)) {
    print(value);
  }

  return 0;
}
