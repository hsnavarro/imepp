#include "testlib.h"

int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);
  int n = inf.readInt(1, 100000, "n");
  int q = inf.readInt(1, 100000, "q");

  int cnt = 0;
  for(int i = 0; i < n; i++) inf.readInt();
  for (int i = 0; i < q; i++) {
    int esc = inf.readInt(1, 2, "esc");
    if(esc == 1) {
      cnt++;
      int l = inf.readInt(1, n, "l");
      inf.readInt(l, n, "r");

      int jans = ans.readInt(-10, 1000000, "jans");
      int pans = ouf.readInt(-10, 1000000, "pans");
      if(jans != pans) quitf(_wa, "Expected: %d, found %d", jans, pans);

      inf.readStrictDouble(0.0, 10.0, 2, 2, "v_i");
    } else {
      inf.readInt(1, n, "i");
      inf.readInt(0, 10, "value");
    }
  }

  quitf(_ok, "%d answers", cnt);
}

