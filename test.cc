#include "anykey.h"
#include "resource.h"
#include <string>

using namespace AnyKey;

//#pragma data_seg("hookdata")
//HHOOK g_hook = 0;
//HINSTANCE g_inst;
//#pragma data_seg()
//
//bool set_hook();
//bool rm_hook();
//
//LRESULT CALLBACK dlg_proc(HWND hdlg, UINT msg, WPARAM, LPARAM) {
//  switch(msg) {
//  case WM_CREATE:
//    break;
//  case WM_INITDIALOG:
//    set_hook();
//    break;
//  case WM_COMMAND:
//    break;
//  case WM_CLOSE:
//    rm_hook();
//    EndDialog(hdlg, 0);
//    break;
//  default:
//    break;
//  }
//  return 0;
//}

//int APIENTRY WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int) {
//  HANDLE mutex = CreateMutex(0, 0, "sadopqn;ands5");
//  if(GetLastError() == ERROR_ALREADY_EXISTS) {
//    MessageBox(0, "Only one instance could be executed.", "Error", MB_ICONWARNING);
//    CloseHandle(mutex);
//    mutex = 0;
//    return -1;
//  }
//  g_inst = hinst;
//  DialogBoxParam(hinst, MAKEINTRESOURCE(IDD_MAIN), 0, (DLGPROC)dlg_proc, 0);
//  return 0;
//}

int main() {
  keyseq ks = {{{0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x0d},2000}};
  runseq(ks);
  std::string s = "hghhello";
  runseq(s, 10);
  return 0;
}

//LRESULT CALLBACK llk_proc(int code, WPARAM wp, LPARAM lp) {
//  PKBDLLHOOKSTRUCT k = (PKBDLLHOOKSTRUCT)lp;
//  bool kup = WM_KEYUP == wp || WM_SYSKEYUP == wp;
//  if(code != HC_ACTION) return CallNextHookEx(0, code, wp, lp);
//  keyseq ks = {{{0x43},2000},{{0x4e},200},{{0x4d},200},{{0x20},1000},{{0x0d},200},{{0x32},200}};
//  if(k->vkCode == VK_F11 && kup) runseq(ks); // F11 to activate
//  return 0;
//}
//
//bool set_hook() {
//  if(!g_hook) g_hook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)llk_proc, g_inst, 0);
//  return (g_hook != 0);
//}
//
//bool rm_hook() {
//  if(UnhookWindowsHookEx(g_hook)) return false;
//  return true;
//}