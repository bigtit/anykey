#include "anykey.h"
#include <window.h>

using AnyKey::runseq;
using AnyKey::keyseq;

int main() {
  MMRESULT t;
  keyseq ks = {{122,1000},{99,0}};
  runseq(ks);
  return 0;
}
