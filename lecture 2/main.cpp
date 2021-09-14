#include <iostream>
#include <cstring>

class FooString {
  char * buf;
  public:
    FooString(char * _buf);
  ~FooString();
  void show();
  bool compare(char * str);
};

FooString::FooString(char * _buf) {
  int size = strlen(_buf) + 1;
  buf = new char[size];
  for (size_t i = 0; i < size; i++) {
    buf[i] = _buf[i];
  }
}

FooString::~FooString() {
  delete[] buf;
}

void FooString::show() {
  for (int i = 0; buf[i] != '\0'; i++) {
    std::cout << buf[i];
  }
  std::cout << std::endl;
}

bool FooString::compare(char * str) {
  int i = 0;
  while (str[i] != '\0' || buf[i] != '\0') {
    if (str[i] != buf[i])
      return false;
    i++;
  }
  return true;
}

int main() {
  char testStr[10] = "Check";
  FooString str( & testStr[0]);
  std::cout << "Test of FooString::compare - ";
  if (str.compare(testStr)) {
    testStr[2] = 'a';
    if (!str.compare(testStr)) {
      testStr[6] = 'b';
      if (!str.compare(testStr)) {
        std::cout << "OK" << std::endl;
      } else {
        std::cout << "FAILED" << std::endl;
      }
    } else {
      std::cout << "FAILED" << std::endl;
    }
  } else {
    std::cout << "FAILED" << std::endl;
  }
  return 0;
}
