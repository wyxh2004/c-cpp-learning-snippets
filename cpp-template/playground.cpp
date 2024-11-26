class Base {
public:
  void func(int) {}
  void func(double) {}
};

class Derived : public Base {
public:
  using Base::func;
  void func(char) {}
};

[[nodiscard]] int calculate() { return 42; }
