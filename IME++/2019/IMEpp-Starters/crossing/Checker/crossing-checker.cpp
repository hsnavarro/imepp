#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int pans = ouf.readInt(0, 1000, "lcs");
    int jans = ans.readInt(); 
    if (pans == jans)
        quitf(_ok, "The lcs is correct.");
    else
        quitf(_wa, "The lcs is wrong: expected = %d, found = %d", jans, pans);
}
