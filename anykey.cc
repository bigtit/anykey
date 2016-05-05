#include "anykey.h"

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
    gevent = CreateEvent(NULL, TRUE, FALSE, NULL);
    // auto& is mandatory
    for(auto& kt : kts) {
      // gevent = CreateEvent(NULL, TRUE, FALSE, NULL);
      ResetEvent(gevent);
      if(!gevent) exit(-2);
      timer = timeSetEvent(kt.itv, 10, (LPTIMECALLBACK)keyspress_cb, DWORD(&kt.ks), TIME_ONESHOT);
      WaitForSingleObject(gevent, INFINITE);
      // CloseHandle(gevent);
    }
    CloseHandle(gevent);
    return timer;
  }
  MMRESULT runseq(string& str) {
    keyseq ks;
    keytime kt;
    for(auto s : str) kt.ks.push_back((byte)VkKeyScan(s));
    kt.itv = 1000;
    ks.push_back(std::move(kt));
    return runseq(ks);
  }
  MMRESULT runseq(string& str, int itv)
  {
    keyseq ks;
    for(auto s : str) {
      keytime kt;
      kt.itv = itv;
      kt.ks.push_back((byte)VkKeyScan(s));
      ks.push_back(kt);
    }
    return runseq(ks);
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
