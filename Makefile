LDFLAGS := -ldl -lpthread

OUTFILE := a.out

all: cxx/main.o target/debug/librust_rr_test.a
	g++ -g -o cxx/$(OUTFILE) cxx/main.o target/debug/librust_rr_test.a $(LDFLAGS)

run: 
	cxx/$(OUTFILE)

cxx/main.o: cxx/main.cpp cxx/bindings.h
	g++ -g -o cxx/main.o -c cxx/main.cpp

target/debug/librust_rr_test.a: src/lib.rs
	cargo build

clean: 
	rm -f cxx/main.o target/debug/librust_rr_test.a cxx/$(OUTFILE)
