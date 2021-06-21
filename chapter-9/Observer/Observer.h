#pragma once

#include <memory>

class Observer {
public:
  virtual ~Observer() = default;
  virtual int getId() const noexcept = 0;
  virtual void update() = 0;
};

bool operator==(const Observer& lhs, const Observer& rhs) {
  return lhs.getId() == rhs.getId();
}

using ObserverPtr = std::shared_ptr<Observer>;
