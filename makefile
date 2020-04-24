debug:
	emcc -O0 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' fib.c -o fib.js
release:
	emcc -O2 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' fib.c -o fib.js