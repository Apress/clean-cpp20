#pragma once

#include <iostream>
#include <type_traits>

template <typename T>
void print(T var, std::enable_if_t<std::is_enum_v<T>, T>* = nullptr) {
  std::cout << "Calling overloaded print() for enumerations." << std::endl;
}

template <typename T>
void print(T var, std::enable_if_t<std::is_integral_v<T>, T> = 0) {
  std::cout << "Calling overloaded print() for integral types." << std::endl;
}

template <typename T>
void print(T var, std::enable_if_t<std::is_floating_point_v<T>, T> = 0.0) {
  std::cout << "Calling overloaded print() for floating point types." << std::endl;
}

template <typename T>
void print(const T& var, std::enable_if_t<std::is_class_v<T>, T>* = nullptr) {
  std::cout << "Calling overloaded print() for classes." << std::endl;
}
