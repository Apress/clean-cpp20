#pragma once

class Point final {
public:
  Point(const int x, const int y) noexcept : x_{ x }, y_{ y } { }

  int getXCoordinate() const noexcept {
    return x_;
  }

  int getYCoordinate() const noexcept {
    return y_;
  }

private:
  int x_{ 0 };
  int y_{ 0 };
};