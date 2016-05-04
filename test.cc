#include "anykey.h"
#include <iostream>


using AnyKey::runseq;
using AnyKey::keyseq;

int main() {
  keyseq ks = {{{0x35},500},{{0x20},500},{{0x32},500}};
  runseq(ks);
  std::cin.get();
  return 0;
}
