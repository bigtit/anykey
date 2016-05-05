#include "anykey.h"
// #include <iostream>

namespace AnyKey {
  HANDLE gevent;
  void WINAPI keyspress_cb(UINT, UINT, DWORD id, DWORD, DWORD) {
    auto ks = *(vector<byte>*)id;
    for(auto k : ks) keybd_event((BYTE)k, 0, 0, 0);
    for(auto k : ks) keybd_event((BYTE)k, 0, KEYEVENTF_KEYUP, 0);
    // std::cout << "key pressed: " << std::endl;
    SetEvent(gevent);
  }
  MMRESULT runseq(keyseq& kts) {
    MMRESULT timer = 0;
    // auto& is mandatory
    // gevent = CreateEvent(NULL, TRUE, FALSE, NULL);
    for(auto& kt : kts) {
      gevent = CreateEvent(NULL, TRUE, FALSE, NULL);
      if(!gevent) exit(-2);
      timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keyspress_cb,
        DWORD(&kt.ks), TIME_ONESHOT);
      WaitForSingleObjectEx(gevent, INFINITE, false);
      CloseHandle(gevent);
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
}
