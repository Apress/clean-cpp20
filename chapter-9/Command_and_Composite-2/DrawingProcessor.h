#pragma once

#include "Point.h"
#include <iostream>

class DrawingProcessor {
public:
  void drawCircle(const Point& centerPoint, const double radius) {
    // Instructions to draw a circle on the screen...
    std::cout << "drawCircle\n";
  };

  void eraseCircle(const Point& centerPoint, const double radius) {
    // Instructions to erase a circle from the screen...
    std::cout << "eraseCircle\n";
  };

  void drawRectangle(const Point& centerPoint, const int width, const int height) {
    // Instructions to draw a rectangle on the screen...
    std::cout << "drawRectangle\n";
  };

  void eraseRectangle(const Point& centerPoint, const int width, const int height) {
    // Instructions to erase a rectangle from the screen...
    std::cout << "eraseRectangle\n";
  };

  // ...
};
