#include "rust_rr_test.h"
#include<iostream>


int main() {
  /*  StringListContainer* slc = new_StringListContainer();
  void* other_p = malloc(16);

  StringListContainer_Add(slc, "test");
  StringListContainer_Add(slc, "hello");
  StringListContainer_Add(slc, "my");
  StringListContainer_Add(slc, "darlin'");

  StringListContainer_print(slc);
  */
  StringListContainer slc;
  slc.Add("test");
  slc.Add("test");
  slc.Add("test");
  slc.Add("test");
  slc.print();
}
