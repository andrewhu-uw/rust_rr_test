#include <cstdarg>
#include <cstdint>
#include <cstdlib>

struct StringListContainer;

struct SLCArgs {
  enum class Tag {
    Add,
    Count,
    Print,
  };

  struct Add_Body {
    const char *_0;
  };

  Tag tag;
  union {
    Add_Body add;
  };
};

extern "C" {

void StringListContainer_Add(StringListContainer *slc_p, const char *s_p);

void StringListContainer_do(StringListContainer *slc_p, SLCArgs m);

void StringListContainer_print(const StringListContainer *slc_p);

StringListContainer *new_StringListContainer();

} // extern "C"
