//
// Created by Admin on 17.02.2021.
//

#include "../inc/graphics.h"

void		Graphics::render_text(std::string str)
{
    SDL_Color	color;
    SDL_Surface	*text;

    if (TTF_Init() != 0)
    {
        std::cout <<"FAIL TO LOAD TTF\n";
        exit(0);
    }
    if (font == nullptr)
    {
        std::cout << "FAIL TO LOAD FONT!\n";
        exit(0);
    }
    color = (SDL_Color){255, 255, 255, 0};
    text = TTF_RenderText_Solid(font, str.c_str(), color);
    SDL_BlitSurface(text, nullptr, image, nullptr);
    SDL_FreeSurface(text);
    SDL_UpdateWindowSurface(win);
}

size_t	Graphics::map_rgb(size_t red, size_t green, size_t blue)
{
    if (red > 255)
        red = 255;
    if (green > 255)
        green = 255;
    if (blue > 255)
        blue = 255;
    return ((red << 16) + (green << 8) + blue);
}

int Graphics::clearImg() {
    uint32_t 		*pixels;
    int			i;

    i = -1;
    if (image == nullptr)
        return (-1);
    pixels = static_cast<uint32_t *>(image->pixels);
    while (++i < win_height * win_width)
        pixels[i] = 255;
//    update();
    return (1);
}

int Graphics::imgPutPixel(size_t x, size_t y, size_t color) {
    uint32_t	*pixels;

    if (x < 0 || y < 0 || x >= win_width || y >= win_height || image == nullptr)
        return (-1);
    SDL_LockSurface(image);
    pixels = static_cast<uint32_t *>(image->pixels);
    pixels[y * win_width + x] = color;
    SDL_UnlockSurface(image);
    return (1);
}

Graphics::Graphics(size_t width, size_t height) {
    TTF_Init();
    font = TTF_OpenFont("./resources/OpenSans-Regular.ttf", 32);
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "[Error] SDL Init :" <<  SDL_GetError() << std::endl;
    }
    else {
        std::cout << "SDL INITIALISED!" << std::endl;
        SDL_DisplayMode dm;
        SDL_GetCurrentDisplayMode(0, &dm);
    }

    win = SDL_CreateWindow("Fractal", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    image = SDL_GetWindowSurface(win);
}

Graphics::~Graphics() {
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Graphics::update() {
    SDL_UpdateWindowSurface(win);
}
