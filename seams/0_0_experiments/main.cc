#include <stdafx.h>

using namespace std;
using namespace std::chrono;

inline uint32_t RSBHack(uint32_t n) {
  n |= (n >> 1);
  n |= (n >> 2);
  n |= (n >> 4);
  n |= (n >> 8);
  n |= (n >> 16);
  return n - (n >> 1);
}

inline uint64_t RSBHack(uint64_t n) {
  n |= (n >> 1);
  n |= (n >> 2);
  n |= (n >> 4);
  n |= (n >> 8);
  n |= (n >> 16);
  n |= (n >> 32);
  return n - (n >> 1);
}

int main() {
  for (uint32_t) return 0;
}
