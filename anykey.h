#include <vector>
using std::vector;

namespace AnyKey {
  using byte = unsigned char;
  using keytime = struct {
    byte key;
    int itv;
  };
  using keyseq = vector<keytime>;

  MMRESULT runseq(keyseq&);
}
