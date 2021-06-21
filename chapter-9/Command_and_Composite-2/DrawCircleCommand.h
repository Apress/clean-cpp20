#pragma once

#include "Command.h"
#include "DrawingProcessor.h"
#include "Point.h"

class DrawCircleCommand final : public UndoableCommand {
public:
  DrawCircleCommand() = delete;
  DrawCircleCommand(DrawingProcessor& receiver, const Point& centerPoint,
    const double radius) noexcept :
    receiver_{ receiver }, centerPoint_{ centerPoint }, radius_{ radius } { }

  virtual void execute() override {
    receiver_.drawCircle(centerPoint_, radius_);
  }

  virtual void undo() override {
    receiver_.eraseCircle(centerPoint_, radius_);
  }

private:
  DrawingProcessor& receiver_;
  const Point centerPoint_;
  const double radius_;
};
