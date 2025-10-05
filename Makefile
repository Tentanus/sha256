SRC := $(wildcard src/*.cpp)
TESTSRC := $(wildcard test/*.cpp)

.PHONY: all build clean test

all: build

build: $(SRC) $(TESTSRC)
	@cmake -B build
	@cmake --build build

test: build
	cd ./build/test && ctest -V

clean:
	rm -rf build