#include "anykey.h"
#include <iostream>

using namespace AnyKey;

int main() {
  keyseq ks = {{{0x35,0x34},1500},{{0x20},500},{{0x32},500},{{0x35,0x34},500},{{0x20},500},{{0x32},500}};
  keytime k = {{0x47,0x46},500};
  /*auto t = runloop(k);
  std::cin.get();
  stoploop(t);*/
  runseq(ks);
  std::cin.get();
  return 0;
}
