using byte = unsigned char;
using keytime = struct {
  byte key;
  int itv;
};
using keyseq = vector<keytime>;

namespace AnyKey {
  class anykey {
    MMRESULT timer; // one timer is enough
    keyseq ks;
  public:
    anykey();
    ~anykey();
    void run_seq(keyseq&);
  };
}
