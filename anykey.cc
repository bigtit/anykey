#include "anykey.h"
#include <windows.h>

namespace AnyKey {
  MMRESULT runseq(keyseq& kts) {
    MMRESULT timer;
    for(auto kt : kts) {
      timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keypress_cb,
          DWORD(kt.key), TIME_ONESHOT);
    }
    return timer;
  }
  void WINAPI keypress_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    keybd_event((BYTE)id, 0, 0, 0);
    keybd_event((BYTE)id, 0, KEYEVENTF_KEYUP, 0);
  }
  void WINAPI keydown_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    keybd_event((BYTE)id, 0, 0, 0);
  }
}
