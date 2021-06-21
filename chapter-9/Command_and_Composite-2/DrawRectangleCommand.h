#pragma once

#include "Command.h"
#include "DrawingProcessor.h"
#include "Point.h"

class DrawRectangleCommand final : public UndoableCommand {
public:
  DrawRectangleCommand() = delete;
  DrawRectangleCommand(DrawingProcessor& receiver, const Point& centerPoint,
    const int width, const int height) noexcept :
    receiver_{ receiver }, centerPoint_{ centerPoint }, width_{ width },
    height_{ height } { }

  virtual void execute() override {
    receiver_.drawRectangle(centerPoint_, width_, height_);
  }

  virtual void undo() override {
    receiver_.eraseRectangle(centerPoint_, width_, height_);
  }

private:
  DrawingProcessor& receiver_;
  const Point centerPoint_;
  const int width_;
  const int height_;
};