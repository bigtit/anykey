#ifndef _ANYKEY_H_
#define _ANYKEY_H_
#include <windows.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

namespace AnyKey {
  // extern HANDLE gevent;
  using byte = unsigned char;
  using keytime = struct {
    vector<byte> ks;
    // byte k;
    int itv;
  };
  using keyseq = vector<keytime>;

  MMRESULT runseq(keyseq&);
  MMRESULT runseq(string&); // deprecated
  MMRESULT runseq(string&, int);
  MMRESULT runloop(keytime&);
  void stoploop(MMRESULT);
}
#endif