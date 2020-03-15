#include "testlib.h"

int main(int argc, char* argv[]){
  registerValidation(argc, argv);
  int n = inf.readInt(1, 15, "n");
  inf.readSpace();
  inf.readInt(0, 1000000000, "x");
  inf.readSpace();
  inf.readInt(0, 1000000000, "d");
  inf.readEoln();
  
  for(int i = 0; i < n; ++i){
    inf.readInt(0, 1000000000, "s_i");
    if(i < n-1) inf.readSpace();
  }
  inf.readEoln();
  inf.readEof();
}
