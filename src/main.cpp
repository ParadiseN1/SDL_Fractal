#include "../inc/fractal.h"
#include "../inc/julia_set.h"
#include "../inc/mandelbrot.h"
#include "../inc/zoom.h"


void mouse_hook(double *imaginary, double *real){
    int x, y;
    SDL_GetMouseState(&x, &y);

    if (x > win_width / 2.0)
        *imaginary = (1 - (win_width / (double)x) / 2) * 2;
    else if (x <= win_width / 2)
        *imaginary = (static_cast<double>(x) / (static_cast<double>(win_width) / 2) - 1);
    if (y > win_height / 2)
        *real = (1 - (win_height / (double)y) / 2) * 2;
    else if (y <= win_height / 2.0)
        *real = ((static_cast<double>(y) / (static_cast<double>(win_height) / 2)) - 1);
}

Graphics::RGB random_color(){
    srand((unsigned) time(0));
    size_t r = 1 + (rand() % 255);
    size_t g = 1 + (rand() % 255);
    size_t b = 1 + (rand() % 255);

    std::cout << r << " " << g << " " << b << std::endl;
    return Graphics::RGB{r, g, b};


}


void main_loop(Graphics &&gtx)
{
    int x, y;
    bool loop = true;
    SDL_Event event;
    double im_scale, re_scale;
    Julia fractal_julia{20};
    Mandelbrot fractal_man{20};
    Fractal *fractal = &fractal_julia;
    size_t start = 0;
    size_t time = 0;
    size_t last_frame = 0;

    mouse_hook(&im_scale, &re_scale);
    gtx.rgb_color = {128, 0, 128};

    fractal->Draw(&gtx, im_scale, re_scale);
    while (loop) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                loop = false;
            }
            else if(event.type == SDL_MOUSEWHEEL and fractal->getType() == "Mandelbrot") {
                SDL_GetMouseState(&x, &y);
                if (event.wheel.y > 0) // scroll up
                {
                    zoom(1, x, y, fractal);
                } else if (event.wheel.y < 0) // scroll down
                {
                    zoom(0, x, y, fractal);
                }
                gtx.clearImg();
                fractal->Draw(&gtx, im_scale, re_scale);
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        loop = false;
                        break;
                    case SDLK_SPACE:
                        if (fractal->getType() == "Julia") {
                            fractal = &fractal_man;
                            gtx.clearImg();
                            fractal->Draw(&gtx, im_scale, re_scale);
                        }
                        else
                            fractal = &fractal_julia;
                        break;
                    default:
                        loop = true;
                }
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                gtx.rgb_color = random_color();
                gtx.clearImg();
                fractal->Draw(&gtx, im_scale, re_scale);
            }
        }
        if (fractal->getType() == "Julia") {
            gtx.clearImg();
            mouse_hook(&im_scale, &re_scale);
            fractal->Draw(&gtx, im_scale, re_scale);
        }
    }
}
    // Mandelbrot:

    // 1 thread  - 0.083935 sec
    // 2 threads - 0.07306  sec
    // 3 threads - 0.061305 sec
    // 4 threads - 0.048093 sec
    // 5 threads - 0.043842 sec
    // 6 threads - 0.044643 sec
    // 20 threads - 0.037477 sec

    // Julia:

    // 1 thread  - 0.083935 sec
    // 2 threads - 0.07306  sec
    // 3 threads - 0.061305 sec
    // 4 threads - 0.048093 sec
    // 5 threads - 0.043842 sec
    // 6 threads - 0.044643 sec
    // 20 threads - 0.037477 sec

int main()
{
    Graphics gtx{win_width, win_height};

    main_loop(std::move(gtx));
    return 0;
}