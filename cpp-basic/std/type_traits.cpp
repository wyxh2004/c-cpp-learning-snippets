#include <iostream>
#include <type_traits>

struct TrivalStruct {
  int x;
  float y;
};

struct NoneTrivialStruct {
  NoneTrivialStruct() {} // constructor, making it none trivial
  int x;
  float y;
};

struct StandardLayoutStruct {
  char a;
  int b;
};

struct NonStandardLayoutStruct {
  int b;
  char a; // due to the padding, it is not standard layout, so it can't be used
          // in std::aligned_storage
};

int main() {
  // is_trivial?
  std::cout << "TrivialStruct is trivial: "
            << std::is_trivial<TrivalStruct>::value << std::endl;
  std::cout << "NoneTrivialStruct is trivial: "
            << std::is_trivial<NoneTrivialStruct>::value << std::endl;
  // is_standard_layout?
  std::cout << "StandardLayoutStruct is standard layout: "
            << std::is_standard_layout<StandardLayoutStruct>::value
            << std::endl;
  std::cout << "NonStandardLayoutStruct is standard layout: "
            << std::is_standard_layout<NonStandardLayoutStruct>::value
            << std::endl;
  // is_pod?
  std::cout << "TrivialStruct is pod: " << std::is_pod<TrivalStruct>::value
            << std::endl;
  std::cout << "NoneTrivialStruct is pod: "
            << std::is_pod<NoneTrivialStruct>::value << std::endl;

  return 0;
}