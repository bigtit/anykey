#ifndef _ANYKEY_H_
#define _ANYKEY_H_
#include <windows.h>
#include <vector>
using std::vector;

namespace AnyKey {
  HANDLE gevent;
  using byte = unsigned char;
  using keytime = struct {
    vector<byte> ks;
    // byte k;
    int itv;
  };
  using keyseq = vector<keytime>;

  MMRESULT runseq(keyseq&);
  MMRESULT runloop(keytime&);
  void stoploop(MMRESULT);
}
#endif