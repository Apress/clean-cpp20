#pragma once

#include <concepts>
#include <memory>
#include <string>

template<typename Class>
concept ClassWithConstCallableMethod = requires (const Class& c) {
  { c.getTypeOfInstanceAsString() } -> std::same_as<std::string>;
};

class PolymorphicObjectWrapper {
public:
  template<ClassWithConstCallableMethod T>
  PolymorphicObjectWrapper(const T& obj) :
    wrappedObject_(std::make_shared<ObjectModel<T>>(obj)) {}

  std::string getTypeOfInstanceAsString() const {
    return wrappedObject_->getTypeOfInstanceAsString();
  }

private:
  struct ObjectConcept {
    virtual ~ObjectConcept() = default;
    virtual std::string getTypeOfInstanceAsString() const = 0;
  };

  template<ClassWithConstCallableMethod T>
  struct ObjectModel final : ObjectConcept {
    ObjectModel(const T& obj) : object_(obj) {}
    std::string getTypeOfInstanceAsString() const override {
      return object_.getTypeOfInstanceAsString();
    }

  private:
    T object_;
  };

  std::shared_ptr<ObjectConcept> wrappedObject_;
};