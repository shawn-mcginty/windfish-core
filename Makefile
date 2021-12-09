bin/statemanager_test: src/statemanager.c src/statemanager.test.c
	mkdir -p bin
	clang src/statemanager.c src/statemanager.test.c -o bin/statemanager_test

.PHONY:test
test: bin/statemanager_test
	./bin/statemanager_test
