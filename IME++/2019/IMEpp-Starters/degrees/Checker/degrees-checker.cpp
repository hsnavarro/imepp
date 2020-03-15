#include <string.h>
#include "testlib.h"

using namespace std;


int main(int argc, char* argv[]) {
  registerTestlibCmd(argc, argv);

  string jans = ans.readWord("=[\\[\\]]");
  string pans = ouf.readWord("=[\\[\\]]");

  if (jans != pans) quitf(_wa, "expected: %s, found: %s", jans.c_str(), pans.c_str());

  if (jans == "=]") {
    int jans_val = ans.readInt();
    int pans_val = ouf.readInt();
    if (jans_val != pans_val) quitf(_wa, "expected: =] %d, found: =] %d", jans_val, pans_val);
    else quitf(_ok, "the answer is correct"); 
  } else quitf(_ok, "the answer is correct");
}

