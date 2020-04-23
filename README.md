# wasm-mandelbrot
an implementation for calculating the mandelbrot set. It has some weird memory leak issues though, fair warning.

for some reason Module.\_free doesn't seem to be... freeing memory. it might be a bug in emscripten that causes problems with event listeners, but I'm not really sure.
