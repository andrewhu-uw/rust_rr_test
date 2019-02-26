#ifndef RUST_RR_TEST_H
#define RUST_RR_TEST_H

extern "C" {

  struct StringListContainer_impl;

  StringListContainer_impl* new_StringListContainer();

  void StringListContainer_print(StringListContainer_impl*);

  void StringListContainer_Add(StringListContainer_impl*, const char*);

}

class StringListContainer {
 protected:
  StringListContainer_impl* impl;
 public:
  StringListContainer() {
    impl = new_StringListContainer();
  }

  void Add(const char* str) {
    StringListContainer_Add(impl, str);
  }

  void print() {
    StringListContainer_print(impl);
  }
};

#endif
