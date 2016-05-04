#include "anykey.h"
#include <iostream>


using AnyKey::runseq;
using AnyKey::keyseq;

int main() {
  keyseq ks = {{{0x35},1000},{{0x20},1000}};
  runseq(ks);
  std::cin.get();
  return 0;
}
