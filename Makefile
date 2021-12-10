.PHONY:clean
clean:
	rm build

.PHONY:build
build:
	mkdir -p build
	cd build && cmake ..
	cd build && make

.PHONY:test
test: build
	cd build && ctest
