#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int pans = ouf.readInt(0, 32768, "numteams");
    int jans = ans.readInt(); 
    if (pans == jans)
        quitf(_ok, "The number of teams is correct.");
    else
        quitf(_wa, "The number of teams is wrong: expected = %d, found = %d", jans, pans);
}
