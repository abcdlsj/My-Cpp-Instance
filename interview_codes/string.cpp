#include <bits/stdc++.h>

class String {
public:
  String() : _str(new char[1]) { *_str = '\0'; };
  String(const char *str) : _str(new char[strlen(str) + 1]) {
    strcpy(_str, str);
  };
  String(const String &str) : _str(new char[str.size() + 1]) {
    strcpy(_str, str.c_str());
  };

  String &operator=(String rhs) {
    swap(rhs);
    return *this;
  }
  ~String() { delete[] _str; }

  //
  size_t size() const { return strlen(_str); }
  void swap(String &rhs) { std::swap(_str, rhs._str); }
  const char *c_str() const { return _str; }
private:
  char *_str;
};

void foo(String x) {}
void bar(const String &x) {}
String baz() {
  String ret("world");
  return ret;
}
int main() {
  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;
  s2 = s1;
  foo(s1);
  bar(s1);
  foo("temporary");
  bar("temporary");
  String s4 = baz();
  std::vector<String> svec;
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(baz());
  svec.push_back("good job");
}