# `rustc` error with small structs

# Building on Linux

You need cbindgen and g++ installed

Then you should be able to just run `make`, and then `make run` to get the output.

The executable file is `cxx/a.out` (sorry)

# Building on Windows

I haven't tested the VS project on any other computer, but it should work once
you generate the .lib file by doing `cargo build`