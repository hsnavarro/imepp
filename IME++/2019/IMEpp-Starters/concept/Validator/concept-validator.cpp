#include "testlib.h"

int main(int argc, char* argv[]){
  registerValidation(argc, argv);
  int n = inf.readInt(1, 100000, "n");
  inf.readSpace();
  int q = inf.readInt(1, 100000, "q");
  inf.readEoln();
  
  for(int i = 0; i < n; ++i){
    inf.readInt(0, 10, "grade_i");
    if(i < n-1) inf.readSpace();
  }
  inf.readEoln();

  for(int i = 0; i < q; ++i){
    int esc = inf.readInt(1, 2, "esc");
    inf.readSpace();
    if(esc == 1) {
     int l = inf.readInt(1, n, "l");
     inf.readSpace();
     inf.readInt(l, n, "r");
     inf.readEoln();
    } else {
      inf.readInt(1, n, "i");
      inf.readSpace();
      inf.readInt(0, 10, "value");
      inf.readEoln();
    }
  }
  inf.readEof();
}
