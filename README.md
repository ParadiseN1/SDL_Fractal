# Fractal implementation using C++ and SDL2.0 library.

The multithread benefit for Mandelbrot Set:
    Mandelbrot:

    1 thread:    0.083935 sec
    2 threads:   0.07306  sec 14% speedup
    3 threads:   0.061305 sec 37% speedup
    4 threads:   0.048093 sec 74% speedup
    5 threads:   0.043842 sec 91% speedup
    6 threads:   0.044643 sec 88% speedup
    20 threads:  0.037477 sec 123% speedup

sec - seconds to render default Mandelbrot Set 1080x720

We can that using concurrent methods we can render our image almost 2.5 times faster!
