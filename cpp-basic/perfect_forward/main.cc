#include <iostream>

class Myclass {
public:
  Myclass(std::string &&str) : data(std::move(str)) {}
  Myclass(Myclass &&other) noexcept : data(std::move(other.data)) {}

private:
  std::string data;
};

Myclass createClass() { return Myclass("Hello"); }

Myclass obj = createClass(); // rvalue reference