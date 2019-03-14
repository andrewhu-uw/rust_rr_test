//#include "rust_rr_test.h"
#include "bindings.h"
#include<iostream>
#include<cstring>
#include<cstddef>

int main() {
  
  StringListContainer* slc = new_StringListContainer();

  StringListContainer_do(slc, {SLCArgs::Tag::Add, {"we live in a society"}});
  StringListContainer_do(slc, {SLCArgs::Tag::Add, {"gamers rise up"}});
  StringListContainer_do(slc, {SLCArgs::Tag::Add, {"bottom text"}});
  StringListContainer_do(slc, {SLCArgs::Tag::Count, {}});
  StringListContainer_do(slc, {SLCArgs::Tag::Print, {}});

  /*
  StringListContainer_Add(slc, "test");
  StringListContainer_Add(slc, "hello");
  StringListContainer_Add(slc, "my");
  StringListContainer_Add(slc, "darlin'");

  StringListContainer_print(slc);
  */
  /*  
  StringListContainer slc;
  slc.Add("test");
  slc.Add("test");
  slc.Add("test");
  slc.Add("test");
  slc.print();
  */
}
