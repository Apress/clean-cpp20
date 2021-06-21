#pragma once

#include "Observer.h"
#include <algorithm>
#include <vector>

class Subject {
public:
  void addObserver(const ObserverPtr& observerToAdd) {
    if (isNotYetObservingThisSubject(observerToAdd)) {
      observers.push_back(observerToAdd);
    }
  }

  void removeObserver(ObserverPtr& observerToRemove) {
    std::erase(observers, observerToRemove);
  }

protected:
  void notifyAllObservers() const {
    for (const auto& observer : observers) {
      observer->update();
    }
  }

private:
  bool isNotYetObservingThisSubject(const ObserverPtr& observerToAdd) const {
    return (std::ranges::find(observers, observerToAdd) == end(observers));
  }

  std::vector<ObserverPtr> observers;
};
