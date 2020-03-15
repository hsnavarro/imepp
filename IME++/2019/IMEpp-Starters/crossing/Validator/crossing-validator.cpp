#include "testlib.h"

int main(int argc, char* argv[]){
  registerValidation(argc, argv);
  inf.readToken("[a-z]{1, 1000}", "a");
  inf.readSpace();
  inf.readToken("[a-z]{1, 1000}", "b");
  inf.readEoln();
  inf.readEof();
}
