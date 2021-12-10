SDL_INCLUDE_MACOS = -I/Library/Frameworks/SDL2.framework -F/Library/Frameworks -framework SDL2

bin/main_test: src/engine.c src/graphics.c src/statemanager.c src/main.c
	clang ${SDL_INCLUDE_MACOS} src/engine.c src/graphics.c src/statemanager.c src/main.c -o bin/main_test

bin/statemanager_test: src/statemanager.c src/statemanager.test.c
	mkdir -p bin
	clang src/statemanager.c src/statemanager.test.c -o bin/statemanager_test

.PHONY:test
test: test_headless bin/main_test
	make test_headless
	./bin/main_test

.PHONY:test_headless
test_headless: bin/statemanager_test
	./bin/statemanager_test

.PHONY:clean
clean:
	rm bin
	rm src/*.o