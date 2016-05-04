#include "anykey.h"

namespace AnyKey {
  MMRESULT runseq(keyseq& kts) {
    MMRESULT timer;
    for(auto kt : kts) {
      timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keyspress_cb,
          DWORD(&kt.ks), TIME_ONESHOT);
    }
    return timer;
  }
  MMRESULT runloop(keytime& kt) {
    auto timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keyspress_cb,
          DWORD(&kt.ks), TIME_PERIODIC);
    return timer;
  }
  void stoploop(MMRESULT timer) {
    timeKillEvent(timer);
  }
  void WINAPI keyspress_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    auto ks = *(vector<byte>*)id;
    for(auto k : ks) keybd_event((BYTE)k, 0, 0, 0);
    for(auto k : ks) keybd_event((BYTE)k, 0, KEYEVENTF_KEYUP, 0);
  }
}
