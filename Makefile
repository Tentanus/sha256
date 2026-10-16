SRC := $(wildcard src/*.cpp)
TESTSRC := $(wildcard test/*.cpp)

INC := $(wildcard inc/*.hpp)

CFL := -Wall -Werror -Wextra

all: build

build: $(SRC) $(TESTSRC)
	@cmake -B build
	@cmake --build build

test: build
	cd ./build/test && ctest -V && ...

self:
	g++ -I inc $(SRC) -o test.out

clean:
	rm -rf build

fclean: clean
	rm -rf ./test.out

.PHONY: all build clean test