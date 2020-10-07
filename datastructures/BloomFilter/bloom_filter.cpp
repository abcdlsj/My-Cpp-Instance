#include <bits/stdc++.h>
using namespace std;

int little_endian() {
  int a = 1;
  return *(char*)&a;
}

inline uint32_t decode_fixed32(const char* ptr) {
  const uint8_t* const buffer = reinterpret_cast<const uint8_t*> (ptr);

}
