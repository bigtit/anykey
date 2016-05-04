#include "anykey.h"
#include <windows.h>

namespace AnyKey {
  anykey::anykey():timer(0) {}
  anykey::~anykey() {
    if(timer) timeKillEvent(timer);
  }
  void anykey::run_seq(keyseq& kts) {
    for(auto kt : kts) {
      timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keypress_cb,
          DWORD(kt.key), TIME_ONESHOT);
    }
  }
  void WINAPI keypress_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    keybd_event((BYTE)id, 0, 0, 0);
    keybd_event((BYTE)id, 0, KEYEVENTF_KEYUP, 0);
  }
  void WINAPI keydown_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    keybd_event((BYTE)id, 0, 0, 0);
  }
}
